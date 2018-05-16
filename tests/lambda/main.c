#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lambda.h"

typedef int (*add_fct)(int);

add_fct	add(int a)
{
	MAKE_CAP(shr, {int a;});

	shr->a = a;
	void *fct = LAMBDA(int, (int b, LAMBDA_CAP(shr)) {
		return shr->a + b;
	});
	return create_caller(shr, fct, 1);
} 

int main()
{
	int (*ah)(int) = add(10);
	int (*ahh)(int) = add(12);	

	printf("res = %d\n", add(10)(50));
	printf("res = %d\n", ahh(53));

	free_lambda(ah);
	free_lambda(ahh);
	return (0);
}