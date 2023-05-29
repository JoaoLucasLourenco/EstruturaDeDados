#include <iostream>
#include "ListaOrdenada.h"
using namespace std;
int main(void)
{
	Lista<char> l = Lista<char>();
	l.Add('c');
	l.Add('b');
	l.Add('b');
	l.Add('a');
	l.Add('a');
	cout << l.Mostra() << endl;
	cout << "Tamanho da lista: " << l.Tamanho()<< endl;
	cout << "Item a ser removido com repeticao: " <<l.RemoveCr('a')<<endl;
	cout << l.Mostra()  << endl;
	cout << "Tamanho da lista: " << l.Tamanho() << endl;
	cout << "Item a ser removido sem repeticao: " << l.RemoveSr('b') << endl;
	cout << l.Mostra() << endl;
	cout << "Tamanho da lista: " << l.Tamanho() << endl;
	

	return 1;
}