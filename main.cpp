#include <iostream>
#include <tree_node/element_coord/elem_coord.h>
#include <tree_node/arithmetic_node.h>
#include <tree_node/function_node.h>
#include <tree_node/tree_node_factory.h>
#include <types.h>
#include <tree.h>

#include <parser.h>

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

   // CoordRange( 2.2, 3.3 );                   // CE - OK
   // CoordRange( 2.2 );                        // CE - OK

   // lvalue
   int i1 = 3, i2 = 1;
   std::size_t szt1 = 2, szt2 = 3;
   // CoordRange( i1 );                // CE!!! WTF
   CoordRange( i1, i2 );
   CoordRange( szt1, szt2 );
   // CoordRange( szt1 );              // CE!!! WTF
   ///////////////////////

   ///////////////////////
   /// FilterRange
   // rvalue
   FilterRange( "asd" );
   FilterRange( std::string( "asd" ) );
   FilterRange( "asd", "fgh" );
   FilterRange( std::string( "asd" ), std::string( "fgh" ) );
   // TODO FIXME

   // lvalue
   std::string s1 = "asd", s2 = "dfg";
   FilterRange( s1, s2 );
   ///////////////////////

   ///////////////////////
   /// CoordType
   // rvalue
   CoordType();
   CoordType{};
   CoordType{ CoordRange( 1 ) };
   auto ct1 = CoordType{ CoordRange( 1, 2 ) };
   CoordType{ CoordRange( 1 ), CoordRange( 1, 2 ) };
   // TODO FIXME - compile error here

   // lvalue
   ///////////////////////

   ///////////////////////
   /// CoordType
   // rvalue
   FilterType();
   FilterType{};
   FilterType{ FilterRange( "asd" ) };
   FilterType{ FilterRange( "asd", "fgh" ) };

   // lvalue
   ///////////////////////

   ///////////////////////
   /// ElemCoord
   //rvalue
   ElemCoord( 1, 2, 3, "asd" );
   ElemCoord( 1, 2, 3, std::string( "asd" ) );
   ElemCoord( 1, 2, 3 );
   ElemCoord( std::size_t( 1 ), CoordType{ CoordRange( 1, 1 ) }, CoordType{ CoordRange( 2, 2 ) } );
   ElemCoord( 1, CoordType{ CoordRange( 1, 1 ) }, CoordType{ CoordRange( 2, 2 ) }, FilterType{ FilterRange("1", "4") } );
   ElemCoord( 1, CoordType{ 1 }, CoordType{ CoordRange( 2, 2 ) }, FilterType{ FilterRange("1", "4") } );
   ElemCoord( 1, CoordType{ 1 }, CoordType{ CoordRange( 2, 2 ) }, FilterType{ "FilterRange()" } );
   ElemCoord( 1, 2, 3, "asd" );

   //lvalue
   ElemCoord( i1, i2, szt1, "asd" );
   ElemCoord( i1, i2, szt1, s1 );
   ElemCoord( i1, i2, szt1 );
   ///////////////////////

   auto n = NodeFactory::MakeNode< LexemeType::SCALAR >( "1" );
   ArithmeticNode( "+" );
   auto n1 = NodeFactory::MakeNode< LexemeType::ARITHMETIC >( "+" );
   auto n2 = NodeFactory::MakeNode< LexemeType::FUNCTION >( "coalesce" );

   FilterType{ FilterRange( "asd" ), FilterRange( "fgh" ), FilterRange( "qwe" ) };

}

int main()
{
   //Parse();
   SimpleSemanticActions();
   return 0;
}
