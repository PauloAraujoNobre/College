/*     1° Exercício Programa de Grafos     				 										 */ 
/*												         										                 */ 
/* Implementação do Algoritmo de Dijkstra              								 */
/* Implementado pelos alunos:			                 										 */
/* Matheus Holanda Matos, Moises Moura Rabelo, Paulo Henrique Araujo Nobre e Paulo Eduardo Dutra */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAXV 150
#define INFINITO 10000

int vertices = 0;   	//quantia de vértices
int arcos    = 0; 		//quantia de arcos
int origem   = 0;     //vértice origem requisitado
int destino  = 0;    	//vértice destino requisitado
int origemU  = 0;    	//vértice origem para cada arco
int destinoV = 0;   	//vértice destino para cada arco
int *custos  = NULL; 	//lista de adjacências 


/*ALGORITMO DE DIJKSTRA*/

//O algoritmo de Dijkstra soluciona o problema
//do caminho mais curto num grafo dirigido
//ou nao dirigido, com arestas de peso não negativo
void dijkstra(int vertices, int origem, int destino, int *custos) 
{ 
	int i = 0;
	int j = 0;
	int v = 0;
	int ant[MAXV];     //vetor dos antecessores 
	int z[MAXV];       //vetor com as vértices com conhecimento de seus caminhos mínimos
	int shorter[MAXV]; //vetor com o caminho mínimo solicitado
	double min;
	double dist[MAXV]; //vetor com os custos dos caminhos
	
	//Inicialização
	for (i = 0; i < vertices; i++) 
	{
		if (custos[(origem - 1) * vertices + i] != -1) 
		{
			ant[i] = origem - 1; 
			dist[i]=custos[(origem - 1) * vertices + i];
		}
		else 
		{
			ant[i] = -1;
			dist[i] = INFINITO;
		}
		z[i] = 0;
	}
	z[origem - 1] = 1;    
	dist[origem - 1] = 0; 

	//Inserção no vetor de vértices de caminho mínimo conhecido
	while (v != destino - 1 && min != INFINITO) 
	{
		min = INFINITO; 
		
		for (i = 0; i < vertices; i++) 
		{
			if (z[i] == 0) 
			{ 
				if (dist[i] >= 0 && dist[i] < min) 
				{ 
					min = dist[i]; 
					v = i; 
				}
			}
		}

		//Inserção das distâncias dos novos vizinhos de z
		if (min != INFINITO && v != destino - 1) 
		{
			z[v] = 1; 
			for (i = 0; i < vertices; i++) 
			{
				if (z[i] == 0)
				{ 
					if (custos[v * vertices + i] != -1 && dist[v] + custos[v * vertices + i] < dist[i]) 
					{ 
						dist[i] = dist[v] + custos[v * vertices + i]; 
						ant[i] = v; 
					}
				}
			}
		}
	}

  //Saída e Verificação se existe algum caminho	
	if (min == INFINITO) {
		printf("\nNão há caminho entre os vértices %d e %d.\n", origem, destino);
	}	
	else 
	{
		//Inserindo o caminho mínimo pedido num vetor só pra ele   
		i = destino;
		shorter[0] = destino;
		i = ant[i - 1];
		int count = 1;
		
		for (j = 1; i != -1; j++)
		{
			shorter[j] = i+1;
			i = ant[i];
			count++;
		}
		
		//Printando a saída como pedida no trabalho (a, b) (b , c)
		printf("\nCaminho mínimo do vértice %d para o vértice %d: \n\n", origem, destino);
		
    	for (i = 1; i < count; i++) {
			printf("(%d, %d) ", shorter[count - i], shorter[count - (i + 1)]);
		}
		printf("\n\nCusto: %d\n", (int)dist[destino - 1]);
	}
}

/* FUNÇÃO PARA ABERTURA DO ARQUIVO */

//A função faz a abertura do arquivo e
//a validação caso o usuário deixe de 
//passar o arquivo na execução ou passe mais
//de um arquivo
void openFile(int argc, char *argv[], FILE **arquivo) 
{
	char caminhoDoArquivo[50]; //Para caso não tenha sido iniciado com o nome de arquivo ou arquivo não ter sido encontrado

	if (argc == 2) {		//Se houver argumento mandado quando iniciado o programa, procura-se esse arquivo
		*arquivo = fopen(argv[1], "r");
	} 
	else if (argc > 2) 
	{   //Se for mandado mais de um argumento
		printf("Foi pego apenas o primeiro arquivo \n");
		*arquivo = fopen(argv[1], "r");
	}
	else { //Não houve nenhum argumento
		printf("Não houve nome de arquivo... \nSe quiser ...\n");		
	}
	
	if (*arquivo == NULL && argc > 1) { //Foi mandado N argumentos, mas não foi encontrado nenhum arquivo com tais nomes.
		printf("Arquivo não encontrado \n");
	}

	while (*arquivo == NULL) 
	{
		printf("Insira o caminho do arquivo:\n");
		fgets(caminhoDoArquivo, sizeof(caminhoDoArquivo), stdin);

		//Por o fgets armazenar quebra de linha, removemos o último caractere
		char *p_chr = strchr(caminhoDoArquivo, '\n'); 

		if (p_chr != NULL)  {
      *p_chr = '\0';
    }
		*arquivo = fopen(caminhoDoArquivo, "r");
	}
}

/* FUNÇÃO PARA LEITURA DO ARQUIVO */

//A função faz a leitura do arquivo e
//armazena as variáveis necessárias para
//o cálculo do Dijkstra
void readFile (FILE *arquivo) 
{
	int i = 0;
	int j = 0;

  	fscanf(arquivo, "%d %d %d %d", &vertices, &arcos, &origem, &destino); //Leitura da primeira Linha do arquivo txt
	
	free(custos);
	custos = (int*)malloc(sizeof(int)*vertices*vertices);

	for (i = 0; i <= vertices * vertices; i++) {
		custos[i] = -1;
	}

	//Armazenamento das variáveis a partir da linha 2 do arquivo txt
	for (j = 0; j < arcos; j++) 
	{
		fscanf(arquivo, "%d %d", &origemU, &destinoV);
		//Armazenamento dos custos
		fscanf(arquivo, "%d", &custos[(origemU-1)*vertices+destinoV-1]); 
	}
	fclose(arquivo);
}

int main( int argc, char *argv[] )
{
	setlocale(LC_ALL, "Portuguese"); //Para habilitar os usos de acentuação
	
	FILE *arquivo = NULL;

	openFile(argc, argv, &arquivo);	
  	readFile(arquivo);
  	
  	dijkstra(vertices, origem, destino, custos);

	return 0;
}
