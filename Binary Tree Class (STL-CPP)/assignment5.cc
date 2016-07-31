#include "assignment5.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
//--------------------------------------------------------------
// Do not modify this section of code
//--------------------------------------------------------------
const int MAX_SIZE = 1000;
const int MAX_COUNT = 20;
const int WIDTH = 5;
const int ROW_SIZE = 5;
int mcount = 0;
int rcount = 0;

void display(int d) {
    if ( mcount < MAX_COUNT ) {
        cout << setw(WIDTH) << d;
        mcount++;
        rcount++;
        if ( rcount == ROW_SIZE ) {
            cout << endl;
            rcount = 0;
        }
    }
}
//--------------------------------------------------------------
// End
//--------------------------------------------------------------

/***************************************************************
binTree()

Use:        This is the constructor for the binTree class. It
            initializes the root to NULL

Returns:    Nothing
***************************************************************/
binTree::binTree()
{
	root = NULL;
}

/***************************************************************
void binTree::insert(int x)

Use: This is public insert function from binTree(). It is called
     upon to insert values. It calls the private insert function
     to actually insert the values.

Parameter:  (int x) - The value to be inserted.

Returns:    Nothing
***************************************************************/

void binTree::insert(int x)
{
	insert(root, x);
}

/***************************************************************
void binTree::insert(Node*& r,int x)

Use: This is private insert function from binTree(). This function
     is used to insert a node with the data value 'x' in a binary
     tree at root 'r'.

Parameter: (Node*& r) - Takes a pointer and reference to a node.
           (int x) - The value to be inserted.

Returns: Nothing.
***************************************************************/

void binTree::insert(Node*& r,int x)
{
	if(r == NULL)
	{
		r = new Node(x);
	}
	else
	{
		int left_height = size(r -> left);
		int right_height = size(r -> right);

		if(right_height < left_height)
			insert(r -> right, x);
		else
			insert(r -> left, x);
	}
}

/***************************************************************
height()

Use: This is public function of height(). It calls the private
     version to calculate the height.

Returns: Returns the height from the root.
***************************************************************/

unsigned binTree::height() const
{
	return height(root);
}

/***************************************************************
height()

Use: This is private function of height(). It calculates the
     height of the left and right sub trees and returns the value
     of the greater.

Parameter: (Node*) - Takes in a pointer to a Node

Returns: rightHt - Height of the right sub tree.
         leftHt -  Height of the left sub tree.
***************************************************************/

unsigned binTree::height(Node* n) const
{
    //If n is null means tree is empty.
	if(n == NULL)
		return 0;

    //else when tree is not empty.
	else
	{
		int left_height = height(n -> left);
		int right_height = height(n -> right);

		if(right_height > left_height)
			return right_height + 1;
		else
			return left_height + 1;
	}
}

/***************************************************************
size()

Use: This is public function of size(). It calls the private version
     to calculate the size and then this function returns the size.

Returns: Size of the root.
***************************************************************/

unsigned binTree::size() const
{
	return size(root);
}

/***************************************************************
size()

Use: Calculates the size of the binary tree.

Parameter: (Node* n) - Pointer to a node

Returns: unsigned int - size of the tree.
         return 0 - empty tree.
***************************************************************/

unsigned binTree::size(Node* n) const
{
	if(n != NULL)
	{
		return 1+size(n -> left) + size( n -> right );
	}
	else
		return 0;
}

/***************************************************************
inorder()

Use: This is public function of inorder(). This is the function
     that is called upon, and then this calls the private inorder
     function.

Parameter: void(*p) - Function pointer.
           int - Current value.

Returns:Nothing.
***************************************************************/

void binTree::inorder(void(*p)(int))
{
	inorder(root, p);
}

/***************************************************************
inorder()

Use: Organizes the binary tree in inorder

Parameter: Node* n - Pointer to a node
           void(*p) - Function pointer
           int - Integer being passed in

Returns: Nothing
***************************************************************/

void binTree::inorder(Node* n, void(*p)(int))
{
	if(n != NULL)
	{
		inorder(n -> left, p);
		p(n -> data);

		inorder(n -> right, p);
	}
}

/***************************************************************
preorder()

Use: This is public function of preorder(). This is the function
     that is called upon, and then this calls the private preorder
     function.

Parameter:  void(*p) - Function pointer
            int - Integer being passed in

Returns: Nothing.
***************************************************************/

void binTree::preorder(void(*p)(int))
{
	preorder(root, p);
}

/***************************************************************
preorder()

Use: Organizes the binary tree in preorder

Parameter: Node* n - Pointer to a node
           Void(*p) - Function pointer
           int - Integer being passed in

Returns: Nothing.
***************************************************************/

void binTree::preorder(Node*n, void(*p)(int))
{
	if(n != NULL)
	{
		p (n -> data);
		preorder( n-> left, p );
		preorder( n-> right, p );
	}
}

/***************************************************************
postorder()

Use: This is public function of postorder(). This is the function
     that is called upon, and then this calls the private postorder
     function.

Parameter: void(*p) - Function pointer
           int - Integer being passed in

Returns: Nothing.
***************************************************************/

void binTree::postorder(void(*p)(int))
{
	postorder(root, p);
}

/***************************************************************
postorder()

Use:Organizes the binary tree in postorder. This function is
    called upon by the public inorder() function.

Parameter : Node* n - Pointer to a node
            Void(*p) - Function pointer
            int - Integer being passed in

Returns: Nothing.
***************************************************************/

void binTree::postorder(Node* n, void(*p)(int))
{
	if(n != NULL)
	{
		postorder(n -> left, p );
		postorder(n -> right, p );
		p( n -> data );
	}
}


//--------------------------------------------------------------
// Do not modify this section of code
//--------------------------------------------------------------
#define BINTREE_MAIN
#ifdef BINTREE_MAIN
int main() {
    vector<int> v(MAX_SIZE);
    for (int i=1; i<MAX_SIZE; i++)
        v[i] = i;
    random_shuffle( v.begin(), v.end() );
    //mcount = rcount = 0;
    //for_each( v.begin(), v.end(), display );

    binTree bt;
    vector<int>::iterator it;
    for (it=v.begin(); it!=v.end(); it++)
        bt.insert( *it );

    cout << "Height: " << bt.height() << endl;
    cout << "Size: " << bt.size() << endl;
    cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.inorder( display );
    cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.preorder( display );
    cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.postorder( display );

    cout << endl;
    return 0;
}

#endif
//---------------------------------
// End
//--------------------------------
