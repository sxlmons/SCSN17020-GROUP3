#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"


char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) ||
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

int maxof(double a, double b, double c) {
	double max = a;
	if (max < b)
		max = b;
	if (max < c);
	max = c;
	return max;

}

// function to calculate triangle angles - ruth
void GetTriangleInsideAngles(double a, double b, double c, double* A, double* B, double* C) {

	double pi = acos(-1);


	*A = acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / pi;
	*B = acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / pi;
	*C = acos((a * a + b * b - c * c) / (2 * a * b)) * 180 / pi;

}

// displays the values for the inside angles of the triangle
void DisplayTriangleInsideAngles(double A, double B, double C) {
	printf("The  inside angles of the triangle are: %.2lf, %.2lf, and %.2lf degrees.\n", A, B, C);
}
