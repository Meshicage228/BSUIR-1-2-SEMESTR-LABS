#include <iostream>
#include "Header.h"
using namespace std;
#define N 9
struct Edge {
    int source_num, dest_num, prior;
};
void ImplementAndShow(LinkedGrath* gr, int key, int option) {
    int choice;
    if (option == 1) {
        deleteNodes(gr, key);
    }
    else if (option == 2) {
        deleteVerx(gr, key);
    }
    cout << "Показать граф ? \n1.Да\n2.Нет\nОпция: ";
    cin >> choice;
    if (choice == 1) {
        cout << "Получившийся граф : \n";
        printGrath(gr);
    }
    cout << "Показать матрицу смежности ? \n1.Да\n2.Нет\nОпция: ";
    cin >> choice;
    if (choice == 1) {
        cout << "Матрица : \n";
        ShowMatrix(gr);
    }
    cout << endl;
}
int main() {
    setlocale(0, "rus");
    Edge edges[] = {
        {1, 2, 3}, {1, 7, 2}, {1, 8, 4},
        {2, 1, 3}, {2, 7, 2}, {2, 3, 1}, {2, 5 ,4},
        {7, 1, 2}, {7, 2, 2}, {7, 8, 2}, {7, 5, 7},
        {3, 2, 1}, {3, 5, 4}, {3, 4, 3},
        {4, 3, 3}, {4, 5, 2}, {4, 6, 1},
        {5, 3, 4}, {5, 4, 2}, {5, 6, 7}, {5, 7, 7}, {5, 8, 6}, {5, 2 ,4},
        {6, 8, 3}, {6, 4, 1}, {6, 5, 7},
        {8, 1, 4}, {8, 7, 2}, {8, 6, 3}, {8, 5, 6},
    };
    int number_of_elements = sizeof(edges) / sizeof(edges[0]);
    LinkedGrath* grathnew = createGrath(edges, number_of_elements);
    cout << "Изначальный граф : \n";
    printGrath(grathnew);
    cout << "Изначальная матрица смежности : \n";
    ShowMatrix(grathnew);
    int choice = 0;
    int show_grath;
    do {
        cout << "1.Удалить ребро 2\n2.Удалить веришну N7\nОпция:";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 1: {
            ImplementAndShow(grathnew, 2, 1);
            break;
        }
        case 2: {
            ImplementAndShow(grathnew, 7, 2);
            break;
        }
        default: cout << "No option" << endl; return 0;

        }
    } while (choice > 0 && choice < 4);
}