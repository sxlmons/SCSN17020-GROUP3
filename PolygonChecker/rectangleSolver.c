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

// Using the Convex Hull algorithm, Jarvis March. This algorithm finds the point with the smallest x,y coordinate and then checks all points for their angle to this point.
// It then adds these points in order depending if they are clockwise or counterclockwise to the original point. This algorithm brute forces it so it gets slower with more points.

// 1. Locate the bottom left most point and add it to the point array.
// 2. Create a line between this point and all other points.
// 3. Compare these lines to see which is rotated the most clockwise using the cross product.
// 4. Add this point to the point array and check again using it as the reference point.
// 5. Continue until the original point is reached.




int findStartingPointIndex(VECTOR2 q[]) { // 1.
	int smallestIndex = 0;
	for (int i = 1; i < QUAD_SIZE; i++) {
		if (q[i].y < q[smallestIndex].y) {
			smallestIndex = i;
		}
	}
	return smallestIndex;
}

int getCrossProduct(VECTOR2 a, VECTOR2 b, VECTOR2 origin) {
	// Cross product formula = a0.x * b.y - a0.y * b.x
	// Cross product is negative if b is to the left of a and positive if it is on the right. 0 if they are in line at 180 degrees or 0 degrees == No rectangle
	int xProd = (a.x - origin.x) * (b.y - origin.y) - (a.y - origin.y) * (b.x - origin.x);
	if (xProd < 0)
		return -1;
	if (xProd > 0)
		return 1;
	return 0;
}

// q[] is the set of points, hull is the set of points that make the hull. Unlike normal Jarvis March, this set size will always be 4.
VECTOR2* JarvisMarch(VECTOR2 quad[QUAD_SIZE]) {
	VECTOR2 hull[QUAD_SIZE] = { 0 };
	int start = findStartingPointIndex(quad);
	int originPoint = start;
	int mostClockwisePoint;
	hull[0] = quad[start];

	for (int j = 1; j < QUAD_SIZE; j++) {


		mostClockwisePoint = (originPoint + j) % QUAD_SIZE;
		for (int i = 0; i < QUAD_SIZE; i++) {
			if (getCrossProduct(quad[mostClockwisePoint], quad[i], quad[originPoint]) == 1)
				mostClockwisePoint = i;
		}
		originPoint = mostClockwisePoint;
		hull[j] = quad[originPoint];
	}

	/*mostClockwisePoint = (originPoint + 2) % QUAD_SIZE;
	for (int i = 0; i < QUAD_SIZE; i++) {
		if (getCrossProduct(quad[mostClockwisePoint], quad[i], quad[originPoint]) == 1)
			mostClockwisePoint = i;
	}
	originPoint = mostClockwisePoint;
	hull[2] = quad[originPoint];

	mostClockwisePoint = (originPoint + 3) % QUAD_SIZE;
	for (int i = 0; i < QUAD_SIZE; i++) {
		if (getCrossProduct(quad[mostClockwisePoint], quad[i], quad[originPoint]) == 1)
			mostClockwisePoint = i;
	}
	originPoint = mostClockwisePoint;
	hull[3] = quad[originPoint];*/

	return hull;
}