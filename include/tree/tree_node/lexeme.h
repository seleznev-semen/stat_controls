#pragma once

#include <memory>

#include "elem_coord.h"
#include "../constants.h"
#include "../../types/types.h"

///////////////////////////////////////////////////////////////////////////
/// base lexeme interface

/** lexeme interface **/
class ILexeme
{
public:
	virtual LexemeType GetType() = 0;
};

using LexemePtr = std::shared_ptr< ILexeme >;

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
/// scalar lexeme

template< typename T >
constexpr bool is_scalar_trait = std::is_same< int, std::remove_reference_t< T > >::value
										||	std::is_same< double, std::remove_reference_t< T > >::value
										|| std::is_same< std::string, std::remove_reference_t< T > >::value;

template< typename T >
using ScalarT = std::enable_if_t< is_scalar_trait< T > >;

class ScalarLexeme : public ILexeme
{
public:
   template< typename ST, typename = ScalarT< ST > >
	ScalarLexeme( const ST& value )
	{
		if constexpr( std::is_same< std::string, std::remove_reference< ST > >::value )
			mValue = value;
		else
			mValue = std::to_string( value );
	}
	
	template< typename ST, typename = ScalarT< ST > >
	ScalarLexeme( ST&& value )
	{
		if constexpr( std::is_same< std::string, std::remove_reference< ST > >::value )
			mValue = std::move( value );
		else
			mValue = std::to_string( value );
	}
	
	virtual LexemeType GetType() override;

private:
	std::string	mValue;
};

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
/// element lexeme 

class ElementLexeme : public ILexeme
{
public:
	ElementLexeme( const ElemCoord& elem_coord )
		: mElemCoord( elem_coord )
	{}

	ElementLexeme( ElemCoord&& elem_coord )
		: mElemCoord( std::move( elem_coord ) )
	{}

	virtual LexemeType GetType() override;

private:
	ElemCoord mElemCoord;		
};

///////////////////////////////////////////////////////////////////////////
// aritetic lexeme

class ArithmeticLexeme : public ILexeme
{
public:
	ArithmeticLexeme( const std::string& value )
		: mValue( value )
	{}
	
	ArithmeticLexeme( std::string&& value )
		: mValue( std::move( value ) )
	{}
		
	virtual LexemeType GetType() override;

private:
	std::string	mValue;
};

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
/// boolean lexeme

class BooleanLexeme : public ILexeme 
{
public:
	BooleanLexeme( const std::string& value )
		: mValue( value )
	{}
	
	BooleanLexeme( std::string&& value )
		: mValue( std::move( value ) )
	{}
		
	virtual LexemeType GetType() override;

private:
	std::string	mValue;
};

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/// function lexeme

class FunctionLexeme : public ILexeme 
{
public:
   FunctionLexeme( const std::string& function_name )
      : mValue( function_name )
      , mParametersCount( constants::DefineParametersCount( function_name ) )
   {}
   
	virtual LexemeType GetType() override;

private:
	std::string	mValue;
   size_t mParametersCount;
};

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/// function lexeme

class SumLexeme : public ILexeme 
{
public:
   SumLexeme( bool is_expression )
      : mIsExpression( is_expression ) 
   {}

	virtual LexemeType GetType() override;

private:
   bool mIsExpression;
};

///////////////////////////////////////////////////////////////////////////







 
