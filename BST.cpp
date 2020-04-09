#include "BST.h"
#include <vector>

/**
 * Implement the BST constructor
 */
BST::BST() {
    root = NULL;
    numElements = 0;
}

/**
 * Implement the BST destructor
 */
BST::~BST() {
    clear();
}

/**
 * Implement size() correctly
 */
unsigned int BST::size() const {
    return numElements;
}

/**
 * Implement clear() correctly without memory leaks
 */
void BST::clear() {
    Node * currPtr = root;
    while (currPtr != NULL) {
        if (currPtr -> leftChild != NULL) {
            currPtr = currPtr -> leftChild;
            continue;
        }
        if (currPtr -> rightChild != NULL) {
            currPtr = currPtr -> rightChild;
            continue;
        }
        Node* temp = currPtr -> parent;
        if (currPtr == root){}
        else if (currPtr == currPtr->parent->leftChild) {
            delete currPtr;
            temp -> leftChild = NULL;
        }
        else {
            delete currPtr;
            temp -> rightChild = NULL;
        }
        
        currPtr = temp;
    }
    delete root;
    root = NULL;
    numElements = 0;
}

/**
 * Implement insert() correctly
 */
bool BST::insert(int element) {
    numElements++;
    Node * newNode = new Node(element);
    Node * currPtr = root;
    Node * parentPtr = root;
    while (currPtr != NULL) {
        if  (currPtr -> data > element) {
            parentPtr = currPtr;
            currPtr = currPtr -> leftChild;
        }
        else if(currPtr -> data < element) {
            parentPtr = currPtr;
            currPtr = currPtr -> rightChild;
        }
        else {
            numElements--;
            return false;
        }
    }
    currPtr = newNode;
    if (parentPtr != NULL) {
        currPtr = newNode;
        newNode -> parent = parentPtr;
        if (parentPtr -> data > element) {
            parentPtr -> leftChild = newNode;
        }
        else {
            parentPtr -> rightChild = newNode;
        }
    }
    else {
        root = newNode;
    }
    return true;
}

/**
 * Implement find() correctly
 */
bool BST::find(const int & query) const {
    Node * currPtr = root;
    while (currPtr != NULL) {
        if (currPtr -> data == query) {
            return true;
        }
        else if (currPtr -> data < query) {
            currPtr = currPtr -> rightChild;
        }
        else {
            currPtr = currPtr -> leftChild;
        }
    }
    return false;
}

/**
 * Implement the getLeftMostNode() function correctly
 */
BST::Node* BST::getLeftMostNode() {
    if (root == NULL) {
        return NULL;
    }
    Node * currPtr = root;
    while (true) {
        if (currPtr -> leftChild != NULL) {
            currPtr = currPtr -> leftChild;
        }
        else {
            return currPtr;
        }
    }
}

/**
 * Implement the BST::Node successor function correctly
 */
BST::Node* BST::Node::successor() {
    if (this -> rightChild != NULL) {
        Node * currPtr = this -> rightChild;
        Node * prevPtr = currPtr;
        while (currPtr != NULL) {
            prevPtr = currPtr;
            currPtr = currPtr -> leftChild;
        }
        return prevPtr;
    }
    else {
        Node * currPtr = this;
        while (currPtr -> parent != NULL) {
            if (currPtr -> parent -> leftChild == currPtr) {
                return currPtr -> parent;
            }
            currPtr = currPtr -> parent;
        }
    }
    return NULL;
}
