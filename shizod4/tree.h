#pragma once
#include <utility>
#include <iostream>
using namespace std;
class tree
{
private:
	class node
	{
	public:
		node* left;
		node* right;
		pair<char, int> info;
		node(char a, int b=0);
		~node();
	};
public:
	node* root;
	tree();
	void add_node(char ch);
	void add_node(char ch, int k);
	void kol_num(node* cur, int& kol);
	void delete_non_num(node* curr, node* parent);
	void delete_non_num2();
	void kol_NNum(node* cur, int& kol);
	node* FindMin(node* root);
	void print(node* n, string  rpref = "", string cpref = "", string lpref = "");
	void print_v(node* cur);
	void del_key(node*& st, char key);
	void searchKey(node*& curr, char key, node*& parent);
};

