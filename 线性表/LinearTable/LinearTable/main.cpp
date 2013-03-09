
#include "SqList.h"
#include <iostream>
#include <conio.h>
#include "LinkList.h"

using namespace std;

void SqList_Test(void)
{
	SqList sq_list;
	memset( &sq_list , 0 , sizeof(sq_list));

	if( OK == InitList_Sq(sq_list) )
	{
		//int input = 0;
		//int c = 0; 
		//cout<<"开始构建队列!"<<endl;
		//while( c != 'q' ){
		//	cout<<"请输入插入的数据:";
		//	cin>>input;
		//	ListInsert_Sq( sq_list , ListLength_Sq(sq_list)+1 , input );
		//	cout<<"list :";
		//	ListTraverse_Sq( sq_list , Visit_Print );
		//	cout<<endl;
		//	cout<<"len="<<sq_list.len<<" ";
		//	cout<<"capacity="<<sq_list.capacity<<endl; 
		//	cout<<"按q退出~!"<<endl;
		//	c = getch();
		//}

		//c = 0;
		//cout<<"删除队列元素!"<<endl;
		//while( c != 'q' ){
		//	cout<<"输入要删除的元素"<<1<<"~"<<sq_list.len<<endl;
		//	cin>>input;
		//	ElemType del_e = 0;
		//	if( OK == ListDelete_Sq(sq_list,input,del_e) )
		//	{
		//		cout<<"删除成功!"<<endl;
		//	}else{
		//		cout<<"删除失败!"<<endl;
		//	} 
		//	cout<<"list :";
		//	ListTraverse_Sq( sq_list , Visit_Print );
		//	cout<<endl;
		//	cout<<"len="<<sq_list.len<<" ";
		//	cout<<"capacity="<<sq_list.capacity<<endl; 
		//	cout<<"按q退出~!"<<endl;
		//	c = getch();
		//}
		//DestroyList_Sq(sq_list); 
	}else{
		cout<<"初始化静态表失败!"<<endl;
	}

	SqList list_a;
	SqList list_b;
	SqList list_c; 
	memset( &list_a , 0 , sizeof(list_a));
	memset( &list_b , 0 , sizeof(list_b));
	memset( &list_c  , 0 , sizeof(list_c)); 

	InitList_Sq(list_a);
	InitList_Sq(list_b);  

	for( int i = 0 ; i < 20 ; i++ )
	{
		ListInsert_Sq( list_a , list_a.len+1 , i+1);
	}
	ListTraverse_Sq( list_a , Visit_Print );
	cout<<endl;
	for( int j = 3 ; j < 30 ; j++ )
	{
		ListInsert_Sq(list_b , list_b.len+1 , j+1 ); 
	}
	ListTraverse_Sq( list_b , Visit_Print );
	cout<<endl;

	MergeList_Sq( list_a , list_b , list_c);

	ListTraverse_Sq( list_c , Visit_Print );
	cout<<endl;

	DestroyList_Sq(list_a);
	DestroyList_Sq(list_b);
	DestroyList_Sq(list_c);
}

void LinkList_Test(void)
{
	LinkList l = NULL;
	
	if( OK == InitList_L(l) )
	{
		int input = 0;
		int insert_pos = 0;
		int c = 0; 
		cout<<"开始构建队列!"<<endl;
		while( c != 'q' ){
			cout<<"请输入插入的数据:";
			cin>>input; 
			cout<<"请输入插入位置:";
			cin>>insert_pos;
			if( OK != ListInsert_L(l,insert_pos,input) )
			{
				cout<<"插入失败!!!"<<endl;
			}
			cout<<"list :";
			ListTraverse_L( l , Visit_Print );
			cout<<endl;
			cout<<"len="<<ListLength_L(l)<<" "; 
			cout<<"按q退出~!"<<endl;
			c = getch();
		}
		DestroyList_L(l);
	} 

	LinkList La = NULL;
	LinkList Lb = NULL;
	LinkList Lc  = NULL;

	InitList_L(La);
	InitList_L(Lb);
	InitList_L(Lc);

	for( int i = 0 ; i < 20 ; i++ )
	{
		ListInsert_L( La , i+1 , i+1);
	}
	cout<<"list:";
	ListTraverse_L( La , Visit_Print );
	cout<<endl;

	for( int j = 4 ; j < 40 ; j++ )
	{
		ListInsert_L( Lb , ListLength_L(Lb)+1  , j );
	}
	cout<<"list:";
	ListTraverse_L( Lb , Visit_Print );
	cout<<endl;

	MergeList_L(La,Lb,Lc);

	cout<<"list:";
	ListTraverse_L( Lc , Visit_Print );
	cout<<endl;

	DestroyList_L(La);
	DestroyList_L(Lb);
	DestroyList_L(Lc);
}

void main()
{
	//SqList_Test();
	LinkList_Test();
}