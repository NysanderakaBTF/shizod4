// shizod4->cpp : Этот файл содержит функцию "main"-> Здесь начинается и заканчивается выполнение программы->
//
#include <algorithm>
#include <iostream>
#include "tree.h"
using namespace std;
int main()
{
	setlocale(LC_ALL,"rus");
	tree* t = new tree();
	int k;
	//for (int i = 0; i < 10; i++) {
	//	char a; int b;
	//	cin >> a >> b;
	//	t->add_node(a, b);
	//}
	//t->print(t->root);
	//t->print_v(t->root);
	//int k = 0;
	//t->kol_NNum(t->root, k);
	//cout <<k<<endl;
	////t->delete_non_num2(t->root, nullptr);
	//t->delete_non_num2();
	//t->print(t->root);
	string tre;
	int ken;
	cout << "Практическая работа №4 \"Применение хеш-таблицы для поиска данных в двоичном файле с записями фиксированной длины.\". Резников Григорий." << endl << endl;
	cout << " (1): создание строки для заполненеия дерева \n" <<
		" (2): вывести дерево\n" <<
		" (3): вставить новое значение\n" <<
		" (4): определить кол-во цифр в дереве\n" <<
		" (5): удалить не цифры\n" <<
		" (6): вывод узлов по убыванию\n" <<
		endl;
	int num=0,nn=0;
	char ch;
	do  {
		cout << endl<<"Введите номер задания" << endl;
		cin >> num;
		switch (num)
		{
		case 1:
			cout << "Enter lenght" << endl;
			cin >> ken;
			for (size_t i = 0; i < ken; i++)
			{
				tre.push_back(char(33 + rand() % 94));
			}
			cout << tre;
			for (size_t i = 0; i < ken; i++)
			{
				t->add_node(tre[i]);
			}
			
			break;
		case 2:
			t->print(t->root);
			break;
		case 3:
			cout << "Enter char" << endl;
			cin >> ch;
			t->add_node(ch);
			break;
		case 4:
			t->kol_NNum(t->root, nn);
			cout << nn;
			break;
		case 5:
			cout << "tree before" << endl;
			t->print(t->root);
			t->delete_non_num(t->root,nullptr);
			cout << "Tree after" << endl;
			t->print(t->root);
			break;
		case 6:
			t->print_v(t->root);
			break;
		default:
			cout << "wrong number" << endl;
			break;
		}
	} while (true);

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1-> В окне обозревателя решений можно добавлять файлы и управлять ими->
//   2-> В окне Team Explorer можно подключиться к системе управления версиями->
//   3-> В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения->
//   4-> В окне "Список ошибок" можно просматривать ошибки->
//   5-> Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода->
//   6-> Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл->
