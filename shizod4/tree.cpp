#include "tree.h"
#include <vector>
#include <algorithm>
#include <functional>
tree::node::node(char a, int b)
{
	info.first = a;
	info.second = b;
	left = nullptr;
	right = nullptr;
}

tree::node::~node()
{
	delete left;
	delete right;
}

tree::tree()
{
    root = nullptr;
}

void tree::add_node(char ch)
{
	node* cur = root;
	if (cur == nullptr) {
        root = new node(ch, 1);
	}
	else {
		while (cur->left!=nullptr|| cur->right != nullptr)
		{
            if (cur->info.first == ch) {
                cur->info.second++;
                return;
            }
            if (ch > cur->info.first)
                if (cur->right != nullptr)
                    cur = cur->right;
                else
                    break;
            else
                if (cur->left != nullptr)
                    cur = cur->left;
                else
                    break;
		}
        if (ch == cur->info.first) {
            cur->info.second++;
        }
        else {
            if (ch > cur->info.first)
                cur->right = new node(ch,1);
            else
                cur->left = new node(ch, 1);
        }
	}
}
void tree::add_node(char ch, int k)
{
    node* cur = root;
    if (cur == nullptr) {
        root = new node(ch, k);
    }
    else {
        while (cur->left != nullptr || cur->right != nullptr)
        {
            if (cur->info.first == ch) {
                cur->info.second++;
                return;
            }
            if (ch > cur->info.first)
                if (cur->right != nullptr)
                    cur = cur->right;
                else
                    break;
            else
                if (cur->left != nullptr)
                    cur = cur->left;
                else
                    break;
        }
        if (ch == cur->info.first) {
            cur->info.second++;
        }
        else {
            if (ch > cur->info.first)
                cur->right = new node(ch, k);
            else
                cur->left = new node(ch, k);
        }
    }
}

void tree::kol_num(node* cur, int& kol)
{
	if (cur != nullptr) {
		kol_num(cur->left, kol);
		kol_num(cur->right, kol);
		if (isdigit(cur->info.first))
			kol++;
	}
	return;
}



void tree::delete_non_num(node* cur, node* parent)
{
    cur = root;
    pair<char, bool> p;
    //function< pair<char,bool>(node*)> nodelist = [&p, &nodelist](node* cur) {
    //    if (cur != nullptr) {
    //        cout << "///////////////////" << "                 " << cur->info.first << endl;
    //        if (!isdigit(cur->info.first)) {
    //            cout << "///////////////////" << "                 " << cur->info.first << endl;
    //            return make_pair(cur->info.first, true);
    //        }
    //        else
    //        {
    //            nodelist(cur->left);
    //            nodelist(cur->right);
    //        }

    //    }
    //    return make_pair('0', false);
    //};
    function< void(node*)> nodelist = [&p, &nodelist](node* cur, int next=1) {
        if (next) {
            if (cur != nullptr) {
                cout << "///////////////////" << "                 " << cur->info.first << endl;
                if (!isdigit(cur->info.first)) {
                    cout << "///////////////////" << "                 " << cur->info.first << endl;
                    p = cur->info;
                    next = 0;
                    return;
                }
                else
                {
                    nodelist(cur->left);
                    nodelist(cur->right);
                }

            }
        }
        return;
    };
    vector<char> what_to_delete(0);
    function<void(node*)> dl = [&what_to_delete, &dl](node* cur) {
        if (cur != nullptr) {
            if (!isdigit(cur->info.first))
                what_to_delete.push_back(cur->info.first);
            dl(cur->left);
            dl(cur->right);
        }
        return;
    };

    dl(root);

   // for_each(what_to_delete.begin(), what_to_delete.end(), [](char i) {cout << i << " "; });


    //for (auto to_delete : what_to_delete)
    //{
    //    del_key(root , to_delete);
    //    this->print(this->root);
    //}


    do
    {
        p.second = 0;
        nodelist(root);
        del_key(root, p.first);
        this->print(this->root);
    } while (p.second);
}

void tree::delete_non_num2()
{
    vector<pair<char, int> > trr;

    function<void(node*)> nodelist = [&trr, &nodelist](node* cur) {
        if (cur != nullptr) {
            if(isdigit(cur->info.first))
                trr.push_back(cur->info);
            nodelist(cur->left);
            nodelist(cur->right);
        }
        return;
    };
    nodelist(this->root);

    delete this->root;
    this->root = nullptr;

    for_each(trr.begin(), trr.end(), [this](pair<char, int> a) {this->add_node(a.first, a.second); });
    //for(auto i:trr)
    //{
    //    if (isdigit(i.first)) {
    //        this->add_node(i.first, i.second);
    //    }
    //}
}



