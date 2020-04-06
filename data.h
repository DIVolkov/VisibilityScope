#ifndef CL_DATA
#define CL_DATA

#include <string>

class ClData
{
public:
   
   static std::string static_var;
   std::string var;

   ClData(const std::string & Data);
   
   virtual ~ClData();

   void print_data1(const std::string & var);
   
   void print_data2(void);
   
   const std::string get_private_var(void) const;
   
   void set_private_var(const std::string & var);
   
private:
   std::string private_var;
};

#endif// CL_DATA
