#include <stdio.h>
#include <stdlib.h>
#define infinito 10000
int custo[6][6];

void dijkstra (int orig, int dest){
	int k,t,n=6;
	int d[6],p[6], ultimo;
	int rotulado[6]={-1,-1,-1,-1,-1,-1};
	int nrotulado[6]={0,1,2,3,4,5};
	k=0;
	
	//Passo 1:	
	printf("\nPasso 1:\n\n");
	rotulado[orig]=orig;
	d[orig]=0;
	p[orig]=0;
	ultimo = orig;
	printf("R <- {%d};\n",rotulado[orig]+1);
	printf("NR <- {");
	for(t=0; t<n; t++){
		if (nrotulado[t]==ultimo){
			if(t!=0){
				nrotulado[t]=-t;
			}else nrotulado[t]=-1;
		}
		if (nrotulado[t]==t) {
			printf("%d ",nrotulado[t]+1);
			d[t]=infinito;
			p[t]=n+1;
		}
	}printf("}\n");
	printf("d(%d) <- %d;\n",orig+1,d[orig]);
	printf("p(%d) <- %d;\n",orig+1,p[orig]);
	printf("ultimo <- %d;\n\n",ultimo+1);
	
	//Passo 2:
	while(nrotulado[dest]==dest | k!=n-1){
	printf("Passo 2:\n\n");
	int candidato=0, cand=500;
	for(t=0; t<n; t++){
		if(t==nrotulado[t]){
			if( d[t] <= (d[ultimo] + custo[ultimo][t]) ){
				printf("d(%d) <- %d;\t",t+1,d[t]);
				printf("\n");
			}else{
				d[t]=d[ultimo] + custo[ultimo][t];
				printf("d(%d) <- %d;\t",t+1,d[t]);
				if(d[t]<infinito){
					p[t]=ultimo+1;
					printf("p(%d) <- %d;",t+1,p[t]);
				}printf("\n");
			}
			if(d[t]<=cand){
			cand=d[t];
			candidato=t;
			}
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
	printf("\nk=%d",k);
	d[candidato]=cand;
	ultimo = candidato;

	//Passo 3
	printf("\n\nPasso 3:\n\n");
	if(candidato!=dest){
		printf("Nodo %d nao rotulado, retorne ao Passo 2\n\n", dest+1);
	}else printf("Nodo %d rotulado, PARE!\n\n", dest+1);

	printf("NR <- {");
	for(t=0; t<n; t++){
		if (nrotulado[t]==t) printf("%d ",nrotulado[t]+1);
	}printf("}\n");
		printf("R <- {");
	for(t=0; t<n; t++){
		if (rotulado[t]>=0) printf("%d ",rotulado[t]+1);
	}printf("}\n");
	printf("d(%d) <- %d;\n",ultimo+1,d[ultimo]);
	printf("p(%d) <- %d;\n",ultimo+1,p[ultimo]);
	printf("ultimo <- %d;\n\n",ultimo+1);
	}
	int i=dest;
	while(i!=orig){
		printf(" p(%d) <- %d; ",i+1,p[i]);
		i=p[i]-1;		
	}printf("\n\n");

	printf("O caminho minimo do no %d ao no %d e dado por:\n",orig+1,dest+1);
	i=dest;
	printf("C = {");
	while(i!=orig){
		if((p[i]-1)==orig){
			printf("(%d,%d)",i+1,p[i]);
		}else printf("(%d,%d);",i+1,p[i]);
		i=p[i]-1;		
	}printf("} = %d\n\n", d[dest]);
}

int main() {
			
	custo[0][0] = 0;
	custo[0][1] = 7;
	custo[0][2] = 3;
	custo[0][3] = infinito;
	custo[0][4] = infinito;
	custo[0][5] = infinito;
	
	custo[1][0] = infinito;
	custo[1][1] = 0;
	custo[1][2] = 1;
	custo[1][3] = 6;
	custo[1][4] = infinito;
	custo[1][5] = infinito;
	
	custo[2][0] = infinito;
	custo[2][1] = infinito;
	custo[2][2] = 0;
	custo[2][3] = infinito;
	custo[2][4] = 8;
	custo[2][5] = infinito;
	
	custo[3][0] = infinito;
	custo[3][1] = infinito;
	custo[3][2] = 3;
	custo[3][3] = 0;
	custo[3][4] = infinito;
	custo[3][5] = 2;
	
	custo[4][0] = infinito;
	custo[4][1] = infinito;
	custo[4][2] = infinito;
	custo[4][3] = 2;
	custo[4][4] = 0;
	custo[4][5] = 8;
	
	custo[5][0] = infinito;
	custo[5][1] = infinito;
	custo[5][2] = infinito;
	custo[5][3] = infinito;
	custo[5][4] = infinito;
	custo[5][5] = 0;

	int orig=0, dest=5;
	dijkstra (orig,dest);
	system("pause");
	return 0;
}
