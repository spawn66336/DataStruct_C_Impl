
#include "HString.h"
#include <string.h>
#include <stdio.h>

 Status StrAssign( hString_t& s , char* chars )
{
	int len = strlen(chars);
	s.ch = new char[len+1];
	memset( s.ch , 0 , len+1 );
	memcpy( s.ch , chars , len );
	s.length = len;
	return OK;
}

 Status DestroyString( hString_t& s )
{
	if( s.ch )
	{
		delete[] s.ch;
		s.ch = 0;
		s.length = 0;
		return OK;
	}
	return ERROR;
}

 int StrLength( const hString_t& s )
{
	return s.length;
}

 int StrCompare( const hString_t& lhs , const hString_t& rhs )
{
	for( int i = 0 ; i < lhs.length && i < rhs.length ; i++ )
	{
		if( lhs.ch[i] != rhs.ch[i] )
		{
			return lhs.ch[i] - rhs.ch[i];
		}
	}
	return lhs.length - rhs.length;
}

 Status Concat( hString_t& finalStr , const hString_t& s1 , const hString_t& s2 )
{
	if( finalStr.ch )
	{
		delete[] finalStr.ch;
		finalStr.ch = NULL;
		finalStr.length = 0;
	}

	finalStr.ch = new char[ s1.length + s2.length + 1 ];
	finalStr.length = s1.length + s2.length + 1;
	memset( finalStr.ch , 0 , finalStr.length );
	memcpy( finalStr.ch , s1.ch , s1.length );
	memcpy( &(finalStr.ch[s1.length]) , s2.ch , s2.length );
	return OK;
}

 Status SubString( const hString_t& s , const int pos , const int len , hString_t& subStr )
{
	if( pos < 0 || pos >= s.length || 
		pos + len > s.length || pos + len < 0 ||
		len == 0 )
	{
		return ERROR;
	}

	if( subStr.ch )
	{
		delete[] subStr.ch;
		subStr.ch = NULL;
		subStr.length = 0;
	}

	subStr.ch = new char[len+1];
	subStr.length = len;
	memset( subStr.ch , 0 , len+1 );
	memcpy( subStr.ch , &( s.ch[pos] ) , len );
	return OK;
}

 int Index( const hString_t& s , const hString_t& t , const int pos  )
{
	if( pos < 0 || pos >= s.length )
	{
		return -1;
	}

	for( int i = pos ; i < s.length ; i++ )
	{
		int j = 0;
		for( j = 0 ; j < t.length ; j++ )
		{
			if( s.ch[i+j] != t.ch[j] )
			{
				break;
			}
		}

		if( j == t.length )
		{
			return i;
		}
	}
	return -1;
}

 Status Replace( hString_t& s , const hString_t& t , const hString_t& v )
{
	if( NULL == s.ch )
	{
		return ERROR;
	}

	int currSearchPos = 0;
	int i = 0;
	while(  ( i = Index( s , t , currSearchPos ) ) != -1 )
	{
		//É¾³ý×Ö·û´®t
		StrDelete( s , i , t.length );
		//²åÈëÓ¦Ìæ»»µÄ×Ö·û
		StrInsert( s , i , v );

		currSearchPos = i + v.length;
	}

	return OK;
}

 Status StrInsert( hString_t& s , const int pos , const hString_t& t )
{
	if(  NULL == s.ch )
	{
		return ERROR;
	}

	if( pos < 0 || pos > s.length )
	{
		return ERROR;
	}


	char* newStr = new char[ s.length + t.length + 1];
	if( NULL == newStr ) return OVERFLOW;
	memset( newStr, 0 , s.length + t.length + 1);
	memcpy( newStr , s.ch , pos );
	memcpy( &newStr[pos] , t.ch , t.length );
	memcpy( &newStr[pos+t.length] , &(s.ch[pos]) , s.length - pos );

	delete[] s.ch;
	s.ch = newStr;
	s.length += t.length;

	return OK;
}

 Status StrDelete( hString_t& s , const int pos , const int len )
{
	if( pos < 0 || pos >= s.length )
	{
		return ERROR;
	}

	if( pos+len < 0 || pos+len >s.length )
	{
		return ERROR;
	}

	int j = pos;
	for( int i = pos+len , j = pos  ; i < s.length ; i++ , j++ )
	{
		s.ch[j] = s.ch[i];
	}
	s.ch[s.length-len] = 0;
	s.length -= len;
	return OK;
}

 void ShowStr( hString_t& s )
 {
	 printf( "%s" , s.ch );
 }
