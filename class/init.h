/*
** EPITECH PROJECT, 2017
** init.h for C_Object
** File description:
** description
*/

#pragma once

void *init_member(void *obj, void *func, int nb_args);
void delete_member(void *member);

#define delete(type, obj)	delete_##type(obj);
#define new(type)		init_##type();
