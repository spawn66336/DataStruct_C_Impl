#pragma once

#include "LinkList.h"

/*
	��2-24: дһ�㷨����������ͷ�ڵ㣩��ֵ�ظ��Ľڵ�ɾ����ʹ���нڵ��ֵ������ͬ
*/
Status ClearSameElem( LinkList L );

/*
  ��2-25:  ����ĳѭ��������ǿգ����ޱ�ͷ�ڵ�Ҳ�ޱ�ͷָ�룬ָ��pָ��������е�ĳ�ڵ㡣
				�����һ���㷨����p��ָ�ڵ�ĺ�̽ڵ��Ϊp��ָ�ڵ��ǰ���ڵ㡣
*/
void Adjust( LinkList& p);