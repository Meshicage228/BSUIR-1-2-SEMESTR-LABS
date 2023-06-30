#include <iostream>
using namespace std;
int main()
{
	char choice[80];
	bool des = true;
	do {
		int stroka, stolb;
		cout << "Stroka(N) : "; cin >> stroka; cout << endl;
		cout << "Stolb(M): "; cin >> stolb; cout << endl;
		cout << "Your array : " << stroka << "*" << stolb << ":::" << endl;
		int** arr = new int* [stroka];
		for (int i = 0; i < stroka; i++){
			arr[i] = new int[stolb];
		}
		for (int i = 0; i < stroka; i++){
			for (int j = 0; j < stolb; j++){
				arr[i][j] = rand() % 100 - 20;
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "Sorted array for the stroki : " << endl;
		int min = 0;
		int counter = 0;
		for (int i = 0; i < stroka; i++){
			int min = i;
			for (int i = counter; i < stroka; i++){
				if (arr[min][0] > arr[i][0]){
					min = i;
				}
			}
			for (int j = 0; j < stolb; j++){
				swap(arr[counter][j], arr[min][j]);
			}
			counter++;
		}
		cout << endl;
		for (int i = 0; i < stroka; i++){
			for (int j = 0; j < stolb; j++){
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		for (int i = 0; i < stroka; i++){
			delete[] arr[i];
		}
		delete[] arr;
		cout << "Want to continue ? Yes(1) No(0) : ";
	point : 
		cin >> choice; 
		if (strlen(choice) >= 2){
			cout << "Wrong number, try again... \n";
			goto point;
		}
		switch (*choice){
		case '1': des = true; break;
		case '0': des = false; break;
		default: cout << "Wrong number, try again ... \n"; goto point;
		}
	} while (des);
	return 0; 
}