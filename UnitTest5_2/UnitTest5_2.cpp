#include "pch.h"
#include "CppUnitTest.h"
#include "../oop5.2/oop5_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest52
{
	TEST_CLASS(UnitTest52)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double t = D1(1, 2, 1, 1);
			Assert::AreEqual(t, 1.0);
		}
	};
}
