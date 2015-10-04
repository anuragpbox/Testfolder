
#include <iostream>

using namespace std;

int zeroarr(int (&arr)[10])
{
	cout << typeid(arr).name() << endl;
	int	len = sizeof(arr)/sizeof(arr[1]);
	cout << "----" << len << "----" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i << endl;
		arr[i] = 0;
	}
	return len;
}

int arrlen(int* arr)
{
	cout << typeid(arr).name() << endl;
	int	len = sizeof(arr) / sizeof(*arr);
	cout << "----" << len << "----" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i << endl;
		arr[i] = 0;
	}
	return len;
}
void write(char str[])
{
	cout << str << endl;
}

struct Books
{
	int valdimir=6;
}books;

int main()
{
	cout << "Hello World" << endl;
	cout << "This is a tutorial on pointers and references" << endl;
	cout << "<------->   1 var operations  <------->" << endl;
	cout << "<-------> Pointers"<<endl;
	int a = 6; cout << "int a = " << a << endl;
	char s = 'rds'; cout << "char s = " << s << endl;
	
	int *apt; cout << "int *apt" << endl;
	apt = &a;
	cout << "apt holds address of a which is: " << apt << endl
		 << "and the value in the address *apt is: " << *apt << endl;
	*apt = 7; write("*apt = 7");
	cout << "a =" << a << endl;
	int a2 = 2; cout << "int a2 = 2"<<endl;
	apt = &a2; cout << "apt = &a2;" << endl;
	*apt = 9; write("*apt = 9");
	cout << "a =" << a << endl;
	cout << "a2 =" << a2 << endl;

	cout << "similarly  for char s "<<endl;
	char *spt = &s;
	cout << spt << endl << *spt << endl;
	cout << "cout << spt << endl does not give a pointer address" <<
		"as that is how pointers for characters are porinted" << 
		"Cout starts printing the values in address as string" <<
		"till it encounters \0 counter" << endl;
	
	cout << "<-------> References" << endl;
	write("int a = 7");
	int &aref=a; write("int &aref=a: refrences must have an initializer");
	aref = 10; cout << "aref = 10;" << endl;
	cout << "Now a is :" << a << endl;
	//char &sref
	int b = 2; write("int b = 2");
	aref = b; cout << "aref = b;" << endl; cout << "type of aref :" << typeid(aref).name() << endl;
	cout << "a =" << a << endl;


	cout << "<----------->  1D  Arrays and opinters <---------------->" << endl;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	char charr[] = "Willow null\0 Garage";
	cout << "charr" << charr << endl;



	cout << "XXX----->  End Program  <----XXX" << endl;
	return 0;

	char chr = 'r';
	int intar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << chr << endl;
	char* chrpt;
	char chrar[15] = "Hello";
	chrpt = chrar;
	chrar[3] = '4';
	cout << &chrar[2] << endl;
	cout << &chrpt[3] << endl;
	cout << chrpt+1<<"---" << endl;	
	cout <<*intar<<"  " <<*intar+2 << endl;


	cout << "<----------->  2D Character Arrays <---------------->" << endl;
	
	
	char *names[4] = {
		"Zara Ali",
		"Hina Ali",
		"Nuha Ali",
		"Sara Ali",
	};

	for (int i = 0; i < 4; i++)
	{
		cout << "Value of names[" << i << "] = ";
		cout << names[i] << endl;
	}
	char names3[4][9] = {
		"Zara Ali",
		"Hina Ali",
		"Nuha Ali",
		"Sara Ali",
	};

	char *names2 ="Zara Ali";
	cout << "anmes2" <<endl<< *(names+1) << endl;
	cout << "anmes3" << endl << names3[0] << endl;




	char chr2d[5][6] = { { "nana" }, { "5rere" }, { "223e" } };
	cout << *chr2d << endl;
	
	int t[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ,11,12};
	cout <<"--int"<< endl << t << "---"<< t[0] <<endl;
	cout << "-----<<---" << endl;
	cout<<" and "<<  t       << typeid(t).name() << endl 
		<<" and "<<  t[0]    << typeid(t[0]).name() << endl
		<<" and "<< &t[0][0] << typeid(&t[0][0]).name()<<endl
		<<" and "<< &t[0]    << typeid(&t[0]).name()<<endl
		<<" --- " << endl;
	
	int * ptar[3];
	ptar[0] = t[0];
	ptar[1] = t[1];
	ptar[2] = t[2];

	int ** ptptar;
	ptptar = ptar;

	cout << ptptar << endl;
	cout << "---" << sizeof(intar) << "---" << endl;
	cout << arrlen(intar) << endl;
	cout << zeroarr(intar) << endl;
	cout << intar[0] << endl;
}



/*
// Highllights
// int *ne = new int[SIZE];

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void changeIndexStaticArrayMethod1(int* stat);
void changeIndexStaticArrayMethod2(int(&stat)[3]);
void changeIndexDynamicArrayMethod1(int* dyn, int size);

int main() {
	const int MAX = 3;
	int arr[MAX] = { 1, 2, 3 };

	changeIndexStaticArrayMethod1(arr);
	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	cout << endl;
	changeIndexStaticArrayMethod2(arr);
	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;

	int SIZE;
	cout << "Please choose a size for the array" << endl;
	cin >> SIZE;

	int *ne = new int[SIZE];
	//Build array
	for (int i = 0; i < SIZE; i++) {
		ne[i] = i;
	}

	changeIndexDynamicArrayMethod1(ne, SIZE);
	for (int i = 0; i < SIZE; i++) {
		cout << "ne[" << i << "] = " << ne[i] << endl;
	}


	//To hang program
	cin >> SIZE;

	delete[] arr;
	delete[] ne;
	return 0;
}

void changeIndexStaticArrayMethod1(int* stat) {
	stat[0] = 10;
	stat[1] = 20;
	stat[2] = 30;
}

void changeIndexStaticArrayMethod2(int(&stat)[3]) {
	stat[0] = 40;
	stat[1] = 50;
	stat[2] = 60;
}

void changeIndexDynamicArrayMethod1(int* dyn, int size) {
	for (int i = 0; i < size; i++) {
		dyn[i] = i * 10;
	}
}
*/