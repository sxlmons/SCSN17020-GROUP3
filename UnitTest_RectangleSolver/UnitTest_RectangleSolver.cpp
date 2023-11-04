#include "pch.h"
#include "CppUnitTest.h"
#include "../PolygonChecker/rectangleSolver.h"

extern "C" VECTOR2 findStartingPoint(VECTOR2 q[], size_t arrLength);
extern "C" int getCrossProduct(VECTOR2 a, VECTOR2 b);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRectangleSolver
{
	TEST_CLASS(UnitTestRectangleSolver)
	{
	public:
		
		TEST_METHOD(findStartingPoint_Functional)
		{
			VECTOR2 a[4] = { {1, 2}, {5, 9}, {-3, 20}, {1, 7} };
			VECTOR2 expected = {1, 2};
			VECTOR2 actual = findStartingPoint(a, 4);
			Assert::AreEqual(expected.y, actual.y);
		}
		TEST_METHOD(getCrossProduct_Functional)
		{
			// vector 'b' is to the right of vector 'a' so the function should return -1.
			VECTOR2 a = { 1, 2 };
			VECTOR2 b = { 5, 9 };
			int expected = -1;
			int actual = getCrossProduct(a, b);
			Assert::AreEqual(expected, actual);
		}
	};
}
