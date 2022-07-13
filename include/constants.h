#pragma once

#include<unordered_map>
#include<string>

namespace constants
{

static const std::unordered_map< std::string, std::size_t > FUNCTION_PARAMETER_COUNT
{
   { "isnull",    2 },     //
   { "abs",       1 },     //
   { "floor",     1 },     //
   { "round",     3 },     //
   { "nullif",    2 },     //
   { "coalesce",  999 }      //
};

static std::size_t DefineParametersCount( const std::string& function_name );

} // namespace constants
