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

#define _1(a, ...) a
#define _2(a, b, ...) b
#define _3(a, b, c, ...) c
#define _4(a, b, c, d, ...) d

#define GET_NARG(_0, _1, _2, _3, _4, NB, ...) NB
#define COUNT_AV(...) GET_NARG(_0, ##__VA_ARGS__, 4, 3, 2, 1, 0)

#define BODY(...) GET_NARG(__VA_ARGS__)

#define LBD_0(ret, body) ({ret __lbd__ body __lbd__;})

#define LAMBDA_CLEANUP	__attribute__((cleanup(__free_lamdba)))

#include "lambda.t"