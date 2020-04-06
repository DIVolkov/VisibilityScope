

#include <iostream>
#include <string>

#include "data.h"

static std::string static_var = "Global static in main.cpp";
std::string var = "Global in main.cpp";


namespace TEST{
   static std::string static_var = "Static in namespace TEST in main.cpp";
   std::string var = "In namespace TEST in main.cpp";
   extern std::string var2;
}

int main (void)
{
   ClData data1("instance1"), data2("instance2");
   std::string static_var = "Local static in int main (void)";
   std::string var = "Local in int main (void)";
   
   std::cout << "---------------------------------main-------------------------------" << std::endl;
   std::cout << "static_var = " << static_var << std::endl;
   std::cout << "::static_var = " << ::static_var << std::endl;
   std::cout << "ClData::static_var = " << ClData::static_var << std::endl;
   //std::cout << "data1.static_var = " << data1.static_var << std::endl;// compiler error !!!
   std::cout << "TEST::static_var = " << TEST::static_var << std::endl;
   
   std::cout << "var = " << var << std::endl;
   std::cout << "::var = " << ::var << std::endl;
   std::cout << "data1.var = " << data1.var << std::endl;
   //std::cout << "data1.private_var" << data1.private_var << std::endl;// compiler error !!!
   std::cout << "data2.var = " << data2.var << std::endl;
   std::cout << "TEST::var = " << TEST::var << std::endl;
   std::cout << "TEST::var2 = " << TEST::var2 << " //extern" << std::endl;
   
   data1.print_data1("Parameter/argument of data1.print_data1()");
   data1.print_data2();
   data2.print_data1("Parameter/argument of data2.print_data1()");
   data2.print_data2();
   
   return 0;
}

