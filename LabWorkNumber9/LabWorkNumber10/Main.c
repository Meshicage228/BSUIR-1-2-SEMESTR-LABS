#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //argc, char* arfv[];
    char g[25];
    gets(g);
    int choice;
    do {
        printf("Выбирите пункт меню:\n 1.Ввести символьную строку, заменить все буквы 'a' на буквы 'б' как заглавные, так и строчные. \n 2.Ввести предложение и определить, сколько слов заканчиваются набукву 'а'. \n 3.Ввести полный адрес файла (возможно, без расширения) и изменить его расширение на «.exe». \n 4.Разработать функцию, которая удаляет все лишние пробелы(в начале предложения и сдвоенные пробелы).\n 5.Завершить программу\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            char f[25];
            int i;
            printf("Введите строку.\n");
            scanf("%s", f);
            puts(f);
            i = 0;
            while (f[i] != '\0')
            {
                if (f[i] == 'A') f[i] = 'b';
                if (f[i] == 'a') f[i] = 'b';
                i++;
            }
            printf("Результат: %s", f);
        }
        break;
        case 2:
        {
            char q[80];
            int i, len, count = 0;
            printf("Введите предложение\n");
            gets(q);
            len = strlen(q);
            for (i = 0; i < len - 1; i++)
            {
                if (q[i] == ' ' && q[i - 1] == 'a')
                    count++;
            }
            if (q[len - 1] == 'a')
                count++;
            printf("Найдено %d слов", count);
        }
        break;
        case 3:
        {
            char q[50];
            printf("Введите строку.\n");
            gets(q);
            int len = strlen(q);
            int i = len;
            while (q[i] != '.') {
                if (q[i] == q[0]) break;
                i--;
            }

            if (q[i] == '.')
                strcpy(q + i, ".exe");
            else strcat(q, ".exe");
            puts("Результат:");
            puts(q);
        }
        break;
        case 4:
        {
            char str[101] = "";
            char res[101] = "";
            printf("Введите строку:");
            gets(str);
            int j = 0;
            int i;
            int len = strlen(str);
            for (i = 0; i < len; i++) {
                if (str[i] == ' ')
                {
                    if (j == 0) continue;
                    if (str[i + 1] == ' ') continue;
                }
                res[j] = str[i];
                j++;
            }
            i = strlen(res);
            if (res[i - 2] == ' ')
                res[i - 2] = '\0';
            printf("\nРезультат:%s", res);
            getchar();

        }
        break;
        case 5:
            return 0;
            break;
        default:
            printf("Ошибка!Такой пункт меню отсутствует!\n");
            break;
        }
    } while (choice != 5);
    return 0;
}