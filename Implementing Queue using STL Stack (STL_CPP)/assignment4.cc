/***********************************************************************

AUTHOR: MRINAL SINHA

************************************************************************/

#include "assignment4.h"
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
using namespace std;

/***********************************************************************
bool Queue::empty() const

Use: This is used to check whether the stack s1 and s2 are empty or not.

Returns: true if it's empty else false.
************************************************************************/

bool Queue::empty() const
{
	if (s1.empty() && s2.empty())
		return true;
	else
		return false;
}

/***********************************************************************
int Queue::size() const

Use: This is used to find the size of stack s1 and s2 together.

Returns: sum of total elements in stack s1 and s2.
************************************************************************/

int Queue::size() const
{
	return (s1.size() + s2.size());
}

/***********************************************************************
int Queue::front()

Use: First of all s2 is empty move all elements from s1 to s2 then simply
     return the top element of s2.

Returns: the oldest element.
************************************************************************/

int Queue::front()
{
	if(!s2.empty())
  	{
    		return s2.top();
  	}
  	else
  	{
    		while(!s1.empty())
    		{
      			int t = s1.top();
      			s1.pop();
      			s2.push(t);
    		}
    		return s2.top();
  	}
}

/***********************************************************************
int Queue::back()

Use: This method returns the newest element. Simply retruns the top
		 element in stack s1.

Returns: the newest element.
************************************************************************/

int Queue::back()
{
	return s1.top();
}

/***********************************************************************
void Queue::push(const int& val)

Use: This Method is used to simply add elements to stack s1.

Returns: Nothing.
************************************************************************/

void Queue::push(const int& val)
{
	s1.push(val);
}

/***********************************************************************
void Queue::pop()

Use: This method is used to remove the oldest element. As in front we
		 are retrieving the oldest element here we'll simply pop them.

Returns: Nothing.
************************************************************************/

void Queue::pop()
{
	if(!s2.empty())
  	{
    		s2.pop();
  	}
  	else
  	{
    		while(!s1.empty())
    		{
      			int t = s1.top();
      			s1.pop();
      			s2.push(t);
    		}
    		s2.pop();
  	}
}

//*************************( Main - Function )************************//

int main() {
    Queue q;
    string op;
    int val = 0;
    cout << endl;
    cout << "operation -- size front end" << endl;
    while ( !cin.eof() ) {
        cin >> op;
        if ( op == "push" ) {
            cin >> val;
            q.push( val );
            cout << op << " " << val << "    -- ";
        }
        else if ( op == "pop" ) {
            q.pop();
            cout << op << "       -- ";
        }
        else {
            cerr << "Error input: " << op << endl;
            return 1;
        }
        cout << setw(3) << q.size() << setw(5) << q.front() << setw(5) << q.back() << endl;
    }

    while ( !q.empty() )
        q.pop();
    cout << "End -- size of Queue is: " << q.size() << endl << endl;

    return 0;
}
