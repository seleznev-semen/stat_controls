#include <traits.h>
#include <constants.h>
#include <types.h>
#include <tree_node/tree_node.h>

ITreeNode::ITreeNode( std::size_t children_count )
   : mChildren( children_count )
{}

ITreeNode::ITreeNode( const NodePtr& parent, const NodeArray& children )
   : mChildren( children )
   , mParent( parent )
{}

ITreeNode::ITreeNode( const NodePtr& parent, NodeArray&& children )
   : mChildren( std::move( children ) )
   , mParent( parent )
{}

ITreeNode::ITreeNode() = default;
ITreeNode::ITreeNode( const ITreeNode& ) = default;
ITreeNode::ITreeNode( ITreeNode&& ) = default;
ITreeNode& ITreeNode::operator=( const ITreeNode& ) = default;
ITreeNode& ITreeNode::operator=( ITreeNode&& ) = default;

const NodePtr& ITreeNode::Parent() const
{
   return mParent;
}

const NodeArray& ITreeNode::Children() const
{
   return mChildren;
}

