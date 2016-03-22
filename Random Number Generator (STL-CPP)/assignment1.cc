/*****************************************************

				AUTHOR : MRINAL SINHA

*****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

/****************************************************
genRndNums

Use: This function is used to generate random
     numbers in range [ 1,1000 ].

Parameters: 1. vector<int> &v: Vector of integer type.
            2. vec_size: Is the size of vector.
            3. seed: passing value of seed to pass in
            srand() function.

Returns: Nothing.
****************************************************/

void genRndNums(vector<int>& v, int vec_size, int seed)
{
  srand(seed);
  for(int i = 0; i < vec_size; i++)
  {
    int b = (rand()%1000)+1;
    v.push_back(b);
  }
}

/****************************************************
printVec

Use: This function is used to print the randomly
     generated numbers in sorted form.

Parameters: 1. vector<int> &v: Vector of integer type.
            2. vec_size: Is the size of vector.

Returns: Nothing.
****************************************************/

void printVec(const vector<int>& v, int vec_size)
{
  for(int i = 0; i < (int)v.size(); i++)
  {
    //Prints new line after every 10 columns.
    if(i%10 == 0) cout << endl;
    cout << v[i] <<"\t";
  }
  cout << endl << endl;
}

int main()
{
  int size = 100;
  int seed = 7;
  vector<int> v;
  genRndNums(v,size,seed);

  //Sorts the vector in ascending order.
  sort(v.begin(),v.end());

  printVec(v,size);

  return 0;
}
