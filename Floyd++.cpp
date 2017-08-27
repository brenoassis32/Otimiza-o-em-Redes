#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 12
using namespace std;

class Grafo
{
private:
	int V; // número de vértices

	int roteamento[MAX][MAX][MAX], rota[MAX][MAX], distancias[MAX][MAX][MAX], custo[MAX][MAX];	
	char infinito;	

public:

	// construtor
Grafo(int V)
{
	this->V = V; // atribui o número de vértices
	this->roteamento[V+2][V+2][V+2] = roteamento[V+2][V+2][V+2];
	this->custo[V+1][V+1]=custo[V+1][V+1];
	this->distancias[V+2][V+2][V+2]=distancias[V+2][V+2][V+2];
	this->rota[V+1][V+1]=rota[V+1][V+1];
	this->infinito=infinito;	
	infinito='i';

	for(int i=0; i<=V;i++){
		for(int j=0; j<=V;j++) {
			if(i==j){
				custo[i][j]=0;
			}else custo[i][j]=infinito;
		}
	}		
}
	// adiciona uma aresta ao grafo de v1 à v2
void addAresta(int v1, int v2, int c)
{
	custo[v1][v2]=c;
}

void floyd ()
{
	cout<<"Formato para arco sem valor de custo: i"<<endl;

	int i, j, k;
	k=0;
//Gera Rotas			
	for(k = 0; k <= V+1; k++ )	{
		for(i = 1; i<=V+1; i++ ){
			for(j = 1; j<=V+1; j++ ){
				rota[i-1][j-1] = i;
				roteamento[i][j][k] = rota[i-1][j-1];
			}
		}
	}
//Passo1
	for(k = 0; k <= 1; k++ )	{
		for(i = 0; i <= V; i++ ){
			for(j = 0; j<= V; j++ ){
				distancias[i+1][j+1][k] = custo[i][j];			
			}
		}
	}
//Passo 2	
	for(k = 1; k <= V+1; k++ )	{
		for(i = 1; i<=V+1; i++ ){
			for(j = 1; j<=V+1; j++ ){
				distancias[i][j][k] = distancias[i][j][k-1];
				roteamento[i][j][k] = roteamento[i][j][k-1];
				if(distancias[i][j][k-1] != infinito){
					if(distancias[i][j][k-1] > distancias[i][k][k-1] + distancias[k][j][k-1]) {
					distancias[i][j][k] = distancias[i][k][k-1] + distancias[k][j][k-1];
					roteamento[i][j][k]= roteamento[k][j][k-1];
				    }
				} else{
					if((distancias[i][k][k-1] == infinito) || (distancias[k][j][k-1] == infinito)){
						distancias[i][j][k] = infinito;
					} else{
						distancias[i][j][k] = distancias[i][k][k-1] + distancias[k][j][k-1];
						roteamento[i][j][k]= roteamento[k][j][k-1];				
					}
			    }
			}
		}
	}
		
	for(k = 1; k <= V+1; k++ )	{
	cout<<endl;
	cout<<"k = "<<k<<endl<<endl;	
//Imprime Matriz de Distâncias		
		for(i = 1; i <= V+1; i++){
			for(j = 1; j <= V+1; j++){
				if(distancias[i][j][k] != infinito){
					cout<<" "<<(int)distancias[i][j][k];
				}else cout<<" "<<(char)distancias[i][j][k];
			}
			cout<<endl;
		}
		cout<<endl;

//Imprime roteamento	
		for(i = 1; i <= V+1; i++){
			for(j = 1; j <= V+1; j++){
				cout<<" "<<roteamento[i][j][k];
			}
			cout<<endl;
		}	
	}	
}
};

int main() {
	
/*	Grafo g(5);
	
	g.addAresta(0,1,2);
	g.addAresta(2,0,-4);
	g.addAresta(2,1,3);
	g.addAresta(2,3,-7);
	g.addAresta(3,0,2);
	g.addAresta(4,2,10);
	g.addAresta(4,3,5);
	g.addAresta(4,5,4);
	g.addAresta(5,0,5); 
	g.addAresta(5,3,1);
*/
/*	Grafo g(5);
	
	g.addAresta(0,1,4);
	g.addAresta(0,2,2);
	g.addAresta(1,2,-3);
	g.addAresta(1,3,2);
	g.addAresta(2,4,3);
	g.addAresta(3,4,1);
	g.addAresta(3,5,2);
	g.addAresta(4,3,1);
	g.addAresta(4,5,1);
*/
	Grafo g(2);
	
	g.addAresta(0,1,8);
	g.addAresta(0,2,5);
	g.addAresta(1,0,3);
	g.addAresta(2,1,2);

/*	Grafo g(5);
	
	g.addAresta(0,1,3);
	g.addAresta(0,2,8);
	g.addAresta(0,4,-4);
	g.addAresta(1,3,1);
	g.addAresta(1,4,7);
	g.addAresta(2,1,4);
	g.addAresta(3,2,-5);
	g.addAresta(3,0,2);
	g.addAresta(4,3,6);
*/				
	g.floyd();
	
	cout<<endl;
	system("pause");
	return 0;
}
