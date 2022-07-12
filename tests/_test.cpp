#include "../constants.h"

#include <vector>

int main()
{
   std::vector< std::string > cases{ "isnull", "abs", "ads" };
   for( const auto& name : cases )
      constants::DefineParametersCount( name );

}
