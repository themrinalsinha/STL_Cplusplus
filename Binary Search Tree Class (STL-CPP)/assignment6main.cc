////////////////////////////////////////////
// Assignment 6 driver program -- build BST with random numbers
//              and test search operations
////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include "assignment5.h"
#include "assignment6.h"
using namespace std;

static const int MAX_COUNT = 20;
static int mcount = 0;

void display2(int d) {
    if ( mcount < MAX_COUNT ) {
        cout <<  setw(4) << d;
        mcount++;
    }
}

// produce a random number within range [1 1000]
int rand_1000() {
    return rand() % 1000 + 1;
}

void show_tree_information( BST& bst ) {
    cout << "Size of the tree: " << bst.size() << endl;
    cout << "Height of the tree: " << bst.height() << endl;
    cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = 0;
    bst.inorder( display2 );
    cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = 0;
    bst.preorder( display2 );
    cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = 0;
    bst.postorder( display2 );
}

// For each value in searchVec, search it in the binary search tree
// and report the number of successful searches
void run_search( BST& bst, vector<int>& searchVec ) {
    int success = 0;
    vector<int>::iterator it;
    for ( it = searchVec.begin(); it != searchVec.end(); it++ )
        if ( bst.search( *it ) )
            success++;
    cout << endl << endl << "Out of " << searchVec.size() << " searches, " << success << " are successful." << endl << endl;
}

int main() {
    //-------------- Create a B.S.T. using unique random numbers -----------
    vector<int> inputVec(1000);
    srand(7);
    generate(inputVec.begin(), inputVec.end(), rand_1000);
    sort(inputVec.begin(), inputVec.end());
    vector<int>::iterator it = unique(inputVec.begin(), inputVec.end());
    inputVec.resize( it - inputVec.begin() );
    random_shuffle( inputVec.begin(), inputVec.end() );

    BST bst;
    for (it=inputVec.begin(); it!=inputVec.end(); it++)
        bst.insert( *it );
    cout << "A binary search tree is generated with random numbers: " << endl;
    show_tree_information( bst );

    //-------------- Create a vector of random integers to be searched ------
    vector<int> searchVec(500);
    srand(11);
    generate( searchVec.begin(), searchVec.end(), rand_1000 );

    cout << endl << endl << "Sum of left leaves: " << bst.sumLeftLeaves() << endl;

    //------------ test search operations ----------------
    run_search( bst, searchVec );

    //------------ remove half of nodes from the tree ---------
    int counter = 0;
    random_shuffle( inputVec.begin(), inputVec.end() );
    for ( it = inputVec.begin(); it < inputVec.end(); it += 2 ) {
        if ( bst.remove( *it ) )
            counter++;
    }
    cout << endl << counter << " nodes are removed." << endl << endl;
    show_tree_information( bst );

    cout << endl << endl << "Sum of left leaves: " << bst.sumLeftLeaves() << endl;

    //-------------- test search operations again ---------------
    run_search( bst, searchVec );

    return 0;
}
