#include <iostream>
using namespace std;
struct box {
    int data;
    box* next;
};
struct controle {
    int count;
    int size;
    box* front;
    box* rear;
};
void inici(controle* q) {
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}
int empty(controle* q) {
    return (q->count == NULL);
}
void addqueue(controle* q, int num) {
    if (q->count < q->size) {
        box* ptr = new box();
        ptr->data = num;
        ptr->next = NULL;
        if (!empty(q)) {
            q->rear->next = ptr;
            q->rear = ptr;
        }
        else {
            q->front = q->rear = ptr;
        }
        q->count++;
    }
    else cout << "Вы не можете добавить " << num << " Очередь полна\n";
}
void show(box* q) {
    if (q == NULL) {
        cout << "Конец очереди..\n";
    }
    else {
        cout << q->data << endl;
        show(q = q->next);
    }
}
void delete_negative_num(controle* qptr) {
    box* ptr = qptr->front;
    while (ptr) {
        if (ptr->data < 0 && ptr == qptr->front) {
            box* newptr = qptr->front;
            qptr->front = qptr->front->next;
            delete[] newptr;
            qptr->count--;
            break;
        }
        else if (ptr->data != 0 && ptr->next == qptr->rear && qptr->rear->data < 0) {
            delete[] qptr->rear;
            qptr->rear = ptr;
            qptr->rear->next = NULL;
            qptr->count--;
            break;
        }
        else {
            if (ptr->next->data < 0) {
                box* newptr = ptr->next;
                ptr->next = ptr->next->next;
                delete[] newptr;
                qptr->count--;
                break;
            }
        }
        ptr = ptr->next;
    }
}
void search_negative(controle* head) {
    box* ptr = head->front;
    int a = 0;
    while (ptr)
    {
        if (ptr->data < 0) {
            delete_negative_num(head);
            a = 1;
            cout << "После : \n";
            show(head->front);
            break;
        }
        ptr = ptr->next;
    }
    if (!a) cout << "Не найдено отрицательного числа!";
}
int count_even_num(controle * que) {
    box* ptr = que->front;
    int counter = 0;
    while (ptr) {
        if (ptr->data % 2 == 0) counter++;
        ptr = ptr->next;
    }
    return counter;
}
int count_even_num2(box* que) {
    static int counter = 0;
    if (que == NULL) return counter;
    else {
        if (que->data % 2 == 0) counter++;
        count_even_num2(que = que->next);
    }
}
int main()
{
    setlocale(0, "rus");
    srand(time(NULL));
    controle* que = new controle();
    inici(que);
    int num;
    cout << "Кол-во элементов очереди : ";
    cin >> num; que->size = num;
    for (int i = 0; i < num; i++) {
        int chisl = rand() % 100 - 30;
        addqueue(que, chisl);
    }
    cout << "Сгенерированная очередь : \n";
    show(que->front);
    cout << "Кол-во четных элементов(рукурсией) : " << count_even_num2(que->front) << endl;
    cout << "Кол-во четных элементов(простым перебором) : " << count_even_num(que) << endl;
    search_negative(que);
    cout << endl;
    return 0;
}