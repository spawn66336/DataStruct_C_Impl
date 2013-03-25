#include "Problems.h"
#include <conio.h>

bool SetExpElem( t_exp_elem& exp_elem , const int elem )
{
	if( IsExpElemLegal(elem) )
	{
		if( isdigit(elem) ) { 
			exp_elem.type = TYPE_OPERAND;
			exp_elem.elem = atoi( (char*)&elem );
		}else{
			exp_elem.type = TYPE_OPERATOR; 
			exp_elem.elem = elem;
		}
		exp_elem.weight = GrantExpWeight( exp_elem );
		return true;
	}
	return false;
}

int ExpEvaluate( const t_exp_elem& optr , const t_exp_elem& lhs , const t_exp_elem& rhs ,  t_exp_elem& rs )
{
	int ret = OK;
	switch( optr.elem )
	{
	case '+':
		rs.elem = lhs.elem + rhs.elem;
		break;
	case '-':
		rs.elem =  lhs.elem - rhs.elem;
		break;
	case '*':
		rs.elem = lhs.elem * rhs.elem;
		break;
	case '/':
		rs.elem = lhs.elem / rhs.elem;
		break;
	default:
		ret = ERROR;
		break;
	}
	return ret;
}


void Expression_Problem( void )
{
	T_Stack<t_exp_elem> OPTR;
	T_Stack<t_exp_elem> OPND;

	t_exp_elem e;
	SetExpElem( e ,'#' );
	OPTR.Push(e);

	
	while(1)
	{
		int input_c = getch();  

		t_exp_elem curr_e;
		if( !SetExpElem(curr_e , input_c) )
		{//该字符无意义 
			continue;
		}

		if( input_c != '#' )
		{
			putch(input_c);
		}

		t_exp_elem top_optr;
		OPTR.GetTop(top_optr); 

		 if( curr_e.type == TYPE_OPERATOR )
		 {
			 t_exp_elem lhs , rhs;
			 t_exp_elem rs;
			 SetExpElem( rs , '0');

			 if( curr_e.elem == '#' ) {

				 while( top_optr.elem != '#' )
				 {
					 //取左右操作数
					 if( 
						 OK == OPND.Pop(rhs) &&
						 OK == OPND.Pop(lhs)
						 )
					 { 
						 ExpEvaluate( top_optr , lhs , rhs , rs ); 

						 OPND.Push( rs );
						 OPTR.Pop( top_optr );
						 OPTR.GetTop( top_optr );
					 }else{
						 OPTR.Clear();
						 OPND.Clear();
						 cout<<"表达式错误！"<<endl;
					 } 
				 }

				 t_exp_elem final_val;
				 OPND.Pop(final_val);
				 cout<<"="<<final_val.elem<<endl;

			 } else if( curr_e.elem == ')' ) {

				 while(top_optr.elem != '(' )
				 {
					 //取左右操作数
					 if( 
						 OK == OPND.Pop(rhs) &&
						 OK == OPND.Pop(lhs)
						 )
					 { 
						 ExpEvaluate( top_optr , lhs , rhs , rs ); 

						 OPND.Push( rs );
						 OPTR.Pop( top_optr );
						 OPTR.GetTop( top_optr );
					 }else{
						 OPTR.Clear();
						 OPND.Clear();
						 cout<<"表达式错误！"<<endl;
					 } 
				 }
			 }else{ 

				 while( 
					 top_optr.weight >= curr_e.weight && 
					 top_optr.elem != '(' &&
					 top_optr.elem != '#'
					 )
				 {  
					 //取左右操作数
					if( 
						OK == OPND.Pop(rhs) &&
						OK == OPND.Pop(lhs)
						)
					{ 
						ExpEvaluate( top_optr , lhs , rhs , rs ); 
						OPND.Push( rs );
						OPTR.Pop( top_optr );
						OPTR.GetTop( top_optr );
					}else{
						OPTR.Clear();
						OPND.Clear();
						cout<<"表达式错误！"<<endl;
					}
				 }
				 OPTR.Push(curr_e);
			 }
		 }else{ //若为数字
			 OPND.Push( curr_e );
		 }
	}
}

int GrantExpWeight( t_exp_elem& exp_elem )
{
	int weight = 0;
	if( exp_elem.type == TYPE_OPERATOR )
	{
		switch( exp_elem.elem )
		{
		case '+': 
		case '-':
			weight = 2;
			break;
		case '*':
		case '/':
			weight = 3;
			break;
		case '(':
			weight = 1;
			break;
		case ')':
			weight = 4;
			break;
		case '#':
			weight = -1;
			break;
		}
	}

	return weight;
}

bool IsExpElemLegal( const int elem )
{
	if( isdigit(elem) )
	{
		return true;
	}

	if( 
		'#' == elem ||
		'/' == elem ||
		'+' == elem ||
		'-' == elem ||
		'*' == elem ||
		'(' == elem ||
		')' == elem 
		)
	{
		return true;
	}
	return false;
}

