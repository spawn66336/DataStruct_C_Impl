#pragma once

typedef int TElemType;

#define VISIT_CONTINUE 1
#define VISIT_BREAK 0

typedef int (*PFVISIT)( const TElemType& e );
 
extern int Visit_Print( const TElemType& e );
