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
	char RemoveSr(Elem x)
	{
		if (!Lisempty())
		{
			no* Pl = L;
			if (x == L->info)
			{
				L = L->prox;
				delete Pl;
				TAM--;
				return 1;
			}
			while (Pl->prox and x > Pl->prox->info)
			{
				Pl = Pl->prox;
			}
			if (Pl->prox and x == Pl->prox->info)
			{
				no* aux = Pl->prox;
				Pl->prox = aux->prox;
				delete aux;
				TAM--;
				return 1;
			}
			return 0;
		}

	}
	char RemoveCr(Elem x)
	{
		if (!Lisempty())
		{
			no* aux = L;
			if (x == L->info)
			{
				while (aux and aux->info == x)
				{
					no* Pl = L;
					L = L->prox;
					aux = L;
					delete Pl;
					TAM--;
				}
				return 1;
			}
			while (aux->prox and x > aux->info)
				aux = aux->prox;
			if (aux->prox and aux->prox->info == x)
			{
				while (aux->prox and aux->prox->info == x)
				{
					no* Pl = aux->prox;
					aux->prox = Pl->prox;
					delete Pl;
					TAM--;
				}
				return 1;
			}
			return 0;
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