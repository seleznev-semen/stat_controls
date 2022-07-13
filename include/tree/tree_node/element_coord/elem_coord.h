#pragma once

#include <string>
#include <list>

#include <traits.h>

///////////////////////////////////////////////////////////////////////////
/// Перечисление координаты

template< typename ValT >
class ValueRange
{
public:	
	template< typename VT, typename = StringT< VT > >
   ValueRange( VT&& lhs_lim, VT&& rhs_lim )
      : mLhsLim( std::forward< VT >( lhs_lim ) )
      , mRhsLim( std::forward< VT >( rhs_lim ) )
	{}

   template< typename VT, typename = StringT< VT > >
   ValueRange( VT&& single_coord )
      : mLhsLim( std::forward< VT >( single_coord ) )
      , mRhsLim( std::forward< VT >( single_coord ) )
   {}

	template< typename VT, typename = IntT< VT > >
   ValueRange( VT lhs_lim, VT rhs_lim )
		: mLhsLim( lhs_lim )
		, mRhsLim( rhs_lim )
	{}

   template< typename VT, typename = IntT< VT > >
   ValueRange( VT single_coord )
      : mLhsLim( single_coord )
      , mRhsLim( single_coord )
   {}

private:
	ValT mLhsLim;
   ValT mRhsLim;
};

template< typename T >
auto ValueRangeFactory( T&& value )
{
   ValueRange< remove_const_reference_t< T > > result( std::forward< T >( value ) );
   return result;
}

template< typename T >
auto ValueRangeFactory( T&& lhs, T&& rhs )
{
   ValueRange< remove_const_reference_t< T > > result( std::forward< T >( lhs ), std::forward< T >( rhs ) );
   return result;
}

// Список перечислений по координатам row и col. TODO может содержать знак "*" - для всех перечислений по координате
using CoordRange = ValueRange< std::size_t >;
using CoordType = std::list< CoordRange >;

// Список специфик правила
using FilterRange = ValueRange< std::string >;
using FilterType = std::list< FilterRange >;

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/// Позиция элемента

class ElemCoord
{
public:
   template
      <
         typename RowCoordT,
         typename = std::enable_if_t< std::is_same_v< CoordType, std::remove_reference_t< RowCoordT > > >,
         typename ColCoordT,
         typename = std::enable_if_t< std::is_same_v< CoordType, std::remove_reference_t< ColCoordT > > >,
         typename FilterT,
         typename = std::enable_if_t< std::is_same_v< FilterType, std::remove_reference_t< FilterT > > >
       >
   ElemCoord( std::size_t section, RowCoordT&& rows, ColCoordT&& cols, FilterT&& filters = FilterT() )
      : mSection( section )
      , mRows( std::forward< RowCoordT >( rows ) )
      , mColumns( std::forward< ColCoordT >( cols ) )
      , mFilters( std::forward< FilterT >( filters ) )
   {}

   ElemCoord( std::size_t section, std::size_t row, std::size_t col, const std::string& filter = ""  )
      : mSection  ( section )
      , mRows     ( CoordType{ row } )
      , mColumns  ( CoordType{ col } )
   {
      if( !filter.empty() )
         FilterType{ ValueRangeFactory( filter ) };
   }

	ElemCoord( const ElemCoord& ) = default;
	ElemCoord( ElemCoord&& ) = default;
	ElemCoord& operator=( const ElemCoord& ) = default;
	ElemCoord& operator=( ElemCoord& ) = default;
	
	inline void SetSection();
	inline void SetRow();
	inline void SetColum();
	inline void SetSpecific();
	
private:
   std::size_t mSection;
	CoordType mRows;
	CoordType mColumns;
	FilterType mFilters;
};



