/**
 * @file       to_ascii.cpp
 * @brief      to_ascii fonksiyonunun gövdesini içeren kaynak dosyası.
 */

#include "to_ascii.hpp" // to_ascii

// Converts the given integer to its ASCII equivalent.
int to_ascii(const int value)
{
    // ASCII range: [65, 90]
    return value % (90 - 65 + 1) + 65;
}
