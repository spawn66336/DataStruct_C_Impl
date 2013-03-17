#pragma once

#include "LinkList.h"
#include "DuLinkList.h"
#include "SqList.h"

/*
	例2-24: 写一算法将单链表（带头节点）中值重复的节点删除，使表中节点的值均不相同
*/
Status ClearSameElem( LinkList L );

/*
  例2-25:  假设某循环单链表非空，且无表头节点也无表头指针，指针p指向该链表中的某节点。
				请设计一个算法，将p所指节点的后继节点变为p所指节点的前驱节点。
*/
void Adjust( LinkList& p);

/*
	例2-26
*/

void Locate( DuLinkList& L , const ElemType& e );

/*
   例2-27： 已知两个按元素值递增的链表A和B,设计一算法利用原表结点空间形成两个新链表
				A'和B' 使得 A'=AUB  B'=A交B

				假设传入的是“带头结点的单链表”
*/

void MergeList( LinkList& La , LinkList& Lb );

/*
	例2-28： 若一个具有n个正整数的线性表，采用以head 为头指针的不带头结点的单链表环
					作为存储结构，请编写求指向单链表元素值最大的结点的前驱结点的指针front
					及求指向单链表中元素值最大结点的后继结点的指针rear的算法。
*/
void Biggest( LinkList head , LinkList& front , LinkList& rear );

/*
   例2-29：已知一个线性链表的数据元素为整型，试写一个算法将该链表分割为两个单循环链表，其中一个仅包含偶数元素
				，另一个包含奇数元素。
*/
void Division( LinkList& L , LinkList& La , LinkList& Lb );

/*
	例2-30：设计一个将单循环链表逆置的算法函数
*/

void ReverseList( LinkList& L );

/*
	例2-31：已知顺序表有整数数组data 和整型变量 listlen ,前者下标变量从 0~ n ，用于
				  存放元素的值，其后者记录表中实际元素的个数，并已知data中的元素按从小到大
				  次序排列，设计算法以删除表中重复元素，并要求时间复杂度为O(n)。例如：对
				  表 {1,1,2,3,3,4,6,8,9,9} 执行结果为 { 1,2,3,4,6,8,9 }
*/

void DeleteSameEelems( SqList& L );


/*
	例2-32：设双链表结点结构为llink , data , rlink , 请设计算法将其中 P所指结点与其
					rlink所指结点位置互换的算法
*/