#pragma once
#include <tree/tree_node/tree_node.h>
#include <tree/tree_node/element_coord/elem_coord.h>
#include <forward_types.h>

class ElementNode : public ITreeNode
{
public:
   ElementNode( const ElemCoord& position )
      : ITreeNode()
      , mPosition( position )
   {}

   ElementNode( ElemCoord&& position )
      : ITreeNode()
      , mPosition( std::move( position ) )
   {}

   ElementNode( const ElementNode& other ) = default;
   ElementNode( ElementNode&& other ) = default;
   ElementNode& operator=( const ElementNode& other ) = default;
   ElementNode& operator=( ElementNode&& other ) = default;

   void SetPosition( const ElemCoord& position )
   {
      mPosition = position;
   }

   void SetPosition( ElemCoord&& position )
   {
      std::swap( mPosition, position );
   }

private:
   ElemCoord mPosition;
};
