#include "binary-search-tree.h"
#include <iostream>
#include <queue>

using namespace std;

BinarySearchTree::Node::Node(DataType newval)
{
    val = newval;

    left = nullptr;
    right = nullptr;

    avlBalance = 0;
}

int BinarySearchTree::getNodeDepth(Node* n) const
{
    // Compute the depth of a specified node
    int depth_l = 0;
    int depth_r = 0;

    if (n == nullptr) return 0;

    // Recursively find the depth of the left & right subtrees of the specified node (add 1)
    depth_l = 1 + getNodeDepth(n->left);
    depth_r = 1 + getNodeDepth(n->right);

    // return the depth of the deeper branch
    if (depth_l > depth_r) {
        return depth_l;
    } else {
        return depth_r;
    }
}

// Constructor
BinarySearchTree::BinarySearchTree()
{
    root_ = nullptr;
    size_ = 0;
}

// Destructor
BinarySearchTree::~BinarySearchTree()
{
    // Delete the tree elements with pre-order with queue library functionality
    // Note: reference Week 7 - BinaryTreeBFT code (queue implementation)

    // if the tree is empty, there is nothing to destruct
    if (root_ == nullptr) return;

    // Create an empty queue for level order traversal
    queue<Node *> queue;

    // Do level order traversal starting from root
    queue.push(root_);
    Node *temp = root_;

    // Iterate while there are elements to be deleted
    while (!queue.empty()) {

        // handle the first element in the queue
        temp = queue.front();
        queue.pop();

        // Push all children into the queue
        if (temp->left != nullptr) queue.push(temp->left);
        if (temp->right != nullptr) queue.push(temp->right);

        // delete temp (element)
        //delete temp;
    }
    // set root_ pointer to null
    root_ = nullptr;
}

unsigned int BinarySearchTree::size() const
{
    // Simply return the size of the tree
    return size_;
}

BinarySearchTree::DataType BinarySearchTree::max() const
{
    Node* current_node = root_;

    // The rightmost node is the largest
    while (current_node->right != nullptr) {
        current_node = current_node->right;
    }
    return current_node->val;
}

BinarySearchTree::DataType BinarySearchTree::min() const
{
    Node* temp = root_;

    // The leftmost node is the smallest
    while (temp->left != nullptr) {
        temp = temp->left;
    }
    return temp->val;
}

unsigned int BinarySearchTree::depth() const
{
    // Return the node depth
    // cout << getNodeDepth(root_) << endl;
    return getNodeDepth(root_) - 1;
}

void BinarySearchTree::print() const
{
    // Print the tree elements with level order traversal with queue library functionality
    // Note: reference Week 7 - BinaryTreeBFT code (queue implementation)

    if (root_ == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }

    // create a queue to contain node elements to then print
    queue<Node*> queue;
    Node *temp = root_;

    if(root_ != nullptr) queue.push(root_);
    cout << "[";

    while(!queue.empty())
    {
        temp = queue.front();
        queue.pop();

        cout << temp->val << " ";
        if(temp->left != nullptr) queue.push(temp->left);
        if(temp->right != nullptr) queue.push(temp->right);

    }
    cout << "]" << std::endl;
}

bool BinarySearchTree::exists(DataType val) const
{
    // starting at the root
    Node* temp = root_;

    // check all nodes (until temp == nullptr) or until val is found
    while (temp != nullptr) {
        if (val == temp->val) return true;

        else if (val < temp->val) {
            temp = temp->left;
        }
        else temp = temp->right;
    }
}

BinarySearchTree::Node* BinarySearchTree::getRootNode()
{
    // return root node
    return root_;
}

BinarySearchTree::Node** BinarySearchTree::getRootNodeAddress()
{
    // return reference of root node (memory address)
    return &root_;
}

bool BinarySearchTree::insert(DataType val) {
    // If tree is empty, set the root = val
    if (root_ == nullptr) {
        root_ = new Node(val);

        // increase size and return true
        size_++;
        return true;
    } else {

        Node *temp = root_;
        Node *parent;

        // Iterate until the the end of a branch is reached (temp = null)
        while (temp != nullptr) {

            // Return false is val already exists in the tree
            if (val == temp->val) return false;
                // If val is smaller then the current node key, check L subtree
            else if (val < temp->val) {
                parent = temp;
                temp = temp->left;
            }
                // If val is smaller then the current node key, check L subtree
            else {
                parent = temp;
                temp = temp->right;
            }
        }

        Node *nodeInsert = new Node(val);
        // Double check the following line
        if (val < parent->val) {
            parent->left = nodeInsert;
        } else {
            parent->right = nodeInsert;
        }

        // increase size and return true
        size_++;
        return true;

    }
}

bool BinarySearchTree::remove(DataType val)
{
    // Note: reference Week 7 - BinarySearchTree_Delete code

    // if tree is empty, return false
    if (root_ == nullptr) return false;

    else {
        Node* parent = root_;
        Node* temp = root_;

        bool isLeftChild = false;
        bool found = false;

        // 1. Find val in tree
        while (temp != nullptr) {
            if (temp->val == val) {
                found = true;
                break;
            } else if (val < temp->val) {
                parent = temp;
                temp = temp->left;
                isLeftChild = true;
            } else {
                parent = temp;
                temp = temp->right;
                isLeftChild = false;
            }
        }

        // 2. If not found return false
        if (!found) return false;

        // 3. If found, then:
        else {
            // 3.1. If val is a leaf node, remove it and return true
            if (temp->left == nullptr && temp->right == nullptr) {
                // if val is the root node
                if (temp == root_) {
                    delete root_;
                    root_ = nullptr;
                    size_--;
                    return true;
                }
                // if val is not the root node
                delete temp;
                if (isLeftChild) parent->left = nullptr;
                else parent->right = nullptr;

                // decrease size and return true
                size_--;
                return true;
            }

            // 3.3. If val has 2 child nodes, replace values with predecessor, delete predecessor and return true
            if (temp->left != nullptr && temp->right != nullptr) {
                // determine the predecessor
                Node *predecessor = temp->left;
                while (predecessor->right != nullptr) predecessor = predecessor->right;

                // Store predecessor value
                int predecessorVal = predecessor->val;
                // Recursively remove predecessor value
                remove(predecessorVal);
                // Replace deleted node with the predecessor
                temp->val = predecessorVal;

                // decrease size and return true
                size_--;
                return true;
            }

            // 3.2. If val has only one child node, cut val from the tree and link val's parent directly to val's child
            // Left node != null, right node == null
            if (temp->left != nullptr && temp->right == nullptr) {
                if(temp == root_) root_ = temp->left;
                if (isLeftChild) parent->left = temp->left;
                else parent->right = temp->left;
                delete temp;

                // decrease size and return true
                size_--;
                return true;
            }

            // Left node == null, right node != null
            else if (temp->left == nullptr && temp->right != nullptr) {
                if(temp == root_) root_ = temp->right;
                if (isLeftChild) parent->left = temp->right;
                else parent->right = temp->right;
                delete temp;

                // decrease size and return true
                size_--;
                return true;
            }
        }
    }
}

void BinarySearchTree::updateNodeBalance(Node* n) {
    //Determine the avlBalance of specified node
    int leftHeight = getNodeDepth(n->left) - 1;
    int rightHeight = getNodeDepth(n->right) - 1;

    n->avlBalance = leftHeight - rightHeight;
}