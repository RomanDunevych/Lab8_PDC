#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <Windows.h>

using namespace std;

const int MAX_VERTICES = 100;

vector<int> adjList[MAX_VERTICES];
bool visited[MAX_VERTICES];
int dfsNumber[MAX_VERTICES];

void initializeGraph() {
    fill(begin(visited), end(visited), false);
    fill(begin(dfsNumber), end(dfsNumber), 0);
}

void addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void loadGraphFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Помилка відкриття файлу." << endl;
        return;
    }

    int u, v;
    while (file >> u >> v) {
        addEdge(u, v);
    }
    file.close();
}

void DFS(int start) {
    stack<int> dfsStack;
    int counter = 0;

    dfsStack.push(start);

    cout << "Поточна вершина\tDFS Номер\tВміст стеку" << endl;
    cout << "--------------------------------------------------" << endl;

    while (!dfsStack.empty()) {
        int current = dfsStack.top();

        if (!visited[current]) {
            visited[current] = true;
            dfsNumber[current] = ++counter;
            cout << current << "\t\t" << dfsNumber[current] << "\t\t";

            // Виводимо вміст стека
            stack<int> tempStack = dfsStack;  // Скопіюємо стек
            while (!tempStack.empty()) {
                cout << tempStack.top() << " ";
                tempStack.pop();
            }
            cout << endl;
        }

        bool hasUnvisitedNeighbors = false;
        for (int i = adjList[current].size() - 1; i >= 0; --i) {
            int neighbor = adjList[current][i];
            if (!visited[neighbor]) {
                dfsStack.push(neighbor);
                hasUnvisitedNeighbors = true;
                break;
            }
        }

        if (!hasUnvisitedNeighbors) {
            dfsStack.pop();
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    initializeGraph();

    string filename;
    int startVertex;

    cout << "Введіть назву файлу: ";
    cin >> filename;
    loadGraphFromFile(filename);

    cout << "Введіть початкову вершину: ";
    cin >> startVertex;

    DFS(startVertex);

    return 0;
}
