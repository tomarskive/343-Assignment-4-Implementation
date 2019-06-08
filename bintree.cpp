//--------------------------bintree.cpp-----------------------------------------
//Kathleen Guinee CSS343 Section B
//Created: 4/28/2019
//Last Modification: 4/28/2019
//------------------------------------------------------------------------------
//Purpose: This is the cpp file for a Binary Tree class that
//creates, compares, and manipulates binary trees.
//------------------------------------------------------------------------------
//Notes: The Binary Tree uses linked nodes to connect different data elements.
//Data is stored using the NodeData object (which is a pointer in this class).
//This class allows for the retrieval of specific nodes, getting the height for
//nodes, inserting data, converting Binary Trees to arrays, and  converting
//arrays to balanced trees.
//------------------------------------------------------------------------------
#include "bintree.h"
using namespace std;

//------------------------------------------------------------------------------
//default constructor, constructs an empty Binary Tree
BinTree::BinTree()
{
  //if root == NULL, BST is empty
  root = NULL;
}//end default constructor

//-----------------------------------------------------------------------------
/*Copy constructor, constructs a binary tree that has the same values as the
rhsTree. Deep copy. Calls the overloaded assignment operator*/
BinTree::BinTree(const BinTree &rhsTree)
{
  //preorder
  root= NULL;
//  cout<<"inside constructor"<<endl;
  *this=rhsTree;
}//end copy constructor

//-----------------------------------------------------------------------------
//destructor, frees allocated memory used in creation of the binary tree
BinTree::~BinTree()
{
  deleteTree(root);
}//end destructor

//-----------------------------------------------------------------------------
/*returns true if the data exists in the tree, returns false if it does not.
If the data is found, then it stores the data in returnNode so that it can be
used/viewed outside of the function*/
bool BinTree::retrieve(const NodeData &findNode, NodeData* &returnNode)
{
    return retrieveHelper(root, findNode, returnNode);
}//end retrieve(&NodeData, NodeData*&)

//-----------------------------------------------------------------------------
/*If "findNode" exists, then returns the height. Otherwise, returns 0. Height
is counted from the bottom up. A leaf node would have a height of 1. Its
parent would have a height of 2. */
int BinTree::getHeight (const NodeData &find) const
{
  Node* current;

  if(findNode(root, find, current))
  {
    return heightHelper(current);
  }
  return 0;
}//end getHeight(nodeData &find)

//-----------------------------------------------------------------------------
/*adds data from BST to an array. The data is added inorder. The BST is
destroyed in the process and is empty after completion. Assunes that the array
has all null values apart from the items added*/
void BinTree::bstreeToArray(NodeData* array [])
{
  int index = -1;
  toArrayHelper(root, array, index);
  deleteTree(root);
}//end bstreeToArray(NodeData* array[])

//-----------------------------------------------------------------------------
/*converts an array of NodeData * to a balanced tree. The array is left empty
after completion and all items in it are nullified. Assumes that the array
contains a maximum of 100 items and each item that is not a NodeData * to be
included in the balanced tree is set to NULL*/
void BinTree::arrayToBSTree(NodeData* array[])
{
  //delete this tree
  deleteTree(root);

  int low = 0;
  int high = 0;

  //while high is not on a NULL index
  while(array[high+1])
  {
    high++;
  }
  //if the first item is not NULL (and thus the array is empty)
  if(array[0])
  {
    balance(low, high, root, array);
  }
  //delete all the dataNode pointers in the array
  for(int i = 0; array[i]!=NULL; i++)
  {
    delete array[i];
    array[i]=NULL;
  }
}//end arrayToBSTree(NodeData* array[])


//-----------------------------------------------------------------------------
/*adds a NodeData item to the Binary Tree. Inserts it into the correct
position.*/
bool BinTree::insert(const NodeData* n)
{
  //if the tree is empty
  if(root==NULL)
  {
    root = new Node;
    root->data = new NodeData;
    *root->data = *n;
    root->left = NULL;
    root->right = NULL;
    return true;
  }
  else
  {//start at the root
    Node* current = root;
    Node* prev = NULL;
    //while you have not reached the end of the tree and you have not found
    while(current && *current->data != *n)
    {
      prev = current;
      if(*n < *current->data)
      {
        current = current->left;
      }
      else
      {
        current = current->right;
      }
    }
    //if you have reached the end, then insert it as a leaf
    if(!current)
    {
      current = new Node;
      current->data = new NodeData;
      *current->data = *n;
      current->left = NULL;
      current->right = NULL;
      if(*n < *prev->data)
      {
        prev->left = current;
      }
      else
      {
        prev->right = current;
      }
      return true;
    }
    //if you get here, it means that you tried to insert a duplicate
    return false;
  }
}//end Insert(NodeData *n)

