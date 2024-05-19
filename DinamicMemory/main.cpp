//DynamicMemory
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int ROWS, const int COLS);
void Print(int arr[], const int n);
void Print(int** arr, const int ROWS, const int COLS);
void Clear(int** arr, const int ROWS);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* insert(int arr[], int& n, int index, int value);
int* erase(int arr[], int& n, int index);
//Stack - ��� ������ ������, �� ������� ��������� ���������� ������� ����������� ������

int** Allocate(const int ROWS, const int COLS);
int** Push_row_back(int** arr, int& ROWS, const int COLS);
int** Push_row_front(int** arr, int& ROWS, const int COLS);
int** Insert_row(int** arr, int& ROWS, const int COLS, int index);
int** Pop_row_back(int** arr, int& ROWS, const int COLS);
int** Pop_row_front(int** arr, int& ROWS, const int COLS);
int** Erase_row(int** arr, int& ROWS, const int COLS, int index);
void Push_col_back(int** arr, const int ROWS, int& COLS);
void Push_col_front(int** arr, const int ROWS, int& COLS);
void Insert_col(int** arr, const int ROWS, int& COLS, int index);
void Pop_col_back(int** arr, const int ROWS, int& COLS);
void Pop_col_front(int** arr, const int ROWS, int& COLS);
void Erase_col(int** arr, const int ROWS, int& COLS, int index);



//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define PREFORMANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n = 0;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	int index;
	cout << "������� ����������� �������� � ����� �������: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "������� ����������� �������� � ������ �������: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
	cout << "�������� ���������� ��������: " << endl;
	arr = pop_back(arr, n);
	Print(arr, n);
	cout << "�������� �������� ��������: " << endl;
	arr = pop_front(arr, n);
	Print(arr, n);
	do
	{
		cout << "������� ������ �������� ��� ������ �� 0  ��  " << n << endl; cin >> index;
		if (index < 0 || index >= n)cout << "������ ������� �� ����������" << endl;

	} while (index < 0 || index >= n);
	cout << endl;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = insert(arr, n, index, value);
	Print(arr, n);
	do
	{
		cout << "������� ������ �������� ��� �������� �� 0  ��  " << n << endl; cin >> index;
		if (index < 0 || index >= n)cout << "������ ������� �� ����������" << endl;

	} while (index < 0 || index >= n);
	arr = erase(arr, n, index);
	Print(arr, n);


	delete[] arr;

