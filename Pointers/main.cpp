# include <iostream>
using namespace std;
//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");

#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl;// вывод значени€ переменной "а" на экрвн
	cout << &a << endl;// вх€тие адреса переменной "а" пр€мо при выводе
	cout << pa << endl;// вывод адреса переменной "а" хран€щегос€ в указателе "ра"
	cout << *pa << endl; // разъименование указател€ "ра" и вывод значени€ по адресу  
#endif // POINTERS_BASICS

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr <<endl;
	cout << *arr<<endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;

}
