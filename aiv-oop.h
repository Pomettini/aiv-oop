#ifndef AIV_OOP_H
#define AIV_OOP_H

#include <stdlib.h>

#define VMETHOD(name) void(*name)()
#define EVENT(name) void(*name)(void*)
#define ARG(name) (void*)name
#define NEW(type) (type*)malloc(sizeof(type))
#define DELETE(this) free(this)

#endif