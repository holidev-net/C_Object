/*
** EPITECH PROJECT, 2017
** C_Object
** File description:
** lambda.h
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