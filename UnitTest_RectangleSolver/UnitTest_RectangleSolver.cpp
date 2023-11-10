#include "pch.h"
#include "CppUnitTest.h"
#include <stdio.h>
#include <array>
#include "../PolygonChecker/convexHull.h"


extern "C" int findStartingPointIndex(VECTOR2 q[]);
extern "C" int getCrossProduct(VECTOR2, VECTOR2, VECTOR2);
extern "C" VECTOR2* JarvisMarch(VECTOR2 quad[]);

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
			VECTOR2 a[4] = { {1, 3}, {4, 0}, {-4, 1}, {-3, -1} };
			VECTOR2 expected = { -3, -1 };
			VECTOR2* temp = JarvisMarch(a);
			VECTOR2 actual = *temp;
			Assert::AreEqual(expected.x, actual.x);
		}
		TEST_METHOD(JarvisMarch_returnsSortedHull_0_y)
		{
			VECTOR2 a[4] = { {1, 3}, {4, 0}, {-4, 1}, {-3, -1} };
			VECTOR2 expected = { -3, -1 };
			VECTOR2* temp = JarvisMarch(a);
			VECTOR2 actual = *temp;
			Assert::AreEqual(expected.y, actual.y);
		}
		TEST_METHOD(JarvisMarch_returnsSortedHull_1_x)
		{
			VECTOR2 a[4] = { {1, 3}, {4, 0}, {-4, 1}, {-3, -1} };
			VECTOR2 expected = { -4, 1 };
			VECTOR2* temp = JarvisMarch(a);
			VECTOR2 actual = *(temp + 1);
			Assert::AreEqual(expected.x, actual.x);
		}
		TEST_METHOD(JarvisMarch_returnsSortedHull_1_y)
		{
			VECTOR2 a[4] = { {1, 3}, {4, 0}, {-4, 1}, {-3, -1} };
			VECTOR2 expected = { -4, 1 };
			VECTOR2* temp = JarvisMarch(a);
			VECTOR2 actual = *(temp + 1);
			Assert::AreEqual(expected.y, actual.y);
		}
		TEST_METHOD(JarvisMarch_returnsSortedHull_2_x)
		{
			VECTOR2 a[4] = { {1, 3}, {4, 0}, {-4, 1}, {-3, -1} };
			VECTOR2 expected = { 1, 3 };
			VECTOR2* temp = JarvisMarch(a);
			VECTOR2 actual = *(temp + 2);
			Assert::AreEqual(expected.x, actual.x);
		}
		TEST_METHOD(JarvisMarch_returnsSortedHull_2_y)
		{
			VECTOR2 a[4] = { {1, 3}, {4, 0}, {-4, 1}, {-3, -1} };
			VECTOR2 expected = { 1, 3 };
			VECTOR2* temp = JarvisMarch(a);
			VECTOR2 actual = *(temp + 2);
			Assert::AreEqual(expected.y, actual.y);
		}
		TEST_METHOD(JarvisMarch_returnsSortedHull_3_x)
		{
			VECTOR2 a[4] = { {1, 3}, {4, 0}, {-4, 1}, {-3, -1} };
			VECTOR2 expected = { 4, 0 };
			VECTOR2* temp = JarvisMarch(a);
			VECTOR2 actual = *(temp + 3);
			Assert::AreEqual(expected.x, actual.x);
		}
		TEST_METHOD(JarvisMarch_returnsSortedHull_3_y)
		{
			VECTOR2 a[4] = { {1, 3}, {4, 0}, {-4, 1}, {-3, -1} };
			VECTOR2 expected = { 4, 0 };
			VECTOR2* temp = JarvisMarch(a);
			VECTOR2 actual = *(temp + 3);
			Assert::AreEqual(expected.y, actual.y);
		}
	};
}