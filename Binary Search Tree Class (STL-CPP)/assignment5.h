#ifndef ASSIGNMENT5
#define ASSIGNMENT5

//Node Class
class Node
{
	friend class BST;
	friend class binTree;
	public:
		Node(int& x, Node* l = 0, Node* r = 0)
		{ data = x; left = l; right = r; }

	public:
		int data; 		// Holds current value.
		Node* left; 	// Pointer to left tree.
		Node* right; 	// Pointer to right tree.
};



class binTree {
    public:
        binTree();
        virtual void insert( int );
        unsigned height() const;
        unsigned size() const;
        void inorder( void(*)(int) );
        void preorder( void(*)(int) );
        void postorder( void(*)(int) );

    protected:
        Node* root;
    private:
        void insert( Node*&, int );
        unsigned height( Node* ) const;
        unsigned size( Node* ) const;
		void inorder( Node*, void(*)(int) );
		void preorder( Node*, void(*)(int) );
		void postorder( Node*, void(*)(int) );
};

#endif
