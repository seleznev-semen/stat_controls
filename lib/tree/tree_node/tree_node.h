#pragma once
#include <vector>
#include <memory>


class ITreeNode;
using NodePtr   = std::shared_ptr< ITreeNode >;
using NodeArray = std::vector< NodePtr >;

class ITreeNode
{
public:
   ITreeNode( std::size_t children_count );

   ITreeNode( const NodePtr& parent, const NodeArray& children );

   ITreeNode( const NodePtr& parent, NodeArray&& children );

   ITreeNode();
   ITreeNode( const ITreeNode& other );
   ITreeNode( ITreeNode&& other );
   ITreeNode& operator=( const ITreeNode& other );
   ITreeNode& operator=( ITreeNode&& other );
   
   inline const NodePtr& Parent() const;
   
   inline const NodeArray& Children() const;

   void SetParent( const NodePtr& new_parent );
   void SetParent( NodePtr&& new_parent );

   void AddChildren( const NodeArray& children );
   void AddChildren( NodeArray&& children );

   void AddChild( const NodePtr& new_child );
   void AddChild( NodePtr&& new_child );

protected:
   NodeArray mChildren;
   NodePtr mParent;
};





