#pragma once
#include <memory>
#include <list>

#include <types.h>
#include <constants.h>
#include <tree_node/tree_node.h>
#include <tree_node/scalar_node.h>
#include <tree_node/element_node.h>
#include <tree_node/arithmetic_node.h>
#include <tree_node/boolean_node.h>
#include <tree_node/function_node.h>
#include <tree_node/logic_node.h>
#include <tree_node/tree_node_factory.h>
#include <tree_node/element_coord/elem_coord.h>
#include <tree_node/element_coord/value_range.h>


// TreeNode classes
class ITreeNode;
class ScalarNode;
class ElementNode;
class ArithmeticNode;
class BooleanNode;
class FunctionNode;
class LogicNode;

// Node generative class
class NodeFactory;

// Element coordinates included classes
class ElemCoord;
template< typename T > class ValueRange;
class CoordType;

using CoordRange = CoordRange;
using FilterRange = FilterRange;

enum class LexemeType;

// functions
static std::size_t DefineParametersCount( const std::string& function_name );
