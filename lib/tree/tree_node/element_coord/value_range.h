#pragma once
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

using CoordRange = ValueRange< std::size_t >;
using FilterRange = ValueRange< std::string >;

class CoordType
{
   using storage_t = std::list< CoordRange >;

public:
   CoordType( std::initializer_list< CoordRange > init_list )
      : mCoord{ init_list }
   {}

   CoordType( const CoordRange& coord )
      : mCoord{ coord }
   {}

   CoordType( CoordRange&& coord )
      : mCoord{ std::move( coord ) }
   {}

   CoordType( std::size_t coord )
      : mCoord{ CoordRange( coord ) }
   {}

   CoordType( std::size_t lhs_lim, std::size_t rhs_lim )
      : mCoord{ CoordRange( lhs_lim, rhs_lim ) }
   {}

   CoordType() = default;
   CoordType( const CoordType& ) = default;
   CoordType( CoordType&&  ) = default;
   CoordType& operator=( const CoordType& ) = default;
   CoordType& operator=( CoordType&& ) = default;

   inline const storage_t& Get() const
   {
      return mCoord;
   }
private:
   storage_t mCoord;
};

class FilterType
{
   using storage_t = std::list< FilterRange >;

public:
   FilterType( std::initializer_list< FilterRange > init_list )
      : mFilter{ init_list }
   {}

   FilterType( const FilterRange& filter )
      : mFilter{ filter }
   {}

   FilterType( FilterRange&& filter )
      : mFilter{ std::move( filter ) }
   {}

   template < typename T, typename = StringT< T > >
   FilterType( T&& filter )
      : mFilter{ FilterRange( std::forward< T >( filter ) ) }
   {}

   template < typename T, typename = StringT< T >,
              typename U, typename = StringT< U > >
   FilterType( T&& lhs_lim, U&& rhs_lim )
      : mFilter{ FilterRange( std::forward< T >( lhs_lim ), std::forward< U >( rhs_lim ) ) }
   {}

   FilterType() = default;
   FilterType( const FilterType& ) = default;
   FilterType( FilterType&&  ) = default;
   FilterType& operator=( const FilterType& ) = default;
   FilterType& operator=( FilterType&& ) = default;

   inline const storage_t& Get() const
   {
      return mFilter;
   }

private:
   std::list< FilterRange > mFilter;
};

///////////////////////////////////////////////////////////////////////////
