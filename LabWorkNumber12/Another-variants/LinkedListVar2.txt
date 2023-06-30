#include <iostream>
using namespace std;

struct Element {
    int number;
    Element* next;
    bool flag_to_delete;
};

typedef Element** head_of_list;

Element* FindEndOfList(head_of_list head) {
    Element* ptr = *head;
    while (ptr->next) 
        ptr = ptr->next;
    return ptr;
}

void AddElementToList(head_of_list head, int num) {
    Element* ptr = new Element();
    ptr->number = num;
    ptr->next = NULL;
    ptr->flag_to_delete = false;
    if (*head == NULL)
        *head = ptr;
    else
        FindEndOfList(head)->next = ptr;
}

void PrintList(Element* head) {
    if (!head)
        cout << "the end of list \n";
    else {
        cout << head->number << endl;
        PrintList(head = head->next);
    }
}

void DeleteList(head_of_list head) {
    Element* ptr = NULL;
    *head = NULL;
    while (ptr) {
        ptr = *head;
        *head = ptr->next;
        delete ptr;
    }
}

void FindAndShowMinAndMaxNumber(head_of_list head) {
    if (*head) {
        Element* ptr = *head;
        Element* minptr = *head;
        Element* maxptr = *head;
        while (ptr) {
            if (minptr->number >= ptr->number)
                minptr = ptr;
            if (maxptr->number <= ptr->number)
                maxptr = ptr;
            ptr = ptr->next;
        }
        cout << "Min is - " << minptr->number << endl;
        cout << "Max is - " << maxptr->number << endl;
    }
}

void CountList(Element* head) {
    int counter = 0;
    Element* ptr = head;
    while (ptr) {
        ptr = ptr->next;
        counter++;
    }
    cout << "Size of that list - " << counter << endl << endl;
}

void ShowInfoAboutLists(Element* firstList, Element* secondList) {
    if (firstList != NULL && secondList != NULL) {
        cout << "Main list : \n"; PrintList(firstList);
        FindAndShowMinAndMaxNumber(&firstList);
        CountList(firstList);
        cout << "SecondList list : \n"; PrintList(secondList);
        FindAndShowMinAndMaxNumber(&secondList);
        CountList(secondList);
    }
    else 
        cout << "Lists are empty..." << endl;
}

void AppendList(head_of_list source, head_of_list destination) {
    Element* ptr = FindEndOfList(source);
    ptr->next = *destination;
}

int CheckAndSetSize() {
    int size_of_list;
    do {
        cout << "Set size of List : ";
        cin >> size_of_list;
    } while (size_of_list <= 0);
    return size_of_list;
}

void WriteElementsToList(head_of_list destination) {
    int size_of_list = CheckAndSetSize();
    int element_to_push;
    for (int i = 0; i < size_of_list; i++) {
         element_to_push = rand() % 100 - 10;
        AddElementToList(destination, element_to_push);
    }
}

int main() {
    setlocale(0, "rus");
    srand(time(NULL));

    Element* List = NULL;
    Element* ListNew = NULL;

    WriteElementsToList(&List);
    WriteElementsToList(&ListNew);
    
    ShowInfoAboutLists(List, ListNew);

    AppendList(&List, &ListNew);
    cout << "Result of the merging \n";

    ShowInfoAboutLists(List, ListNew);

    DeleteList(&List);
    DeleteList(&ListNew);

    ShowInfoAboutLists(List, ListNew);
}
