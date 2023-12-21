/**
 * @file       AVLTree.cpp
 * @brief      AVLTree sınıfının metot gövdelerini içeren kaynak dosyası.
 */

#include "avl/AVLTree.hpp" // AVLTree
#include "stack/Stack.hpp" // Stack

// Default constructor.
AVLTree::AVLTree() = default;

// Recursively deletes the tree with post-order traversal.
AVLTree::~AVLTree()
{
    clear();
}

// Recursively deletes the tree with post-order traversal.
void AVLTree::clear()
{
    clear_helper(m_root);

    m_root  = nullptr;
    m_count = 0;
}

// Recursively deletes the tree with post-order traversal.
void AVLTree::clear_helper(Node* root)
{
    // Base case.
    if (root == nullptr)
    {
        delete root;
        return;
    }

    if (root->leftchild)
    {
        clear_helper(root->leftchild);
        root->leftchild = nullptr; // Set left child pointer to nullptr.
    }
    if (root->rightchild)
    {
        clear_helper(root->rightchild);
        root->rightchild = nullptr; // Set right child pointer to nullptr.
    }
}

// Inserts the item to the tree.
Node* AVLTree::insert(const int item)
{
    m_root = insert_helper(m_root, item);
    m_count++;

    return m_root;
}

// Removes the item from the tree.
int AVLTree::remove(const int item)
{
    // Find the item first.
    int temp = find_helper(m_root, item);

    // If the item exists, remove it.
    if (temp != 0)
    {
        m_root = remove_helper(m_root, item);
        m_count--;
    }

    // Return the removed item.
    return temp;
}

// Finds the item in the tree.
int AVLTree::find(const int item) const
{
    // Find the item recursively.
    return find_helper(m_root, item);
}

// Returns the tree's size.
int AVLTree::size() const
{
    return m_count;
}

// Returns true if the tree is empty.
bool AVLTree::empty() const
{
    return size() == 0;
}

// Prints the tree in post-order traversal.
void AVLTree::print() const
{
    if (m_root == nullptr)
    {
        return;
    }
    else
    {
        print_helper(m_root);
    }
}

// Returns the root's height.
int AVLTree::height(Node* node)
{
    if (node == nullptr)
    {
        /*
         *  The reason for empty node's height -1 is that it makes
         *  the node height formula convenient, we don't have to
         *  write special cases.
         *
         *  (-1) + 1 -> 0.
         */
        return -1;
    }

    return node->height;
}

// Returns the root's balance factor.
int AVLTree::balance_factor(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    // Balance factor = height(right subtree) - height(left subtree)
    // A node is said to be balanced if its balance factor is -1, 0, or 1.
    return height(node->rightchild) - height(node->leftchild);
}

// Rotate the root to the right.
Node* AVLTree::rotate_right(Node* y)
{
    Node* x  = y->leftchild;  // x is the root's left child.
    Node* T2 = x->rightchild; // T2 is the x's right child.

    x->rightchild = y;  // Make the root as x's right child.
    y->leftchild  = T2; // Make T2 as the root's left child.

    // Apply the node height formula.
    y->height = std::max(height(y->leftchild), height(y->rightchild)) + 1;
    x->height = std::max(height(x->leftchild), height(x->rightchild)) + 1;

    // Return the new root.
    return x;
}

// Rotate the root to the left.
Node* AVLTree::rotate_left(Node* x)
{
    Node* y  = x->rightchild; // y is the root's right child.
    Node* T2 = y->leftchild;  // T2 is the y's left child.

    y->leftchild  = x;  // Make the root as y's left child.
    x->rightchild = T2; // Make T2 as the root's right child.

    // Apply the node height formula.
    x->height = std::max(height(x->leftchild), height(x->rightchild)) + 1;
    y->height = std::max(height(y->leftchild), height(y->rightchild)) + 1;

    // Return the new root.
    return y;
}

// Balance the root.
Node* AVLTree::balance(Node* root)
{
    if (root == nullptr)
    {
        return root;
    }

    // Apply the node height formula.
    // Update the root's height.
    root->height = std::max(height(root->leftchild), height(root->rightchild)) + 1;

    // Check for balance factor whether root is left or right-heavy.
    int balance = balance_factor(root);

    // If the root is left-heavy.
    if (balance > 1)
    {
        // If the root's right child is right-heavy.
        if (balance_factor(root->rightchild) < 0)
        {
            // Double rotation (Right-left rotation).
            root->rightchild = rotate_right(root->rightchild);
        }

        return rotate_left(root); // Single rotation.
    }

    // If the root is right-heavy.
    if (balance < -1)
    {
        // If the root's left child is left-heavy.
        if (balance_factor(root->leftchild) > 0)
        {
            // Double rotation (Left-right rotation).
            root->leftchild = rotate_left(root->leftchild);
        }

        return rotate_right(root); // Single rotation.
    }

    return root;
}

