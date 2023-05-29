#include <iostream>
#include "FilaOO.h"
using namespace std;
int main()
{
	Fila<char> f = Fila<char>();
	f.enqueue('a');
	f.enqueue('b');
	f.enqueue('c');
	cout << "primeiro da fila: " << f.qfirst() << endl;
	cout << "dequeue da fila: " << f.dequeue() << endl;
	cout << "primeiro da fila: " << f.qfirst() << endl;
	
	Fila<int> f2 = Fila<int>();
	f2.enqueue(1);
	f2.enqueue(2);
	f2.enqueue(3);
	cout << "primeiro da fila: " << f2.qfirst() << endl;
	cout << "dequeue da fila: " << f2.dequeue() << endl;
	cout << "primeiro da fila: " << f2.qfirst() << endl;

	Fila<float> f3 = Fila<float>();
	f3.enqueue(10.2);
	f3.enqueue(12.3);
	f3.enqueue(9.4);
	cout << "primeiro da fila: " << f3.qfirst() << endl;
	cout << "dequeue da fila: " << f3.dequeue() << endl;
	cout << "primeiro da fila: " << f3.qfirst() << endl;
	return 0;
}
