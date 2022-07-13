#include <iostream>
#include <tree/tree_node/element_coord/elem_coord.h>
using namespace std;

void ctor_tests()
{
   /** c-tors tests*/
   ///////////////////////
   /// CoordRange
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
   ///////////////////////

   ///////////////////////
   /// FilterRange
   // rvalue
   FilterRange( "asd" );
   FilterRange( std::string( "asd" ) );
   FilterRange( "asd", "fgh" );
   FilterRange( std::string( "asd" ), std::string( "fgh" ) );
   // TODO FIXME
   // auto fr1 = ValueRangeFactory( "asd" ); // CE: no matching ctor aaray char[4] -> FilterRange
   auto fr2 = ValueRangeFactory( std::string( "asd" ), std::string( "fgh" ) );

   // lvalue
   std::string s1 = "asd", s2 = "dfg";
   FilterRange( s1, s2 );
   auto fr3 = ValueRangeFactory( s1 );
   ///////////////////////

   ///////////////////////
   /// CoordType
   // rvalue
   CoordType();
   CoordType{};
   CoordType{ CoordRange( 1 ) };
   CoordType{ CoordRange( 1, 2 ) };
   CoordType{ CoordRange( 1 ), CoordRange( 1, 2 ) };
   // TODO FIXME - compile error here
   // CoordType{ ValueRangeFactory( 1 ) };
   CoordType{ ValueRangeFactory( std::size_t( 1 ) ) };

   // lvalue
   CoordType{ cr3 };
   CoordType{ cr3, cr4 };
   CoordType{ cr3, CoordRange( 1 ) };
   // TODO FIXME - compile error here
   // CoordType{ cr4, ValueRangeFactory( 1 ) };
   ///////////////////////

   ///////////////////////
   /// CoordType
   // rvalue
   FilterType();
   FilterType{};
   FilterType{ FilterRange( "asd" ) };
   FilterType{ FilterRange( "asd", "fgh" ) };
   FilterType{ ValueRangeFactory( std::string( "asd" ) ) };

   // lvalue
   FilterType{ fr2 };
   FilterType{ fr2, fr3 };
   FilterType{ fr2, FilterRange( "asd" ) };
   FilterType{ fr2, ValueRangeFactory( std::string( "asd" ) ) };
   ///////////////////////

   ///////////////////////
   /// ElemCoord
   //rvalue
   ElemCoord( 1, 2, 3, "asd" );
   ElemCoord( 1, 2, 3, std::string( "asd" ) );
   ElemCoord( 1, 2, 3 );
   ElemCoord( 1, 2, 3, "asd" );
   // TODO FIXEME -> compile error here
   // ElemCoord( std::size_t( 1 ), CoordType{ CoordRange( 1, 1 ) }, CoordType{ CoordRange( 2, 2 ) } );
   ///////////////////////
}

int main()
{
   ctor_tests();
   return 0;
}