// Insert unique numbers to the tree.
Node* AVLTree::insert_helper(Node* root, const int item)
{
    // First step is the basic BST insertion.
    if (root == nullptr)
    {
        // Done.
        return new Node{item};
    }

    if (item < root->data) // Insert to the right if item is less than root.
    {
        root->leftchild = insert_helper(root->leftchild, item);
    }
    else if (item > root->data) // Insert to the left if item is less than root.
    {
        root->rightchild = insert_helper(root->rightchild, item);
    }
    else // Item already exists in the tree, so no need to insert.
    {
        return root;
    }
    // Second step is the fixing the AVL Tree's property from changed node.
    // Node's height is updated within balance.
    return balance(root);
}

Node* AVLTree::remove_helper(Node* root, const int item)
{
    // First step is BST removal.
    if (root == nullptr)
    {
        return root;
    }

    if (item < root->data)
    {
        root->leftchild = remove_helper(root->leftchild, item);
    }
    else if (item > root->data)
    {
        root->rightchild = remove_helper(root->rightchild, item);
    }
    else // Found, remove it.
    {
        if (root->leftchild == nullptr)
        {
            Node* temp = root->rightchild;
            delete root;
            return temp;
        }
        else if (root->rightchild == nullptr)
        {
            Node* temp = root->leftchild;
            delete root;
            return temp;
        }

        Node* temp       = min(root->rightchild);
        root->data       = temp->data;
        root->rightchild = remove_helper(root->rightchild, temp->data);
    }

    // Second step is the fixing the AVL Tree's property from changed node.
    return balance(root);
}

// Find the min element in the tree.
Node* AVLTree::min(Node* root)
{
    // The min element is the leftmost leaf.
    while (root->leftchild != nullptr)
    {
        root = root->leftchild;
    }
    return root; // Return the min element.
}

// Recursively prints the elements of the AVL tree in post-order traversal.
void AVLTree::print_helper(Node* root) const
{
    if (root == nullptr)
    {
        return;
    }

    // Post-order traversal.
    print_helper(root->leftchild);  // Call left sub-tree.
    print_helper(root->rightchild); // Call right sub-tree.
    std::cout << root->data << ' ';
}

// Finding items are the same as in BST.
int AVLTree::find_helper(Node* root, const int item) const
{
    if (root == nullptr)
    {
        // Not found.
        return -1;
    }

    if (item < root->data)
    {
        // If the item is less than root, search the left sub-tree.
        return find_helper(root->leftchild, item);
    }
    else if (item > root->data)
    {
        // If the item is greater than root, search the right sub-tree.
        return find_helper(root->rightchild, item);
    }
    else
    {
        // Found.
        return root->data;
    }
}

// Insert the leaves to the stack with post-order traversal.
void AVLTree::insert_leaves_to(Stack& st)
{
    insert_leaves_to_helper(m_root, st);
}

// Recursively inserts the leaves to the stack with post-order traversal.
void AVLTree::insert_leaves_to_helper(Node* root, Stack& st)
{
    // Base case.
    if (root == nullptr)
    {
        return;
    }

    // Post-order traversal.
    insert_leaves_to_helper(root->leftchild, st);
    insert_leaves_to_helper(root->rightchild, st);

    // Insert the leaves to the stack.
    if (root->isleaf())
    {
        st.push(root->data);
    }
}

// Converts the sum of the tree to ASCII code.
int AVLTree::sum() const
{
    int result{}; // Accumulator.

    sum_helper(m_root, result); // Sum the tree recursively.
    return result;              // Return the sum.
}

// Recursively sums the tree with post-order traversal.
void AVLTree::sum_helper(Node* root, int& accumulator) const
{
    if (root == nullptr)
    {
        // Base case.
        return;
    }

    // Exclude the leaves.
    if (root->isleaf())
    {
        return;
    }

    accumulator += root->data; // Sum the root's data.
    // Post-order traversal.
    sum_helper(root->leftchild, accumulator);
    sum_helper(root->rightchild, accumulator);
}
