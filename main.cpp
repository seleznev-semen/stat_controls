#include <iostream>
#include <tree/tree_node/element_coord/elem_coord.h>
using namespace std;

int main()
{
   /** c-tors tests*/
   {  /// CoordRange
      // rvalue
      CoordRange( 1, 1 );
      CoordRange( 1 );
      CoordRange( std::size_t( 1 ) );
      CoordRange( std::size_t( 1 ), std::size_t( 1 ) );
      auto cr1 = ValueRangeFactory( 1 );
      auto cr2 = ValueRangeFactory( 1, 1 );

      // CoordRange( 2.2, 3.3 );                   // CE - OK
      // CoordRange( 2.2 );                        // CE - OK
      // auto error = ValueRangeFactory( 4.4 );    // CE - OK

      // lvalue
      int i1 = 3, i2 = 1;
      std::size_t szt1 = 2, szt2 = 3;
      // CoordRange( i1 );                // CE!!! WTF
      CoordRange( i1, i2 );
      CoordRange( szt1, szt2 );
      // CoordRange( szt1 );              // CE!!! WTF
      auto cr3 = ValueRangeFactory( szt1 );
      auto cr4 = ValueRangeFactory( szt1, szt2 );
   }

   {  /// FilterRange
      // rvalue
      FilterRange( "asd" );
      FilterRange( std::string( "asd" ) );
      FilterRange( "asd", "fgh" );
      FilterRange( std::string( "asd" ), std::string( "fgh" ) );
      // TODO FIXME
      // auto cr1 = ValueRangeFactory( "asd" ); // CE: no matching ctor aaray char[4] -> FilterRange
      auto cr2 = ValueRangeFactory( std::string( "asd" ), std::string( "fgh" ) );

      // lvalue
      std::string s1 = "asd", s2 = "dfg";
      FilterRange( s1, s2 );
      auto cr4 = ValueRangeFactory( s1 );
   }

   return 0;
}
