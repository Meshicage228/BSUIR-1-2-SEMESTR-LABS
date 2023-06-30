#include <iostream>
using namespace std;
void RandomArray(int arr[], int size) {
    cout << "Array : " << endl;
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 60 - 30;
        cout << arr[i] << " ";
    }
    cout << endl;
}
void ShowArray(int arr[], int size) {
    cout << "Sorted version : " << endl;
    for (int i = 0; i < 30; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void BubbleSort(int arr[], int start, int size) {
    for (int i = start; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
    ShowArray(arr, size);
}
void InsertionSort(int arr[], int start, int size) {
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
    ShowArray(arr, size);
}
int Partition(int arr[], int start, int end_point) {
    int i = start;
    while (i < end_point) {
        if (arr[i] > arr[end_point] && i == end_point - 1) {
            swap(arr[i], arr[end_point]);
            end_point--;
        }
        else if (arr[i] > arr[end_point]) {
            swap(arr[end_point - 1], arr[end_point]);
            swap(arr[i], arr[end_point]);
            end_point--;
        }
        else i++;
    }
    return end_point;
}
void QuickSort(int arr[], int start, int end) {
    if (start < end) {
        int pivot = Partition(arr, start, end);
        QuickSort(arr, start, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}
void ShellSort(int arr[], int n) {
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }
    ShowArray(arr, n);
}
void merge(int arr[], int low, int high, int middle) {
    int i = low;
    int counter = low;
    int* copy = new int[high];
    int j = middle + 1;
    while (i <= middle && j <= high) {
        if (arr[i] <= arr[j]) {
            copy[counter] = arr[i]; i++; counter++;
        }
        else {
            copy[counter] = arr[j]; j++; counter++;
        }
    }
    while (i <= middle) {
        copy[counter] = arr[i]; i++; counter++;
    }
    while (j <= middle) {
        copy[counter] = arr[j]; j++; counter++;
    }
    for (int i = low; i < counter; i++) {
        arr[i] = copy[i];
    }
}
void MergeSort(int arr[], int low, int high) {
    if (low < high) {
        int middle = (low + high) / 2;
        MergeSort(arr, low, middle);
        MergeSort(arr, middle + 1, high);
        merge(arr, low, high, middle);
    }
}

int main() {
    srand(time(NULL));
    int option;
    do {
        cout << "1.ShellSort \n2.BubbleSort \n3.QuickSort \n4.InsertionSort \n5.IndividualTask\n6.Quit\nOption: ";
        cin >> option;
        int arr[30];
        RandomArray(arr, 30);
        switch (option) {
        default: cout << "No such option given...\n"; break;
        case 1: ShellSort(arr, 30); break;
        case 2: BubbleSort(arr, 0, 30); break;
        case 3: QuickSort(arr, 0, 29); ShowArray(arr, 30); break;
        case 4: InsertionSort(arr, 0, 30); break;
        case 5: MergeSort(arr, 0, 29); ShowArray(arr, 30); break;
        case 6: cout << "Quit...";  break;
        }
    } while (option != 6);
}