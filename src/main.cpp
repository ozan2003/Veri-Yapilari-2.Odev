/**
 * @file       main.cpp
 * @brief      Programın başlangıç noktası.
 */

#include "array/ArrayList.hpp" // ArrayList
#include "to_ascii.hpp"        // to_ascii

#include <algorithm> // std::minmax_element, std::find_if
#include <cstdlib>   // std::system
#include <fstream>   // std::ifstream
#include <iomanip>   // std::setw
#include <iostream>  // std::cout, std::flush, std::cerr, std::ios_base::sync_with_stdio
#include <sstream>   // std::istringstream
#include <string>    // std::string, std::getline

constexpr int line_number{500}; // veri.txt's line number.

int main()
{
    // Increase output performance.
    std::ios_base::sync_with_stdio(false); // Disable synchronization between C and C++ standard streams
                                           // since we're not using printf() and scanf() anyway.

    // Open the file.
    std::ifstream fin{"veri.txt"};
    if (!fin.good()) // Check if the file is opened successfully.
    {
        std::cerr << "File could not be opened.\n";
        return 1;
    }

    // Initialize the array with veri.txt's line number.
    ArrayList array(line_number);

    // Traverse the array.
    for (int i{}; i < array.size(); ++i)
    {
        // Read one line per iteration.
        if (std::string line; std::getline(fin, line))
        {
            // Create a string stream to read numbers from the line.
            std::istringstream sin{line};

            // Read every number in the line.
            for (int num; sin >> num;)
            {
                // Insert unique numbers in the tree.
                array[i].tree.insert(num);
            }

            // Insert leaves to the stack.
            array[i].tree.insert_leaves_to(array[i].stack);
        }
        // Enumerate the index of the Pair for display purposes. Index starts from 1.
        array[i].index = i + 1;
    }

    // All numbers are read from the file, so we don't need the stream anymore.
    fin.close();

    // Find and remove the item with the only non-empty tree.
    auto non_empty_item = std::find_if(array.begin(), array.end(),
                                       [](const Pair& p)
                                       {
                                           return !(p.tree.empty());
                                       });

    // Traverse the array until all trees are empty.
    while (non_empty_item != array.end())
    {
        // Find the min and max elements in the stack.
        auto [min_item, max_item] = std::minmax_element(array.begin(), array.end(),
                                                        [](const Pair& p1, const Pair& p2)
                                                        {
                                                            // If both stacks are not empty, compare their tops.
                                                            if (!(p1.stack.empty() || p2.stack.empty()))
                                                            {
                                                                return p1.stack.top() < p2.stack.top();
                                                            }
                                                            // If the first stack is empty, return false.
                                                            // Because we want to remove the min element first.
                                                            else if (p1.stack.empty())
                                                            {
                                                                return false;
                                                            }
                                                            // If the second stack is empty, return true.
                                                            // Because we want to remove the min element first.
                                                            else
                                                            {
                                                                return true;
                                                            }
                                                        });

        // If the min_item's stack is empty, remove it from the array.
        if (auto item = min_item; (*item).stack.empty())
        {
            // The distance between "item" and begginning of array returns an index.
            array.remove(item - array.begin());

            // Traverse the trees and print their sum of contents converted to char.
            for (const auto& element : array)
            {
                std::cout << static_cast<char>(to_ascii(element.tree.sum()));
            }

            std::flush(std::cout); // Flush the output buffer,
                                   // ensure that any buffered output is written
                                   // to the console before clearing the screen.
            // Clear the screen.
            std::system("cls");
        }
        else // Otherwise, pop the top element of the stack and continue.
        {
            (*min_item).stack.pop();
        }

        // If the max_item's stack is empty, remove it from the array.
        if (auto item = max_item; (*item).stack.empty())
        {
            // The distance between "item" and begginning of array returns an index.
            array.remove(item - array.begin());

            // Traverse the trees and print their sum of contents converted to char.
            for (const auto& element : array)
            {
                std::cout << static_cast<char>(to_ascii(element.tree.sum()));
            }

            std::flush(std::cout); // Flush the output buffer,
                                   // ensure that any buffered output is written
                                   // to the console before clearing the screen.
            // Clear the screen.
            std::system("cls");
        }
        else // Otherwise, pop the top element of the stack and continue.
        {
            (*max_item).stack.pop();
        }

        // Update the non_empty_item.
        non_empty_item = std::find_if(array.begin(), array.end(),
                                      [](const Pair& p)
                                      {
                                          return !(p.tree.empty());
                                      });
    }

    // Formatted output.
    std::cout << "=========================\n";
    std::cout << "|" << std::setw(25) << "|\n";
    std::cout << "|" << std::setw(1) << "  Son karakter: " << static_cast<char>(to_ascii((*non_empty_item).tree.sum()))
              << std::setw(7) << "|" << '\n';
    std::cout << "|" << std::setw(4) << "  AVL No      : " << (*non_empty_item).index << std::setw(5) << "|" << '\n';
    std::cout << "|" << std::setw(25) << "|\n";
    std::cout << "=========================\n";
}