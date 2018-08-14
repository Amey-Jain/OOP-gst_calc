#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <cstring>
#include <cstdlib>
#include "db.h"

using namespace std;

const char *db_file = "database.txt";

string load_db(int &count){
  ifstream myfile;
  string data;
  string buffer;
  myfile.open(db_file, ifstream::in);
  if(myfile.is_open())
    while(getline(myfile, buffer)){
      if(buffer.find_first_of("#") == string::npos) 
	data = data + buffer;
      else {
	if(buffer.find("#product_count") != string::npos){
	  //store product count into count variable
	  stringstream prod_cnt(buffer);
	  string token;
	  int ctr = 0;
	  while(getline(prod_cnt, token, '\t')){
	    if(ctr == 1){
	      count = atoi(token.c_str());
	      break;
	    }
	    ctr++;
	  }
	}
      }
    }
  else {
    cout << "Unable to open database file\n";
  }

  cout << "Loaded database with " << count << " products\n";
  myfile.close();
  return data;
}



