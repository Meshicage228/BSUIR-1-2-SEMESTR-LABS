#include "Header.h"
#include <iostream>
using namespace std;

#define N 9

struct Node {
    int source;
    int dest;
    Node* next;
    int priority;
};
struct LinkedGrath {
    Node* head[N];
};
struct Edge {
    int source_num, dest_num, prior;
};
LinkedGrath* createGrath(Edge edges[], int n) {
    LinkedGrath* ptr = new LinkedGrath();
    for (int i = 0; i < N; i++) {
        ptr->head[i] = NULL;
    }
    for (int i = 0; i < n; i++) {
        int src = edges[i].source_num;
        int dest = edges[i].dest_num;
        int node = edges[i].prior;
        Node* newNode = new Node();
        newNode->dest = dest;
        newNode->source = src;
        newNode->priority = node;
        newNode->next = ptr->head[src];
        ptr->head[src] = newNode;
    }
    return ptr;
}
void printGrath(LinkedGrath* LinkedGrath) {
    for (int i = 0; i < N; i++) {
        Node* ptr = LinkedGrath->head[i];
        while (ptr != NULL) {
            cout << i << " -> " << ptr->dest << "(" << ptr->priority << ")" << "  ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    cout << endl;
}

void ShowMatrix(LinkedGrath* grath) {
    bool** arr = new bool* [N];
    for (int i = 0; i < N; i++) {
        arr[i] = new bool[N];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = false;
        }
    }
    cout << endl;
    for (int i = 1; i < N; i++)
    {
        if (grath->head[i] == NULL) continue;
        Node* ptr = grath->head[i];
        while (ptr)
        {
            arr[i][ptr->dest] = true;
            ptr = ptr->next;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void deleteNodes(LinkedGrath* grath, int key) {
    for (int i = 1; i < N; i++) {
        if (grath->head[i] == NULL) continue;
        Node* ptr = grath->head[i];
        Node* nextp = ptr->next;
        bool flag = true;
        while (flag) {
            nextp = ptr->next;
            if (nextp->priority == key) {
                while (nextp) {
                    if (nextp->priority != key) break;
                    nextp = nextp->next;
                }
                ptr->next = nextp;
                ptr = ptr->next;
            }
            else {
                ptr = ptr->next;
                nextp = ptr->next;
            }
            if (ptr == NULL || ptr->next == NULL) flag = false;
        }
    }
}
void deleteVerx(LinkedGrath* grath, int key) {
    for (int i = 1; i < N; i++) {
        if (grath->head[i] == NULL) continue;
        Node* ptr = grath->head[i];
        Node* nextp = ptr->next;
        if (ptr->source == key) {
            grath->head[i] = NULL;
        }
        else {
            bool flag = true;
            while (flag) {
                nextp = ptr->next;
                if (nextp->source == key || nextp->dest == key) {
                    while (nextp) {
                        if (nextp->source != key && nextp->dest != key) break;
                        nextp = nextp->next;
                    }
                    ptr->next = nextp;
                    ptr = ptr->next;
                }
                else {
                    ptr = ptr->next;
                    nextp = ptr->next;
                }
                if (ptr == NULL || ptr->next == NULL) flag = false;
            }
        }
    }
}


