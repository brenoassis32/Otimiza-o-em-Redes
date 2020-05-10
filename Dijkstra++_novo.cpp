#include <iostream>
#include <windows.h>
#include <fstream>
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
	custo[v2][v1]=c;	
}

void dijkstra (int orig, int dest)
{
	int k,t,contador,n=V+1;
	k=0;
	contador=0;
	ofstream myfile;
	myfile.open("Dijkstra.txt");		
	//Passo 1:	
	myfile<<endl<<"Passo 1:"<<endl<<endl;
	rotulado[orig]=orig;
	d[orig]=0;
	p[orig]=0;
	ultimo = orig;
	myfile<<"R <- {"<<rotulado[orig]+1<<"};\n"<<endl;
	myfile<<"NR <- {";
	for(t=0; t<n; t++){
		if (nrotulado[t]==ultimo){
			if(t!=0){
				nrotulado[t]=-t;
			}else nrotulado[t]=-1;
		}
		if (nrotulado[t]==t) {
			myfile<<nrotulado[t]+1<<" ";
			d[t]=infinito;
			p[t]=n+1;
		}
	}myfile<<"}"<<endl;
	myfile<<"d("<<orig+1<<") <- "<<d[orig]<<";"<<endl;
	myfile<<"p("<<orig+1<<") <- "<<p[orig]<<";"<<endl;
	myfile<<"ultimo <- "<<ultimo+1<<";"<<endl<<endl;
	int soma=0;
	//Passo 2:
	while(/*nrotulado[dest]==dest || */k!=V){
	myfile<<"Passo 2:"<<endl<<endl;
	int candidato=0, cand=500;
	for(t=0; t<n; t++){
		if(t==nrotulado[t]){
			if( d[t] <= (d[ultimo] + custo[ultimo][t]) ){
				myfile<<"d("<<t+1<<") <- "<<d[t]<<";\t"<<endl;
			}else{
				d[t]=d[ultimo] + custo[ultimo][t];
				myfile<<"d("<<t+1<<") <- "<<d[t]<<";\t";
				if(d[t]<infinito){
					p[t]=ultimo+1;
					myfile<<"p("<<t+1<<") <- "<<p[t]<<";";
				}myfile<<endl;
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
	d[candidato]=cand;
	ultimo = candidato;

	myfile<<"NR <- {";
	for(t=0; t<n; t++){
		if (nrotulado[t]==t) myfile<<nrotulado[t]+1<<" ";
	}myfile<<"}"<<endl;
		myfile<<"R <- {";
	for(t=0; t<n; t++){
		if (rotulado[t]>=0) myfile<<rotulado[t]+1<<" ";
	}myfile<<"}"<<endl;
	myfile<<"d("<<ultimo+1<<") <- "<<d[ultimo]<<";"<<endl;
	myfile<<"p("<<ultimo+1<<") <- "<<p[ultimo]<<";"<<endl;
	myfile<<"ultimo <- "<<ultimo+1<<";"<<endl<<endl;

	//Passo 3
	myfile<<"Passo 3:"<<endl<<endl;
	if(candidato!=dest){
		myfile<<"Nodo "<<dest+1<<" nao rotulado, retorne ao Passo 2"<<endl<<endl;
	}else myfile<<"Nodo "<<dest+1<<" rotulado, PARE!"<<endl<<endl;
	myfile<<endl<<"k="<<k<<";"<<endl<<endl;

	}
	myfile<<endl<<"contador:"<<contador<<endl;
	//Sleep(5000);
	if(contador!=4*(V-1)+V){
	int i=dest;
	while(i!=orig){
		myfile<<" p("<<i+1<<") <- "<<p[i]<<"; ";
		i=p[i]-1;		
	}myfile<<endl<<endl;

	myfile<<"O caminho minimo do no "<<orig+1<<" ao no "<<dest+1<<" e dado por:"<<endl;
	i=dest;
	myfile<<"C = {";
	while(i!=orig){
		if((p[i]-1)==orig){
			myfile<<"("<<i+1<<","<<p[i]<<")";
		}else myfile<<"("<<i+1<<","<<p[i]<<");";
		i=p[i]-1;		
	}myfile<<"} = "<<d[dest]<<endl<<endl;	
	}else myfile<<"Nao ha caminho disponivel" <<contador<<endl;
	myfile.close();
}
};

int main() {

//	Grafo g(2); //g(6)
	
//	g.addAresta(0,1,2);  //g.addAresta(1,2,2); 

//	int orig=0, dest=5; //orig=5, dest=2;

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
/*	Grafo g(5); // grafo

	g.addAresta(0, 1, 5);
	g.addAresta(0, 2, 4);
	g.addAresta(0, 3, 10);
	g.addAresta(1, 2, 2);
	g.addAresta(1, 3, 2);
	g.addAresta(1, 4, 2);
	g.addAresta(2, 4, 5);
	g.addAresta(3, 4, 1);
	g.addAresta(3, 5, 3);
	g.addAresta(4, 5, 2);
*/
/*	int orig=0, dest=5;

	Grafo g(5); // grafo

	g.addAresta(0, 1, 120);
	g.addAresta(0, 2, 210);
	g.addAresta(0, 3, 210);
	g.addAresta(0, 4, 345);
	g.addAresta(0, 5, 1065);
	g.addAresta(1, 2, 120);
	g.addAresta(1, 3, 120);
	g.addAresta(1, 4, 210);
	g.addAresta(1, 5, 750);
	g.addAresta(2, 3, 120);
	g.addAresta(2, 4, 165);
	g.addAresta(2, 5, 525);
	g.addAresta(3, 4, 120);
	g.addAresta(3, 5, 300);
	g.addAresta(4, 5, 120);
*/

/*	int orig=0, dest=4;

	Grafo g(4); // grafo

	g.addAresta(0, 1, 120);
	g.addAresta(0, 2, 120);
	g.addAresta(0, 3, 210);
	g.addAresta(0, 4, 750);
	g.addAresta(1, 2, 120);
	g.addAresta(1, 3, 165);
	g.addAresta(1, 4, 525);
	g.addAresta(2, 3, 120);
	g.addAresta(2, 4, 300);
	g.addAresta(3, 4, 120);
*/
//	int orig=0, dest=2;

	Grafo g5(11); // grafo

	g5.addAresta(0, 1, 16);
	g5.addAresta(0, 2, 10);
	g5.addAresta(0, 9, 12);
	g5.addAresta(1, 2, 7);
	g5.addAresta(1, 3, 13);
	g5.addAresta(1, 4, 2);
	g5.addAresta(2, 4, 1);
	g5.addAresta(2, 6, 21);
	g5.addAresta(3, 6, 15);
	g5.addAresta(4, 5, 9);
	g5.addAresta(4, 10, 4);
	g5.addAresta(5, 6, 3);
	g5.addAresta(5, 7, 20);
	g5.addAresta(5, 10, 8);
	g5.addAresta(6, 7, 18);
	g5.addAresta(6, 8, 17);
	g5.addAresta(7, 9, 19);
	g5.addAresta(8, 9, 5);
	g5.addAresta(8, 10, 6);
	g5.addAresta(8, 11, 14);
	g5.addAresta(10, 11, 11);

	int orig=0, dest=4;

	Grafo g6(4); // grafo

	g6.addAresta(0, 1, 160);
	g6.addAresta(0, 2, 270);
	g6.addAresta(0, 3, 400);
	g6.addAresta(0, 4, 540);
	g6.addAresta(1, 2, 180);
	g6.addAresta(1, 3, 290);
	g6.addAresta(1, 4, 420);
	g6.addAresta(2, 3, 190);
	g6.addAresta(2, 4, 310);
	g6.addAresta(3, 4, 195);
	
	g6.dijkstra(orig,dest);
	system("pause");
	return 0;
}
