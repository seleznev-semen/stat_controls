#pragma once

#include <tree_node/tree_node.h>
#include <traits.h>
#include <constants.h>

class LogicNode : public ITreeNode
{
public:
   template< typename T, typename = StringT< T > >
   LogicNode( T&& value )
      : ITreeNode( constants::BINARY_NODE_CHILDREN_COUNT )
      , mValue( std::forward< T >( value ) )
   {}

   LogicNode() = default;
   LogicNode( const LogicNode& other ) = default;
   LogicNode( LogicNode&& other ) = default;
   LogicNode& operator=( const LogicNode& other ) = default;
   LogicNode& operator=( LogicNode&& other ) = default;

   template< typename T, typename = StringT< T > >
   inline void Set( T&& value )
   {
      mValue = std::forward< T >( value );
   }

private:
   std::string mValue;
};
