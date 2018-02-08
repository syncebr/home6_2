/*Массив из 20-ти элементов заполнить случайными числами от 0 до 20.
Упорядочить элементы, стоящие на четных местах, по возрастанию, а на нечетных – по убыванию.*/

#include<iostream>
#include<ctime>
using namespace std;

void PrintArr(int arr[], int size);
void GenerateArr(int arr[], int size);
void SortArrIncrease(int arr[], int size);
void SortArrDecrease(int arr[], int size);

int main(void) {
	setlocale(LC_ALL, "rus");
	const int SIZE = 20;
	int arr[SIZE];
	GenerateArr(arr, SIZE);
	cout << "Ваш массив:" << endl;
	PrintArr(arr, SIZE);
	SortArrIncrease(arr+1, SIZE);
	cout << "Ваш массив:" << endl;
	PrintArr(arr, SIZE);
	SortArrDecrease(arr, SIZE);
	cout << "Ваш массив:" << endl;
	PrintArr(arr, SIZE);
	system("pause");
	return 0;
}

//функция генерации массива
void GenerateArr(int arr[], int size) {
	int *ptrArr = arr;
	while (ptrArr < (arr + size)) {
		*ptrArr = rand() % 51;
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
//сортируем четные элементы по возрастанию
void SortArrIncrease(int arr[], int size) {
	int tmp, j;
	for (int i = 0; i<size - 2; i+=2) //i-номер последнего из упорядоченных
	{
		tmp = arr[i + 2]; //сохранить копию вставляемого элемента
		j = i;    //j- индекс элемента, после которого может быть вставка
		while (j >= 0 && arr[j]>tmp)  //пока не найдено место
		{
			arr[j + 2] = arr[j];  //сдвиг элемента вправо
			j-=2;
		}
		arr[j + 2] = tmp;   //вставка на место
	}
}
//сортируем нечетные элементы по убыванию
void SortArrDecrease(int arr[], int size) {
	int tmp, j;
	for (int i = 0; i<size - 2; i += 2) //i-номер последнего из упорядоченных
	{
		tmp = arr[i + 2]; //сохранить копию вставляемого элемента
		j = i;    //j- индекс элемента, после которого может быть вставка
		while (j >= 0 && arr[j]<tmp)  //пока не найдено место
		{
			arr[j + 2] = arr[j];  //сдвиг элемента вправо
			j -= 2;
		}
		arr[j + 2] = tmp;   //вставка на место
	}
}
