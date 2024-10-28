#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <sstream> // Для роботи з потоками
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    std::string get_combinations(int n, int r) {
        std::vector<int> combination(r);
        for (int i = 0; i < r; ++i) {
            combination[i] = i + 1;
        }

        std::ostringstream result;
        do {
            for (int i = 0; i < r; ++i) {
                result << combination[i] << " ";
            }
            result << "\n";

            int i = r - 1;
            while (i >= 0 && combination[i] == n - r + i + 1) {
                --i;
            }

            if (i >= 0) {
                ++combination[i];
                for (int j = i + 1; j < r; ++j) {
                    combination[j] = combination[i] + j - i;
                }
            }
            else {
                break; 
            }

        } while (true);

        return result.str();
    }

    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            std::string expected = "1 2 3 \n1 2 4 \n1 2 5 \n1 3 4 \n1 3 5 \n1 4 5 \n2 3 4 \n2 3 5 \n2 4 5 \n3 4 5 \n";
            std::string actual = get_combinations(5, 3);
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(TestMethod2)
        {
            std::string expected = "1 2 \n1 3 \n1 4 \n2 3 \n2 4 \n3 4 \n";
            std::string actual = get_combinations(4, 2);
            Assert::AreEqual(expected, actual);
        }
    };
}
