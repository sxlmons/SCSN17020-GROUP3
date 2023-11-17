/*
This accepts 4 points as x,y pairs. It then generates lines to form a rectangle. It then reports the shape's perimeter and, if it is a rectangle then it also reports its area.

Author:		Dylan Glass
For:		Software Implementation

Assignment:		GROUP
Created:		2023-11-03
Modified:		--
By:				--
*/
#include <stdio.h>
#include <math.h>
#include "rectangleSolver.h"



bool InputPoints(VECTOR2* points) {
	if (points == NULL) {
		fprintf(stderr, "VECTOR2 pointer is NULL in InputPoints.\n");
		return false;
	}
	
	for (int i = 0; i < QUAD_SIZE; i++) {
		fprintf(stdout, "%s %d %s", "Rectangle point", i ,"X = ");
		if (scanf_s("%d", &points[i].x) != 1) {
			fprintf(stderr, "%s %d %s", "Bad value for x in point", i, "\n");
			return false;
		}
		fprintf(stdout, "%s %d %s", "Rectangle Point", i ,"Y = ");
		if (scanf_s("%d", &points[i].y) != 1) {
			fprintf(stderr, "%s %d %s", "Bad value for y in point", i, "\n");
			return false;
		}
	}
	JarvisMarch(points);
	return true;
}

double getSideLength(VECTOR2 p1, VECTOR2 p2) {
	// distance formula = sqrt((x2 - x1)^2 + (y2 - y1)^2)
	double length;
	length = sqrt(abs(((p2.x - p1.x)+(p2.x - p1.x)) + ((p2.y - p1.y)+(p2.y - p1.y))));
	return length;
}

double calculateArea(double sides[]) {
	return sides[0] * sides[2];
}

void AnalyzeRectangle(VECTOR2* points) {
	if (points == NULL) {
		fprintf(stderr, "VECTOR2 pointer is NULL in AnalyzeRectangle.\n");
	}

	double sides[QUAD_SIZE] = { 0 };
	sides[0] = getSideLength(points[0], points[1]);
	sides[1] = getSideLength(points[1], points[2]);
	sides[2] = getSideLength(points[2], points[3]);
	sides[3] = getSideLength(points[3], points[0]);

	double perimeter = sides[0] + sides[1] + sides[2] + sides[3];
	double area;

	if (sides[0] <= 0 || sides[1] <= 0 || sides[2] <= 0 || sides[3] <= 0) {
		fprintf(stdout, "Not a Shape\n");
	}
	else if (sides[0] == sides[1] && sides[0] == sides[2] && sides[0] == sides[3]) {
		calculateArea(sides);
		fprintf(stdout, "%s %f\n %s %f\n ", "Rectangle and square. Perimeter is:", perimeter, "Area is:", area);
	}
	else if (sides[0] == sides[2] && sides[1] == sides[3]) {
		area = sides[0] * sides[2];
		fprintf(stdout, "%s %f\n %s %f\n ", "Rectangle. Perimeter is:", perimeter, "Area is:", area);
	}
	else {
		area = sides[0] * sides[2];
		fprintf(stdout, "%s %f\n", "Quadrilateral, but not a rectangle. Perimeter is:", perimeter);
	}
}