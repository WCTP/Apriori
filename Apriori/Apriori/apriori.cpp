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
#include "ItemsList.h"
#include "SubList.h"
#include "functions.h"

int main()
{
	/* declaring variables */
	int fileLength, itemCount, x, y;
	string filename;
	SubList sub1, sub2;
	ItemsList items;
	int *itemTranslation;
	bool **transactions;
	bool subFlipper;
	
	/* retreiving filename and file length and item count  */
	filename = getFileName();
	fileLength = getItemList(filename, items);
	itemCount = items.getLength();

	/* initializing the item translation array */
	itemTranslation = new int[itemCount];
	transferItems(items, itemTranslation);

	/* initializing the transactions array */
	transactions = new bool*[itemCount];
	for (x = 0; x < fileLength; x++)
	{
		transactions[x] = new bool[itemCount];
	}
	for (x = 0; x < fileLength; x++)
	{
		for (y = 0; y < itemCount; y++)
		{
			transactions[x][y] = 0;
		}
	}
	initializeTransactions(transactions, itemTranslation, itemCount, filename);

	/* generating subsets */

	//make subset 1?
	//make subset 2?

	//compare & prune??

	system("pause");
	return 0;
}