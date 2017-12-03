#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "ItemsList.h"

using namespace std;

/* functions */
string getFileName();
int getItemList(string filename, ItemsList& item);
void initializeTransactions(bool **transaction, int* itemTranslation, int itemCount, string filename);
int searchItem(int* itemTranslation, int item, int itemCount);
void transferItems(ItemsList& items, int* itemTranslation);

#endif
