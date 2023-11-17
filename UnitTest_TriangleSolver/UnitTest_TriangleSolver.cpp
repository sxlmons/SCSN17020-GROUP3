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

		// tests for the GetTriangleInsideAngles function -- ruth
		// tests an equilateral triangle
		TEST_METHOD(InsideAngles_EquilateralTriangle)
		{
			double sideA = 6, sideB = 6, sideC = 6; 
			double angleA, angleB, angleC; 
			double expectedAngle = 60.00; 
			double tolerance = 0.01; // compares the angles up to the second decimal place

			
			bool actual = GetTriangleInsideAngles(sideA, sideB, sideC, &angleA, &angleB, &angleC);

			
			Assert::IsTrue(actual); 
			// tests that the actual and expected values are equal up to 2 decimal places
			Assert::AreEqual(expectedAngle, angleA, tolerance); 
			Assert::AreEqual(expectedAngle, angleB, tolerance); 
			Assert::AreEqual(expectedAngle, angleC, tolerance); 
		
		}

		// tests an isosceles triangle
		TEST_METHOD(InsideAngles_IsoscelesTriangle)
		{
			
			double sideA = 8, sideB = 8, sideC = 10; 
			double angleA, angleB, angleC; 
			double expectedAngleA = 77.36, expectedAngleB = 51.32, expectedAngleC = 51.32; 
			double tolerance = 0.01; // compares the angles up to the second decimal place

			
			bool actual = GetTriangleInsideAngles(sideA, sideB, sideC, &angleA, &angleB, &angleC);

			
			Assert::IsTrue(actual); 
			// tests that the actual and expected values are equal up to 2 decimal places
			Assert::AreEqual(expectedAngleA, angleA, tolerance);
			Assert::AreEqual(expectedAngleB, angleB, tolerance); 
			Assert::AreEqual(expectedAngleC, angleC, tolerance); 
		}

		// tests a scalene triangle
		TEST_METHOD(InsideAngles_ScaleneTriangle)
		{

			double sideA = 8, sideB = 6, sideC = 12;
			double angleA, angleB, angleC;
			double expectedAngleA = 117.28, expectedAngleB = 26.38, expectedAngleC = 36.34;
			double tolerance = 0.01; // compares the angles up to the second decimal place


			bool actual = GetTriangleInsideAngles(sideA, sideB, sideC, &angleA, &angleB, &angleC);


			Assert::IsTrue(actual);
			// tests that the actual and expected values are equal up to 2 decimal places
			Assert::AreEqual(expectedAngleA, angleA, tolerance);
			Assert::AreEqual(expectedAngleB, angleB, tolerance);
			Assert::AreEqual(expectedAngleC, angleC, tolerance);
		}

		// tests 3 sides that do not form a triangle
		TEST_METHOD(InsideAngles_InvalidTriangle)
		{
			double sideA = 5, sideB = 6, sideC = 12;
			double angleA, angleB, angleC;

			bool actual = GetTriangleInsideAngles(sideA, sideB, sideC, &angleA, &angleB, &angleC);

			Assert::IsFalse(actual);
		}

		// tests a triangle with a negative side value
		TEST_METHOD(InsideAngles_InvalidTriangleNegativeSide)
		{
			double sideA = -1, sideB = 14, sideC = 12;
			double angleA, angleB, angleC;

			bool actual = GetTriangleInsideAngles(sideA, sideB, sideC, &angleA, &angleB, &angleC);

			Assert::IsFalse(actual);
		}

		// tests a triangle with a zero side value
		TEST_METHOD(InsideAngles_InvalidTriangleZeroSide)
		{
			double sideA = 0, sideB = 14, sideC = 12;
			double angleA, angleB, angleC;

			bool actual = GetTriangleInsideAngles(sideA, sideB, sideC, &angleA, &angleB, &angleC);

			Assert::IsFalse(actual);
		}
	};
}
	

