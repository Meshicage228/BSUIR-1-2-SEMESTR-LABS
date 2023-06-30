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
        cout << "Введите количество рандомных чисел < 20 :";
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
        cout << "1.Хеш-таблица\n2.Печать элементов в порядке убывания ключа\n3.Найти элемент хеш-таблицы\n4.Удалить введеное число\n5.Выход\nОпция:";
        int option;
        cin >> option;
        cout << endl;
        switch (option)
        {
        case 1: print_table();
             break;
        case 2: { cout << "Элементы в порядке убывания ключа : \n";  show_priority(size); cout << endl;
            break; }
        case 3: { cout << "Введите число : ";
            int y;
            cin >> y;
            int index = search_for_box(y);
            if (index == -1) cout << "Такого числа не существует...\n";
            else cout << "Число " << y << " обнаружено в хеш-индекске " << index << endl;
            break;
        }
        case 4: cout << "Введите число : "; int x; cin >> x;
              hesh_delete_point(x);
              size--;
             break;
        case 5: cout << "Выход..."; return 0;
        default: cout << "Неверная опция...\n";
            break;
        
        }
    } while (true);
}