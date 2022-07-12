#pragma once
#include <tree/tree_node/tree_node.h>
#include <traits.h>

class ScalarNode : public ITreeNode
{
public:
   template< typename T, typename = NumericT< T > >
   ScalarNode( T value )
      : ITreeNode()
      , mValue( std::to_string( value ) )
   {}

   template< typename T, typename = StringT< T > >
   ScalarNode( const T& value )
      : ITreeNode()
      , mValue( value )
   {}

   template< typename T, typename = StringT< T > >
   ScalarNode( T&& value )
      : ITreeNode()
      , mValue( std::forward( value ) )
   {}

   ScalarNode( const ScalarNode& other ) = default;
   ScalarNode( ScalarNode&& other ) = default;
   ScalarNode& operator=( const ScalarNode& other ) = default;
   ScalarNode& operator=( ScalarNode&& other ) = default;

private:
   std::string mValue;
};
