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

/*
ItemsList
pre: none
post: an ItemsList will be initialized
purpose: to create an ItemsList so that we can store items
*/
ItemsList::ItemsList()
{
	mHead = NULL;
	mTail = NULL;
	mLength = 0;
}

/*
pre: an ItemsList must exist
post: The ItemsList will be destroyed
purpose: to destroy an ItemsList so that we have no memory leak.
*/
ItemsList::~ItemsList()
{
	//clear();

	mHead = NULL;
	mTail = NULL;

	mLength = 0;
}

int ItemsList::getItem(int index)
{
	return 1;
}