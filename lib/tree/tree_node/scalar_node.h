#pragma once

#include <tree_node/tree_node.h>
#include <traits.h>
#include <constants.h>

class ScalarNode : public ITreeNode
{
public:
   template< typename T, typename = NumericT< T > >
   ScalarNode( T value )
      : ITreeNode( constants::LEAF_NODE_CHILDREN_COUNT )
      , mValue( std::to_string( value ) )
   {}

   template< typename T, typename = StringT< T > >
   ScalarNode( T&& value )
      : ITreeNode( constants::LEAF_NODE_CHILDREN_COUNT )
      , mValue( std::forward< T >( value ) )
   {}

   ScalarNode() = default;
   ScalarNode( const ScalarNode& other ) = default;
   ScalarNode( ScalarNode&& other ) = default;
   ScalarNode& operator=( const ScalarNode& other ) = default;
   ScalarNode& operator=( ScalarNode&& other ) = default;

   template< typename T, typename = StringT< T > >
   inline void Set( T&& value )
   {
      mValue = std::forward< T >( value );
   }

private:
   std::string mValue;
};
