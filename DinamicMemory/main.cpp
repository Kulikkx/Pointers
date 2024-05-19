﻿//DynamicMemory DynamicTemplatedOptimisation
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double  arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(char  arr[], const int n);
void FillRand(int** arr, const int ROWS, const int COLS);
void FillRand(double** arr, const int ROWS, const int COLS, int minRand = 0, int maxRand = 100);
void FillRand(char** arr, const int ROWS, const int COLS);
template <typename T>void Print(T arr[], const int n);
template <typename T>void Print(T** arr, const int ROWS, const int COLS);
template <typename T>void Clear(T** arr, const int ROWS);

template <typename T> T* push_back(T arr[], int& n, T value);
template <typename T> T* push_front(T arr[], int& n, T value);
template <typename T> T* pop_back(T arr[], int& n);
template <typename T> T* pop_front(T arr[], int& n);
template <typename T> T* insert(T arr[], int& n, int index, T value);
template <typename T> T* erase(T arr[], int& n, int index);
//Stack - это модель памяти, из которой последний записанный элемент считывается первым
//push
//pop

template <typename T> T** Allocate(const int ROWS, const int COLS);
template <typename T> T** Push_row_back(T** arr, int& ROWS, const int COLS);
template <typename T> T** Push_row_front(T** arr, int& ROWS, const int COLS);
template <typename T> T** Insert_row(T** arr, int& ROWS, const int COLS, int index);
template <typename T> T** Pop_row_back(T** arr, int& ROWS, const int COLS);
template <typename T> T** Pop_row_front(T** arr, int& ROWS, const int COLS);
template <typename T> T** Erase_row(T** arr, int& ROWS, const int COLS, int index);
template <typename T>void Push_col_back(T** arr, const int ROWS, int& COLS);
template <typename T>void Push_col_front(T** arr, const int ROWS, int& COLS);
template <typename T>void Insert_col(T** arr, const int ROWS, int& COLS, int index);
template <typename T>void Pop_col_back(T** arr, const int ROWS, int& COLS);
template <typename T>void Pop_col_front(T** arr, const int ROWS, int& COLS);
template <typename T>void Erase_col(T** arr, const int ROWS, int& COLS, int index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define PREFORMANCE_CHECK

int main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n = 0;
	cout << "Введите размер массива: "; cin >> n;
	typedef char DataType;           // директива typedef дает псевдоним (DataType) 
	DataType* arr = new DataType[n]; // существующему типу данных в данном случ"char"

	FillRand(arr, n);
	Print(arr, n);

	DataType value;
	int index;
	cout << "Введите добавляемое значение в конец массива: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое значение в начало массива: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
	cout << "Удаление последнего элемента: " << endl;
	arr = pop_back(arr, n);
	Print(arr, n);
	cout << "Удаление нулевого элемента: " << endl;
	arr = pop_front(arr, n);
	Print(arr, n);
	do
	{
		cout << "Введите индекс элемента для замены от 0  до  " << n << endl; cin >> index;
		if (index < 0 || index >= n)cout << "Такого индекса не существует" << endl;

	} while (index < 0 || index >= n);
	cout << endl;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = insert(arr, n, index, value);
	Print(arr, n);
	do
	{
		cout << "Введите индекс элемента для удаления от 0  до  " << n << endl; cin >> index;
		if (index < 0 || index >= n)cout << "Такого индекса не существует" << endl;

	} while (index < 0 || index >= n);
	arr = erase(arr, n, index);
	Print(arr, n);


	delete[] arr;

#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	typedef double DataType;
	int ROWS;
	int COLS;
	cout << "Введите количество строк: "; cin >> ROWS;
	cout << "Введите количество элементов строки: "; cin >> COLS;
	// Для указания компилятору используем <int>, это нужно чтобы компилятор знал
	// какого типа данных создавать массив иначе можем столкнуться с проблемой вывода "type deduction"
	//int** arr = Allocate <int>(ROWS, COLS);
	//double** arr = Allocate <double>(ROWS, COLS);
	DataType** arr = Allocate <DataType>(ROWS, COLS);
	int index = 0;
	FillRand(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	cout << "добавление последней стороки в массив: " << endl;
	arr = Push_row_back(arr, ROWS, COLS);
	FillRand(arr[ROWS - 1], COLS);
	Print(arr, ROWS, COLS);
	cout << "добавление нулевой стороки в массив: " << endl;
	arr = Push_row_front(arr, ROWS, COLS);
	FillRand(arr[0], COLS);
	Print(arr, ROWS, COLS);
	do
	{
		cout << "Введите индекс строки для вставки строки от 0  до  " << ROWS << endl; cin >> index;
		if (index < 0 || index > ROWS)cout << "Такого индекса не существует" << endl;

	} while (index < 0 || index > ROWS);
	arr = Insert_row(arr, ROWS, COLS, index);
	FillRand(arr[index], COLS);
	Print(arr, ROWS, COLS);
	cout << "Удаление последней строки в массиве: " << endl;
	arr = Pop_row_back(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	cout << "Удаление нулевой строки в массиве: " << endl;
	arr = Pop_row_front(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	do
	{
		cout << "Введите индекс строки для удаления от 0  до  " << ROWS << endl; cin >> index;
		if (index < 0 || index > ROWS)cout << "Такого индекса не существует" << endl;

	} while (index < 0 || index > ROWS);
	arr = Erase_row(arr, ROWS, COLS, index);
	Print(arr, ROWS, COLS);
	cout << "добавление столбика в конец массива: " << endl;
	Push_col_back(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	cout << "добавление столбика в начало массива: " << endl;
	Push_col_front(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	do
	{
		cout << "Введите индекс элемента столбца для добавлеия от 0  до  " << COLS << endl; cin >> index;
		if (index < 0 || index > COLS)cout << "Такого индекса не существует" << endl;

	} while (index < 0 || index > COLS);
	Insert_col(arr, ROWS, COLS, index);
	Print(arr, ROWS, COLS);
	cout << "Удаление столбика в конце массива: " << endl;
	Pop_col_back(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	cout << "Удаление столбика в начале массива: " << endl;
	Pop_col_front(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	do
	{
		cout << "Введите индекс элемента столбца для удаления от 0  до  " << COLS << endl; cin >> index;
		if (index < 0 || index > COLS)cout << "Такого индекса не существует" << endl;

	} while (index < 0 || index > COLS);
	Erase_col(arr, ROWS, COLS, index);
	Print(arr, ROWS, COLS);
	Clear(arr, ROWS);
#endif // DYNAMIC_MEMORY_2

#ifdef PREFORMANCE_CHECK
	int ROWS;
	int COLS;
	cout << "Введите количество строк: "; cin >> ROWS;
	cout << "Введите количество элементов строки: "; cin >> COLS;

	int** arr = Allocate(ROWS, COLS);
	cout << "Memory allocated" << endl;
	system("PAUSE");

	arr = Push_col_back(arr, ROWS, COLS);
	cout << "Row added" << endl;
	system("PAUSE");

	Clear(arr, ROWS);
	cout << "Memory clean" << endl;
#endif // PREFORMANCE_CHECK

}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)*(arr + i) = rand() % (maxRand - minRand) + minRand;
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
		*(arr + i) /= 100;
	}
}
void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)*(arr + i) = 'A' + rand() % 26;
}
void FillRand(int** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)arr[i][j] = rand() % 100;
	}
}
void FillRand(double** arr, const int ROWS, const int COLS, int maxRand, int minRand)
{
	if (maxRand < minRand)
	{
		int buffer = minRand;
		minRand = maxRand;
		maxRand = buffer;
	}
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = minRand + rand() % (maxRand - minRand);
			arr[i][j] /= 100;
		}
	}
}
void FillRand(char** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)arr[i][j] = rand();
	}
}
template <typename T> void Print(T arr[], const int n) //Вывод массивов на экран
{
	for (int i = 0; i < n; i++)cout << arr[i] << tab;
	//Обращение к элементам массива через опертор индексирования - []:
	cout << endl;
}
template <typename T>void Print(T** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)cout << arr[i][j] << tab;
		cout << endl;
	}
	cout << endl;
}
template <typename T>T* push_back(T arr[], int& n, T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	//Print(arr, n);
	return arr;
}
template <typename T> T* push_front(T arr[], int& n, T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
template <typename T> T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template <typename T> T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
	return arr;
}
template <typename T> T* insert(T arr[], int& n, int index, T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	for (int i = n; i > index; --i)arr[i] = arr[i - 1];
	arr[index] = value;
	n++;
	return arr;
}
template <typename T> T* erase(T arr[], int& n, int index)
{
	T* buffer = new T[n];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index + 1; i < n; i++)buffer[i - 1] = arr[i];
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
template <typename T> T** Allocate(const int ROWS, const int COLS)
{
	T** arr = new T * [ROWS];
	//2) Выделяем память под строки:
	for (int i = 0; i < ROWS; i++)arr[i] = new T[COLS]{};
	return arr;
}
template <typename T>void Clear(T** arr, const int ROWS)
{
	//1) Cначала удаляем строки:
	for (int i = 0; i < ROWS; i++)delete[] arr[i];
	//2) Удаляем массив указателей, обнуляем указатель и сбрасываем строки и элмен.строк.
	delete[] arr;
	arr = nullptr;
	//ROWS = 0;
	//COLS = 0;
	cout << "Массив удалён, память отчищена!!!" << endl;
}
template <typename T> T** Push_row_back(T** arr, int& ROWS, const int COLS)
{
	return push_back(arr, ROWS, new T[COLS]{});

}
template <typename T> T** Push_row_front(T** arr, int& ROWS, int COLS)
{
	return push_front(arr, ROWS, new T[COLS]{});

}
template <typename T> T** Insert_row(T** arr, int& ROWS, const int COLS, int index)
{
	return insert(arr, ROWS, index, new T[COLS]{});
}
template <typename T> T** Pop_row_back(T** arr, int& ROWS, const int COLS)
{
	delete[] arr[ROWS - 1]; // удаляем удаляемую строку из памяти 
	return pop_back(arr, ROWS);
}
template <typename T> T** Pop_row_front(T** arr, int& ROWS, const int COLS)
{
	delete[] arr[0];
	// удаляем удаляемую строку из памяти 
	return pop_front(arr, ROWS);
}
template <typename T> T** Erase_row(T** arr, int& ROWS, const int COLS, int index)
{
	delete[] arr[index]; // удаляем удаляемую строку из памяти 
	return erase(arr, ROWS, index);
}
template <typename T>void Push_col_back(T** arr, const int ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		arr[i] = push_back(arr[i], COLS, T());
		COLS--;
	}
	COLS++;
}
template <typename T>void Push_col_front(T** arr, const int ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		arr[i] = push_front(arr[i], COLS, T());
		COLS--;
	}
	COLS++;
}
template <typename T>void Insert_col(T** arr, const int ROWS, int& COLS, int index)
{
	for (int i = 0; i < ROWS; i++)
	{
		arr[i] = insert(arr[i], COLS, index, T());
		COLS--;
	}
	COLS++;
}
template <typename T>void Pop_col_back(T** arr, const int ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		T* buffer = new T[COLS - 1];
		for (int j = 0; j < COLS - 1; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	COLS--;
}
template <typename T>void Pop_col_front(T** arr, const int ROWS, int& COLS)
{

	for (int i = 0; i < ROWS; i++)
	{
		T* buffer = new T[COLS - 1];
		for (int j = 0; j < COLS - 1; j++)buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	COLS--;
}
template <typename T>void Erase_col(T** arr, const int ROWS, int& COLS, int index)
{
	for (int i = 0; i < ROWS; i++)
	{
		T* buffer = new T[COLS - 1];
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		for (int j = index; j < COLS - 1; j++)buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	COLS--;
}