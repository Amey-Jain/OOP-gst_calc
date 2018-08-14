
# GST Calculator
Aim of this GST calculator is to make a console application using Object oriented concepts which will be able to calculate price of products given to it Read more information in Problem statement.

## How to?
In your linux terminal: 
`git clone https://github.com/Amey-Jain/OOP-gst_calc.git;
cd OOP-gst_calc;
./compile.sh;
./main --run;`

## Classes

### Product
Product class represents a commodity whose price and GST are to be calculated. It has following members:
1. Name : Name of product
2. Unit : Unit of representation (Pieces/ Kilograms/ Meters etc)
3. Price : Price per unit of commodity
4. Slab : GST slab that commodity is associated with
5. Quantity: Quantity details for buyer

### Ilist
Ilist class represents the list of items that are being entered and also calculates the invoice handling all products.