//-----------------------------------------------------------------------------
/* Displays a binary tree as though you are viewing it from the side;
  hard coded displaying to standard output.
  Preconditions: NONE
  Postconditions: BinTree remains unchanged.*/
void BinTree::displaySideways() const {
	sideways(root, 0);
}//end displaySideways()

//-----------------------------------------------------------------------------
/*included for debugging purposes. Checks if the BT is empty. If it is,
returns true. Otherwise, returns false*/
bool BinTree::isEmpty()
{
  return(root==NULL);
}//end isEmpty()

//-----------------------------------------------------------------------------
/*included because it was part of the lab2.cpp file. In order to run that
code against my program, it was necessary to include this function. This
function deletes a BT and sets the root to NULL (which flags the tree as
empty)*/
void BinTree::makeEmpty()
{
  deleteTree(root);
}//end makeEmpty()

//-----------------------------------------------------------------------------
/*overloaded assignment operator. This creates a deep copy of the Binary Tree
that replaces the Binary Tree on the left hand side with the tree on the
right hand side. It uses a preorder traversal and copies each node one at a
time from the rhsTree*/
BinTree& BinTree::operator=(const BinTree &rhsTree)
{
  //check for self assignment
  //delete current tree
  //copy items line by line
  //(preorder)
  if(this == &rhsTree)
  {
    return *this;
  }
   deleteTree(root);
   copyHelper(root, NULL, rhsTree.root, 0);
   return *this;
}//end overloaded assignment operator

//-----------------------------------------------------------------------------
/*overloaded equality operator. Compares two binary trees to determine if they
are equal*/
bool BinTree::operator==(const BinTree &rhsTree) const
{
  return equalityHelper(root, rhsTree.root);
}//end overloaded equality operator

//-----------------------------------------------------------------------------
/*overloaded inequality operator. Compares two binary trees to determine if
they are not equal*/
bool BinTree::operator!=(const BinTree &rhsTree) const
{
  return !(*this==rhsTree);
}//end overloaded inequality operator

//-----------------------------------------------------------------------------
/*helper function used in the << overload. Uses an inorder traversal to return
data items to the ostream result*/
void BinTree::inOrderHelper(const Node *current, ostream &result) const
{
  //inorder
  if(current != NULL)
  {
    inOrderHelper(current->left, result);
    result << (*current->data)<<" ";
    inOrderHelper(current->right, result);
  }
}//end inOrderHelper(Node* current, ostream &result)

//-----------------------------------------------------------------------------
/* Helper method for displaySideways
 Preconditions: NONE
 Postconditions: BinTree remains unchanged.*/
void BinTree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}//end sideways(Node* current, int level)

//-----------------------------------------------------------------------------
/*helper functon for the destructor. Frees both the NodeData and
Nodes using postorder recursive calls.*/
void BinTree::deleteTree(Node*& current)
{
  //if current!= NULL
  if(current)
  {
    //postorder deletion so as to avoid memory leaks
    deleteTree(current->left);
    deleteTree(current->right);
    delete current->data;
    delete current;
    current = NULL;
  }
}//end deleteTree(Node*& current)

//-----------------------------------------------------------------------------
/*Helper for the overloaded assignment operator. Allows for recursive calls
in order to copy all items from the other tree. If direction == 1, direction
represents "right". If direction == 0, it represents "left"*/
void BinTree::copyHelper(Node*& current, Node* prev, const Node* otherCurrent,
      bool direction)
{
  //if the other's tree's current node does not point to NULL
  if(otherCurrent)
  {
    //create a new Node and copy over all the data
    current = new Node;
    current->data = new NodeData;
    *current->data = *otherCurrent->data;
    current->left = NULL;
    current->right = NULL;
    //if this is not the first recursive call
    if(prev)
    {
      //if came from prev's right side
      if(direction)
      {
        prev->right = current;
      }
      else
      {
        //if came from prev's left side
        prev->left = current;
      }
    }
    copyHelper(current->left, current, otherCurrent->left, 0);
    copyHelper(current->right, current, otherCurrent->right, 1);
  }
}//end copyHelper(Node*current, Node* prev, Node* otherCurrent, bool direction)

