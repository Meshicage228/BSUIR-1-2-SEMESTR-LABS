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
        printf("�������� ����� ����:\n 1.������ ���������� ������, �������� ��� ����� 'a' �� ����� '�' ��� ���������, ��� � ��������. \n 2.������ ����������� � ����������, ������� ���� ������������� ������� '�'. \n 3.������ ������ ����� ����� (��������, ��� ����������) � �������� ��� ���������� �� �.exe�. \n 4.����������� �������, ������� ������� ��� ������ �������(� ������ ����������� � ��������� �������).\n 5.��������� ���������\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            char f[25];
            int i;
            printf("������� ������.\n");
            scanf("%s", f);
            puts(f);
            i = 0;
            while (f[i] != '\0')
            {
                if (f[i] == 'A') f[i] = 'b';
                if (f[i] == 'a') f[i] = 'b';
                i++;
            }
            printf("���������: %s", f);
        }
        break;
        case 2:
        {
            char q[80];
            int i, len, count = 0;
            printf("������� �����������\n");
            gets(q);
            len = strlen(q);
            for (i = 0; i < len - 1; i++)
            {
                if (q[i] == ' ' && q[i - 1] == 'a')
                    count++;
            }
            if (q[len - 1] == 'a')
                count++;
            printf("������� %d ����", count);
        }
        break;
        case 3:
        {
            char q[50];
            printf("������� ������.\n");
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
            puts("���������:");
            puts(q);
        }
        break;
        case 4:
        {
            char str[101] = "";
            char res[101] = "";
            printf("������� ������:");
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
            printf("\n���������:%s", res);
            getchar();

        }
        break;
        case 5:
            return 0;
            break;
        default:
            printf("������!����� ����� ���� �����������!\n");
            break;
        }
    } while (choice != 5);
    return 0;
}