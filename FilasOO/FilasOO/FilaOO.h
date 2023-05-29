#pragma once
#include <iostream>
template <class Elem>
class Fila 
{
	private:
		int TAM;
		struct no 
		{
			Elem info;
			no* prox;
		}*P;
		no* U ;

	public:
		Fila();
		~Fila() {};
		void enqueue(Elem);
		Elem dequeue();
		Elem qisempty();
		Elem qfirst();
		Elem qlast();
		int tamanho();
};
template <class Elem>
Fila<Elem>::Fila() 
{
	P = U = NULL;
	TAM = 0;
}
template <class Elem>
Elem Fila<Elem>::qisempty()
{
	return !TAM;
}
template <class Elem>
void Fila<Elem>::enqueue(Elem X)
{
	/*Inserir algo na fila, como fazer ?
		preciso de um novo nó (aux) para passar a informação para o P ou para servir como novo elemento na lista (feito)
		se a fila estiver vazia preciso adicionar aux a P (feito)
		senão preciso percorrer a fila até achar o último nó e adicionar a ele aux (feito)
		TAM++ (feito)
	*/
	no* aux = new no;
	aux->info = X;
	aux->prox = NULL;

	if (qisempty()) {
		P = U = aux;
	}
	else {
		while (U->prox != NULL) {
			U = U->prox;
		}
		U->prox = aux;
	}
	TAM++;
}
template <class Elem>
Elem Fila<Elem>::dequeue()
{
	if (!qisempty())
	{
		no* aux = P;
		Elem x = aux->info;
		P = P->prox;
		delete aux;
		TAM--;
		if (TAM == 0)
			U = NULL;
		return x;
	}
}
template <class Elem>
int Fila<Elem>::tamanho()
{
	return TAM;
}
template <class Elem>
Elem Fila<Elem>::qfirst()
{
	if (!qisempty())
		return P->info;
}
template <class Elem>
Elem Fila<Elem>::qlast()
{
	if (!qisempty())
		return U->info;		
}
