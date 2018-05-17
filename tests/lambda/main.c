#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lambda.h"

typedef int (*add_ret)(int);

add_ret	add(int a)
{
	MAKE_CAP(shr, {
		int a;
	});

	shr->a = a;
	void *fct = LAMBDA(int, (int b, LAMBDA_CAP(shr)) {
		return shr->a + b;
	});
	return create_caller(shr, fct, 1);
} 

int main()
{
	int (*ah)(int) LAMBDA_CLEANUP = add(10);
	int (*ahh)(int) LAMBDA_CLEANUP = add(12);	

	printf("res = %d\n", ah(50));
	printf("res = %d\n", ahh(53));
	return (0);
}