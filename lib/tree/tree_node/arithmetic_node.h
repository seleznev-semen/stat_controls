#pragma once

#include <tree_node/tree_node.h>
#include <traits.h>
#include <constants.h>

class ArithmeticNode : public ITreeNode
{
public:
   template< typename T, typename = StringT< T > >
   ArithmeticNode( T&& value )
      : ITreeNode( constants::BINARY_NODE_CHILDREN_COUNT )
      , mValue( std::forward< T >( value ) )
   {}

   ArithmeticNode() = default;
   ArithmeticNode( const ArithmeticNode& other ) = default;
   ArithmeticNode( ArithmeticNode&& other ) = default;
   ArithmeticNode& operator=( const ArithmeticNode& other ) = default;
   ArithmeticNode& operator=( ArithmeticNode&& other ) = default;

   template< typename T, typename = StringT< T > >
   inline void Set( T&& value )
   {
      mValue = std::forward< T >( value );
   }

private:
   std::string mValue;
};
