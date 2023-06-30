#include <iostream>
using namespace std;

struct Box {
    int number;
    Box* next;
};

typedef Box** head;

Box* EndList(head head) {
    Box* ptr = *head;
    while (ptr->next)
        ptr = ptr->next;
    return ptr;
}

void AddBoxToList(head head, int num) {
    Box* ptr = new Box();
    ptr->number = num;
    ptr->next = NULL;
    if (*head == NULL)
        *head = ptr;
    else
        EndList(head)->next = ptr;
}

void PrintList(Box* head) {
    Box* ptr = head;
    cout << "Start of the list :\n";
    while (ptr) {
        cout << ptr->number << endl;
        ptr = ptr->next;
    }
    cout << "End of the list..,\n\n";
}

void DeleteList(head head) {
    Box* ptr = NULL;
    *head = NULL;
    while (ptr) {
        ptr = *head;
        *head = ptr->next;
        delete ptr;
    }
}
void FindMax(Box* head) {
    if (head) {
        Box* ptr = head;
        Box* maxptr = head;
        while (ptr) {
            if (maxptr->number <= ptr->number)
                maxptr = ptr;
            ptr = ptr->next;
        }
        cout << "Max is - " << maxptr->number << endl;
    }
}
void FindMin(Box* head) {
    if (head) {
        Box* ptr = head;
        Box* maxptr = head;
        while (ptr) {
            if (maxptr->number >= ptr->number)
                maxptr = ptr;
            ptr = ptr->next;
        }
        cout << "Min is - " << maxptr->number << endl;
    }
}
int CountList(Box* head) {
    int counter = 0;
    Box* ptr = head;
    while (ptr) {
        ptr = ptr->next;
        counter++;
    }
    return counter;
}

void ShowInfoAboutList(Box* head) {
    if (head != NULL) {
        cout << "Main list : \n";
        PrintList(head);
        FindMax(head);
        FindMin(head);
        cout << "Size of that list : " << CountList(head) << endl << endl;
    }
    else
        cout << "List is empty..." << endl;
}
int CheckAndSetSize() {
    int size_of_list;
    do {
        cout << "Set size of List : ";
        cin >> size_of_list;
    } while (size_of_list <= 0);
    return size_of_list;
}

void FillList(head top) {
    int size_of_list = CheckAndSetSize();
    int Box_to_push;
    for (int i = 0; i < size_of_list; i++) {
        Box_to_push = rand() % 100 - 10;
        AddBoxToList(top, Box_to_push);
    }
}
void DeleteKFirst(head top, int k) {
    int counter = 0;
    Box* ptr = NULL;
    while (counter < k) {
        ptr = *top;
        *top = ptr->next;
        delete ptr;
        counter++;
    }
}
int main() {
    setlocale(0, "rus");
    srand(time(NULL));

    Box* List = NULL;

    FillList(&List);

    ShowInfoAboutList(List);

    int k = 0;
    int size = CountList(List);
    do {
        cout << "Write k that is <= " << size << endl;
        cin >> k;
    } while (k > size || k < 0);

    DeleteKFirst(&List, k);

    ShowInfoAboutList(List);
}
