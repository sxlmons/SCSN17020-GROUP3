#pragma once

#define QUAD_SIZE 4

typedef struct vector2 {
	int x;
	int y;
} VECTOR2;

// Do I need CRUD for VECTOR2?

int findStartingPointIndex(VECTOR2 q[]);
int getCrossProduct(VECTOR2 a, VECTOR2 b, VECTOR2 origin);
void JarvisMarch(VECTOR2*);