#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int ROWS;
	int COLS;
	cout << "������� ���������� �����: "; cin >> ROWS;
	cout << "������� ���������� ��������� ������: "; cin >> COLS;

	int** arr = Allocate(ROWS, COLS);

	int index = 0;
	FillRand(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	cout << "���������� ��������� ������� � ������: " << endl;
	arr = Push_row_back(arr, ROWS, COLS);
	FillRand(arr[ROWS - 1], COLS, 100, 1000);
	Print(arr, ROWS, COLS);
	cout << "���������� ������� ������� � ������: " << endl;
	arr = Push_row_front(arr, ROWS, COLS);
	FillRand(arr[0], COLS, 100, 1000);
	Print(arr, ROWS, COLS);
	do
	{
		cout << "������� ������ ������ ��� ������� ������ �� 0  ��  " << ROWS << endl; cin >> index;
		if (index < 0 || index > ROWS)cout << "������ ������� �� ����������" << endl;

	} while (index < 0 || index > ROWS);
	arr = Insert_row(arr, ROWS, COLS, index);
	FillRand(arr[index], COLS, 100, 1000);
	Print(arr, ROWS, COLS);
	cout << "�������� ��������� ������ � �������: " << endl;
	arr = Pop_row_back(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	cout << "�������� ������� ������ � �������: " << endl;
	arr = Pop_row_front(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	do
	{
		cout << "������� ������ ������ ��� �������� �� 0  ��  " << ROWS << endl; cin >> index;
		if (index < 0 || index > ROWS)cout << "������ ������� �� ����������" << endl;

	} while (index < 0 || index > ROWS);
	arr = Erase_row(arr, ROWS, COLS, index);
	Print(arr, ROWS, COLS);
	cout << "���������� �������� � ����� �������: " << endl;
	Push_col_back(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	cout << "���������� �������� � ������ �������: " << endl;
	Push_col_front(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	do
	{
		cout << "������� ������ �������� ������� ��� ��������� �� 0  ��  " << COLS << endl; cin >> index;
		if (index < 0 || index > COLS)cout << "������ ������� �� ����������" << endl;

	} while (index < 0 || index > COLS);
	Insert_col(arr, ROWS, COLS, index);
	Print(arr, ROWS, COLS);
	cout << "�������� �������� � ����� �������: " << endl;
	Pop_col_back(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	cout << "�������� �������� � ������ �������: " << endl;
	Pop_col_front(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	do
	{
		cout << "������� ������ �������� ������� ��� �������� �� 0  ��  " << COLS << endl; cin >> index;
		if (index < 0 || index > COLS)cout << "������ ������� �� ����������" << endl;

	} while (index < 0 || index > COLS);
	Erase_col(arr, ROWS, COLS, index);
	Print(arr, ROWS, COLS);
	Clear(arr, ROWS);
#endif // DYNAMIC_MEMORY_2

#ifdef PREFORMANCE_CHECK
	int ROWS;
	int COLS;
	cout << "������� ���������� �����: "; cin >> ROWS;
	cout << "������� ���������� ��������� ������: "; cin >> COLS;

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
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(int** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], const int n) //����� �������� �� �����
{
	for (int i = 0; i < n; i++)
	{
		//��������� � ��������� ������� ����� ������� �������������� - []:
		cout << arr[i] << tab;
	}
	cout << endl;
}
void Print(int** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}
int* push_back(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	//Print(arr, n);
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
int* insert(int arr[], int& n, int index, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	for (int i = n; i > index; --i)
	{
		arr[i] = arr[i - 1];
	}
	arr[index] = value;
	n++;
	return arr;
}
int* erase(int arr[], int& n, int index)
{
	int* buffer = new int[n];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index + 1; i < n; i++)
	{
		buffer[i - 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int** Allocate(const int ROWS, const int COLS)
{
	int** arr = new int* [ROWS];
	//2) �������� ������ ��� ������:
	for (int i = 0; i < ROWS; i++)
	{
		arr[i] = new int[COLS];
	}
	return arr;
}
void Clear(int** arr, const int ROWS)
{
	//1) C������ ������� ������:
	for (int i = 0; i < ROWS; i++)
	{
		delete[] arr[i];
	}
	//2) ������� ������ ����������, �������� ��������� � ���������� ������ � �����.�����.
	delete[] arr;
	arr = nullptr;
	//ROWS = 0;
	//COLS = 0;
	cout << "������ �����, ������ ��������!!!" << endl;
}
int** Push_row_back(int** arr, int& ROWS, const int COLS)
{
	int** buffer = new int* [ROWS + 1];
	for (int i = 0; i < ROWS; i++)buffer[i] = arr[i];
	delete[] arr;
	//4 ���� ������ � ������ ee � ������
	buffer[ROWS] = new int[COLS] {};
	ROWS++;
	return buffer;
}

int** Push_row_front(int** arr, int& ROWS, int COLS)
{
	int** buffer = new int* [ROWS + 1];
	for (int i = 0; i < ROWS; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new int[COLS] {};
	ROWS++;
	return buffer;
}
int** Insert_row(int** arr, int& ROWS, const int COLS, int index)
{
	int** buffer = new int* [ROWS + 1];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = ROWS; i > index; i--)buffer[i] = arr[i - 1];
	delete[] arr;
	buffer[index] = new int[COLS] {};
	ROWS++;
	return buffer;
}
int** Pop_row_back(int** arr, int& ROWS, const int COLS)
{
	int** buffer = new int* [--ROWS]; // ��������������� ������ ����������
	for (int i = 0; i < ROWS; i++)buffer[i] = arr[i];
	delete[] arr[ROWS]; // ������� ��������� ������ �� ������ 
	delete[] arr;
	return buffer;
}
int** Pop_row_front(int** arr, int& ROWS, const int COLS)
{
	int** buffer = new int* [ROWS - 1];
	for (int i = 0; i < ROWS; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	ROWS--;
	return buffer;
}
int** Erase_row(int** arr, int& ROWS, const int COLS, int index)
{
	int** buffer = new int* [ROWS - 1];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < ROWS; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	ROWS--;
	return buffer;
}
void Push_col_back(int** arr, const int ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		int* buffer = new int[COLS + 1] {}; // �������� �������� ������
		for (int j = 0; j < COLS; j++)buffer[j] = arr[i][j];  // �������� �������� �� �������� ������ � ��������
		delete[] arr[i]; // ������� ������ ������
		arr[i] = buffer; // ��������� ����� ������ � ������� ����������
	}
	COLS++; //��������� �������
}

void Push_col_front(int** arr, const int ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		int* buffer = new int[COLS + 1] {};
		for (int j = 0; j < COLS; j++)buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	COLS++;
}

void Insert_col(int** arr, const int ROWS, int& COLS, int index)
{
	for (int i = 0; i < ROWS; i++)
	{
		int* buffer = new int[COLS + 1] {};
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		for (int j = index; j < COLS; j++)buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	COLS++;
}
void Pop_col_back(int** arr, const int ROWS, int& COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		int* buffer = new int[COLS - 1];
		for (int j = 0; j < COLS - 1; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	COLS--;
}
void Pop_col_front(int** arr, const int ROWS, int& COLS)
{

	for (int i = 0; i < ROWS; i++)
	{
		int* buffer = new int[COLS - 1];
		for (int j = 0; j < COLS - 1; j++)buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	COLS--;
}
void Erase_col(int** arr, const int ROWS, int& COLS, int index)
{
	for (int i = 0; i < ROWS; i++)
	{
		int* buffer = new int[COLS - 1];
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		for (int j = index; j < COLS - 1; j++)buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	COLS--;
}