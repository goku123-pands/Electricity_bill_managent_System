# Electricity_bill_managent_System
Takes user details, calculates bill and saves it in a CSV file. 

# Introduction
This code helps to store details of new user in a csv file, view the pre-existing accounts, and calculate electricity bill.

# Concepts used

 * Structs
 * File Handing.
 
# API used

* csvparser.c[[https://sourceforge.net/p/cccsvparser/wiki/Home/](https://sourceforge.net/p/cccsvparser/wiki/Home/)]

### How to install.
####################
### C CSV Parser ###
####################


Compilation under Linux
=======================

1. Creating a shared library
   -------------------------
   cd CsvParser
   mkdir lib
   gcc -Iinclude src/csvparser.c -fPIC -shared -o lib/libcsvparser.so


2. Compiling the usage examples (statically)
   -----------------------------------------
   cd CsvParser
   cd examples
   gcc usage_example.c -I ../include ../src/csvparser.c -o usage_example
   gcc usage_example_with_header.c -I ../include ../src/csvparser.c -o usage_example_with_header