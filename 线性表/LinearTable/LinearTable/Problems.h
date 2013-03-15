#pragma once

#include "LinkList.h"
#include "DuLinkList.h"

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