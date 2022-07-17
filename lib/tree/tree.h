#pragma once

#include <tree_node/tree_node.h>

class StatAST
{
public:
   void AddNode( const NodePtr& node )
   {
      if( mRoot == nullptr )
         mRoot = node;
   }

   inline const NodePtr& Root() const
   {
      return mRoot;
   }


private:
   NodePtr mRoot;
};
