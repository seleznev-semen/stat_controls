#pragma once

#include <string>

#include <forward_types.h>
#include <traits.h>

///////////////////////////////////////////////////////////////////////////
/// Перечисление координаты

template< typename ValT >
class CoordRange
{
public:
	template< typename VT, typename = StringT< VT > >
	CoordRange( const VT& lhs_lim, const VT& rhs_lim )	
		: mLhsLim( lhs_lim )
		, mRhsLim( rhs_lim )
	{}
	
	template< typename VT, typename = StringT< VT > >
	CoordRange( VT&& lhs_lim, VT&& rhs_lim )	
		: mLhsLim( std::move( lhs_lim ) )
		, mRhsLim( std::move( rhs_lim ) )
	{}

	template< typename VT, typename = IntT< VT > >
	CoordRange( VT lhs_lim, VT rhs_lim )
		: mLhsLim( lhs_lim )
		, mRhsLim( rhs_lim )
	{}

   template< typename VT, typename = StringT< VT > >
   CoordRange( const VT& single_coord )
      : mLhsLim( single_coord )
      , mRhsLim( single_coord )
   {}

   template< typename VT, typename = StringT< VT > >
   CoordRange( VT&& single_coord )
      : mLhsLim( std::move( single_coord ) )
      , mRhsLim( std::move( single_coord ) )
   {}

   template< typename VT, typename = IntT< VT > >
   CoordRange( VT single_coord )
      : mLhsLim( single_coord )
      , mRhsLim( single_coord )
   {}

private:
	ValT mLhsLim;
   ValT mRhsLim;
};

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/// Позиция элемента

class ElemCoord
{
public:
   template
      <
         typename RowCoordT,
         typename = enable_if_t< std::is_same_v< CoordType, std::remove_reference_t< RowCoordT > > > >,
         typename ColCoordT,
         typename = enable_if_t< std::is_same_v< CoordType, std::remove_reference_t< ColCoordT > > > >,
         typename FilterT,
         typename = enable_if_t< std::is_same_v< FilterType, std::remove_reference_t< FilterT > > > >
       >
   ElemCoord( std::size_t section, RowCoordT rows, ColCoordT cols, const FilterT filters = FilterT() )
      : mSection( section )
   {
      if constexpr( std::is_rvalue_reference< RowCoordT >::value )
         mRows = std::forward( rows );
      else
         mRows = rows;

      if constexpr( std::is_rvalue_reference< ColCoordT >::value )
         mCols = std::forward( cols );
      else
         mCols = cols;

      if constexpr( std::is_rvalue_reference< FilterT >::value )
         mFilters = std::forward( filters );
      else
         mFilters = filters;
   }

   ElemCoord( std::size_t section, std::size_t row, std::size_t col, const std::string& filter = L""  )
      : mSection  ( section )
      , mRows     ( CoordType{ row } )
      , mColumns  ( CoordType{ col } )
      , mFilters  ( filter.empty() ? FilterType() : FilterType{ filter } )
   {}

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



