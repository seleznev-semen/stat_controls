#pragma once
#include <memory>
#include <list>

#include <types.h>
#include <tree/tree_node/tree_node.h>
#include <tree/tree_node/scalar_node.h>
#include <tree/tree_node/element_node.h>
#include <tree/tree_node/element_coord/elem_coord.h>

enum class LexemeType;

class ITreeNode;
using NodePtr = std::shared_ptr< ITreeNode >;
using NodeList = std::list< NodePtr >;

class ScalarNode;

class ElementNode;
template< typename ValT > class CoordRange;
// TODO может содержать знак "*" - т.е. для все перечисления для текущей координаты
// Список перечислений по координатам row и col
using CoordType = std::list< CoordRange< std::size_t > >;
// Список специфик правила
using FilterType = std::list< CoordRange< std::string > >;
class ElemCoord;
