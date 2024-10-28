#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab3.1_PDC/Lab3.1_PDC.cpp"



extern void stirlingNumbers(int n, int F[20][20]);
extern void bellNumbers(int n, int F[20][20], unsigned long long B[20]);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestStirlingNumbers)
		{
			int F[20][20] = { 0 };
			stirlingNumbers(5, F);

			int expected[6][6] = {
				{ 0, 0, 0, 0, 0, 0 },
				{ 0, 1, 0, 0, 0, 0 },
				{ 0, 1, 1, 0, 0, 0 },
				{ 0, 1, 3, 1, 0, 0 },
				{ 0, 1, 7, 6, 1, 0 },
				{ 0, 1, 15, 25, 10, 1 }
			};

			for (int i = 1; i <= 5; ++i) {
				for (int j = 1; j <= i; ++j) {
					Assert::AreEqual(F[i][j], expected[i][j], L"Stirling number mismatch");
				}
			}
		}

		TEST_METHOD(TestBellNumbers)
		{
			int F[20][20] = { 0 };
			unsigned long long B[20] = { 0 };

			stirlingNumbers(5, F);
			bellNumbers(5, F, B);

			unsigned long long expected[6] = { 0, 1, 2, 5, 15, 52 };

			for (int i = 1; i <= 5; ++i) {
				Assert::AreEqual(B[i], expected[i], L"Bell number mismatch");
			}
		}
	};
}
