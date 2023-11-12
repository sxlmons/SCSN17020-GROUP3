#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> //line 3: added stdlib - joshua

#include "main.h"
#include "convexHull.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

#define MAX_LENGTH 80

int side = 0;

int main() {
	VECTOR2 points[QUAD_SIZE];
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			double A, B, C;
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			if (GetTriangleInsideAngles(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], &A, &B, &C))
				DisplayTriangleInsideAngles(A, B, C);
			break;
		case 2:
			fprintf(stdout, "Rectangle selected.\n");
			InputPoints(points);
			AnalyzeRectangle(points);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	while (scanf_s("%1o", &shapeChoice) != 1) {
		printf_s("Invalid, enter a number."); 
		//line 53-56: added input validation for menu selection - joshua
	}

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		while (scanf_s("%d", &triangleSides[i]) != 1) {
			printf_s("Invalid, enter a number.");
			//line 62-64: added input validation for triangle sides - joshua 
		}
	}
	return triangleSides;
}

