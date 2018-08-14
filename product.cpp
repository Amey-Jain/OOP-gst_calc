#include <iostream>
#include <string>
#include <bits/stdc++.h>

#include "product.h"

using namespace std;

// copy constructor
product::product(product p, double qut){
  name = p.get_name();
  unit = p.get_unit();
  price_per_unit = p.get_price();
  slab_rate = p.get_slab_rate();
  set_quantity(qut);
  status = 'o';
  if((unit == "nos" || unit == "ml") && (qut - static_cast<int>(qut) > 0)){
    //non-fractional value allowed only
    cerr << "Error: Only non-fractional value allowed in these products. Kindly re-enter\n";
    status = 'i';
  }
}

void product::parse_and_store(const string str){
  assert(str.length() != 0);
  string token;
  stringstream check1(str);
  int ctr = 0;
  //tokenize the string str
  while(getline(check1, token, '\t'))
    {
      switch(ctr){
      case 0: name = token;
	ctr++;
	break;
      case 1: unit = token;
	ctr++;
	break;
      case 2: slab_rate = strtod(token.c_str(), NULL);
	ctr++;
	break;
      case 3: price_per_unit = strtod(token.c_str(), NULL);
	ctr++;
	break;
      default: break;
      }
    }
}

ostream& product::print(ostream &output) const {
  //  cout << "Name\tUnit\tPrice\tGST\n";
  output << name << "\t" << unit << "\t" << slab_rate << "\t" << price_per_unit << "\n";
}

void product::alter_slab_rate(double new_slab_rate) {
  cout << "Changing slab rate of " << name << " from " << slab_rate << " to " << new_slab_rate << endl;
  slab_rate = new_slab_rate;
}
