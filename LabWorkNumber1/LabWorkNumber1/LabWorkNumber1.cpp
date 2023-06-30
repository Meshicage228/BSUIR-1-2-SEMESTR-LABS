#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double radian;
	double result;
	double usersSuggestion;
	cout << "Введите радиан : ";
	cin >> radian;
	if (radian < 0) // Замена отрицательного радиана на положительный
	{
		cout << "Вы ввели отрицательный радиан!!!! Меняем его на положительный... \n";
		radian = abs(radian);
	}
	result = cos(radian);
	result = round(result * 10) / 10;
	cout << result;
	//cout.precision(20); // Ставим фиксированное количество знаков после запятой, так как переменные типа double
	cout << "Попробуйте для начала угадать ответ задачи cos(" << radian << ") : ";
	cin >> usersSuggestion;
	if (usersSuggestion == result) // Проверка истинности 
	{
		cout << "Поздравляем!!! Ваш ответ полностью совпал, так как результат вычисления : " << result;
	}
	else
	{
		cout << "Ваш ответ не совпал, действительный ответ : " <<  result << endl;
	}
	return 0;
}
