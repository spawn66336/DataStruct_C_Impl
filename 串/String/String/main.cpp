#include <iostream>
#include "HString.h"

using namespace std;

void StringTest(void)
{
	hString_t s1;
	hString_t s2;
	StrAssign( s1 , "hello");
	StrAssign( s2 , " world!");
	ShowStr( s1 );
	cout<<endl;
	StrInsert( s1 , s1.length , s2);
	ShowStr(s1);
	cout<<endl;

	hString_t s3;
	hString_t s4;
	hString_t s5;
	StrAssign(s3, "my\\name\\is\\zhangpeng!");
	StrAssign( s4 , "\\");
	StrAssign(s5 , " ");
	ShowStr(s3);
	cout<<endl;
	Replace( s3 , s4 , s5 );
	ShowStr(s3);
	cout<<endl;

	hString_t s6;
	hString_t s7;
	StrAssign( s6 , "zhangpeng");
	StrAssign(s7 , "caorui");
	Replace( s3 , s6 , s7);
	ShowStr(s3);
	cout<<endl;

	hString_t s8;
	StrAssign( s8 , "!");
	hString_t s9;
	StrAssign(s9 , "???");
	Replace( s3 , s8 , s9 );
	ShowStr( s3 );
	cout<<endl;

	cout<<"StrConcat ²âÊÔ"<<endl;
	hString_t s10;
	memset( &s10 , 0 , sizeof(s10) );
	Concat( s10 , s1 , s2);
	ShowStr( s10 );
	cout<<endl;
}

void main()
{
	StringTest();
}