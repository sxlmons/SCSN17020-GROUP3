/*
*  CSCN - F23 - Nov 2023 - GROUP 3
*
*  GROUP PROJECT 1 - CPP UNIT TEST TriangeSolver.h
*
*  CONTRIBUTORS:
*  - JOSHUA S
* 
*  Revision History
*
*      1.1      2023-Nov-15          initial
*/

#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "..//PolygonChecker//triangleSolver.h"
}



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTriangleSolver
{
	TEST_CLASS(UnitTestTriangleSolver)
	{
	public:
		
		TEST_METHOD(NotATriangle)
		{
			Assert::AreEqual("Not a triangle", analyzeTriangle(0, 1, 1)); 
			Assert::AreEqual("Not a triangle", analyzeTriangle(1, 0, 1)); 
		}
		TEST_METHOD(TestMethod_EquilateralTriangle)
		{
			Assert::AreEqual("Equilateral triangle", analyzeTriangle(1, 1, 1));
			Assert::AreEqual("Equilateral triangle", analyzeTriangle(10, 10, 10));
		}
		TEST_METHOD(TestMethod_IsoscelesTriangle)
		{
			Assert::AreEqual("Isosceles triangle", analyzeTriangle(2, 2, 1));
		/*	Assert::AreEqual("Isosceles triangle", analyzeTriangle(2, 1, 2));*/
			Assert::AreEqual("Isosceles triangle", analyzeTriangle(1, 2, 2));
		}
		TEST_METHOD(TestMethod_ScaleneTriangle)
		{
			Assert::AreEqual("Scalene triangle", analyzeTriangle(2, 3, 4));
			Assert::AreEqual("Scalene triangle", analyzeTriangle(3, 4, 2));
			Assert::AreEqual("Scalene triangle", analyzeTriangle(4, 2, 3));
		}
	};
}
	

