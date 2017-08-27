#include <iostream>
#include <windows.h>
#define infinito 10000
#define MAX 10
using namespace std;

class Grafo
{
private:
int V; // número de vértices

// ponteiro para um array contendo as listas de adjacências
int custo[MAX][MAX];

	int d[MAX],p[MAX], ultimo, rotulado[MAX], nrotulado[MAX];

public:

	// construtor
Grafo(int V)
{
	this->V = V; // atribui o número de vértices

	this->custo[V][V] = custo[V][V];
	this->d[V]=d[V];
	this->p[V]=p[V];
	this->ultimo=ultimo;
	this->rotulado[V]=rotulado[V]; 
	this->nrotulado[V]=nrotulado[V];

	for(int i=0; i<=V;i++){
		rotulado[i]=-2;
		nrotulado[i]=i;
		for(int j=0; j<=V;j++) {
			custo[i][j]=infinito;
		}
	}		
}
	// adiciona uma aresta ao grafo de v1 à v2
void addAresta(int v1, int v2, int c)
{
	custo[v1][v2]=c;
}

void dijkstra (int orig, int dest)
{
	int k,t,contador,n=V+1;
	k=0;
	contador=0;
	//Passo 1:	
	cout<<endl<<"Passo 1:"<<endl<<endl;
	rotulado[orig]=orig;
	d[orig]=0;
	p[orig]=0;
	ultimo = orig;
	cout<<"R <- {"<<rotulado[orig]+1<<"};\n"<<endl;
	cout<<"NR <- {";
	for(t=0; t<n; t++){
		if (nrotulado[t]==ultimo){
			if(t!=0){
				nrotulado[t]=-t;
			}else nrotulado[t]=-1;
		}
		if (nrotulado[t]==t) {
			cout<<nrotulado[t]+1<<" ";
			d[t]=infinito;
			p[t]=n+1;
		}
	}cout<<"}"<<endl;
	cout<<"d("<<orig+1<<") <- "<<d[orig]<<";"<<endl;
	cout<<"p("<<orig+1<<") <- "<<p[orig]<<";"<<endl;
	cout<<"ultimo <- "<<ultimo+1<<";"<<endl<<endl;
	int soma=0;
	//Passo 2:
	while(/*nrotulado[dest]==dest || */k!=V){
	cout<<"Passo 2:"<<endl<<endl;
	int candidato=0, cand=500;
	for(t=0; t<n; t++){
		if(t==nrotulado[t]){
			if( d[t] <= (d[ultimo] + custo[ultimo][t]) ){
				cout<<"d("<<t+1<<") <- "<<d[t]<<";\t"<<endl;
			}else{
				d[t]=d[ultimo] + custo[ultimo][t];
				cout<<"d("<<t+1<<") <- "<<d[t]<<";\t";
				if(d[t]<infinito){
					p[t]=ultimo+1;
					cout<<"p("<<t+1<<") <- "<<p[t]<<";";
				}cout<<endl;
			}
			if(d[t]<=cand){
			cand=d[t];
			candidato=t;
			}
		}
		if(d[t]==infinito){
			contador++;
		}
	}
	k++;
	if(candidato!=0){
		nrotulado[candidato]=-candidato;
		rotulado[candidato]=candidato;
		}else{
			nrotulado[candidato]=-1;
			rotulado[candidato]=0;
		}
	cout<<endl<<"k="<<k<<";";
	d[candidato]=cand;
	ultimo = candidato;

	//Passo 3
	cout<<endl<<endl<<"Passo 3:"<<endl<<endl;
	if(candidato!=dest){
		cout<<"Nodo "<<dest+1<<" nao rotulado, retorne ao Passo 2"<<endl<<endl;
	}else cout<<"Nodo "<<dest+1<<" rotulado, PARE!"<<endl<<endl;

	cout<<"NR <- {";
	for(t=0; t<n; t++){
		if (nrotulado[t]==t) cout<<nrotulado[t]+1<<" ";
	}cout<<"}"<<endl;
		cout<<"R <- {";
	for(t=0; t<n; t++){
		if (rotulado[t]>=0) cout<<rotulado[t]+1<<" ";
	}cout<<"}"<<endl;
	cout<<"d("<<ultimo+1<<") <- "<<d[ultimo]<<";"<<endl;
	cout<<"p("<<ultimo+1<<") <- "<<p[ultimo]<<";"<<endl;
	cout<<"ultimo <- "<<ultimo+1<<";"<<endl<<endl;
	}
	cout<<endl<<"contador:"<<contador<<endl;
	Sleep(5000);
	if(contador!=4*(V-1)+V){
	int i=dest;
	while(i!=orig){
		cout<<" p("<<i+1<<") <- "<<p[i]<<"; ";
		i=p[i]-1;		
	}cout<<endl<<endl;

	cout<<"O caminho minimo do no "<<orig+1<<" ao no "<<dest+1<<" e dado por:"<<endl;
	i=dest;
	cout<<"C = {";
	while(i!=orig){
		if((p[i]-1)==orig){
			cout<<"("<<i+1<<","<<p[i]<<")";
		}else cout<<"("<<i+1<<","<<p[i]<<");";
		i=p[i]-1;		
	}cout<<"} = "<<d[dest]<<endl<<endl;	
	}else cout<<"Nao ha caminho disponivel" <<contador<<endl;
}
};

int main() {

	Grafo g(2); //g(6)
	
	g.addAresta(0,1,2);  //g.addAresta(1,2,2); 

	int orig=0, dest=1; //orig=5, dest=2;

/*
	Grafo g(5); //g(6)
	
	g.addAresta(0,1,2);  //g.addAresta(1,2,2); 
	g.addAresta(2,0,1);  //g.addAresta(3,1,1); 
	g.addAresta(2,1,3);  //g.addAresta(3,2,3);
	g.addAresta(3,0,2);  //g.addAresta(4,1,2);
	g.addAresta(3,2,2);  //g.addAresta(4,3,2);
	g.addAresta(4,2,10); //g.addAresta(5,3,10);
	g.addAresta(4,3,5);  //g.addAresta(5,4,5);
	g.addAresta(4,5,4);  //g.addAresta(5,6,4);
	g.addAresta(5,0,5);  //g.addAresta(6,1,5);
	g.addAresta(5,3,1);  //g.addAresta(6,4,1);
	
	int orig=1, dest=4; //orig=5, dest=2;

/*
	Grafo g(5);
	
	g.addAresta(0,1,7);
	g.addAresta(0,2,3);
	g.addAresta(1,2,1);
	g.addAresta(1,3,6);
	g.addAresta(2,4,8);
	g.addAresta(3,2,3);
	g.addAresta(3,5,2);
	g.addAresta(4,3,2);
	g.addAresta(4,5,8);
	
	int orig=0, dest=5;
//*/
/*	Grafo g(8);
	
	g.addAresta(0,1,5);
	g.addAresta(0,7,10);
	g.addAresta(0,3,10);	
	g.addAresta(1,5,5);
	g.addAresta(2,3,5);
	g.addAresta(3,4,5);
	g.addAresta(3,6,10);
	g.addAresta(4,0,5);
	g.addAresta(4,2,10);
	g.addAresta(4,8,10);
	g.addAresta(5,6,15);
	g.addAresta(6,0,10);
	g.addAresta(6,2,5);
	g.addAresta(7,8,20);
	g.addAresta(8,1,10);
	
	int orig=5, dest=7;
*/
	g.dijkstra(orig,dest);
	system("pause");
	return 0;
}
