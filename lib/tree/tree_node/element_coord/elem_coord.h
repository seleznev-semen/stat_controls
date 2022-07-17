#pragma once
#include <string>
#include <list>

#include <traits.h>
#include <tree_node/element_coord/value_range.h>

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
         typename FilterT = FilterType,
         typename = std::enable_if_t< std::is_same_v< FilterType, std::remove_reference_t< FilterT > > >
       >
   ElemCoord( std::size_t section, RowCoordT&& rows, ColCoordT&& cols, FilterT&& filters = FilterT() )
      : mSection( section )
      , mRows( std::forward< RowCoordT >( rows ) )
      , mColumns( std::forward< ColCoordT >( cols ) )
      , mFilters( std::forward< FilterT >( filters ) )
   {}

   ElemCoord( std::size_t section, std::size_t row, std::size_t col, const std::string& filter = std::string( "" )  )
      : mSection  ( section )
      , mRows     ( row )
      , mColumns  ( col )
   {
      if( !filter.empty() )
         mFilters = FilterType( filter );
   }

   ElemCoord() = default;
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



