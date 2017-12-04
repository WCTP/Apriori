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

void calculateSupport(SubList& sub1, SubList& sub2, bool flipper, bool **transaction, int fileLength)
{
	int i, j, k;
	if (flipper)
	{
		for(i = 0; i < sub1.getLength(); i++)
		{
			for (j = 0; j < /*length of each subset. I.e {0} is 1*/ 1; j++)
			{
				for (k = 0; k < fileLength; k++)
				{
					if (transaction[k][sub1.getSupport(i)] == true)
						sub1.incrementSupport(i);
				}
			}
		}


		flipper = false;
	}

	else
	{
		for (i = 0; i < fileLength; i++)
		{
			for (j = 0; j < /*transaction[i].length*/100; j++)
			{
				if (sub2.getSubset(0) == transaction[i][j])
				{
					sub2.incrementSupport(0);
				}
			}
		}

		flipper = true;
	}

	
}

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

void generateSubSet1(SubList &sub1, int itemCount)
{
	//Knowing the transaction array is rows for transaction, columns for whether that thing exists in items or not...
	//read through and generate subsets of {1} {2}...{n} with support x
	//Is sublist an item or an index for the item?

	int *i;
	int *subIndex;
	i = new int;
	for (*i = 0; *i < itemCount; *i++)
	{
		//subIndex = new int;
		//*subIndex = i;
		sub1.insert(i);
	}

	
}

void generateSubSet2(SubList& sub1,SubList &sub2, int itemCount)
{
	//Knowing the transaction array is rows for transaction, columns for whether that thing exists in items or not...
	//read through and generate subsets of {1} {2}...{n} with support x
	//Is sublist an item or an index for the item?

	int i, j;
	int *sub2Index;
	for (i = 0; i < itemCount; i++)
	{
		for (j = i + 1; j < itemCount; j++)
		{
			sub2Index = new int[2];
			sub2Index[0] = i;
			sub2Index[1] = j;
			sub2.insert(sub2Index);
		}
	}


}

void generateSubSet(SubList& sub1, SubList& sub2, int itemCount, int subSetNumber, bool subFlipper)
{
	int i, j, k, w;
	int *newSubSet;
	bool isSame = true;
	for (i = 0; i < itemCount; i++)
	{
		for (j = i + 1; j < itemCount; j++)
		{
			
			if (subFlipper)
			{

				//dealing with sub2
				isSame = true;
				for (k = 0; k < subSetNumber - 2; k++)
				{
					if (sub2.getItem(i, k) != sub2.getItem(j, k))
					{
						isSame = false;
					}
				}

				if (isSame)
				{
					newSubSet = new int[subSetNumber];
					for (w = 0; w < subSetNumber - 1; w++)
					{
						newSubSet[w] = sub2.getItem(i, w);
					}
					newSubSet[subSetNumber - 1] = sub2.getItem(j, subSetNumber - 2);
					sub1.insert(newSubSet);
				}

			}
			else
			{
				//dealing with sub1
				isSame = true;
				for (k = 0; k < subSetNumber - 2; k++)
				{
					if (sub1.getItem(i, k) != sub1.getItem(j, k))
					{
						isSame = false;
					}
				}

				if (isSame)
				{
					newSubSet = new int[subSetNumber];
					for (w = 0; w < subSetNumber - 1; w++)
					{
						newSubSet[w] = sub1.getItem(i, w);
					}
					newSubSet[subSetNumber - 1] = sub1.getItem(j, subSetNumber - 2);
					sub2.insert(newSubSet);
				}
			}
			

		}
	}
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

void outputSupport(SubList& sub1, SubList& sub2, bool flipper, ofstream& fout)
{
	if (flipper)
	{
		fout << sub1;
	}

	else
	{
		fout << sub2;
	}
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