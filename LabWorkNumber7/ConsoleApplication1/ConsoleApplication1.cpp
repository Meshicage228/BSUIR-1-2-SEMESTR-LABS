#include <iostream>
#include <cstring>
#include <stdio.h>
#include <Windows.h>
using namespace std;

struct team {
    char strana[20];
    char nameofteam[20];
    char name[30];
    int year;
    int numberofplayer;
    int height;
    int weight;
};
void info(team& t) {
    cout << "Страна:";
    cin >> t.strana;
    cout << "Имя:";
    cin >> t.name;
    cout << "Возраст:";
    cin >> t.year;
    cout << "Номер игрока:";
    cin >> t.numberofplayer;
    cout << "Рост игрока:";
    cin >> t.height;
    cout << "Вес игрока:";
    cin >> t.weight;
    cout << "\n";
}
team* SizeAndMemory(team* teamnum, int& size) {
    static int counter = 1;
    cout << "Напишите кол-во игроков " << counter++ << " команды : ";
    do {
        cin >> size;
        if (size <= 0) {
            cout << "Неверное кол-во игроков!: ";
        }
    } while (size <= 0);
    teamnum = new team[size];
    return teamnum;
}
void ShowInfo(team it[], const char* name, int size) {
    cout << "Информация о самой молодой команде (" << name << ")\n";
    cout << "Информация о самой молодой команде (" << name << ")\n";
    for (int i = 0; i < size; i++) {
        int number = i + 1;
        cout << "Страна игрока N" << number << " : " << it[i].strana << endl;
        cout << "Имя игрока N" << number << " : " << it[i].name << endl;
        cout << "Возраст игрока N" << number << " : " << it[i].year << endl;
        cout << "Номер игрока N" << number << " : " << it[i].numberofplayer << endl;
        cout << "Рост игрока N" << number << " : " << it[i].height << endl;
        cout << "Вес игрока N" << number << " : " << it[i].weight << endl;
        cout << endl;
    }
}
void WriteAllInformation(team t[], int sizeofcommand, int& sum) {
    for (int i = 0; i < sizeofcommand; i++) {
        cout << "Введите информацию об игроке команды: " << endl;
        info(t[i]);
        sum += t[i].year;
    }
}
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char choice[20];
    team* team1 = NULL;
    team* team2 = NULL;
    team* team3 = NULL;
    do {
        cout << "1.Ввод данных и результат программы\n";
        cout << "2.Выход из меню\n";
        cout << "Ваша опция : ";
        do{
            cin >> choice;
        if (strlen(choice) >= 2) {
            cout << "Не сущетсвует такой опции, пробуйте еще раз : ";    
        }
         }while (strlen(choice) >= 2);
        switch (*choice) {
        case '1': {
            int numbercom1, numbercom2, numbercom3;
            int sum1 = 0, sum2 = 0, sum3 = 0;

            team1 = SizeAndMemory(team1, numbercom1);
            cout << "Напишите название команды :";
            cin >> team1->nameofteam;
            WriteAllInformation(team1, numbercom1, sum1);

            team2 = SizeAndMemory(team2, numbercom2);
            cout << "Напишите название команды :";
            cin >> team2->nameofteam;
            WriteAllInformation(team2, numbercom2, sum2);

            team3 = SizeAndMemory(team3, numbercom3);
            cout << "Напишите название команды :";
            cin >> team3->nameofteam;
            WriteAllInformation(team3, numbercom3, sum3);

            if (sum1 < sum2 && sum1 < sum3 && numbercom1 > 0) {
                ShowInfo(team1, team1->nameofteam, numbercom1);
            }
            else if (sum2 < sum1 && sum2 < sum3 && numbercom2 > 0) {
                ShowInfo(team2, team2->nameofteam, numbercom2);
            }
            else {
                if (numbercom3 > 0) ShowInfo(team3, team3->nameofteam, numbercom3);
            }
            delete[]team1;
            delete[]team2;
            delete[]team3;
        }
                break;
        case '2': cout << "Завершение программы..."; return 0;
        }
    } while (*choice != 2);
    return 0;
}