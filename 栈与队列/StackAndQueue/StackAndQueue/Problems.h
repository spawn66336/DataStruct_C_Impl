#pragma once
#include "T_Stack.h"

enum E_EXP_ELEM_TYPE{
	TYPE_OPERATOR = 1,
	TYPE_OPERAND 
};
typedef struct {
	int type;    
	int elem;
	int weight;
}t_exp_elem;

extern bool SetExpElem( t_exp_elem& exp_elem ,  const int elem );

extern int ExpEvaluate(const t_exp_elem& optr , const  t_exp_elem& lhs , const t_exp_elem& rhs , t_exp_elem& rs );

extern bool IsExpElemLegal( const int elem );

extern int GrantExpWeight( t_exp_elem& exp_elem );

extern void Expression_Problem(void);