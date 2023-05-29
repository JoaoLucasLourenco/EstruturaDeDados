#include <iostream>
#include "PilhaOO.h"
using namespace std;

int main()
{
	Pilha<char> p1 = Pilha<char>();
	p1.push('a');
	p1.push('b');
	p1.push('c');
	cout << "Topo de p1 " << p1.top() << endl;
	cout << "Pop de p1 " << p1.pop() << endl;
	cout << "Topo de p1 " << p1.top() << endl;
	return 0;
}