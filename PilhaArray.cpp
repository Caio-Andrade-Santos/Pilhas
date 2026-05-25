#include <iostream>
using namespace std;

//Feito por: Alexandre Zampieri Salles e Caio Andrade.

#define MAX 30

struct Pilha {
    int topo;
    int elementos[MAX];
};
//inicia
void init(Pilha *p)
{
    p->topo = 0;
}
//empilha
int push(Pilha *p, int valor)
{
    if (p->topo >= MAX)
    {
        return 0;
    }

    p->elementos[p->topo++] = valor;
    return 1;
}
//desempilha
int pop(Pilha *p)
{
    if (p->topo == 0)
    {
        return -1;
    }

    return p->elementos[--p->topo];
}

int isEmpty(Pilha *p)
{
    return (p->topo == 0);
}

int main()
{
    Pilha pares;
    Pilha impares;

    init(&pares);
    init(&impares);

    int numero;
    int anterior = -999999;

    cout << "Digite 30 numeros inteiros em ordem crescente:" << endl;

    for (int i = 0; i < 30; i++)
    {
        do
        {
            cout << "Numero " << i + 1 << ": ";
            cin >> numero;

            if (numero <= anterior)
            {
                cout << "Invalido! Digite um numero maior que o anterior." << endl;
            }

        } while (numero <= anterior);

        anterior = numero;

        
        if (numero % 2 == 0)
        {
            push(&pares, numero);
        }
        else
        {
            push(&impares, numero);
        }
    }


    cout << endl;
    cout << "-- NUMEROS PARES --" << endl;

    while (!isEmpty(&pares))
    {
        cout << pop(&pares) << endl;
    }

    cout << endl;
    cout << "-- NUMEROS IMPARES --" << endl;

    while (!isEmpty(&impares))
    {
        cout << pop(&impares) << endl;
    }

    return 0;
}