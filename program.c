
// #include <stdlib.h>
#include <stdio.h>
#include "entity/entitymanager.h"

void dot(Entity entity)
{
	printf("[dot] ");

	if (entity.update != NULL)
	{
		entity.update(&entity);
	}
	else
	{
		printf("Entity::update not set.");
	}

	printf("\n");
}

void arrow(Entity* entity)
{
	printf("[arrow] ");

	if (entity->update != NULL)
	{
		entity->update(entity);
	}
	else
	{
		printf("Entity::update not set.");
	}

	printf("\n");
}

void updateEntity(void* entity)
{
	if (entity != NULL)
	{
		printf("[updateEntity] Updating entity...");
	}
}

void updateNamedEntity(void* namedEntity)
{
	if (namedEntity != NULL)
	{
		printf("[updateNamedEntity] Updating namedEntity...");
	}
}

void construct()
{
	Entity entity;
	entity.update = &updateEntity;

	dot(entity);
	arrow(&entity);

	// I'd like to not have to say namedEntity.entity to access
	// the "super-class" Entity structure...
	NamedEntity namedEntity;
	// namedEntity.entity.update = &updateNamedEntity;
	// But for now, I can't think of how to do it.

	// Maybe?
	//((Entity*) &namedEntity)->update = &updateNamedEntity;
	// Well, yeah, it works... but I'll take dots here over .. that casting..

	dot(*((Entity*) &namedEntity));
	arrow((Entity*) &namedEntity);
}

int main()//int argumentCount, char** arguments)
{
	// A message for thee..
	
	// Generate a segmentation fault.
	// char* message = "Hello, there!\n";
	// printf("%s", message);

	// Don't generate a segmentation fault.
	char* message = "Hello, there!";
	printf("%s\n", message);

	// EntityManager entityManager;// = newEntityManager();

	construct();

	// And one for thine box.
	return 0;
}
