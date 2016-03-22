/***********************************************************************

						AUTHOR : MRINAL SINHA

************************************************************************/

#include <algorithm>   //Used for sort(), find() and equal_range()
#include <iostream>    //Used for cout and endl
#include <cstdlib>		 //Used for srand() and rand()
#include <vector>      //Used for Vector
#include <iomanip>		 //Used for setting decimal precision
using namespace std;

const int TOBE_SEARCHED = 5000;

/***********************************************************************
genRndNums

Use: This function is used to generate random numbers in range [1,10000].

Parameters: 1. vector<int> &v: Vector of integer type.
            2. vec_size: Is the size of vector.
            3. seed: passing value of seed to pass in srand() function.

Returns: Nothing.
************************************************************************/

void genRndNums(vector<int>& v, int vec_size, int seed)
{
	srand(seed);
	for (int i = 0; i < vec_size; i++)
	{
		int input = (rand() % 10000) + 1;
		v.push_back(input);
	}
}

/***********************************************************************
linearSearch

Use: This function is used to search the elements of searchNums vector
		 in container vector (linearly).

Parameters: 1. const vector<int>& v: Is a reference to vector.
					  2. int x: It is the element that is to search.

Returns: Returns 1, if element found else returns O.
************************************************************************/

int linearSearch(const vector<int>& v, int x)
{
	vector<int>::const_iterator loc;
	loc = find(v.begin(), v.end(), x);
	if (loc != v.end())
		return 1;
	else
		return 0;
}

/***********************************************************************
binarySearch

Use: This function is used to search the elements of searchNums vector
		 in container vector (using binary Search method (equal_range) ).

Parameters: 1. const vector<int>& v: Is a reference to vector.
					  2. int x: It is the element that is to search.

Returns: Returns the difference between Upper bound and Lower bound.
************************************************************************/

int binarySearch(const vector<int>& v, int x)
{
	pair<vector<int>::const_iterator, vector<int>::const_iterator> bounds;
	bounds = equal_range(v.begin(), v.end(), x);
	return ((bounds.second - v.begin()) - (bounds.first - v.begin()));
}

/***********************************************************************
search

Use: This is a generic search algorithm, it takes pointer to the search
		 function. It call p() for each element of one vector to another.

Parameters: 1. const vector<int>& container: Reference to vector.
						2. const vector<int>& searchNums: Reference to vector.
						3. int(*p)(const vector<int>&, int)): Pointer to the search
							 functions.

Returns: It returns the total count of match found.
************************************************************************/

int search(const vector<int>& container, const vector<int>& searchNums,
	int(*p)(const vector<int>&, int))
{
	int size = searchNums.size();
	int total_count = 0;
	for (int i = 0; i < size; i++)
	{
		if (p(container, searchNums[i]))
		{
			total_count++;
		}
	}
	return total_count;
}

/***********************************************************************
sort

Use: A sort function that sorts the elements of a vector in ascending
	   order.

Parameters: 1. Reference to the vector to sort.

Returns: Nothing.
************************************************************************/

void sortVec(vector<int>& v)
{
	sort(v.begin(), v.end());
}

/***********************************************************************
printStat

Use: The function prints the total percent of successful searches.

Parameters: 1. int totalSucCnt: Total Number of comparisons.
 						2. It's a size of vector whose elements are to be searched.

Returns: Nothing.
************************************************************************/

void printStat(int totalSucCnt, int vec_size)
{
  float result = 0;
	result = ((float)totalSucCnt / vec_size);
	cout << fixed << setprecision(2) << "Successful searches: "
			 << result*100 << "%";
	cout << endl << endl;
}

int main()
{
	vector<int> container, tobeSearched;
	genRndNums(container, 10000, 7);
	genRndNums(tobeSearched, TOBE_SEARCHED, 5);

	cout << "\nConducting linear search ..." << endl;
	int linear_search_count = search(container, tobeSearched, linearSearch);
	printStat(linear_search_count, TOBE_SEARCHED);

	cout << "\nConducting binary search on unsorted container ..." << endl;
	int binary_search_count = search(container, tobeSearched, binarySearch);
	printStat(binary_search_count, TOBE_SEARCHED);

	sortVec(container);

	cout << "\nConducting binary search on sorted container ..." << endl;
	binary_search_count = search(container, tobeSearched, binarySearch);
	printStat(binary_search_count, TOBE_SEARCHED);

	return 0;
}
