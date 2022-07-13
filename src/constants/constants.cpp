#include <constants.h>



namespace constants
{
static std::size_t DefineParametersCount( const std::string& function_name )
{
   std::size_t result = 0;
   auto function_iterator = FUNCTION_PARAMETER_COUNT.find( function_name );
   if( function_iterator != FUNCTION_PARAMETER_COUNT.end() )
      result = function_iterator->second;

   return result;
}

} // constants
