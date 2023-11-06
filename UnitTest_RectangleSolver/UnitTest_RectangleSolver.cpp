#include "pch.h"
#include "CppUnitTest.h"
#include <stdio.h>
#include "../PolygonChecker/rectangleSolver.h"

extern "C" int findStartingPointIndex(VECTOR2 q[]);
extern "C" int getCrossProduct(VECTOR2, VECTOR2, VECTOR2);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRectangleSolver
{
	TEST_CLASS(UnitTestRectangleSolver)
	{
	public:
		
		TEST_METHOD(findStartingPoint_Functional)
		{
			VECTOR2 a[4] = { {1, 2}, {5, 9}, {-3, 20}, {1, 7} };
			int expected = 0;
			int actual = findStartingPointIndex(a);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(getCrossProduct_Functional)
		{
			// vector 'b' is to the right of vector 'a' so the function should return -1.
			VECTOR2 a = { 1, 2 };
			VECTOR2 b = { 5, 9 };
			VECTOR2 origin = { 1, 1 };
			int expected = -1;
			int actual = getCrossProduct(a, b, origin);
			Assert::AreEqual(expected, actual);
		}
	};
}
