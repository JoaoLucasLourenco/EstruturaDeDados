#pragma once
#include <iostream>
using namespace std;
template <class Elem>
class Lista
{
private:
	struct no {
		Elem info;
		no* prox;
	}*L;
	int TAM;
public:
	Lista()
	{
		L = NULL;
		TAM = 0;
	}
	~Lista() {}
	void Add(Elem x) {
		no** Pl = &L;
		while (*Pl != NULL and x > (*Pl)->info)
			Pl = &(*Pl)->prox;

		no* aux = new no;
		aux->info = x;
		aux->prox = *Pl;
		*Pl = aux;
		TAM++;
	}
	void AddSr(Elem x)
	{
		no** Pl = &L;
		while (*Pl != NULL and x > (*Pl)->info)
			Pl = &(*Pl)->prox;
		if (*Pl != NULL and x == (*Pl)->info) { return; }
		no* aux = new no;
		aux->info = x;
		aux->prox = *Pl;
		*Pl = aux;
		TAM++;
	}
	Elem RemoveSr(Elem x)
	{
		if (!Lisempty())
		{
			no* Pl = L;
			no* aux = Pl;
			if (x == L->info)
			{
				L = L->prox;
				delete Pl;
				TAM--;
				return x;
			}
			while (Pl->info != x and Pl != NULL)
			{
				aux = Pl;
				Pl = Pl->prox;
			}
			aux->prox = Pl->prox;
			delete Pl;
			TAM--;
			return x;
		}

	}
	Elem RemoveCr(Elem x)
	{
		if (!Lisempty())
		{
			no* aux = L;
			while (aux)
			{
				if (aux->info == x)
				{
					if (aux == L)
					{
						RemoveSr(x);
						aux = L;
					}
					else
					{
						RemoveSr(x);
						aux = aux->prox;
					}
				}
				else
					aux = aux->prox;
			}
			return x;
		}
	}
	Elem Lisempty()
	{
		return !TAM;
	}
	Elem First()
	{
		if (!Lisempty())
			return L->info;
	}
	int Tamanho()
	{
		return TAM;
	}
	string Mostra()
	{
		if (!Lisempty())
		{
			string result = "[";
			no* aux = L;
			while (aux)
			{
				result += aux->info;
				if (aux->prox)
					result += ", ";
				aux = aux->prox;
			}
			result += "]";
			return result;
		}
	}
	int Conta(Elem x)
	{
		if (!Lisempty())
		{
			no* Pl = L;
			int c = 0;
			while (Pl)
			{
				if (Pl->info == x)
					c++;
				Pl = Pl->prox;
			}
			return c;
		}
	}
};