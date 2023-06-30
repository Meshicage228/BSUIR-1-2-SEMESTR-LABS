#include "Header.h"
#include <iostream>
using namespace std;

struct box {
    int num;
    int index;
    bool priority;
};

int main()
{
    init_hash_table();
    srand(time(NULL));
    setlocale(0, "rus");
    int size = 0;
    do {
        cout << "������� ���������� ��������� ����� < 20 :";
        cin >> size;
    } while (size < 0 || size >= 20);
    box* arr = new box[size];
    print_table();
    cout << "Array : \n";
    for (int i = 0; i < size; i++) {
        arr[i].num = rand() % 1201 + 100;
        cout << i << " ---- " << arr[i].num << endl;
        hash_table_instert(&arr[i]);
    }
    do {
        cout << "1.���-�������\n2.������ ��������� � ������� �������� �����\n3.����� ������� ���-�������\n4.������� �������� �����\n5.�����\n�����:";
        int option;
        cin >> option;
        cout << endl;
        switch (option) {
        case 1: print_table();
            break;
        case 2: { 
            cout << "�������� � ������� �������� ����� : \n";  show_priority(size); cout << endl; 
            break; 
        }
        case 3: {
            cout << "������� ����� : ";
            int y;
            cin >> y;
            int index = search_for_box(y);
            if (index == -1) cout << "������ ����� �� ����������...\n";
            else cout << "����� " << y << " ���������� � ���-�������� " << index << endl;
            break;
        }
        case 4: cout << "������� ����� : "; int x; cin >> x;
            hesh_delete_point(x);
            size--;
            break;
        case 5: cout << "�����..."; return 0;
        case 6: cout << searchmax();
        default: cout << "�������� �����...\n";
            break;

        }
    } while (true);
}