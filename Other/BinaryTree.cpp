#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm> 
using namespace std;

struct tree{
	char data;
	tree* lson;
	tree* rson;
	tree (char d): data(d), lson(nullptr), rson(nullptr){}
}; 
string s;
int iii = 1, leaf;
void settree(tree** a);
void aoru(tree* a, int cnt);
void xian(tree* a);
void zhong(tree* a);
void hou(tree* a);
void exchange(tree* a);

int main() {
	cin >> s;
	tree* head = new tree(s[0]);
	settree(&head);
	cout << "BiTree" << endl;
	aoru(head, 0);
	cout << "pre_sequence  : ";
	xian(head);
	cout << endl << "in_sequence   : ";
	zhong(head);
	cout << endl << "post_sequence : ";
	hou(head);
	cout << endl << "Number of leaf: " << leaf << endl << "BiTree swapped" << endl;
	exchange(head);
	aoru(head, 0);
	cout << "pre_sequence  : ";
	xian(head);
	cout << endl << "in_sequence   : ";
	zhong(head);
	cout << endl << "post_sequence : ";
	hou(head);
	cout << endl;
	system("pause");
} 

void settree(tree **a) {
	if (iii > s.size()) return;
	if (s[iii] != '#') {
		tree* son1 = new tree(s[iii]);
		(*a)->lson = son1;
		iii++;
		settree(&son1);
	} else iii++;
	if (iii > s.size()) return;
	if (s[iii] != '#') {
		tree* son2 = new tree(s[iii]);
		(*a)->rson = son2;
			iii++;
		settree(&son2);
	} else iii++;
}

void aoru(tree* a, int cnt){
	for (int i = 0; i < cnt; i++) {
		cout << "    ";
	}
	cout << a->data << endl;
	if (a->lson != nullptr) aoru(a->lson,cnt+1);
	if (a->rson != nullptr) aoru(a->rson,cnt+1);
}

void xian(tree* a) {
	cout << a->data;
	if (a->lson != nullptr) xian(a->lson);
	if (a->rson != nullptr) xian(a->rson);
	if (a->lson == nullptr && a->rson == nullptr) leaf++;
}

void zhong(tree* a) {
	if (a->lson != nullptr) zhong(a->lson);
	cout << a->data;
	if (a->rson != nullptr) zhong(a->rson);
}

void hou(tree* a) {
	if (a->lson != nullptr) hou(a->lson);
	if (a->rson != nullptr) hou(a->rson);
	cout << a->data;
}

void exchange(tree* a) {
	swap(a->lson, a->rson);
	if (a->lson) exchange(a->lson);
	if (a->rson) exchange(a->rson);
}
