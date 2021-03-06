#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class StringList
{
public:
	StringList();
	// Creates a new, empty, list

	StringList(string init[], int size);
	// Creates a new list, initialized from the given values

	StringList(const StringList& other);
	// Copy constructor

	void addEntry(string str);
	// Adds a string to the list

	void displayAllEntry() const;
	// Diaplay all strings from the list

	int countEntry() const;
	// Returns the number of strings in the list

	string get(int idx) const;
	// Returns the string at the given index

	void set(int idx, string str);
	// Sets the string at the given index

	~StringList();
	// Destroys the list, releasing any allocated memory

	void operator=(const StringList& right_side);
	// Assignment operator

private:
	string *list;
	int size;

	void copy_array(string *other, int sz);
	// Helper function that copies the contents of
	// other into list
};

int main()
{
	// Make an array and put some names in it
	const int init_names_size = 5;
	string init_names[init_names_size];
	init_names[0] = "Ahmad";
	init_names[1] = "Wiggum";
	init_names[2] = "Natasha";
	init_names[3] = "Layla";

	// Make two lists, one with each constructor
	StringList names(init_names, 5), list;

	cout << "Initial list:" << endl;
	names.displayAllEntry();

	// Add and remove some names
	names.addEntry("Iyad");
	cout << "After adding a name:" << endl;
	names.displayAllEntry();

	names.addEntry("Muntz");
	cout << "After adding another name:" << endl;
	names.displayAllEntry();

	names.addEntry("Burns");
	names.addEntry("Sameer");
	cout << "After adding three names:" << endl;
	names.displayAllEntry();

	cout << endl << "An empty list created with the default constructor:"
		<< endl;
	list.displayAllEntry();

	list.addEntry("Milhouse");
	list.addEntry("Hind");
	cout << "After adding two entries:" << endl;
	list.displayAllEntry();
	list.set(0, "Jimbo");
	cout << "After changing the first entry:" << endl;
	list.displayAllEntry();

	cout << endl << "After assigning first list to the second list: " << endl;
	list = names;
	list.displayAllEntry();
	cout << "First list (again): " << endl;
	names.displayAllEntry();

	cout << endl << "A third list, created with the copy constructor: " << endl;
	StringList list_copy(list);
	list_copy.displayAllEntry();

	return 0;


}

// Creates a new, empty, list
StringList::StringList() : size(0)
{
}

// Helper function that copies the contents of other into list
void StringList::copy_array(string *other, int sz)
{
	if (sz != size)
	{
		if (size > 0)
		{
			delete[] list;
		}
		size = sz;
		if (size > 0)
		{
			list = new string[size];
		}
	}

	for (int i = 0; i < size; i++)
	{
		list[i] = other[i];
	}
}

// Creates a new list, initialized from the given values
StringList::StringList(string init[], int sz)
{
	size = 0; //to make sure copy_array(.) will not delete an empty array
	copy_array(init, sz);
}

// Copy constructor
StringList::StringList(const StringList& other)
{
	size = 0;
	copy_array(other.list, other.size);
}

// Adds an entry to the list
void StringList::addEntry(string newEntry)
{
	// Create a new array, copy the contents of the old array, then
	// delete it
	string *newArray = new string[size + 1];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = list[i];
	}

	if (size > 0)
	{
		delete[] list;
	}

	// Add the new entry and increment the size
	newArray[size++] = newEntry;

	list = newArray;
}


// Returns the number of strings in the list
int StringList::countEntry() const
{
	return size;
}

// Returns the string at the given index
string StringList::get(int idx) const
{
	return list[idx];
}

// Sets the string at the given index
void StringList::set(int idx, string str)
{
	list[idx] = str;
}

// Destroys the list, releasing any allocated memory
StringList::~StringList()
{
	if (size > 0)
	{
		delete[] list;
	}
}

// Assignment operator
void StringList::operator=(const StringList& right_side)
{
	copy_array(right_side.list, right_side.size);
}

// Prints the entries in the list
void StringList::displayAllEntry()const
{
	for (int i = 0; i < size; i++)
	{
		cout << " " << i << ": " << list[i] << endl;
	}
	cout << endl;
}

