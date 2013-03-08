#pragma once

#include <stdio.h>
#include <memory.h>

#define NULL 0
#define TRUE   1
#define FALSE  0
#define OK       1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2

#define ElemType int

typedef int Pos;
typedef int Status;

#define L_GREATER_R  -1
#define L_EQUAL_R       0
#define L_LESS_R          1
typedef int (*PFCOMPARE)(const ElemType& lhs , const ElemType& rhs );

#define VISIT_BREAK 0
#define VISIT_CONTINUE 1
typedef int (*PFVISIT)(const ElemType& e );


extern int Compare( const ElemType& lhs , const ElemType& rhs );
extern int Visit_Print( const ElemType& e );

