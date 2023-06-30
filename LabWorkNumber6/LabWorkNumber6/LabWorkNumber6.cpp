#include <iostream>
#include <string>
#include <cstdio>
#include <stdio.h>
using namespace std;
int main() {
    setlocale(0, "rus");
    char choice[20];
    do{
        cout << "1. Ввод данных и результат программы\n";
        cout << "2. Выход из меню\n";
        cout << "Ваша опция : ";
        point2 :
        cin >> choice;
        if (strlen(choice) >= 2) {
            cout << "Не сущетсвует такой опции, пробуйте еще раз : ";
            goto point2;
        }
        switch (*choice){
        case '1': {
            point :
            char stroka[100];
            char copy[100];
            cout << "Введите вашу строку : ";
            cin >> stroka;
            char* ptr = 0;
            int i = 0;
            int counter = 0;
            bool dotdes = false;
            bool des = false;
            for (int i = 0; i < strlen(stroka); i++) {
                if (stroka[i] == '.') {
                    des = true;
                    break;
                }
            }
            if (!des) {
                cout << "В введеной строке не обнаружена точка, попробуйте еще раз!\n";
                goto point;
            }
            do {
                if (stroka[i] >= '0' && stroka[i] <= '9' || stroka[i] == '.' && dotdes) {
                        if (stroka[i] >= '0' && stroka[i] <= '9') {
                            if(!counter) 
                                dotdes = true;
                        }
                        if (stroka[i] == '.') {
                            dotdes = false;
                            counter = 1;
                        }
                        ptr = &stroka[i];
                        cout << *ptr;
                    }
                if (ptr) {
                    stroka[i] = '\0';
                    ptr = 0;
                }
                i++;
            } while (stroka[i] != '\0');
            if (ptr) cout << ptr;
            cout << endl;
        }
            break;
        case '2': {
            cout << "Выход из программы..."; return 0;
        }
            break;
        default:{
            cout << "Не сущетсвует такой опции, пробуйте еще раз \n";
        }break;
        }
    }while (*choice != '2');
    return 0;
}