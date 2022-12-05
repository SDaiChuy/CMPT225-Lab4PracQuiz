/*
 * BST.cpp
 * 
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are allowed.
 *
 * Date of last modification: Nov. 2022
 */
 
#include "BST.h"
#include <iostream>

using std::cout;
using std::endl;

/* Constructors and Destructor */

  // Default constructor: Constructs an empty tree.
  BST::BST() { }            

  // Parameterized constructor
  BST::BST(int element) {
    root = new BSTNode(element);
    elementCount = 1;
  }

  // Copy constructor
  BST::BST(const BST & aBST) {
  
    //cout << "BST Copy constructor called!" << endl;
           
    if ( aBST.elementCount == 0 ) {
      //cout << "aBST is empty!" << endl;	
      this->elementCount = 0;
      this->root = nullptr;
    }
    else
      copyR(aBST.root);	
  }

  // Destructor 
  BST::~BST() {

    //cout << "BST destructor called!" << endl;
     
    if ( this->root != nullptr ) {
      destroyR(root);
      root = nullptr;
    }

  }                


/* Helper methods */
  
  // Description: Recursive preorder traversal of a binary search tree in order to build its copy.
  void BST::copyR(BSTNode * current) {
    
    //cout << "copyR called!" << endl;

    if (current != nullptr) {
      this->insert(current->element);
      copyR(current->left);
      copyR(current->right);
    }    
    return;
  }

  // Description: Recursive postorder traversal of a BST in order to release heap memory allocated to BSTNode.
  void BST::destroyR(BSTNode * current) {
  
    // cout << "destroyR called!" << endl;
  
    if (current != nullptr) {
      destroyR(current->left);
      destroyR(current->right);
      delete current;
      current = nullptr;
      this->elementCount--;
    }
    return;
  }

/* Getters and setters */
   

  // Description: Returns the number of elements currently stored in the binary search tree.     
  unsigned int BST::getElementCount() const { 
    return this->elementCount;
  }


/* BST Operations */

  // Description: Inserts an element into the binary search tree.
  //              This is a wrapper method which calls the recursive insertR( ).
  // Exception: Throws the exception "UnableToInsertException" when newElement 
  //            cannot be inserted (e.g., "new" operator fails).   
  void BST::insert(int newElement) {
     
    // Binary search tree is empty, so add the new element as the root
    BSTNode * newBSTNode = new BSTNode(newElement);
    if (newBSTNode == nullptr)
      throw UnableToInsertException("In insert(): operator new failed!");
    if (elementCount == 0 ) // and root == nullptr
      root = newBSTNode;
    else {
      try { // can I let it flow through? no try/catch block?
        insertR(newBSTNode, root);
      }
      catch ( UnableToInsertException & e ) {
        throw UnableToInsertException("Operator new failed!");
      }
    }

    this->elementCount++;
    return;
  } 
  

  // Description: Recursive insertion into a binary search tree.
  void BST::insertR(BSTNode * newBSTNode, BSTNode * current) { 
  
    // If the element to be inserted < the element at current node, insert it to the left subtree
    if (newBSTNode->element < current->element) {
      // If current node's left subtree is empty add the new node there
      if (!current->hasLeft()) {
        current->left = newBSTNode; // new BSTNode(anElement);
        return;
      }
      // Otherwise descend into the left subtree
      else 
        insertR(newBSTNode, current->left);
    }
    // If the element to be inserted > the element at current node, insert it to the right subtree
    else { // if ( element >=  current->getElement() ) {
      // If current node's right subtree is empty add the new node there
      if (!current->hasRight()) {
        current->right = newBSTNode; //new BSTNode(anElement);
        return;
      }
      // Otherwise descend into the right subtree
      else 
        insertR(newBSTNode, current->right);
    }
  }

  // Description: Prints the content of the binary search tree in order.
  //              This is a wrapper method which calls the recursive printsInOrderR( ).
  void BST::printInOrder() const {

    cout << "Printing BST with elementCount = " << elementCount << endl;
    cout << "{ ";
    if (elementCount != 0) printInOrderR(root);
    cout << "}";

    return;
  }

  // Description: Recursively traverse the a binary search tree
  //              printing its elements in order.   
  void BST::printInOrderR(BSTNode *current) const {
    if (current != nullptr) {
      printInOrderR(current->left);
      cout << current->element << " ";
      printInOrderR(current->right);
    }
    return;
  }
  

  // Description: Returns the number of nodes in this binary search tree.
  //              You cannot return "elementCount".
  //              Fell free to implement this method as an iterative method or
  //              as a wrapper method calling a recursive method.		
  unsigned int BST::numberOfNodes( ) const {
  
    // to do
    if(elementCount == 0){
      return 0;
    }
    return numberOfNodesR(root);
  }

  // Description: Recursively get the number of nodes in the given tree
  unsigned int BST::numberOfNodesR(BSTNode* current) const{
    if(current == nullptr){
      return 0;
    }
    return numberOfNodesR(current->left) + numberOfNodesR(current->right) + 1;
    
  }

  // Description: Returns the height of this binary search tree.
  //              Fell free to implement this method as an iterative method or
  //              as a wrapper method calling a recursive method.
  unsigned int BST::height() const {
    // to do
    if(elementCount == 0){
      return 0;
    }
    return heightR(root);

  }

  // Description: Recursively get the height of the tree
  unsigned int BST::heightR(BSTNode* current) const{
    if(current == nullptr){
      return 0;
    }
    int left = heightR(current->left);
    int right = heightR(current->right);

    if(left > right){
      return left + 1;
    }
    return right + 1;
  }

  // Description: Remove a certain element in the BST
  //              Wrapper function for the recursive removeR();
  void BST::remove(int toBeRemoved){
    if(elementCount == 0){
      throw UnableToInsertException ("remove() was called on an empty BST.");
    }
    removeR(root, toBeRemoved);
  }

  //Description: Recursively remove a certain element
  void BST::removeR(BSTNode* current, int toBeRemoved){
    if(current == nullptr){
      return;
    }
    // check if element is smaller
    if(current->element < toBeRemoved){
      cout << current->element << " is smaller" << endl;
      removeR(current->right, toBeRemoved);
    }
    
    // check if element is greater
    else if(current->element > toBeRemoved){
      cout << current->element << " is greater" << endl;
      removeR(current->left, toBeRemoved);

    }
    
    // check if element is equal
    else if(current->element == toBeRemoved){
      
    }
  }

  bool BST::search(int toBeFound) const{
    if(elementCount == 0){
      return 0;
    }

    return searchR(root, toBeFound);
  }
  bool BST::searchR(BSTNode* current, int toBeFound)const{
    // goes through the whole BST and not found
    // therefore the element is not in the BST
    if(current == nullptr){
      return false;
    }

    // case for when it equals
    if(current->element == toBeFound){
      return true;
    }

    // case for when it does not equal
    // recursively find the element
    if(current->element != toBeFound){
      if(current->element < toBeFound){
        searchR(current->right, toBeFound);
      }
      else{
        searchR(current->left, toBeFound);
      }
    }
    
  }