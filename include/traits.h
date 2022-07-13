#pragma once
#include <type_traits>
#include <string>

template< typename T >
using remove_const_reference_t =  std::remove_const_t< std::remove_reference_t< T > >;

template< typename S >
constexpr bool is_string_trait = std::is_constructible< std::string, remove_const_reference_t< S > >::value;

template< typename S >
using StringT = std::enable_if_t< is_string_trait< S > >;

template< typename I >
constexpr bool is_int_trait = std::is_same< remove_const_reference_t< I >, std::size_t >::value
                           || std::is_same< remove_const_reference_t< I >, int >:: value;

template< typename I >
using IntT = std::enable_if_t< is_int_trait< I > >;

template< typename T >
constexpr bool is_numeric_trait = std::is_same< int, std::remove_reference_t< T > >::value
                               ||std::is_same< double, std::remove_reference_t< T > >::value;

template< typename T >
using NumericT = std::enable_if_t< is_numeric_trait< T > >;




/// Type Deducer
template< typename T >
struct TD
{
   TD() = delete;
};
