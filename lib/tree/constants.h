#pragma once
#include<unordered_map>
#include<string>

namespace constants
{

constexpr std::size_t BINARY_NODE_CHILDREN_COUNT = 2;
constexpr std::size_t LEAF_NODE_CHILDREN_COUNT = 0;

static const std::unordered_map< std::string, std::size_t > FUNCTION_PARAMETER_COUNT
{
   { "isnull",    2 },
   { "abs",       1 },
   { "floor",     1 },
   { "sum",       1 },
   { "round",     3 },
   { "nullif",    2 },
   { "coalesce",  999 }
};

std::size_t DefineParametersCount( const std::string& function_name );

} // namespace constants
