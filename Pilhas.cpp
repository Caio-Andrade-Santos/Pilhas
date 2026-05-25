#include <iostream>
using namespace std;

struct No {
	int dado;
	struct No *ant;
};

struct Pilha {
     No *topo;
};

Pilha* init() {
	Pilha *p = new Pilha;
	p->topo = NULL;
	return p;
}

int isEmpty(Pilha *p) {
	return (p->topo == NULL);
}

int count(Pilha *p) {
	int i = 0;
	No *no;
	no = p->topo;
	while (no != NULL) {
		i++;
		no = no->ant;
	}
	return i;
}
/*
int countTotal(Pilha *p, Pilha *p1)
{
	int x = count(p) + count(p1); 
	if(x >= 4)
	{
		return 1;;
	}
	else
	{
		return 0;
	}
}
*/
void print(Pilha *p) {
    No *no;
	no = p->topo;
    cout << "--------------------------" << endl;
	cout << "-- Qtde: " << count(p) << "            --" << endl;
	cout << "--------------------------" << endl;	
	while (no != NULL) {
		cout << no->dado << endl;
		no = no->ant;
	}	
	cout << "--------------------------" << endl;
}

void push(Pilha *p,Pilha *p2, int v) {
    No *no = new No;
	no->dado = v;
	
 if (v % 2 == 0) {

        while (p->topo != NULL && v <= p->topo->dado) {
            cout << "Digite um numero maior que o anterior: ";
            cin >> v;
            while(v % 2 != 0)
			{
				cout << "Digite um numero Par: ";
            	cin >> v;
			}
        }

        no->dado = v;
        no->ant = p->topo;
        p->topo = no;

    } else {

        while (p2->topo != NULL && v <= p2->topo->dado) {
            cout << "Digite um numero maior que o anterior: ";
            cin >> v;
            while(v % 2 == 0)
			{
				cout << "Digite um numero impar: ";
            	cin >> v;
			}
        }

        no->dado = v;
        no->ant = p2->topo;
        p2->topo = no;
    }
}

void pop(Pilha *p, Pilha *p1)
{
    while (!isEmpty(p) || !isEmpty(p1))
    {

        if (!isEmpty(p) && !isEmpty(p1))
        {

            if (p->topo->dado > p1->topo->dado)
            {
                No *no = p->topo;

                cout << no->dado << endl;

                p->topo = no->ant;

                delete no;
            }
            else
            {
                No *no1 = p1->topo;

                cout << no1->dado << endl;

                p1->topo = no1->ant;

                delete no1;
            }
        }

        else if (!isEmpty(p))
        {
            No *no = p->topo;

            cout << no->dado << endl;

            p->topo = no->ant;

            delete no;
        }

        else if (!isEmpty(p1))
        {
            No *no1 = p1->topo;

            cout << no1->dado << endl;

            p1->topo = no1->ant;

            delete no1;
        }
    }
}
void freePilha(Pilha *p) {
    No *no;
	no = p->topo;
	while (no != NULL) {
		No *temp = no->ant;
		free(no);
		no = temp;
	}	
	free(p);
}

int main(int argc, char** argv)
{
	int x = 0;
	
	Pilha *pilhaImpar;
	pilhaImpar = init();
	
		Pilha *pilhaPar;
	pilhaPar = init();
	
		Pilha *pilhaTotal;
	pilhaTotal = init();
	
	for( int i = 0 ; i < 5 ; i++)
	{
		cout << "digite um numero para empilhar: ";
		cin >> x;
		push(pilhaPar,pilhaImpar, x);
		
	}
	cout << " ------ PILHA DOS IMAPRES -------- " << endl;
	print(pilhaImpar);
	
	cout << " ------ PILHA DOS PARES -------- " << endl;
	print(pilhaPar);
	
	cout << " ------ DESEMPILHANDO -------- " << endl;
	pop(pilhaPar,pilhaImpar);
	
	
	 
	/*pilhaFloat;
	pilhaFloat = init();
	
	cout << "Pilha vazia: " 
	     << (isEmpty(pilhaFloat)?"Sim":"Nao")
	     << endl;
	     
    push(pilhaFloat, 10);
   
    print(pilhaFloat);
   
    push(pilhaFloat, 15);
    push(pilhaFloat, 20);
    push(pilhaFloat, 25);
    push(pilhaFloat, 30);

	cout << "Pilha vazia: " 
	     << (isEmpty(pilhaFloat)?"Sim":"Nao")
	     << endl;
	     
    print(pilhaFloat);
   
    float desempilhado = pop(pilhaFloat); 
     if (desempilhado == -1)
	 {
	 	cout << "Pilha vazia" << endl;
	 }
	 else
	 {
		 cout << "Desempilhou: " << desempilhado << endl;
	 }
   
    print(pilhaFloat);
    
    free(pilhaFloat);
	*/
	return 0;
}