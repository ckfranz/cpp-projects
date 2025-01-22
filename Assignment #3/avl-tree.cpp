#include "avl-tree.h";
#include <algorithm> // to include 'abs'
#include <iostream>

using namespace std;

bool AVLTree::insert(DataType val)
{
    //////////////////////////////////////
    // 1. Use the regular BST Insert operation, insert new Node N.
    bool result = BinarySearchTree::insert(val);

    // if cannot be inserted, return false
    if(!result) return false;

    //////////////////////////////////////
    // 2. Find out if any of N’s ancestors is unbalanced.

    Node* root = *getRootNodeAddress();

    // special case, if N is inserted at the root node, nothing unbalanced, just return. (ie. only 1 node)
    if(root->val == val) {
        //cout << val << " : balanced" << endl;
        return true;
    }

    // 2.1. If unbalanced, find out the pointer to the unbalanced ancestor that is closest to N.
    Node *temp;
    temp = root;
    Node *temp_parent;
    Node *alpha = nullptr;

    do {
        temp_parent = temp;
        if (val > temp->val) temp = temp->right;
        else if (val < temp->val) temp = temp->left;

        // now, check if temp_parent is unbalanced.
        updateNodeBalance(temp_parent);

        if (abs(temp_parent->avlBalance) >= 2) {
            alpha = temp_parent;
            //cout << "unbalanced apha:" << alpha->val << endl;
        }
        //cout << temp_parent->val << " : " << abs(temp_parent->avlBalance) << endl;
    } while (temp->val != val);

    // 2.2. If not, job done and return.
    if(!alpha) return true; // ie. no node become unbalanced by insert

    //////////////////////////////////////
    // 3. Then re-balance the AVL tree using one of the four rotations, depending on the cases.
    if ( val < alpha->val && val < alpha->left->val) SingleRightRotation(alpha);
    else if (val > alpha->val && val > alpha->right->val) SingleLeftRotation(alpha);
    else if (val < alpha->val && val > alpha->left->val) LeftRightRotation(alpha);
    else if (val > alpha->val && val < alpha->right->val) RightLeftRotation(alpha);

    return true;
}

bool AVLTree::remove(DataType val) {




    //////////////////////////////////////
    // 1. Use the regular BST Insert operation, remove Node D.

    // check if the root node is the node being deleted
    bool isRoot = false;
    Node *initialRoot = *getRootNodeAddress();
    if (val == initialRoot->val) isRoot = true;

    bool result = BinarySearchTree::remove(val);
    //print();
    Node *rootTest = *getRootNodeAddress();
    do {

    // if cannot be removed, return false
    if (!result) return false;

    //////////////////////////////////////
    // 2. Find out if any of D’s ancestors is unbalanced.
    Node *root = *getRootNodeAddress();

    // special case, if D is removed from the root node, just return
    if (root == nullptr) {
        //cout << val << "EMPTY!" << endl;
        return true;
    }

    // 2.1. If unbalanced, find out the pointer to the unbalanced ancestor that is closest to N.
    Node *temp;
    temp = root;
    Node *temp_parent;
    Node *alpha = nullptr;
    Node *A = nullptr;

    do {
        temp_parent = temp;

        // if the node deleted was from the left subtree, or it was the root,
        if (val < temp->val || isRoot) temp = temp->left;
            // if the node was deleted from the right subtree,
        else if (val > temp->val && !isRoot) temp = temp->right;

        // now, check if temp_parent is unbalanced.
        updateNodeBalance(temp_parent);

        if (abs(temp_parent->avlBalance) >= 2) {
            alpha = temp_parent;

            updateNodeBalance(alpha);
            if (alpha->avlBalance > 0) A = alpha->left;
            else A = alpha->right;
        }
    } while (temp != nullptr);

    // 2.2. If not, job done and return.
    if (!alpha) return true; // ie. no node become unbalanced by remove

    //////////////////////////////////////
    // 3. Then re-balance the AVL tree using one of the four rotations, depending on the cases.

    updateNodeBalance(A);

    if (A == alpha->left && A->avlBalance >= 0) SingleRightRotation(alpha);
    else if (A == alpha->right && A->avlBalance <= 0) SingleLeftRotation(alpha);
    else if (A == alpha->left && A->avlBalance < 0) LeftRightRotation(alpha);
    else if (A == alpha->right && A->avlBalance > 0) RightLeftRotation(alpha);

    // now, check to see if this caused an imbalance in the root node
    updateNodeBalance(rootTest);

} while (rootTest->avlBalance < -1 || rootTest->avlBalance > 1);

    return true;
}

void AVLTree::SingleRightRotation(Node *alpha)
{
    // Input is alpha
    // A is alpha's left
    Node *A = alpha->left;

    // alpha's left = A's right
    alpha->left = A->right;

    // A's right = alpha
    A->right = alpha;

    // If alpha was the root of the whole tree, make A to be the new root.
    if (*getRootNodeAddress() == alpha) {
        *getRootNodeAddress() = A;
    }
    else {
        // Let alpha's parent take A as the new child.

        // find alpha's parent
        Node *temp = *getRootNodeAddress();
        Node **parentPointerToAlpha = nullptr;
        do {
            if (alpha->val > temp->val)  {
                parentPointerToAlpha = &temp->right;
                temp = temp->right;
            }
            else if (alpha->val < temp->val) {
                parentPointerToAlpha = &temp->left;
                temp = temp->left;
            }
        }
        while (temp->val != alpha->val);

        *parentPointerToAlpha = A;
    }
    //cout << "root " << (*getRootNodeAddress())->val << endl;
}

void AVLTree::SingleLeftRotation(Node *alpha) {
    // Input is alpha
    // A is alpha's right
    Node *A = alpha->right;

    // alpha's right = A's left
    alpha->right = A->left;

    // A's left = alpha
    A->left = alpha;

    // If alpha was the root of the whole tree, make A to be the new root.
    if (*getRootNodeAddress() == alpha) {
        *getRootNodeAddress() = A;
    } else {
        // Let alpha's parent take A as the new child.

        // find 	alpha's parent
        Node *temp = *getRootNodeAddress();
        Node **parentPointerToAlpha = nullptr;
        do {
            if (alpha->val > temp->val) {
                parentPointerToAlpha = &temp->right;
                temp = temp->right;
            } else if (alpha->val < temp->val) {
                parentPointerToAlpha = &temp->left;
                temp = temp->left;
            }
        } while (temp->val != alpha->val);

        *parentPointerToAlpha = A;
    }
}

void AVLTree::LeftRightRotation(Node *alpha)
{
    // Input is alpha

    // A is alpha's left
    Node *A = alpha->left;

    // B is A's right

    // Call single left rotation with input (A)
    SingleLeftRotation(A);

    // Call single right rotation with input (alpha)
    SingleRightRotation(alpha);
}

void AVLTree::RightLeftRotation(Node *alpha)
{
    // Input is alpha

    // A is alpha's right
    Node *A = alpha->right;

    // B is A's left

    // Call single right rotation with input (A)
    SingleRightRotation(A);

    // Call single left rotation with input (alpha)
    SingleLeftRotation(alpha);
}