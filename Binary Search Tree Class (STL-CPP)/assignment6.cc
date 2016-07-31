/************************************************************************

	AUTHOR : MRINAL SINHA

*************************************************************************/
#include <iostream>
#include "assignment5.h"
#include "assignment6.h"
using namespace std;

/********************************************************************
insert(int x)

Use: This is the public function for insert(). It calls the private
     insert() function to insert values in the tree.

Parameter: (int x) The value to insert in the BST.

Returns: Nothing.
********************************************************************/

void BST::insert(int x)
{
    insert(root, x);
}

/********************************************************************
insert(Node*& n, int x)

Use: This is the private function for insert(). The values passed
     here is from public version of insert(). This function inserts
     values into the tree.

Parameter: 1. (Node*&) This is a pointer reference to the root
           node of the tree.
           2. (int x) This is the value to insert in the tree.

Returns: Nothing.
********************************************************************/

void BST::insert(Node*& n, int x)
{
    if(n == NULL)
        n = new Node(x);
    else if(x < n -> data)
        insert(n -> left, x);
    else if(x > n -> data)
        insert(n -> right, x);
}

/********************************************************************
search(int x)

Use: This is the public version of search(). It passes an integer
     into the private version which then searches the tree for that
     value.

Parameter: (int x) The value to be searched.

Returns: Returns a boolean value.
********************************************************************/

bool BST::search(int x)
{
    return search(root, x);
}

/********************************************************************
bool BST::search(Node*& n, int x)

Use: This function searches the binary tree for the value x. Returns
     true if found else flase.

Parameters:  1. (Node*&) Pointer reference to the current node
             2. (int x) The value to be searched for within the
             tree.

Returns: A boolean value.
********************************************************************/

bool BST::search(Node*& n, int x)
{
    if(n == NULL)
        return false;
    else if(n -> data == x)
        return true;
    else if(n -> data > x)
        return (search(n -> left, x));
    else if(n -> data < x)
        return(search(n -> right, x));
    else
        return false;
}

/********************************************************************
bool BST::remove(int x)

Use: This is the public function for remove(). This function calls the
     private remove() function to see if the value x can be removed
     from the tree.

Parameters: (int x) The integer to be removed from the tree.

Returns: A boolean value.
********************************************************************/

bool BST::remove(int x)
{
    return remove(root, x);
}

/********************************************************************
bool BST::remove(Node*& n, int x)

Use: This is the private function of remove(). This function is called
     by the public version. It deletes a value from the BST.
     There are three possible cases of node removal.
     A. The node to be removed is a leaf.
     B. The node only has one child.
     C. The node has two children.

Parameters: 1. (Node*&) A pointer reference to the node root.
            2. (int x) The integer to be removed from the tree.

Returns: Returns a boolean value.
********************************************************************/

bool BST::remove(Node*& n, int x)
{
    Node* temp = n;
    if(n == NULL)
        return false;
    if(n -> data > x)
        return remove(n -> left, x);
    if(n -> data < x)
        return remove(n -> right, x);
    if(n -> left != NULL && n -> right != NULL)
    {
        temp = n -> left;
        while(temp -> right != NULL)
            temp = temp -> right;
        n -> data = temp -> data;
        return remove(n -> left, temp -> data);
    }
    if(n -> right == NULL)
        n = n -> left;
    else if(n -> left == NULL)
        n = n -> right;
    else
    {
        temp = n -> left;
        while(temp -> right != NULL)
            temp = temp -> right;
        temp -> right = n -> right;
        temp = n;
        n = n -> left;
        delete temp;
    }
    return true;
}

/********************************************************************
int BST::sumLeftLeaves()

Use: This is the public function for the sum of left leaf nodes
     from the BST class. This function calls the private
     sumLeftLeaves() function to actually find sum of left leaf
     nodes.

Parameter: (int x) The value returns the sum of leaves.

Returns: sum of the leaves.
********************************************************************/

int BST::sumLeftLeaves()
{
    return sumLeftLeaves(root);
}

/********************************************************************
bool leaf_Node(Node *root)

Use: This function is used to find the the leaf node the the BST.

Parameter: (int x) The value returns the sum of leaves.

Returns: A boolean value.
********************************************************************/

bool leaf_Node(Node *root)
{
    if(root == NULL)
        return false;
    else if(root -> left == NULL && root -> right == NULL)
        return true;
    else
        return false;
}

/********************************************************************
int BST::sumLeftLeaves(Node*& n)

Use: This function is use to calculate the sum of all the left
     leaf node present in the BST.

Parameters: 1. (Node*&) A Pointer reference to root node.

Returns: sum of all the left leaf node.
********************************************************************/

int BST::sumLeftLeaves(Node*& n)
{
    int sum = 0;
    if(n != NULL)
    {
        if(leaf_Node(n -> left))
            sum += n -> left -> data;
        else
            sum += sumLeftLeaves(n -> left);
        sum += sumLeftLeaves(n -> right);
    }
    return sum;
}
