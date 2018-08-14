// This file stores database handling functions
#ifndef __DB_H__
#define __DB_H__

#include <string>
#include <iostream>

using namespace std;

string load_db(int &count);
int write_to_db(int count);
#endif
