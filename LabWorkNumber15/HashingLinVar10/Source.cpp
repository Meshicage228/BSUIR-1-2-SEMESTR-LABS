#include "Header.h"
#include <iostream>

using namespace std;
#define SIZE_TABLE 20

struct box {
    int num;
    int index;
    bool priority;
};
box* push_table[SIZE_TABLE];
unsigned int hashing(int a) {
    int hash_value = 0;
    hash_value = a % SIZE_TABLE;
    return hash_value;
}
void init_hash_table() {
    for (int i = 0; i < SIZE_TABLE; i++) {
        push_table[i] = NULL;
    }
}
void print_table() {
    cout << "Начало хеш-таблицы : \n";
    for (int i = 0; i < SIZE_TABLE; i++) {
        if (push_table[i] == NULL) {
            cout << i << " ----------- \n";
        }
        else {
            cout << i << " " << push_table[i]->num << endl;
        }
    }
    cout << "Конец.\n ";
}
void hash_table_instert(box* p) {
    int index = hashing(p->num);
    bool flag = true;

    if (push_table[index] == NULL) {
        push_table[index] = p;
        push_table[index]->priority = false;
        p->index = index;
    }
    else {
        do {
            while (index != SIZE_TABLE - 1) {
                if (push_table[index] == NULL) {
                    push_table[index] = p;
                    push_table[index]->priority = false;
                    p->index = index;
                    flag = false;
                    break;
                }
                index++;
            }
            index = 0;
        } while (flag);

    }
}
int search_for_box(int a) {
    int index = hashing(a);
    bool flag = true;
    int tries = 0;
    do {
        while (index != SIZE_TABLE) {
            if (push_table[index] == NULL) {
                index++;
                continue;
            }
            if (push_table[index]->num == a) {
                return index;
            }
            index++;
        }
        index = 0;
        tries++;
        if (tries == 2) break;
    } while (flag);
    return -1;
}
void hesh_delete_point(int a) {
    int index = search_for_box(a);
    if (index == -1) cout << "Такое число не обнаружено\n";
    else {
        push_table[index] = NULL;
        cout << "После удаления :\n";
        print_table();
    }
}
int searchmax() {
    box* ptr = NULL;
    int i = 0;
    for (i; i < SIZE_TABLE; i++) {
        if (push_table[i] == NULL) continue;
        else { 
            ptr = push_table[i]; 
            break; 
        }
    }
    for (i; i < SIZE_TABLE; i++) {
        if (push_table[i] == NULL) continue;
        if (ptr->num < push_table[i]->num) 
            ptr = push_table[i];
    }
    return ptr->num;
}
void show_priority(int n) {
    for (int i = 0; i < n; i++) {
        int k = 0;
        while (k < SIZE_TABLE) {
            if (push_table[k] == NULL || push_table[k]->priority == true) k++;
            else if (push_table[k] != NULL && push_table[k]->priority == false) break;
            else k++;

        }
        box* ptr = push_table[k];
        while (k < SIZE_TABLE) {
            if (push_table[k] != NULL && push_table[k]->priority == false) {
                if (ptr->num <= push_table[k]->num) {
                    ptr = push_table[k];
                }
            }
            k++;
        }
        ptr->priority = true;
        cout << ptr->index << '\t' << ptr->num << endl;
    }
    for (int i = 0; i < SIZE_TABLE; i++) {
        if (push_table[i] != NULL) {
            push_table[i]->priority = false;
        }
    }
}