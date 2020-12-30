#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <functional>
#include <numeric>

using namespace std;
int kvid(const int arr[], int n);
bool find_less_mod(int val1, int val2)
{
	return abs(val1) < abs(val2);//Якщо модуль val1 меньше модуля val2 повернемо 1, якщо ні - 0
}

int sum_mod(int val1, int val2)
{
	return abs(val1) + abs(val2);//Повертаємо сумму модулів элементів
}
int main()
{
	size_t n = 0;
	int temp;
	
	cout << " Vvedit rozmir masiva "; cin >> n;
	int* arr = new int[n];



	for (int i = 0; i <= n - 1; i++)
	{
		cout << " Vvedit " << i << " Element masiva : ";
		cin >> arr[i];
	}
	size_t ind = min_element(arr, arr + n, find_less_mod) - arr;
	cout << "Index of minimal element by modul: " << ind << endl;//Шукаємо мінімальний по модулю елемент
//за допомогою стандартного алгоритма min_element, після чого віднімаємо з нього адресу покажчика
// на масив, отримуємо порядковий номер в масиві мінімального за модулем елемента
	cout << "Sum: " << accumulate(find_if(arr, arr + n, bind2nd(less<int>(), 0)) + 1, arr + n, 0, sum_mod) << endl; //Рахуємо сумму через accumulate. Перший параметр стандартний алгоритм find_if
//який шукає перший елемент менше нуля, додаємо до значення 1, отримуємо
// покажчик на наступний за першим елементом більше нуля.
// Від цього покажчика до покажчика на кінець масиву, складаємо елементи масиву функцією
// сума по модулю.
	cout << "Kilkist videmnih = " << kvid(arr, n) << endl;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0){
			arr[i] *= arr[i];
	}
	}
	cout << "Novii vidsortovanii masiv: ";
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{

				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	cout << endl << endl;

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	system("pause");
}
int kvid(const int arr[], int n)
{

	int m = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			m++;
		}
	}
	return m;
}