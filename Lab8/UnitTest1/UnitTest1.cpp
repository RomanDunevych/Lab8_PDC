#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

const int MAX_VERTICES = 100;
std::vector<int> adjList[MAX_VERTICES]; // ������ ��������

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
            // ���������� ����
            for (int i = 0; i < MAX_VERTICES; ++i) {
                adjList[i].clear(); // �������� ������ ��������
            }

            // ������ �����
            addEdge(1, 2);
            addEdge(1, 5);

            // ����������, �� ����� ���� ����� ���������
            Assert::AreEqual(2, (int)adjList[1].size()); // ������� 1 ������� ���� 2 �����
            Assert::AreEqual(1, (int)adjList[2].size()); // ������� 2 ������� ���� 1 �����
            Assert::AreEqual(1, (int)adjList[5].size()); // ������� 5 ������� ���� 1 �����

            // ���������� �����
            Assert::AreEqual(2, adjList[1][0]); // ���� ��� ������� 1
            Assert::AreEqual(5, adjList[1][1]); // ������ ���� ��� ������� 1
            Assert::AreEqual(1, adjList[2][0]); // ���� ��� ������� 2
            Assert::AreEqual(1, adjList[5][0]); // ���� ��� ������� 5
        }
    };
}
