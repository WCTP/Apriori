/*		Author: Jimmy Griffiths & Walter Proulx
 *		Class : CSI-281-01
 *		Assignment : Final Project
 * 		Date Assigned : November 30, 2017
 * 		Due Date : November 5, 2017
 *
 *		Description :
 *			An implementation of the Apriori algorithm.
 *
 *		Certification of Authenticity :
 *			I certify that this is entirely my own work, except where I have given fully
 * 			documented references to the work of others. I understand the definition and
 * 			consequences of plagiarism and acknowledge that the assessor of this assignment
 * 			may, for the purpose of assessing this assignment :
 * 			-	Reproduce this assignment and provide a copy to another member of
 *				academic staff; and / or
 *			-	Communicate a copy of this assignment to a plagiarism checking service
 *				(which may then retain a copy of this assignment on its database for
 *				the purpose of future plagiarism checking)
 *
 ***********************************************************************************************/
#include "functions.h"
#include "ItemsList.h"

/*      Pre:  none
 *     Post:  string
 *  Purpose:  retrieves filename from user
 ********************************************************************/
string getFileName()
{
	string filename = "";

	fstream fin;

	while (filename == "")
	{
		cout << "Please enter a filename: ";

		getline(cin, filename);

		fin.open(filename);
		if (!fin.good())
		{
			cout << "ERROR: File not found!" << endl;
			filename = "";
			fin.close();
		}
	}

	fin.close();

	return filename;
}

/*      Pre:  string, ItemList
 *     Post:  int
 *  Purpose:  makes a list of all the objects in the file and stores
 *			  them in the ItemList object
 ********************************************************************/
int getItemList(string filename, ItemsList& items)
{
	int item;
	int fileLength = 0;
	fstream fin;
	string line;
	stringstream lineConvert;

	fin.open(filename);

	while (!fin.eof())
	{
		getline(fin, line);
		lineConvert << line;

		while (!lineConvert.eof())
		{
			lineConvert >> item;
			items.insert(item);
		}

		lineConvert.str("");
		lineConvert.clear();

		fileLength++;
	}

	fin.close();

	return fileLength;
}

/*      Pre:  2D dynamic bool array, string
 *     Post:  none
 *  Purpose:  goes through a transaction file and translates the file
 *			  from numbers to a 2D bool array
 ********************************************************************/
void initializeTransactions(bool **transaction, int* itemTranslation, int itemCount, string filename)
{
	int item;
	fstream fin;
	string line;
	stringstream lineConvert;

	fin.open(filename);

	for (int tranIndex = 0; !fin.eof(); tranIndex++)
	{
		getline(fin, line);
		lineConvert << line;

		while (!lineConvert.eof())
		{
			lineConvert >> item;
			item = searchItem(itemTranslation, item, itemCount);
			transaction[tranIndex][item] = 1;
		}

		lineConvert.str("");
		lineConvert.clear();
	}

	fin.close();
}

/*      Pre:  2D dynamic bool array, string
 *     Post:  none
 *  Purpose:  goes through a transaction file and translates the file
 *			  from numbers to a 2D bool array
 ********************************************************************/
int searchItem(int* itemTranslation, int item, int itemCount)
{
	int index;
	bool found = false;

	for (index = 0; index < itemCount && found == false; index++)
	{
		if (item == itemTranslation[index])
		{
			found = true;
			index--;
		}
	}

	return index;
}

/*      Pre:  ItemsList, int
 *     Post:  none
 *  Purpose:  transfers items from a ItemsList object to a dynamic
 *			  integer array
 ********************************************************************/
void transferItems(ItemsList& items, int* itemTranslation)
{
	int length = items.getLength();

	for (int x = 0; x < length; x++)
	{
		itemTranslation[x] = items.getItem(x);
	}
}