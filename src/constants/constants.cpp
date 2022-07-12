#include <constants.h>

#define DEBUG_MODE

#ifdef DEBUG_MODE
#include <iostream>
#endif

namespace constants
{
static std::size_t DefineParametersCount( const std::string& function_name )
{
   std::size_t result = 0;
   auto function_iterator = FUNCTION_PARAMETER_COUNT.find( function_name );
   if( function_iterator != FUNCTION_PARAMETER_COUNT.end() )
      result = function_iterator->second;

#ifdef DEBUG_MODE
   else
      std::cerr << "[DefineParametersCount] incorrect stat function name: " + function_name << std::endl;
#endif

   return result;
}

} // constants
