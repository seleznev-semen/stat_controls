#pragma once
#include <tree_node/tree_node.h>
#include <traits.h>
#include <constants.h>

class FunctionNode : public ITreeNode
{
public:
   template< typename T, typename = StringT< T > >
   FunctionNode( T&& value )
      : ITreeNode( constants::DefineParametersCount( value ) )
      , mValue( std::forward< T >( value ) )
   {}

   FunctionNode() = default;
   FunctionNode( const FunctionNode& other ) = default;
   FunctionNode( FunctionNode&& other ) = default;
   FunctionNode& operator=( const FunctionNode& other ) = default;
   FunctionNode& operator=( FunctionNode&& other ) = default;

   template< typename T, typename = StringT< T > >
   inline void Set( T&& value )
   {
      mValue = std::forward< T >( value );
   }

private:
   std::string mValue;
};
