/*******************************************************************************
CSCI 340 - Assignment 7 - Spring 2016

Programmer: Dhwani Shah
Z-ID: z1787631
Section: 3
TA: Robert Durham
Date Due: April 2,2016

Purpose:   The  purpose  of  this program is to sort numbers using the heapsort
technique. Your program first builds a heap structure for the numbers. Then, it
retrieves these numbers from the heap in a certain order and prints them out on
stdout.
*******************************************************************************/

#include <iostream>    //Used for cin() and cout().
#include <iomanip>     //Used for setw().
#include <algorithm>   //Used for random_shuffle().
#include <vector>      //Used for Vectors.
using namespace std;

/*******************************************************************************
void heapify(vector < int >& v, int heap_size, int r, bool(*compar)(int, int))

Uses : This function heapifies a  tree  from  the root position r, assuming r's
       two sub-trees are already heaps.

Parameters : 1. vector <int>&v: It is a reference to a vector.
             2. int heap_size: Size of heap.
             3. int r: refers root.
             4. bool(*compar)(int, int)): It is pointer to boolean function.

Returns : Nothing.
*******************************************************************************/

void heapify(vector < int >& v, int heap_size, int r, bool(*compar)(int, int))
{
	int left = (2*r);      //left child.
	int right = (2*r + 1); //right child.
	int largest;           //maximum value.

	if ((left <= heap_size) && (compar(v[left], v[r])))
		largest = left; //assign left as largest.
	else
		largest = r;  //assign root as largest.

	if ((right <= heap_size - 1) && (compar(v[right], v[largest])))
		largest = right;  //assign right as largest.

	//if root is not the largest
	if (largest != r)
    {
		swap(v[r], v[largest]);
		heapify(v, heap_size, largest, compar);
	}
}

/*******************************************************************************
bool less_than(int e1, int e2)

Uses : This function compares two integers and returns true if e1 is less than
       e2. Otherwise, the function returns false.

Parameters : 1. int e1: It is an integer.
             2. int e2: It is an integer.

Returns : It returns TRUE if e1 < e2 and FALSE if it is not.
*******************************************************************************/

bool less_than(int e1, int e2)
{
	//It compare the two integers to see if e1 is less than e2.
	if (e1 < e2)
		return true;
	else
		return false;
}

/*******************************************************************************
bool greater_than(int e1, int e2)

Uses : This function compares two integers & returns true if e1 is greater than
       e2. Otherwise, the function returns false.

Parameters : 1. int e1: It is an integer.
             2. int e2: It is an integer.

Returns : It returns TRUE if e1 > e2 and FALSE if it is not.
*******************************************************************************/

bool greater_than(int e1, int e2)
{
	//It compare the two integers to see if e1 is greater than e2.
	if (e1 > e2)
		return true;
	else
		return false;
}

/*******************************************************************************
int extract_heap(vector < int >& v, int& heap_size, bool(*compar)(int, int))

Uses : This function extracts the root with the last element of the current
       heap, updates heap_size, and heapifies the root, returning the old root.

Parameters : 1. vector < int >& v: Reference to the vector of heap.
             2. int& heap_size: Reference to the heap_size integer.
             3. bool(*compar)(int, int): It is boolean function pointer.

Returns : It returns value of the old root.
*******************************************************************************/

int extract_heap(vector < int >& v, int& heap_size, bool(*compar)(int, int))
{
	int root = v[1];

	//If the root is empty
	if (!v.empty())
    {
		v[1] = v[heap_size];
		heap_size--;
	}
		heapify(v, heap_size, 1, compar);
	return root;
}

/*******************************************************************************
void build_heap(vector<int>& v, int heap_size, bool(*compar)(int, int))

Uses : This function constructs a heap with heap_size elements in the vector v.

Parameters : 1. vector < int >& v: Reference to the vector of heap.
             2. int heap_size: The size of heap to be constructed
             3. bool(*compar)(int, int): It is boolean function pointer.

Returns : Nothing.
*******************************************************************************/

void build_heap(vector<int>& v, int heap_size, bool(*compar)(int, int))
{
	//Builds the heap by calling heapify
	for (int i = heap_size / 2; i > 0; i--)
    {
		heapify(v, heap_size, i, compar);
	}
}

/*******************************************************************************
void heap_sort(vector < int >& v, int heap_size, bool(*compar)(int, int))

Uses : This  function  is used to  implements  the heap sort  algorithm. In the
       beginning vector  v  contains  a heap and in the end the vector contains
       the sorted heap maybe ascending or descending depending on which function
       greater_than or less_than was called.

Parameters : 1. vector < int >& v: Reference to the vector of heap.
             2. int heap_size: The size of heap to be constructed
             3. bool(*compar)(int, int): It is boolean function pointer.

Returns : Nothing.
*******************************************************************************/

void heap_sort(vector < int >& v, int heap_size, bool(*compar)(int, int))
{
	for (int i = heap_size; i > 1; i--)
    {
		v[i] = extract_heap(v, heap_size, compar);
	}
	reverse(v.begin()+1, v.end());
}

/*******************************************************************************
void print_vector(vector<int>& v, int pos, int size)

Uses : This function is called to print the items that are in the vector. With
       ITEM_WIDTH = 4 and the ITEMS_PER_LINE = 8.

Parameters : 1. vector < int >& v: Reference to the vector of heap.
             2. int pos: from where to start printing.
             3. int size: The size of the vector.

Returns : Nothing.
*******************************************************************************/

void print_vector(vector<int>& v, int pos, int size)
{
	//Setting Item width and Item to display per line.
	const int ITEM_WIDTH = 4;
	const int ITEMS_PER_LINE = 8;

	int counter = 0;
	for (int i = pos; i < size + 1; i++)
    {
		if (counter == ITEMS_PER_LINE)
        {
			cout << endl;
			counter = 0;
		}
		counter++;
		cout << setw(ITEM_WIDTH) << v[i];
	}
	cout << endl;
}

int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake
    int heap_size = 24;
    for (int i=1; i<=heap_size; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+heap_size+1 );
    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, heap_size );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, heap_size, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, heap_size );
    heap_sort( v, heap_size, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, heap_size );

    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, heap_size, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, heap_size );
    heap_sort( v, heap_size, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, heap_size );

    return 0;
}
