
#include "SqList.h"
#include <iostream>
#include <conio.h>
#include "LinkList.h"
#include "SLinkList.h"
#include "DuLinkList.h"
#include "Problems.h"

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
	//LinkList l = NULL;
	//
	//if( OK == InitList_L(l) )
	//{
	//	int input = 0;
	//	int insert_pos = 0;
	//	int c = 0; 
	//	cout<<"开始构建队列!"<<endl;
	//	while( c != 'q' ){
	//		cout<<"请输入插入的数据:";
	//		cin>>input; 
	//		cout<<"请输入插入位置:";
	//		cin>>insert_pos;
	//		if( OK != ListInsert_L(l,insert_pos,input) )
	//		{
	//			cout<<"插入失败!!!"<<endl;
	//		}
	//		cout<<"list :";
	//		ListTraverse_L( l , Visit_Print );
	//		cout<<endl;
	//		cout<<"len="<<ListLength_L(l)<<" "; 
	//		cout<<"按q退出~!"<<endl;
	//		c = _getch();
	//	}

	//	ClearSameElem(l);

	//	cout<<"list :";
	//	ListTraverse_L( l , Visit_Print );
	//	cout<<endl;

	//	DestroyList_L(l);
	//} 

	/*LinkList La = NULL;
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
	DestroyList_L(Lc);*/


	LinkList La = NULL;
	LinkList Lb = NULL;

	InitList_L( La );
	InitList_L( Lb );

	for( int i = 1 ; i <=20 ; i++ )
	{
		ListInsert_L(La , i , i );
	}
	cout<<"La: ";
	ListTraverse_L(La , Visit_Print );
	cout<<endl;

	for( int j = 10 ; j <= 30 ; j++ )
	{
		ListInsert_L( Lb , ListLength_L(Lb)+1 , j );
	}
	cout<<"Lb: ";
	ListTraverse_L( Lb , Visit_Print );
	cout<<endl;

	MergeList( La , Lb);

	cout<<"AUB: ";
	ListTraverse_L( La , Visit_Print );
	cout<<endl;

	cout<<"AnB: ";
	ListTraverse_L( Lb , Visit_Print );
	cout<<endl;
	 


	DestroyList_L(La);
	DestroyList_L(Lb);
}

void SLinkList_Test()
{ 

	int L = 0;
	InitSpace_SL();

	int La  = 0;
	int Lb = 0;
	int Lc  = 0;

	InitList_SL(La);
	InitList_SL(Lb);
	InitList_SL(Lc);

	for( int i = 0 ; i < 20 ; i++ )
	{
		ListInsert_SL(La,i+1,i+1);
	}
	cout<<"list a:";
	ListTraverse_SL(La , Visit_Print );
	cout<<endl;

	for( int j = 5 , k =0 ; j < 30 ; j++ , k++ )
	{
		ListInsert_SL(Lb,(k+1), j+1);
	}
	cout<<"list b:";
	ListTraverse_SL(Lb , Visit_Print );
	cout<<endl;

	//MergeList_SL(La,Lb,Lc);
	//cout<<"list c:";
	//ListTraverse_SL(Lc , Visit_Print );
	//cout<<endl;


	int S = 0;
	Difference_SL(La,Lb,S);
	cout<<"list S:";
	ListTraverse_SL(S , Visit_Print );
	cout<<endl;

	DestroyList_SL(La);
	DestroyList_SL(Lb);
	DestroyList_SL(Lc);
	DestroyList_SL(S);

	//if( OK == InitList_SL(L) )
	//{
	//	int input = 0;
	//	int insert_pos = 0;
	//	int c = 0;

	//	while( c != 'q' )
	//	{ 
	//			cout<<"请输入插入的数据:";
	//			cin>>input; 
	//			cout<<"请输入插入位置:";
	//			cin>>insert_pos;
	//			if( OK != ListInsert_SL(L ,insert_pos,input) )
	//			{
	//				cout<<"插入失败!!!"<<endl;
	//			}
	//			cout<<"list :";
	//			ListTraverse_SL( L , Visit_Print );
	//			cout<<endl;
	//			cout<<"len="<<ListLength_SL(L)<<endl;
	//			cout<<"pool capacity="<<GetCapacity_SL()<<endl;
	//			cout<<"alloc size="<<GetAllocSize_SL()<<endl;
	//			cout<<"按q退出~!"<<endl;
	//			c = getch(); 
	//	}
	//	DestroyList_SL(L);
	//}
}

