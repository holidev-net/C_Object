#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lambda.h"

//#define CAPTURE(args...)


typedef int (*add_ret)(int);
typedef int (*test1_ret)(int);

int	(*tmp_g)(int, void*);

add_ret	add(int a)
{
	void *fct = LBD_1(int, 1, (int n1, struct cap_s *shr) {
		return shr->a + n1;
	}, a);
	return fct;
}

test1_ret	test1(int n1, int n2)
{
	void *fct = LBD_2(int, 1, (int a, struct cap_s *shr) {
		return shr->n1 + shr->n2 + a;
	}, n1, n2);
	return fct;
}

int main()
{
	add_ret ah LAMBDA_CLEANUP = add(10);
	test1_ret ahh LAMBDA_CLEANUP = test1(13, 10);

	int bla = 9;
	void (*fct)(int) LAMBDA_CLEANUP = LBD_1(void, 1, (int a, struct cap_s *shr) {
		printf("%d\n", shr->bla * a - 3);
	}, bla);

	fct(100);
	printf("res = %d\n", ah(50));
	printf("res = %d\n", ahh(53));
	return (0);
}