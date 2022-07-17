#pragma once

#include <tree_node/tree_node.h>
#include <traits.h>

class BooleanNode : public ITreeNode
{
public:
   template< typename T, typename = StringT< T > >
   BooleanNode( T&& value )
      : ITreeNode()
      , mValue( std::forward< T >( value ) )
   {}

   BooleanNode() = default;
   BooleanNode( const BooleanNode& other ) = default;
   BooleanNode( BooleanNode&& other ) = default;
   BooleanNode& operator=( const BooleanNode& other ) = default;
   BooleanNode& operator=( BooleanNode&& other ) = default;

   template< typename T, typename = StringT< T > >
   inline void Set( const T& value )
   {
      mValue = std::forward< T >( value );
   }

private:
   std::string mValue;
};