void DuLinkList_Test(void)
{
	//DuLinkList L;
	//memset( &L , 0 , sizeof(L) );

	//InitList_DuL(L);

	//for( int i = 0 ; i < 20 ; i++ )
	//{
	//	LP_DuLNode new_node = NULL;
	//	MakeNode(new_node , i);
	//	Append_DuL( L , new_node );
	//} 

	//ListTraverse_DuL( L , Visit_Print );
	//DestroyList_DuL(L);

	//DuLinkList La;
	//DuLinkList Lb;
	//DuLinkList Lc;
	//memset( &La , 0 , sizeof(La) );
	//memset( &Lb , 0 , sizeof(Lb) );
	//memset( &Lc , 0 , sizeof(Lc) );

	//for( int i = 0 ; i < 20 ; i++ )
	//{
	//	LP_DuLNode new_node = NULL;
	//	MakeNode(new_node , i);
	//	Append_DuL( La , new_node );
	//}
	//cout<<"list a:";
	//ListTraverse_DuL( La , Visit_Print );
	//cout<<endl;

	//for( int i = 5 ; i < 30 ; i++ )
	//{
	//	LP_DuLNode new_node = NULL;
	//	MakeNode(new_node , i);
	//	Append_DuL( Lb , new_node );
	//}
	//cout<<"list b:";
	//ListTraverse_DuL( Lb , Visit_Print );
	//cout<<endl;

	//MergeList_DuL( La , Lb , Lc , Compare );

	//cout<<"list c:";
	//ListTraverse_DuL( Lc , Visit_Print );
	//cout<<endl;

	//DestroyList_DuL(La);
	//DestroyList_DuL(Lb);
	//DestroyList_DuL(Lc);

	DuLinkList L;
	memset( &L , 0 , sizeof(L) );
	InitList_DuL(L);

	for( int i = 1 ; i <= 20 ; i++ )
	{
		LP_DuLNode p = NULL; 
		MakeNode(p,i);
		Append_DuL(L,p);
	}
	ListTraverse_DuL(L , Visit_Print );
	cout<<endl;

	for( int i = 1 ; i<= 10 ; i++ )
	{
		Locate( L , 7 );
	}

	for( int i = 1 ; i <= 9 ; i++ )
	{
		Locate( L , 6 );
	}

	for( int i = 1 ; i <= 8 ; i++ )
	{
		Locate( L , 5);
	}
	ListTraverse_DuL(L , Visit_Print );
	cout<<endl;

	DestroyList_DuL(L);
}

void CLinkList_Test(void)
{
	LinkList L = NULL;
	InitList_CL(L);
	for( int i = 1 ; i <= 20 ; i++ )
	{
		ListInsert_CL( L , i , i );
	}
	ListTraverse_CL( L , Visit_Print );
	cout<<endl;

	LinkList p = L->next;
	for( int i = 1 ; i <= 5 ; i++ )
	{
		p = p->next;
	}
	Adjust(p);
	ListTraverse_CL( L , Visit_Print );
	cout<<endl;
	DestroyList_CL(L);
}

void LinkList_NoHead_Test(void)
{
	LinkList L;
	InitList_CLNH(L);

	for( int i = 1 ; i <= 20 ; i++ )
	{
		ListInsert_CLNH( L , i , i );
	}
	cout<<"L : ";
	ListTraverse_CLNH( L , Visit_Print );
	cout<<endl;

	ReverseList( L );
	cout<<"逆序 L : ";
	ListTraverse_CLNH( L , Visit_Print );
	cout<<endl;

	DestroyList_CLNH(L);

}

void Problem_Test(void)
{
	SqList L;
	int test_data[] = { 1,1,2,3,3,4,6,8,9,9 };
	memset( &L , 0 , sizeof(L) );
	InitList_Sq(L);

	for( int i = 0 ; i < sizeof(test_data)/4 ; i++ )
	{
		ListInsert_Sq( L , i+1 , test_data[i] );
	}
	cout<<"L 紧缩前: ";
	ListTraverse_Sq( L , Visit_Print );
	cout<<endl;
	
	DeleteSameEelems( L);

	cout<<"L 紧缩后: ";
	ListTraverse_Sq( L , Visit_Print );
	cout<<endl;

	DestroyList_Sq(L);
}

void main()
{
	//SqList_Test();
	//LinkList_Test();
	//CLinkList_Test();
	//SLinkList_Test();
	//DuLinkList_Test();
	//LinkList_NoHead_Test();
	Problem_Test();
}