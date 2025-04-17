#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_lab2.5(a)/Pair.h"
#include "../OOP_lab2.5(a)/Pair.cpp"
#include "../OOP_lab2.5(a)/Money.h"
#include "../OOP_lab2.5(a)/Money.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest15
{
	TEST_CLASS(UnitTest15)
	{
	public:

		TEST_METHOD(TestPairAdd)
		{
			Pair p1; p1.Init(2, 3);
			Pair p2; p2.Init(5, 7);
			Pair p3 = p1 + p2; // (7, 10)
			Assert::AreEqual(7, p3.getFirst());
			Assert::AreEqual(10, p3.getSecond());
		}
	};
}
