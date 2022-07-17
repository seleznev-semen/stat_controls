#pragma once
#include <tree_node/tree_node.h>
#include <tree_node/element_coord/elem_coord.h>
#include <constants.h>

class ElementNode : public ITreeNode
{
public:
   ElementNode( const ElemCoord& position )
      : ITreeNode( constants::LEAF_NODE_CHILDREN_COUNT )
      , mPosition( position )
   {}

   ElementNode( ElemCoord&& position )
      : ITreeNode( constants::LEAF_NODE_CHILDREN_COUNT )
      , mPosition( std::move( position ) )
   {}

   ElementNode() = default;
   ElementNode( const ElementNode& other ) = default;
   ElementNode( ElementNode&& other ) = default;
   ElementNode& operator=( const ElementNode& other ) = default;
   ElementNode& operator=( ElementNode&& other ) = default;

   inline void Set( const ElemCoord& position )
   {
      mPosition = position;
   }

   inline void Set( ElemCoord&& position )
   {
      std::swap( mPosition, position );
   }

private:
   ElemCoord mPosition;
};
