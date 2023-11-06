#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.1/Lab_06_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int min = 15;
			int max = 85;
			int random = RandomNumberGeneration(min, max);
			Assert::IsTrue(random >= min && random <= max);
		}
	};
}