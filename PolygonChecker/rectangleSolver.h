#pragma once
#include <stdbool.h>

typedef struct vector2 {
	int x;
	int y;
} VECTOR2;

void QuickHull();

VECTOR2 SetVectorPoints(int x, int y);