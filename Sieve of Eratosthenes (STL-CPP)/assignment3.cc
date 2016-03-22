/***********************************************************************

						AUTHOR : MRINAL SINHA

************************************************************************/

#include <iostream>  //Used for cout and endl.
#include <iomanip>   //Used for setw()
#include <set>	     //Needed to create a set container.
using namespace std;

const int NO_ITEMS = 10; //Only allow 10 primes on each line output.
const int ITEM_W = 6;	 //Allocates 6 spaces.

/***********************************************************************
sieve

Use: This function is used to filter all the prime numbers in the given
     set and in the end all the nonprime numbers will be erased, leaving
     all the prime number behind.

Parameters: 1. set<int>& s: Reference to the set.
            2. int n: This is the max number of element in set.

Returns: Nothing.
************************************************************************/

void sieve( set<int>& s, int n)
{
	//Insert values in the set from 2 to n.
	for(int i = 2; i < n; i++)
	{
		s.insert(i);
	}

	set<int>::iterator it;
	for(it = s.begin(); it != s.end(); it++)
	{
		for(int j = 2; j < n; j++)
		{
			//All (it * j) is not a prime a number.
			int isNotPrime = (*it * j);

			if (((*it)*(*it)) < n )
			{
				//Erase all the numbers that is not prime.
				s.erase(isNotPrime);
			}
		}
	}
}

/***********************************************************************
print_primes

Use: This function is used to print all the remaining element in integer
     set.

Parameters: 1. const set<int>& s: Reference to a const set that has been
               modified by the sieve() function.

Returns: Nothing.
************************************************************************/

void print_primes( const set<int>& s )
{
	int count = 0;
	cout << endl << endl;
	cout << "There are " << s.size() << " prime numbers:" << endl <<endl;
	set<int>::iterator i;
	for(i = s.begin(); i != s.end(); i++)
    {
        if (count == NO_ITEMS)
        {
            cout << endl;
            count = 0;
        }
        ++count;
        //Prints the prime number.
        cout << setw(ITEM_W) << *i;
    }
    cout << endl << endl;
}

int main()
{
    set<int> s;
    sieve(s, 500);
    print_primes(s);
    return 0;
}
