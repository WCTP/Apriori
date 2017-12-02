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
	/* making variables */
	SubList test;
	int *subset;

	subset = new int[3];
	subset[0] = 10;
	subset[1] = 11;
	subset[2] = 12;

	/* testing SubList object */

	test.insert(subset);
	test.display(3);

	getFileName();

	delete[] subset;

	system("pause");
	return 0;
}