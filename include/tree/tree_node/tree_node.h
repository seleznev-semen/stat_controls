#pragma once
#include <forward_types.h>


class ITreeNode
{
public:
   ITreeNode()
		: mParent( nullptr )
      , mChildren( NodeList() )
	{}
	
   ITreeNode( const ITreeNode& other ) = default;
   ITreeNode( ITreeNode&& other ) = default;
   ITreeNode& operator=( const ITreeNode& other ) = default;
   ITreeNode& operator=( ITreeNode&& other ) = default;
   
   inline const NodePtr& GetParent() const
   {
      return mParent;
   }
   
   inline const NodeList& GetChildren() const
   {
      return mChildren;
   }

   void SetParent( const NodePtr& new_parent );
   void SetParent( NodePtr&& new_parent );

   void AddChildren( const NodeList& children );
   void AddChildren( NodeList&& children );

   void AddChildren( const NodeList& children );
   void AddChildren( NodeList&& children );

   void AddChild( const NodePtr& new_child );
   void AddChild( NodePtr&& new_child );

protected:
	NodePtr   mParent;
	NodeList mChildren;
};


