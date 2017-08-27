/*
	Implementação do algoritmo de Kruskal
	Para detectar ciclos iremos utilizar o algoritmo Union-Find que detecta
	ciclos em grafos NÃO direcionados.
*/
#include <iostream>
#include <windows.h>
#define infinito 10000
#define MAX 12
using namespace std;

class Grafo
{
private:
	int V; // número de vértices

	int custo[MAX][MAX], c[MAX], c1[MAX];

public:

	// construtor
Grafo(int V)
{
	this->V = V; // atribui o número de vértices
	this->custo[V+1][V+1]=custo[V+1][V+1];
	this->c[V+1]=c[V+1];
	this->c1[V+1]=c1[V+1];


	for(int i=0; i<=V;i++){
		c[i]=-2;
		c1[i]=i;
		for(int j=0; j<=V;j++) {
			custo[i][j]=10000;
		}
	}		
}
	// adiciona uma aresta ao grafo de v1 à v2
void addAresta(int v1, int v2, int cus)
{
	custo[v1][v2]=cus;
	custo[v2][v1]=custo[v1][v2];
}

void kruskal ()
{	
	int orig=0, p1[V],p2[V];
	int lst=0, st=0, n=V;
	c[orig]=orig;
	
	cout<<"Passo 1:"<<endl<<endl;
	cout<<"LST: "<<lst<<endl;
	cout<<"C <- {"<<c[orig]+1<<"};"<<endl;
	cout<<"C' <- {";
	for(int t=0; t<=n; t++){
		if (c1[t]==c[t]){
			if(t!=0){
				c1[t]=-t;
			}else c1[t]=-1;
		}
		if (c1[t]==t) {
			cout<<c1[t]+1<<" ";
		}
	}cout<<"}"<<endl;
	cout<<"ST: "<<st<<endl<<endl;
	int k=0;
	cout<<"Passo 2: "<< endl;
	int i=orig;
	while(k!=V){
		int menor=1000;
		for(int t=0; t<=n; t++){
			if (c1[t]==t){
				for(int j=0; j<=n;j++){
					if (c[j]==j){
						if(custo[j][t]<menor){
							menor=custo[j][t];
							p1[k]=j;
							p2[k]=t;
							i=t;
						}					
					}
				}
			}
		}
		c[i]=i;
		c1[i]=-i;
		lst+=menor;
		cout<<"LST: "<<lst<<endl;
		cout<<"C <- {";
		for(int t=0; t<=n; t++){
			if (c[t]>=0) cout<<c[t]+1<<" ";
		}cout<<"}"<<endl;
		cout<<"C' <- {";
		for(int t=0; t<=n; t++){
			if (c1[t]==t) cout<<c1[t]+1<<" ";
		}cout<<"}"<<endl;
		cout<<"ST: {";
		for(int t=0; t<=k;t++){
			if(t==k){
				cout<<"("<<p1[t]+1<<","<<p2[t]+1<<")";
			}else cout<<"("<<p1[t]+1<<","<<p2[t]+1<<"); ";
		}cout<<"}"<<endl<<endl;
		k++;
	}
}
};

int main(int argc, char *argv[])
{
	Grafo g(3); // g(4)
	
	g.addAresta(0,1,1); // g.addAresta(1,2,1)
	g.addAresta(0,3,2); // g.addAresta(1,4,2)
	g.addAresta(1,2,3); // g.addAresta(2,3,3)
	g.addAresta(1,3,4); // g.addAresta(2,4,4)
	g.addAresta(2,3,5);	// g.addAresta(3,4,5)
	g.kruskal();

	Grafo g1(6); // grafo

	g1.addAresta(0, 1, 4);
	g1.addAresta(0, 2, 4);
	g1.addAresta(0, 3, 2);
	g1.addAresta(1, 2, 6);
	g1.addAresta(1, 4, 1);
	g1.addAresta(2, 4, 5);
	g1.addAresta(2, 3, 3);
	g1.addAresta(2, 5, 2);
	g1.addAresta(4, 5, 3);
	g1.addAresta(4, 6, 2);
	g1.addAresta(5, 6, 4);

	g1.kruskal(); // roda o algoritmo de Kruskal
	
	return 0;
}
