
#ifndef __ENTITY_H__

#include "../functions/update.h"

typedef struct
{
	UpdateFunction update;
} Entity;

typedef struct
{
	Entity entity;
	char* name;
	unsigned int nameLen;
} NamedEntity;

#define __ENTITY_H__
#endif
