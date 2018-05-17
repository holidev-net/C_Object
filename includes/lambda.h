/*
 * --------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <benjamin.viguier@epitech.eu> wrote this file. As long as you retain this 
 * notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in
 * return Benjamin Viguier
 * --------------------------------------------------------------------------
 */

#pragma once

#include <stdlib.h>
#include "cobject.h"

#define LAMBDA(ret, body) ({ret __lbd__ body __lbd__;})
#define MAKE_CAP(name, body) struct cap_s body *name = malloc(sizeof(*name))
#define LAMBDA_CAP(name) struct cap_s *name
#define LAMBDA_CLEANUP	__attribute__((cleanup(__free_lamdba)))

void	free_lambda(void *lbd)
{
	free(get_capture(lbd));
	free_caller(lbd);
}

void	__free_lamdba(void *lbd)
{
	free_lambda(*((void**) lbd));
}