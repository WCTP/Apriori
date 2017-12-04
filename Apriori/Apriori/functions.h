#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "ItemsList.h"
#include "SubList.h"

using namespace std;

/* functions */
void calculateSupport(SubList& sub1, SubList& sub2, bool flipper, bool **transaction, int fileLength);

string getFileName();
int getItemList(string filename, ItemsList& item);

void generateSubSet(SubList& sub1, bool **transaction, int fileLength, int *translation);

void initializeTransactions(bool **transaction, int* itemTranslation, int itemCount, string filename);

void outputSupport(SubList& sub1, SubList& sub2, bool flipper, ofstream &fout);

int searchItem(int* itemTranslation, int item, int itemCount);
void transferItems(ItemsList& items, int* itemTranslation);

#endif
