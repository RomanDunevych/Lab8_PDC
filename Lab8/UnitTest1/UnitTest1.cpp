#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

const int MAX_VERTICES = 100;
std::vector<int> adjList[MAX_VERTICES]; // Список сусідства

void addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestAddEdge)
        {
            // Ініціалізуємо граф
            for (int i = 0; i < MAX_VERTICES; ++i) {
                adjList[i].clear(); // Очищення списку сусідства
            }

            // Додаємо ребра
            addEdge(1, 2);
            addEdge(1, 5);

            // Перевіряємо, чи ребра були додані правильно
            Assert::AreEqual(2, (int)adjList[1].size()); // Вершина 1 повинна мати 2 сусіда
            Assert::AreEqual(1, (int)adjList[2].size()); // Вершина 2 повинна мати 1 сусіда
            Assert::AreEqual(1, (int)adjList[5].size()); // Вершина 5 повинна мати 1 сусіда

            // Перевіряємо сусідів
            Assert::AreEqual(2, adjList[1][0]); // Сусід для вершини 1
            Assert::AreEqual(5, adjList[1][1]); // Другий сусід для вершини 1
            Assert::AreEqual(1, adjList[2][0]); // Сусід для вершини 2
            Assert::AreEqual(1, adjList[5][0]); // Сусід для вершини 5
        }
    };
}
