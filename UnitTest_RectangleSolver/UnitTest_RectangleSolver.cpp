#include "pch.h"
#include "CppUnitTest.h"
#include <stdio.h>
#include <array>
#include "../PolygonChecker/convexHull.c"


extern int findStartingPointIndex(VECTOR2 q[]);
extern int getCrossProduct(VECTOR2, VECTOR2, VECTOR2);
extern void JarvisMarch(VECTOR2*);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRectangleSolver
{
	TEST_CLASS(UnitTestRectangleSolver)
	{
	public:
		
		TEST_METHOD(findStartingPointIndex_returnsIndexOfLowestYVector)
		{
			VECTOR2 a[4] = { {1, 2}, {5, 9}, {-3, 20}, {1, 7} };
			int expected = 0;
			int actual = findStartingPointIndex(a);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(getCrossProduct_retunsCounterclockwise)
		{
			// vector 'b' is to the right of vector 'a' so the function should return -1.
			VECTOR2 a = { 1, 2 };
			VECTOR2 b = { 5, 9 };
			VECTOR2 origin = { 1, 1 };
			int expected = -1;
			int actual = getCrossProduct(a, b, origin);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(JarvisMarch_returnsSortedHull_0_x)
		{
			VECTOR2 actual[4] = { {1, 3}, {4, 0}, {-4, 1}, {-3, -1} };
			VECTOR2 expected = { -3, -1 };
			JarvisMarch(actual);
			Assert::AreEqual(expected.x, actual[0].x);
		}
		TEST_METHOD(JarvisMarch_returnsSortedHull_0_y)
		{
			VECTOR2 a[4] = { {1, 3}, {4, 0}, {-4, 1}, {-3, -1} };
			VECTOR2 expected = { -3, -1 };
			JarvisMarch(a);
			Assert::AreEqual(expected.y, a[0].y);
		}
		TEST_METHOD(JarvisMarch_returnsSortedHull_1_x)
		{
			VECTOR2 a[4] = { {1, 3}, {4, 0}, {-4, 1}, {-3, -1} };
			VECTOR2 expected = { -4, 1 };
			JarvisMarch(a);
			Assert::AreEqual(expected.x, a[1].x);
		}
		TEST_METHOD(JarvisMarch_returnsSortedHull_1_y)
		{
			VECTOR2 a[4] = { {1, 3}, {4, 0}, {-4, 1}, {-3, -1} };
			VECTOR2 expected = { -4, 1 };
			JarvisMarch(a);
			Assert::AreEqual(expected.y, a[1].y);
		}
		TEST_METHOD(JarvisMarch_returnsSortedHull_2_x)
		{
			VECTOR2 a[4] = { {1, 3}, {4, 0}, {-4, 1}, {-3, -1} };
			VECTOR2 expected = { 1, 3 };
			JarvisMarch(a);
			Assert::AreEqual(expected.x, a[2].x);
		}
		TEST_METHOD(JarvisMarch_returnsSortedHull_2_y)
		{
			VECTOR2 a[4] = { {1, 3}, {4, 0}, {-4, 1}, {-3, -1} };
			VECTOR2 expected = { 1, 3 };
			JarvisMarch(a);
			Assert::AreEqual(expected.y, a[2].y);
		}
		TEST_METHOD(JarvisMarch_returnsSortedHull_3_x)
		{
			VECTOR2 a[4] = { {1, 3}, {4, 0}, {-4, 1}, {-3, -1} };
			VECTOR2 expected = { 4, 0 };
			JarvisMarch(a);
			Assert::AreEqual(expected.x, a[3].x);
		}
		TEST_METHOD(JarvisMarch_returnsSortedHull_3_y)
		{
			VECTOR2 a[4] = { {1, 3}, {4, 0}, {-4, 1}, {-3, -1} };
			VECTOR2 expected = { 4, 0 };
			JarvisMarch(a);
			Assert::AreEqual(expected.y, a[3].y);
		}
	};
}