void tree::kol_NNum(node* cur, int& kol)
{
    if (cur != nullptr) {
        kol_NNum(cur->left, kol);
        kol_NNum(cur->right, kol);
        if (isdigit(cur->info.first))
            kol++;
    }
    return;
}

tree::node* tree::FindMin(node* r)
{
    if (r->left == nullptr && r->right == nullptr)
        return r;

    if(r!=nullptr)
        while (r->left != nullptr) {
            r = r->left;
        }
    return r;
}



void tree::print(node* n, string  rpref, string cpref , string lpref )
{
        string ch_hor = "-", ch_ver = "|", ch_ddia = "/", ch_rddia = "\\", ch_udia = "\\", ch_ver_hor = "|-", ch_udia_hor = "\\-", ch_ddia_hor = "/-", ch_ver_spa = "| ";
        if (!n) return;
        if (n->right)
            print(n->right, rpref + "  ", rpref + ch_ddia_hor, rpref + ch_ver_spa);
        cout << cpref << n->info.first << endl;
        if (n->left)
            print(n->left, lpref + ch_ver_spa, lpref + ch_udia_hor, lpref + "  ");
}

void tree::print_v(node* cur)
{
    //if (cur == nullptr)
    //    return;
    //print_v(cur->right);
    //cout << cur->info.first <<" - " << cur->info.second << endl;
    //print_v(cur->left);
    if (cur == nullptr)
        return;
    print_v(cur->left);
    cout << cur->info.first << " - " << cur->info.second << endl;
    print_v(cur->right);
}
void tree::searchKey(node*& curr, char key, node*& parent)
{
    // ����� ������ � ����� �����
    while (curr != nullptr && curr->info.first != key)
    {
        // �������� �������� �� �������� ����
        parent = curr;

        // ���� �������� ���� ������ �������� ����, ��������� � ����� ���������;
        // ����� ���� � ������ ���������
        if (key < curr->info.first) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
}
void tree::del_key(node*& st, char key)
{
    node* parent = nullptr;

    // �������� � ��������� ����
    node* curr = st;

    // ����� ����� � BST � ��������� ��� ������������� ���������
    searchKey(curr, key, parent);

    // ����������, ���� ���� �� ������ � ������
    if (curr == nullptr) {
        return;
    }

    // ������ 1: ��������� ���� �� ����� �������� ���������, �. �. �������� �������� �����
    if (curr->left == nullptr && curr->right == nullptr)
    {
        // ���� ��������� ���� �� �������� �������� �����, �� ������������� ���
        // ������������ �����/������ �������� ������� � null
        if (curr != root)
        {
            if (parent->left == curr) {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
        }
        // ���� ������ ����� ������ �������� ����, ������������� ��� � null
        else {
            st = nullptr;
        }

        // ����������� ������
        delete curr;
    }

    // ������ 2: ��������� ���� ����� ���� ��������
    else if (curr->left && curr->right)
    {
        // ����� ��� ��������������� ����-��������]
        node* successor;
        if(curr->right!=nullptr)
            successor = FindMin(curr->right);
        else
            successor = FindMin(curr->left);

        // ��������� ����������� ��������
        pair<char, int> val = successor->info;

        // ���������� ������� ���������. �������� ��������, ��� ��������
        // ����� ����� �� ����� ������ ������� (������� �������)
        //del_key(root, successor->info.first);
        del_key(st, successor->info.first);

        // �������� �������� ��������� � ������� ����
        curr->info = val;
    }

    // ������ 3: ��������� ���� ����� ������ ������ �������
    else {
        // �������� �������� ����
        node* child = (curr->left) ? curr->left : curr->right;

        // ���� ��������� ���� �� �������� �������� �����, ������������� ��� ��������
        // ������ �������
        if (curr != root)
        {
            if (curr == parent->left) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
        }

        // ���� ��������� ���� �������� �������� �����, �� ���������� ������ ���������
        else {
            root = child;
        }

        // ����������� ������
        //free(curr);
        //curr = st;
    }
}
