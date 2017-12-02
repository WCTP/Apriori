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