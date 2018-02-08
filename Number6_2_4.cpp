/*Массив из 10-ти элементов заполнить случайными числами от 0 до 5. 
Пользуясь указателями, найти максимальное количество подряд идущих нулей.*/

#include<iostream>
#include<ctime>
using namespace std;

void PrintArr(int arr[], int size);
void GenerateArr(int arr[], int size);
int MaxZeroStreak(int arr[], int size);

int main(void) {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	const int SIZE = 20;
	int maxZeroStreak;
	int arr[SIZE];
	GenerateArr(arr, SIZE);
	cout << "Ваша массив:" << endl;
	PrintArr(arr, SIZE);
	maxZeroStreak = MaxZeroStreak(arr, SIZE);
	cout << "максимальная длинна 0= " << maxZeroStreak<<endl;
	system("pause");
	return 0;
}

//функция генерации массива
void GenerateArr(int arr[], int size) {
	int *ptrArr = arr;
	while (ptrArr < (arr + size)) {
		*ptrArr = rand() % 6;
		ptrArr++;
	}
}
//функция вывода массива
void PrintArr(int arr[], int size) {
	int *ptrArr = arr;
	if (size == 0) cout << "массив пуст";
	while (ptrArr < (arr + size)) {
		printf("%2d   ", *ptrArr);
		ptrArr++;
	}
	cout << endl;
}

int MaxZeroStreak(int arr[], int size) {
	int maxStreak=0;
	int tmp;
	int *ptrArr;
	ptrArr = arr;
	while (ptrArr < (arr + size)) {
		tmp = 1;
		if (*ptrArr == 0) {
			tmp = 0;
			while (*ptrArr == 0 && ptrArr<(arr+size)) {
				tmp++;
				ptrArr++;
			}
			if(maxStreak<tmp) maxStreak = tmp;
		}
		ptrArr += tmp;
	}
	return maxStreak;
}
