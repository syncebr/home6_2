/*Дан отсортированный по возрастанию массив целых чисел, элементы которого не повторяются 
(заполнить случайными числами от 0 до 50, а затем отсортировать). Запросить у пользователя значение элемента.
Если такой элемент имеется в массиве, то  удалить его (сдвинуть влево оставшуюся часть массива).
Если такого элемента нет, то вывести сообщение. Использовать указатели для продвижения по массиву.*/

#include<iostream>
#include<ctime>
using namespace std;


void PrintArr(int arr[], int size);
void GenerateArr(int arr[], int size);
void SortArr(int arr[], int size);
void DeleteElement(int arr[], int size);

int main(void) {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	const int SIZE = 15;
	int arr[SIZE];
	GenerateArr(arr, SIZE);
	SortArr(arr, SIZE);
	cout << "Ваш массив:" << endl;
	PrintArr(arr, SIZE);
	DeleteElement(arr, SIZE);
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
		printf("%2d\t", *ptrArr);
		ptrArr++;
	}
	cout << endl;
}

void SortArr(int arr[], int size) {
	int tmp,j;
	for (int i = 0; i<size - 1; i++) //i-номер последнего из упорядоченных
	{
		tmp = arr[i + 1]; //сохранить копию вставляемого элемента
		j = i;    //j- индекс элемента, после которого может быть вставка
		while (j >= 0 && arr[j]>tmp)  //пока не найдено место
		{
			arr[j + 1] = arr[j];  //сдвиг элемента вправо
			j--;
		}
		arr[j + 1] = tmp;   //вставка на место
	}
}

void DeleteElement(int arr[], int size) {
	int element;
	cout <<"Введите элемент, который хотите удалить: ";
	cin >> element;
	int *ptrArr;
	bool flag = false;
	ptrArr = arr;
	//находим элемент в массиве равный введенному элементу
	while (ptrArr < (arr + size)) {
		if (*ptrArr == element) break;
		ptrArr++;
	}
	if (ptrArr >= (arr + size)) {
		cout << "элемент не найден!" << endl;
		flag = true;
	}
	while (ptrArr < (arr + size)) {
		*ptrArr = *(ptrArr + 1);
		ptrArr++;
	}
	
	if (!flag) {
		size--;
		PrintArr(arr, size);
	}
	
	DeleteElement(arr, size);
}
