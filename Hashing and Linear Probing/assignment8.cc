#include "assignment8.h"
#include <iostream>
#include <iomanip>
#include <fstream>  // It is required ot open file.
#include <string>
#include <vector>

using namespace std;

/*******************************************************************************
Entry* get_entry(const string& line)

Uses : This take a line of input and parse it to make a new entry. The format of
       line is "A:item key:item description".

Parameters : 1. (const string& line) - This is the line input that is read form
		the file.

Returns : Returns a new entry that has the key and description form the file
	  that was read from the text file.
*******************************************************************************/
Entry* get_entry(const string& line)
{
	//It creates entry to hold key and description.
	Entry* parsed_line = new Entry;

	parsed_line->key = line.substr(2, 3);
	parsed_line->description = line.substr(6, line.length() - 6);
	return parsed_line;
}

/*******************************************************************************
string get_key(const string& line)

Uses : This method takes input and return the item key.

Parameters : 1. (const string& line) - This is the line input that is read form
		the file.

Returns : Returns the parsed string which has the key.
*******************************************************************************/
string get_key(const string& line)
{
	string gKey = line.substr(2, 3);
	return gKey;
}

/*******************************************************************************
HT::HT(int s = 11)

Uses : This is a default constructor. The hash table which is a vector of entry,
       is created dynamically with the given size of input.

Parameters : 1. (int s = 11) - This a the size that teh vector will be initalized.

Returns : Nothing.
*******************************************************************************/
HT::HT(int s = 11)
{
	//hTable is created with given size 11.
	hTable = new vector<Entry>(s);
	table_size = s;
	item_count = 0;
}

/*******************************************************************************
HT::~HT()

Uses : THis is the destructor for Hash Table. It release the resources that are
       in use by the hTable.

Parameters : Nothing.

Returns : Nothing.
*******************************************************************************/
HT::~HT()
{
	//Releases the hTable resources.
	delete hTable;
}

/*******************************************************************************
int HT::search (const string& key)

Uses : It is the public function that searches the hash table for a record with
       the given key. It computes the hash value. If the search was successful
       the function will return the position of the found element.

Parameters : 1. (const string& key) - Takes key as an input.

Returns : 1. (keyIndex) - Returns position of the found element.
	  2. (-1) - Return it if the search was not successful.
*******************************************************************************/
int HT::search (const string& key)
{
	int keyIndex = hashing(key);
	for(int i = 0; i < table_size; i++) {
		if ((*hTable)[keyIndex].key == key)
			return keyIndex;
		keyIndex = (keyIndex + 1) % table_size;
	}
	return -1;
}

/*******************************************************************************
bool HT::insert(const Entry& e)

Uses : It is  public member function to inserts item e in the hash table. It first 
       checks if the items key already exists in the hash table by calling the 
       search() function. If the key exists, an error message is printed and insert()
       returns false. If the hash table is already full, an error message is printed 
       and the function returns false. If the above checks do not fail, the hash value
       is computed for the key of e. If the hash table position of the hash value is 
       empty, the item is placed on that position. Otherwise, an appropriate position
       is determined by linear probing. After the item is inserted, item_count is 
       increased and the function returns true.

Parameters : 1. (const Entry& e) - This is reference to the entry element.

Returns : 1. Return true if the item has been inserted.
	  2. Return flase if the identical key found or the table is full.
*******************************************************************************/
bool HT::insert(const Entry& e)
{
	int keyIndex = hashing(e.key);

	string sKey = e.key;
	if (search(sKey) != -1) {
		cerr << "Unable to insert - identical key found" << endl;
		return false;
	}
	else if (item_count == table_size) {
		cerr << "Unable to insert - the table is full." << endl;
		return false;
	}

	else {
		int i;
		for (i = 0; i < table_size; i++) {
			if ((*hTable)[keyIndex].key == "---" || (*hTable)[keyIndex].key == "+++") {
				(*hTable)[keyIndex] = e;
				item_count++;

				return true;
			}
			keyIndex = keyIndex + 1 % table_size;
		}
	}
	return false;
}

/*******************************************************************************
bool HT::remove(const string& s)

Uses : It is public member function for remove it simply removes an item with
       the given key value.

Parameters : 1. (const string& s) - This is the given key.

Returns : 1. Returns true if the key has been removed from the table.
          2. Returns false if the key is not found.
*******************************************************************************/
bool HT::remove(const string& s)
{
	if (search(s) == -1) {
		return false;
	}

	else {
		int keyIndex = search(s);

		(*hTable)[keyIndex].key = "+++";
		item_count--;
		return true;
	}
}

/*******************************************************************************
void HT::print ()

Uses : It is public member function for printing the existing entries in the
       hash table. It prints the index value, key and description.

Parameters : NOthing.

Returns : Nothing.
*******************************************************************************/
void HT::print ()
{
	cout << endl << "----Hash Table-----" << endl;

	for (int i = 0; i < table_size; i++) {
		if ((*hTable)[i].key != "---" && (*hTable)[i].key != "+++") {
			cout << right << setw(2) << i << ": ";
			cout << (*hTable)[i].key << " ";
			cout << (*hTable)[i].description << endl;
		}
	}
	cout << "---------------------------" << endl << endl;
}


// key is in form of letter-letter-digit
// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)
// compute sum%htable_size
int HT::hashing(const string& key) {
	return ((int)key[0] + (int)key[1] + (int)key[2]) % table_size;
}

int main(int argc, char** argv) {
	if (argc < 2) {
		cerr << "argument: file-name\n";
		return 1;
	}

	HT ht;
	ifstream infile(argv[1], ios::in);
	string line;
	infile >> line;
	while (!infile.eof()) {
		if (line[0] == 'A') {
			Entry* e = get_entry(line);
			ht.insert(*e);
			delete e;
		}
		else {
			string key = get_key(line);
			if (line[0] == 'D') {
				cout << "Removing " << key << "...\n";
				bool removed = ht.remove(key);
				if (removed)
					cout << key << " is removed successfully...\n\n";
				else
					cout << key << " does not exist, no key is removed...\n\n";
			}
			else if (line[0] == 'S') {
				int found = ht.search(key);
				if (found < 0)
					cout << key << " does not exit in the hash table ..." << endl << endl;
				else
					cout << key << " is found at table position " << found << endl << endl;
			}
			else if (line[0] == 'P') {
				cout << "\nDisplaying the table: " << endl;
				ht.print();
			}
			else
				cerr << "wrong input: " << line << endl;
		}
		infile >> line;

	}

	infile.close();
	return 0;
}
