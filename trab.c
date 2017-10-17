#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PILOTOS 50
#define MAX_NOME 50
#define MAX_EQUIPES 50



/* Armazena informações de um piloto */
typedef struct {
	char nome[MAX_NOME+1];
	int equipe;
	int pontos;
	int classif[MAX_PILOTOS];
} plt;

/* Armazena informações de uma equipe */
typedef struct {
	char nome[MAX_NOME+1];
	int pontos;
} equ;

/* Armazena informações de um campeonato */
typedef struct {
	char nome[MAX_NOME+1];
	int num_plts;
	plt piloto[MAX_PILOTOS];
	int num_equs;
	equ equipe[MAX_EQUIPES];
	int qtd_pontos;
	int sistema_pt[MAX_PILOTOS];
} cmp;


void ler_pontos ( int V[], int quant){
	 int i;

	for ( i=0; i<quant; i++){
		scanf("%d", &V[i]);
	}
} 

void busca_pilotos (plt A[MAX_PILOTOS], char nome [MAX_NOME], int tam, int pontos){
	 int i;

	for ( i = 0; i < tam; i++) {
		if (strcmp(nome, A[i].nome)== 0){
			A[i].pontos+=pontos;
		}
	}

}
void busca_equipes (equ A[MAX_PILOTOS], char nome [MAX_NOME], int tam, int pontos){
	int i;

	for ( i = 0; i < tam; i++) {
		if (strcmp(nome, A[i].nome)== 0){
			A[i].pontos+=pontos;
		}
	}
}

void soma_equipes ( equ A[MAX_EQUIPES], int tam){
	 int i, j;

	for (i=0; i<tam; i++){
		for ( j = i+1; j<tam; j++){
			if(strcmp(A[j].nome, "\0")==0){
				j++;
			}
			if ( strcmp (A[i].nome, A[j].nome)==0){
				A[i].pontos += A[j].pontos;
				strcpy(A[j].nome, "\0");
		    }
		}
    }
}

int main(int argc, char const *argv[]) {
	
	int c, i, j, k, n;
	int pontos;

	system ("clear");

	plt piloto [MAX_PILOTOS]= {0};
	equ equipes[MAX_EQUIPES] = {0};
	cmp camp[MAX_NOME] = {0};
    equ eq[MAX_NOME];

	char nome_prova[MAX_NOME];
	char nome_plt[MAX_NOME];
	char nome_equipe[MAX_NOME];

   	/* quantidade de Casos de Teste*/
	scanf("%d", &c);
	printf("\n");

	i =0;
	while ( i< c){
		/*Nome do Campeonato*/
		scanf(" %[^\n]", camp[i].nome);

		/*Quantidade de Pilotos*/
		scanf("%d", &camp[i].num_plts);

		/*Ler os Numeros de Pilotos e equipes*/

		for (j =0; j<camp[i].num_plts; j++) {
	    	scanf(" %[^,],", camp[i].piloto[j].nome);
	    	scanf(" %[^\n]", camp[i].equipe[j].nome);
        }
    	
    	/*Sistema e Quantidade de Pontuação*/
    	scanf("%d", &camp[i].qtd_pontos);
        ler_pontos (camp[i].sistema_pt, camp[i].qtd_pontos);

    	/*Quantidade de Provas*/

    	scanf("%d", &k);

    	  for (j=0; j<1 ; j++){
    	  	scanf(" %[^\n]",nome_prova);
    	  	  for (n =0; n<camp[i].num_plts; n++){
    	  	  	  scanf(" %[^,],", piloto[n].nome);
    	  	  	  scanf(" %[^\n]", equipes[n].nome);
    	  	  	  piloto[n].pontos = camp[i].sistema_pt[n];
    	  	  	  equipes[n].pontos = camp[i].sistema_pt[n];
    	  	  }
    	  }
    	  printf("************************************************\n");
    	
    	  printf("\n");

    	  soma_equipes (equipes, camp[i].num_plts);

    	   for (j=0; j<k-1 ; j++){
    	  	  scanf(" %[^\n]",nome_prova);
    	  	    for (n =0; n<camp[i].num_plts; n++){
    	  	     	scanf(" %[^,],", nome_plt);
    	  	     	scanf(" %[^\n]", nome_equipe);
    	  	     	pontos = camp[i].sistema_pt[n];
    	  	     busca_pilotos(piloto,nome_plt, camp[i].num_plts, pontos);
    	  	     busca_equipes (equipes, nome_equipe, camp[i].num_plts, pontos );
    	  	    }
    	    }
   			/*
       	  	for (n =0; n<camp[i].num_plts; n++){
       	  		printf("%s, %d\n",equipes[n].nome, equipes[n].pontos );
         }*/
   			

    	  printf("%s\n\n",camp[i].nome );
    	  printf("Classificacao apos %d provas realizadas\n\n",k );
    	  printf("Pilotos\n");
    	  for (j =0; j<camp[i].num_plts; j++){
    	  		printf("%d. %s, %d pontos\n",j+1, piloto[j].nome, piloto[j].pontos);
    	  }
    	  printf("\nEquipes\n\n");
    	   for (j =0; j<camp[i].num_plts; j++ ){
       	  		printf("%s, %d\n",equipes[j].nome, equipes[j].pontos );
    	  }



		i++;
	}
	return 0;
}	