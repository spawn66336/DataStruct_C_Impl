#pragma once

#include "def.h"

typedef struct hString_s{
	char  *ch;
	int	  length;
}hString_t;


extern Status StrAssign( hString_t& s , char* chars );

extern Status DestroyString( hString_t& s );

extern int StrLength( const hString_t& s );

extern int StrCompare( const hString_t& lhs , const hString_t& rhs );

extern Status Concat( hString_t& finalStr , const hString_t& s1 , const hString_t& s2  );

extern Status SubString( const hString_t& s , const int pos , const int len , hString_t& subStr );

extern int Index( const  hString_t& s , const hString_t& t , const int pos );

extern Status Replace( hString_t& s , const hString_t& t , const hString_t& v );

extern Status StrInsert( hString_t& s , const int pos , const hString_t& t );

extern Status StrDelete( hString_t& s , const int pos , const int len );

extern void ShowStr( hString_t& s );

