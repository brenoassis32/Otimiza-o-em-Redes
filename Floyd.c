#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int i, j, k, roteamento[7][7][7], rota[6][6], distancias[7][7][7], custo[6][6];	
	char infinito;	
	k=0;
	
	printf("Digite o formato para arco sem valor de custo: ");
	scanf("%c", &infinito);
		
	custo[0][0] = 0;
	custo[0][1] = 2;
	custo[0][2] = infinito;
	custo[0][3] = infinito;
	custo[0][4] = infinito;
	custo[0][5] = infinito;
	
	custo[1][0] = infinito;
	custo[1][1] = 0;
	custo[1][2] = infinito;
	custo[1][3] = infinito;
	custo[1][4] = infinito;
	custo[1][5] = infinito;
	
	custo[2][0] = -4;
	custo[2][1] = 3;
	custo[2][2] = 0;
	custo[2][3] = -7;
	custo[2][4] = infinito;
	custo[2][5] = infinito;
	
	custo[3][0] = 2;
	custo[3][1] = infinito;
	custo[3][2] = infinito;
	custo[3][3] = 0;
	custo[3][4] = infinito;
	custo[3][5] = infinito;
	
	custo[4][0] = infinito;
	custo[4][1] = infinito;
	custo[4][2] = 10;
	custo[4][3] = 5;
	custo[4][4] = 0;
	custo[4][5] = 4;
	
	custo[5][0] = 5;
	custo[5][1] = infinito;
	custo[5][2] = infinito;
	custo[5][3] = 1;
	custo[5][4] = infinito;
	custo[5][5] = 0;
	
	
	for(k = 0; k <= 6; k++ )	{
		for(i = 1; i<=6; i++ ){
			for(j = 1; j<=6; j++ ){
				rota[i-1][j-1] = i;
				roteamento[i][j][k] = rota[i-1][j-1];
			}
		}
	}

	for(k = 0; k <= 1; k++ )	{
		for(i = 0; i <= 5; i++ ){
			for(j = 0; j<= 5; j++ ){
				distancias[i+1][j+1][k] = custo[i][j];
				
			}
		}
	}
	

		
	for(k = 1; k <= 6; k++ )	{
		 
		 
		for(i = 1; i<=6; i++ ){
			for(j = 1; j<=6; j++ ){
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
		
	for(k = 1; k <= 6; k++ )	{
	printf("\n");
	printf("k = %d\n\n", k);	
		
		for(i = 1; i <= 6; i++){
			for(j = 1; j <= 6; j++){
				if(distancias[i][j][k] != infinito){
					printf(" %d",distancias[i][j][k]);
				} else{
				
					printf(" %c",distancias[i][j][k]);
				
				}
						
			}
			printf("\n");
		}
		printf("\n");
	
	
		for(i = 1; i <= 6; i++){
			for(j = 1; j <= 6; j++){
				printf(" %d",roteamento[i][j][k]);
			}
			printf("\n");
		}	
		
	}	
		
	system("pause");
	return 0;
}
