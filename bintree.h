//--------------------------bintree.h------------------------
//Kathleen Guinee CSS343 Section B
//Created: 4/28/2019
//Last Modification: 4/28/2019
//--------------------------------------------------------
//Purpose: This is the header file for a Binary Tree class that
//creates, compares, and manipulates binary trees.
//--------------------------------------------------------
//Notes: The Binary Tree uses linked nodes to connect different data elements.
//Data is stored using the NodeData object (which is a pointer in this class).
//This class allows for the retrieval of specific nodes, getting the height for
//nodes, inserting data, converting Binary Trees to arrays, and  converting
//arrays to balanced trees.
//-------------------------------------------------------
#ifndef BIN_TREE_H
#define BIN_TREE_H

#include "nodedata.h"

class BinTree
{
  /*overloaded << operator. Outputs the entire tree in order. If the tree is
  empty, nothing will be output.*/
  friend ostream& operator<<(ostream &outStream, const BinTree &tree);

public:
  //constructors and destructor

  //default constructor, constructs an empty Binary Tree
  BinTree();

  /*Copy constructor, constructs a binary tree that has the same values as the
  rhsTree. Deep copy*/
  BinTree(const BinTree &rhsTree);

  //destructor, frees allocated memory used in creation of the binary tree
  ~BinTree();

  /*returns true if the data exists in the tree, returns false if it does not.
  If the data is found, then it stores the data in returnNode so that it can be
  used/viewed outside of the function*/
  bool retrieve(const NodeData &, NodeData* &returnNode);

  /*If "findNode" exists, then returns the height. Otherwise, returns 0. Height
  is counted from the bottom up. A leaf node would have a height of 1. Its
  parent would have a height of 2. */
  int getHeight (const NodeData &findNode) const;

  /*adds data from BST to an array. The data is added inorder. The BST is
  destroyed in the process and is empty after completion. Assunes that the array
  has all null values apart from the items added*/
  void bstreeToArray(NodeData* []);

  /*converts an array of NodeData * to a balanced tree. The array is left empty
  after completion and all items in it are nullified. Assumes that the array
  contains a maximum of 100 items and each item that is not a NodeData * to be
  included in the balanced tree is set to NULL*/
  void arrayToBSTree(NodeData* []);

  /*adds a NodeData item to the Binary Tree. Inserts it into the correct
  position.*/
  bool insert(const NodeData* n);

  /*helper function that was included from lab2.cpp . This function helps
  visualize the BT by displaying it sidewas so as to aid with debugging*/
  void displaySideways() const;

  /*included for debugging purposes. Checks if the BT is empty. If it is,
  returns true. Otherwise, returns false*/
  bool isEmpty();

  /*included because it was part of the lab2.cpp file. In order to run that
  code against my program, it was necessary to include this function. This
  function deletes a BT and sets the root to NULL (which flags the tree as
  empty)*/
  void makeEmpty();

  /*overloaded assignment operator. This creates a deep copy of the Binary Tree
  that replaces the Binary Tree on the left hand side with the tree on the
  right hand side. It uses a preorder traversal and copies each node one at a
  time from the rhsTree*/
  BinTree& operator=(const BinTree &rhsTree);

  /*overloaded equality operator. Compares two binary trees to determine if they
  are equal*/
  bool operator==(const BinTree &rhsTree) const;

  /*overloaded inequality operator. Compares two binary trees to determine if
  they are not equal*/
  bool operator!=(const BinTree &rhsTree) const;

private:

  /*Node struct defines the node as containing a NodeData pointer, a pointer to
  the left child, and a pointer to it's right child. */
  struct Node
  {
    NodeData* data;
    Node* left;
    Node* right;
  };

  //root of the Binary Tree. Stored as a node pointer
  Node* root;

  /*helper function used in the << overload. Uses an inorder traversal to return
  data items to the ostream result*/
  void inOrderHelper(const Node *current, ostream &result) const;

  /*helper function for displaySideways(). This code was included from the
  lab2.cpp file provided in the assignment*/
  void sideways(Node* current, int level) const;

  /*helper functon for the destructor. Frees both the NodeData and
  Nodes using postorder recursive calls.*/
  void deleteTree(Node*& current);

  /*Helper for the overloaded assignment operator. Allows for recursive calls
  in order to copy all items from the other tree*/
  void copyHelper(Node*& current, Node* thisPrev, const Node* otherCurrent,
        bool right);

  /*Helper for the equality overoaded operator. Allows for recursive comparisons
  of Nodes and the tree structure between the rhs and lhs trees*/
  bool equalityHelper(const Node* current, const Node* otherCurrent) const;

  /*Helper for node retrieval function. Allows for recursive traversal of
  the tree*/
  bool retrieveHelper(const Node* current, const NodeData &find,
    NodeData* &returnNodeData);

  /*Helper function for heightHelper. Confirms if the node exists or not. If
  it exists, it sets ReturnNode to point to the correct node so as to allow the
  heightHelper to find the height of that node*/
  bool findNode(Node* current, const NodeData& find, Node* &returnNode) const;

  /*helps the getHeight function find the height of a node. Takes in a reference
  to the Node that you want to know the height of.*/
  int heightHelper(Node*&current) const;

  /*assists the BSTtoArray function by allowing for recursive traversal of the
  BST.*/
  void toArrayHelper(const Node* current, NodeData* array[], int& index);

  /*helper function for array to BST. This function alows for recursive calls to
  allow for creation of balanced tree*/
  void balance(int low, int high, Node*& current, NodeData* array[]);

};

#endif
