#include "pch.h"
#include "CppUnitTest.h"
#include <sstream>
#include <vector>
#include "../Lab5.1/Lab5.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
    TEST_CLASS(UnitTest2)
    {
    public:

        TEST_METHOD(TestSetOperations)
        {
            // Підготовка тестових даних
            std::istringstream input("5\n1 2 3 4 5\n3\n1 2 3\n2\n3 4\n");
            std::cin.rdbuf(input.rdbuf()); // Підміна стандартного вводу

            // Результати операцій
            std::vector<int> notA, AperB, AobB, ArizB, AxorB;

            // Очікувані результати
            std::vector<int> expectedNotA = { 0, 0, 0, 1, 1 };  // Доповнення A
            std::vector<int> expectedAperB = { 0, 0, 1, 0, 0 }; // A ∩ B
            std::vector<int> expectedAobB = { 1, 1, 1, 1, 0 };  // A ∪ B
            std::vector<int> expectedArizB = { 1, 1, 0, 0, 0 }; // A \ B
            std::vector<int> expectedAxorB = { 1, 1, 0, 1, 0 }; // A ⊕ B

            // Перевірка результатів
            Assert::AreEqual(static_cast<int>(expectedNotA.size()), static_cast<int>(notA.size()));
            for (size_t i = 0; i < expectedNotA.size(); ++i) {
                Assert::AreEqual(expectedNotA[i], notA[i]);
            }

            Assert::AreEqual(static_cast<int>(expectedAperB.size()), static_cast<int>(AperB.size()));
            for (size_t i = 0; i < expectedAperB.size(); ++i) {
                Assert::AreEqual(expectedAperB[i], AperB[i]);
            }

            Assert::AreEqual(static_cast<int>(expectedAobB.size()), static_cast<int>(AobB.size()));
            for (size_t i = 0; i < expectedAobB.size(); ++i) {
                Assert::AreEqual(expectedAobB[i], AobB[i]);
            }

            Assert::AreEqual(static_cast<int>(expectedArizB.size()), static_cast<int>(ArizB.size()));
            for (size_t i = 0; i < expectedArizB.size(); ++i) {
                Assert::AreEqual(expectedArizB[i], ArizB[i]);
            }

            Assert::AreEqual(static_cast<int>(expectedAxorB.size()), static_cast<int>(AxorB.size()));
            for (size_t i = 0; i < expectedAxorB.size(); ++i) {
                Assert::AreEqual(expectedAxorB[i], AxorB[i]);
            }
        }
    };
}