//-----------------------------------------------------------------------------
/*Helper for the equality overoaded operator. Allows for recursive comparisons
of Nodes and the tree structure between the rhs and lhs trees*/
bool BinTree::equalityHelper(const Node* current,
    const Node* otherCurrent) const
{
  //check for self-assignment and if both are empty
  if(current == otherCurrent || (!current && !otherCurrent))
  {
    return true;
  }
  //otherwise, if one of them is NULL (but not both), or if
  //this data != other data, return false
  if(!current || !otherCurrent || (*current->data != *otherCurrent->data))
  {
    return false;
  }
  //both sides must return true for this to be the same tree
  return (equalityHelper(current->left, otherCurrent->left) &&
    equalityHelper(current->right, otherCurrent->right));
}//end equalityHelper(Node* current, Node* otherCurrent)

//-----------------------------------------------------------------------------
/*Helper for node retrieval function. Allows for recursive traversal of
the tree*/
bool BinTree::retrieveHelper(const Node* current, const NodeData &find,
  NodeData* &returnNodeData)
{
  //preorder
  if(current)
  {
    if(*current->data == find)
    {
      returnNodeData = current->data;
      return true;
    }
    if(find < *current->data)
    {
      return retrieveHelper(current->left, find, returnNodeData);
    }
    else
    {
      return retrieveHelper(current->right, find, returnNodeData);
    }
  }
  return false;
}//end retrieveHelper()

//-----------------------------------------------------------------------------
/*Helper function for heightHelper. Confirms if the node exists or not. If
it exists, it sets ReturnNode to point to the correct node so as to allow the
heightHelper to find the height of that node*/
bool BinTree::findNode(Node* current, const NodeData& find,
    Node* &returnNode) const
{
  if(current)
  {
    if(*current->data == find)
    {
      returnNode = current;
      return true;
    }
    return (findNode(current->left, find, returnNode) ||
            findNode(current->right, find, returnNode));
  }
  return false;
}//end findNode(Node* current, NodeData& find)

//-----------------------------------------------------------------------------
/*helps the getHeight function find the height of a node. Takes in a reference
to the Node that you want to know the height of.*/
int BinTree::heightHelper(Node* &current) const
{
  if(current)
  {
    int left = heightHelper(current->left)+1;
    int right = heightHelper(current->right)+1;

    if(left >=right)
    {
      return left;
    }
    return right;
  }
  return 0;
}//end heightHelper(Node* &current)

//-----------------------------------------------------------------------------
/*assists the BSTtoArray function by allowing for recursive traversal of the
BST.*/
void BinTree::toArrayHelper(const Node* current, NodeData* array [], int& index)
{
  if(current)
  {
    //inorder traversal
    toArrayHelper(current->left, array, index);
    index = index+1;
    NodeData* temp = new NodeData;
    *temp = *current->data;
    array[index] = temp;
    toArrayHelper(current->right, array, index);
  }
}//end toArrayHelper(Node* current, NodeData* array[], int& index)

//-----------------------------------------------------------------------------
/*helper function for array to BST. This function alows for recursive calls to
allow for creation of balanced tree*/
void BinTree::balance(int low, int high, Node*& current, NodeData* array[])
{
  if((high<low) || (low>high))
  {
    return;
  }
  current = new Node;
  int mid = (low+high)/2;
  current->data = new NodeData;
  *current->data = *array[mid];
  current->left = NULL;
  current->right = NULL;

  if(low != high)
  {
    balance(low, mid-1, current->left, array);
    balance(mid+1, high, current->right, array);
  }
}//end balance(int low, int high, Node*& current, Node* array[])

//-----------------------------------------------------------------------------
/*overloaded << operator. Outputs the entire tree in order. If the tree is
empty, nothing will be output.*/
ostream& operator<<(ostream &outStream, const BinTree &tree)
{
  tree.inOrderHelper(tree.root, outStream);
  return outStream;
}
