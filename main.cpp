#include <iostream>
#include <string>
#include <cassert>
#include <cstring>
#include <bits/stdc++.h>
#include <cstdlib>
#include <list>

#include "db.h"
#include "product.h"

using namespace std;

// class to hold all of items
class ilist {
public:
  ilist();
  int enter_item(string item_name, double item_units); //takes input of an item name and checks if it exists in existing database or not
  void print_items(); 
  void print_gst_invoice();
private:
  list <product> items;
  product *p_list;
  int prod_count;
};

// initializes the p_list, parses and stores all
// values from db file into its objects
ilist::ilist(){
  string data, line;
  
  data = load_db(prod_count);
  if(prod_count <= 0)
    cerr << "Error: Negative/Zero products to initialize\n" ;
  
  stringstream str(data);
  int ctr = 0;
  //initialize product list
  p_list = new product[prod_count];
  //tokenize and store all product values inside
  while(getline(str, line, '|')){
    p_list[ctr].parse_and_store(line);
    ctr++;
  }
}

// Checks item name with each item in item_list. If a match is found, its index
// is returned back, else -1.
int ilist::enter_item(string item_name, double item_units){
  int item_found = 0;
  for(int i = 0;i < prod_count ; i++){
    if(item_name.compare(p_list[i].get_name()) == 0){
      //insert into items list
      product p = product(p_list[i], item_units);
      if(p.get_status() == 'o') // all ok
	items.push_back(p);
      if(p.get_status() == 'i') {
	cerr << "Error: Item \'" << p.get_name() << "\' cannot have non-fractional quantities. Kindly re-enter product\n";
	return -1;
      }
	
      item_found = 1;
      return i;
    }
  }
  
  if(item_found != 1){
    cerr << "Error: Item name " << item_name << " not found in database\n";
    return -1;
  }
  return 0;
}

void ilist::print_gst_invoice(){
  list <product>::iterator ptr;
  double gst_total = 0, gross_total = 0;
  cout << "Name\t\tQuantity   \tPrice\tGST Applicable\tTotal\n";
  for(ptr = items.begin(); ptr != items.end(); ptr++){
    double temp_gst = static_cast<double>(ptr->get_price() * ptr->get_quantity() * ptr->get_slab_rate() / 100);
    cout << ptr->get_name() << "\t\t" << ptr->get_quantity() << " " << ptr->get_unit() << "\t\t"
	 << ptr->get_price() << "\t" << temp_gst << "\t\t"
	 << (ptr->get_price() * ptr->get_quantity()) + temp_gst << endl;
    gst_total = gst_total + temp_gst;
    gross_total = gross_total + (ptr->get_price() * ptr->get_quantity()) + temp_gst;
  }
  cout << "--------------------------------------------------------------------------\n";
  cout << "\nGROSS \tTOTAL             \t\t"<< gst_total <<"    \t\t" << gross_total << "\n";
}

void ilist::print_items(){
  for( int i = 0; i < prod_count; i++)
    cout << p_list[i].get_name() << endl;
}

int main(int argc, char *argv[]){
  //open and load db file
  string data, line, token1, token2;
  double quant_temp;
  string item_temp;
  ilist product_list;
  
  if((argc < 2) || strcmp(argv[1],"--help") == 0){
    cout << "How to use tool\n";
    cout << "user:~/working/directory$:./main --run\n";
    cout << "Enter the list of items and quantity saperated by space. Enter eol for indicating End of list\n";
    cout << "rice 2.5\n"
	 << "perfume 2\n"
	 << "eol\n";
    exit(1);
  }
  else if(argc > 2){
    cout << "Undefined options. Exiting Try --help for help\n--run for running program\n";
    exit(1);
  }

  else if(strcmp(argv[1],"--run") == 0){
    
  cout << "Enter the list of items and quantity saperated by space. Enter eol for indicating End of list\n";

  while(getline(cin, line, '\n')){
    if(line.compare("eol") == 0)
      break;
    stringstream temp(line);
    getline(temp, token1, ' ');
    getline(temp, token2, ' ');
    quant_temp =  strtod(token2.c_str(), NULL);
    if(quant_temp == 0) {
      cerr << "Error: Enter item  name and then quantity\n";
      continue;
    }
    int i = product_list.enter_item(token1, quant_temp);
    if(i < 0)
      cerr << "Error: Unable to enter product\n";
  }
  product_list.print_gst_invoice();
  }
  return 0;
}

