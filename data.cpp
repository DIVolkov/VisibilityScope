#include <iostream>

#include "data.h"

static std::string static_var = "Global static in data.cpp";

namespace TEST{
   static std::string static_var = "Static in namespace TEST in data.cpp";
   //std::string var = "In namespace TEST in data.cpp"; // linker error !!!
   extern std::string var;
   std::string var2 = "In namespace TEST in data.cpp";
}

//std::string var = "Global in data.cpp";// linker error !!!
extern std::string var;

std::string ClData::static_var = "Static in class ClData";



//---------------------------------------------------------
ClData::ClData(const std::string & Data)
      : var("Public in class ClData " + Data)
      , private_var("Private in class ClData " + Data)
//---------------------------------------------------------
{
}

//---------------------------------------------------------
ClData::~ClData()
//---------------------------------------------------------
{
}

//---------------------------------------------------------
//void ClData::print_data1(const std::string & var) // Compiler error that a local variable shadows a parameter
void ClData::print_data1(const std::string & argument_var)
//---------------------------------------------------------
{
   static std::string static_var = "Static in int ClData::print_data1(void)";
   std::string var = "Local in int ClData::print_data1(void)";
   
   std::cout << "\n---------------Begin of int ClData::print_data1(void)----------------" << std::endl;
   std::cout << "argument_var = " << argument_var << std::endl;
   
   std::cout << "static_var = " << static_var << std::endl;
   std::cout << "::static_var = " << ::static_var << std::endl;
   std::cout << "ClData::static_var = " << ClData::static_var << std::endl;
   std::cout << "TEST::static_var = " << TEST::static_var << std::endl;
   
   std::cout << "var = " << var << std::endl;
   std::cout << "::var = " << ::var << " //extern" << std::endl;
   std::cout << "ClData::var = " << ClData::var << std::endl;
   std::cout << "this->var = " << this->var << std::endl;
   std::cout << "ClData::private_var = " << ClData::private_var << std::endl;
   std::cout << "this->private_var = " << this->private_var << std::endl;
   std::cout << "TEST::var = " << TEST::var << " //extern" << std::endl;
   std::cout << "TEST::var2 = " << TEST::var2 << std::endl;
   std::cout << "---------------End of int ClData::print_data1(void)----------------" << std::endl;
}

//---------------------------------------------------------
void ClData::print_data2(void)
//---------------------------------------------------------
{
   std::cout << "\n---------------Begin of int ClData::print_data2(void)----------------" << std::endl;
   std::cout << "static_var = " << static_var << std::endl;
   std::cout << "::static_var = " << ::static_var << std::endl;
   
   std::cout << "var = " << var << std::endl;
   std::cout << "::var = " << ::var << " //extern" << std::endl;
   std::cout << "---------------End of int ClData::print_data2(void)----------------" << std::endl;
}


//---------------------------------------------------------
const std::string ClData::get_private_var(void) const
//---------------------------------------------------------
{
   return private_var;
}


//---------------------------------------------------------
void ClData::set_private_var(const std::string & var)
//---------------------------------------------------------
{
   private_var = var;
}


