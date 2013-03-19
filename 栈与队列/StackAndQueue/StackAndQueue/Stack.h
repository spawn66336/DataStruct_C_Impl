#pragma once
#include "def.h"

#define STACK_INIT_SIZE 100
#define STACK_INC_SIZE 10

typedef struct {
	ElemType* base;
	ElemType* top;
	int			stacksize;
}SqStack;

extern Status InitStack_Sq( SqStack& S );
extern Status DestroyStack_Sq( SqStack& S);
extern Status ClearStack_Sq( SqStack& S );
extern Status StackEmpty_Sq( SqStack& S );
extern int	   StackLength_Sq( SqStack& S );
extern Status GetTop_Sq( SqStack& S , ElemType& e );
extern Status Push_Sq( SqStack& S , ElemType& e );
extern Status Pop_Sq( SqStack& S , ElemType& e );
extern Status StackTraverse_Sq( SqStack& S , PFVISIT visit );