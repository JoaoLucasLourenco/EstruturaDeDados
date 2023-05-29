#pragma once
#include <iostream>
template <class Elem>
class Pilha {
private:
	struct no { char info; no* prox; } *P;
	int TAM;
public:
	Pilha();
	~Pilha() {};
	void push(Elem);
	Elem pop();
	Elem top();
	Elem empty();
	int tamanho() { return TAM; };
};
template <class Elem>
Pilha<Elem>::Pilha() { P = NULL; TAM = 0; }
template <class Elem>
void Pilha<Elem>::push(Elem X) {
	no* aux = new no;
	aux->info = X;
	aux->prox = P;
	P = aux;
	TAM++;
}

template <class Elem>
Elem Pilha<Elem>::empty()
{
	return !TAM;
}

template <class Elem>
Elem Pilha<Elem>::top()
{
	if (!empty())
		return P->info;
	else
		return '\0';
}

template <class Elem>
Elem Pilha<Elem>::pop()
{
	no* aux = P;
	Elem X = aux->info;
	P = P->prox;
	delete aux;
	TAM--;
	return X;
}

