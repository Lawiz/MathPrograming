// Laba1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include "Random.h"
#include <ctime>
#include <locale>
using namespace std;
#define CYCLE 100000
int test();
int knapsack_s(int V, // [in] вместимость рюкзака 
	short n, // [in] количество типов предметов
	const int v[], // [in] размер предмета каждого типа
	const int c[], // [in] стоимость предмета каждого типа
	short m[]); // [out] количество предметов каждого типа );

int main()
{
	test();
	system("pause");
}
int test()
{

	int cycle = 1000;
	double av1 = 0, av2 = 0;
	clock_t t1 = 0, t2 = 0;
	Random *rnd = new Random();
	setlocale(0,"");
	t1 = clock();
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i <cycle ; i++)
		{
			av1 += (int)rnd->Next(-100, 100);
			av2 += (double)rnd->Next(-100, 100);

		}
		t2 = clock();
		cout << "number of cycles:" << cycle << endl;
		cout << "averag value(int):" << av1 / cycle << endl;
		cout << "average value(double)" << av2 / cycle << endl;
		cout << "time (s):" << (t2 - t1) << "y.e.:" << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
		cout << endl;
		cout << "--------------------------------" << endl;
		cycle *= 10;
	}
	return 0;


}

