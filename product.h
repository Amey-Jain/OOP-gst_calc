#ifndef __PRODUCT_H__
#define __PRODUCT_H__
 
#include <string>

using namespace std;

// Class product hold information for a single product for runtime
// that are initialized during start of program 
class product {
public:
  product() : price_per_unit(0) {}
  product(product p, double qut);
  void parse_and_store(const string str);
  ostream& print(ostream &output) const;
  string get_name() const { return name; }
  string get_unit() const { return unit; }
  double get_price() const { return price_per_unit; }
  double get_slab_rate() const { return slab_rate; }
  double get_quantity() const { return quantity; }
  char get_status() const { return status; }
  void set_quantity(double q) { quantity = q; }
  void alter_slab_rate(double new_slab_rate);
private:
  string name;
  string unit;
  double price_per_unit;
  double slab_rate;
  double quantity; 
  char status; //stores the current status of a product.
  // i : invalid entry. Some value being entered in product is invalid. Its case where fractional
  //    values are being stored on non-fractionable quantities like pieces.
  // 
  // w : written over. It means something is changed in product (except quantity) and it should be re-written to database.txt
  // o : all ok
};

#endif
