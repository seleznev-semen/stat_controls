#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/fusion/include/std_pair.hpp>

void RemoveSpaces( std::string& string )
{
   string.erase( std::remove_if( string.begin(), string.end(), isspace ), string.end() );
}

namespace qi = boost::spirit::qi;

template< typename Iterator>
struct stat_grammar : qi::grammar< Iterator >
{
   stat_grammar() : stat_grammar::base_type( expression )
   {
      expression = term >> *( '+' >> term | '-' >> term );
      term = factor >> *( '*' >> factor | '/' >> factor );
      factor = qi::uint_ | '(' >> expression >> ')' | '+' >> factor | '-' >> factor;
   }

   qi::rule< Iterator > expression;
   qi::rule< Iterator > term;
   qi::rule< Iterator > factor;
};

using string_t = std::string;
using iterator_t = string_t::iterator;

void Parse()
{
   string_t expression;

   stat_grammar< iterator_t > stat_parser;

   while(true)
   {
      std::getline( std::cin, expression );
      if( expression == "q" || expression == "Q" )
         break;

      RemoveSpaces( expression );

      iterator_t begin = expression.begin(),
                 end   = expression.end();

      bool success = qi::parse( begin, end, stat_parser );

      std::cout << "---------------------\n";

      if( success && begin == end )
         std::cout << "Parsing succeeded\n";
      else
         std::cout << "Parsing failed\nstopped at: \"" << string_t( begin, end ) << "\"\n";

      std::cout << "---------------------\n";
   }

}

///////////////////


void to_log( const int& val )
{
   std::clog << val << std::endl;
}

template< typename Iter >
struct int_gr : qi::grammar< Iter, std::pair< int, int >() >
{
   int_gr() : int_gr::base_type( expression )
   {
      // phoenix_operator is not required
      expression %= '[' >> qi::int_ >> ',' >> qi::int_ >> ']';
      // requires phoenix_operator.hpp
      // expression = ( '[' >> qi::int_[ &to_log ] >> ']' )[ qi::_val = qi::_1 ];
   }

   qi::rule< Iter, std::pair< int, int >() > expression;
};

void SimpleSemanticActions()
{
   string_t expression;

   int_gr< iterator_t > gr;
   while(true)
   {
      std::getline(std::cin, expression);
      if(expression == "q" || expression == "Q")
         break;

      RemoveSpaces( expression );

      iterator_t begin = expression.begin(),
                 end   = expression.end();
      std::vector< int > result;

      // requires boost/fusion/include/std_pair.hpp for explicit conversion from fusion::vector<int, int> to std::pair<int, int>
      //bool success = qi::parse( begin, end, gr, result );

      bool success = qi::parse( begin, end,
       '{' >> *( qi::omit[ *( qi::char_ - ':' ) ] >> ':' >> qi::int_ ) % ',' >> '}'
                                           , result );

      if( success && begin == end )
      {
         for( auto& i : result )
            std::cout << i << std::endl;
      }
   }

}
