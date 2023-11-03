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

#define QUAD_SIZE 4
VECTOR2 quadrilateral[QUAD_SIZE];





// Using the Convex Hull algorithm, Jarvis March. This algorithm finds the point with the smallest x,y coordinate and then checks all points for their angle to this point.
// It then adds these points in order depending if they are clockwise or counterclockwise to the original point. This algorithm brute forces it so it gets slower with more points.






// Quickhull algorithm to find which points connect to which. References: wikipedia.org & geeksforgeeks.org
void QuickHull(VECTOR2 q[], int n, VECTOR2 p1, VECTOR2 p2, int side) {
	
	int index = -1;
	int max_distance = 0;
	// 1. find points with min and max x coordinates and min and max y. These form the first line. 
	// Search through all of the points and compare them with eachother to get the ones with the greatest distance inbetween each other.
	for (int i = 0; i < n; i++) {
		int temp = lineDistance(p1, p2, q[i]);
		if (findSide(p1, p2, q[i]) == side && temp > max_distance) {
			index = i;
			max_distance = temp;
		}
	}
	if (index == -1) {
		q[0] = p1.x;

	}
}
int findSide(VECTOR2 p1, VECTOR2 p2, VECTOR2 p3) {
	int value = (p3.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p3.x - p1.x);
	if (value < 0) {
		return -1;
	}
	if (value > 0) {
		return 1;
	}
	return 0;
}
int lineDistance(VECTOR2 p1, VECTOR2 p2, VECTOR2 p3) {
	return abs((p3.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p3.x - p1.x));
}