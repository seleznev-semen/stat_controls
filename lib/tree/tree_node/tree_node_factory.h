#pragma once
#include <memory>

#include <tree_node/tree_node.h>
#include <tree_node/scalar_node.h>
#include <tree_node/element_node.h>
#include <tree_node/arithmetic_node.h>
#include <tree_node/boolean_node.h>
#include <tree_node/function_node.h>
#include <tree_node/logic_node.h>
#include <types.h>


class NodeFactory
{
public:
   template< LexemeType type, typename... Args >
   static NodePtr MakeNode( Args... args )
   {
      NodePtr result;
      if constexpr( type == LexemeType::SCALAR )
            result = std::make_shared< ScalarNode >( std::forward< Args >( args )... );
      else if constexpr( type == LexemeType::ELEMENT )
            result = std::make_shared< ElementNode >( std::forward< Args >( args )... );
      else if constexpr( type == LexemeType::ARITHMETIC )
            result = std::make_shared< ArithmeticNode >( std::forward< Args >( args )... );
      else if constexpr( type == LexemeType::BOOLEAN )
            result = std::make_shared< BooleanNode >( std::forward< Args >( args )... );
      else if constexpr( type == LexemeType::FUNCTION )
            result = std::make_shared< FunctionNode >( std::forward< Args >( args )... );
      else if constexpr( type == LexemeType::LOGIC )
            result = std::make_shared< LogicNode >( std::forward< Args >( args )... );

      return result;
   }
};

