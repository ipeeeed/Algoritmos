#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Listas Duplamente Ligadas ou Listas Duplamente Encadeadas combinado com Criptografia de dados.
struct Criptography {
	char mensagem[30];
	struct Criptography *anterior;
	struct Criptography *proximo;
}; typedef struct Criptography node; // O comando [typedef] da o apelido "node" para "struct Criptography".

void Criptografar(char cripto[30])
{
// Caracteres especiais nao serao criptografados...
	int parada = strlen(cripto);
	int valor = 0;
	//Criptografa!
	while(valor != parada)
	{
		if (cripto[valor] > 96 && cripto[valor] < 123)
		{
			if (cripto[valor] > 117 && cripto[valor] < 123)
			{
				cripto[valor]-=21;
			}
			else
			{
				cripto[valor]+=5;
			}
		}
		else if (cripto[valor] > 64 && cripto[valor] < 91)
		{
			if (cripto[valor] > 85 && cripto[valor] < 91)
			{
				cripto[valor]-=21;
			}
			else
			{
				cripto[valor]+=5;
			}
		}
		else if (cripto[valor] < 58 && cripto[valor] > 47)
		{
			if (cripto[valor] < 51 && cripto[valor] > 47)
			{
				cripto[valor]+=7;
			}
			else
			{
				cripto[valor]-=3;
			}
		}
		valor++;
	}
	printf("\n------------------------\nElemento Criptografado: %s\n------------------------\n", cripto);
	valor--;
	//Descriptografa!
	while(valor != -1)
	{
		if (cripto[valor] < 123 && cripto[valor] > 96)
		{
			if (cripto[valor] < 102 && cripto[valor] > 96)
			{
				cripto[valor]+=21;
			}
			else
			{
				cripto[valor]-=5;
			}
		}
		else if (cripto[valor] < 91 && cripto[valor] > 64)
		{
			if (cripto[valor] < 70 && cripto[valor] > 64)
			{
				cripto[valor]+=21;
			}
			else
			{
				cripto[valor]-=5;
			}
		}
		else if (cripto[valor] > 47 && cripto[valor] < 58)
		{
			if (cripto[valor] > 54 && cripto[valor] < 58)
			{
				cripto[valor]-=7;
			}
			else
			{
				cripto[valor]+=3;
			}
		}
		valor--;
	}
}

void ExibeCripto(node *CabecaLista)
{
	if (CabecaLista -> proximo == NULL)
	{
		printf("\n\n------------------------\nLista Vazia\n------------------------\n\n");
	}
	else
	{
		node *aux = CabecaLista -> proximo;
		printf("\n\n------------------------\nExibindo Lista...\n------------------------\n\n");
		while(aux != NULL)
		{
			Criptografar(aux -> mensagem);
			aux = aux -> proximo;
		}
	}
}

void ExibeDescripto(node *CabecaLista)
{
	if (CabecaLista -> proximo == NULL)
	{
		printf("\n\n------------------------\nLista Vazia\n------------------------\n\n");
	}
	else
	{
		node *aux = CabecaLista -> proximo;
		printf("\n\n------------------------\nExibindo Lista...\n------------------------\n\n");
		while(aux != NULL)
		{
			printf("\n------------------------\nElemento Descriptografado: %s\n------------------------\n", aux -> mensagem);
			aux = aux -> proximo;
		}
	}
}

void InsereElemento(node *CabecaLista)
{
	printf("\n\n------------------------\n Inserindo...\n------------------------\n\n");
	node *novo = (node *)malloc(sizeof(node)); // Alocando um novo node
	node *aux = CabecaLista;
	
	if(!novo)
	{
		printf("\nSem mem�ria disponivel\n");
		exit(1);
	}

	printf("\nInsira Elemento: ");
	scanf("%s", &novo -> mensagem);

	while(aux -> proximo != NULL)
	{
		aux = aux -> proximo;
	}
	novo -> proximo = NULL;
	novo -> anterior = aux;
	aux -> proximo = novo;
}

void Opcao(int *num, node *CabecaLista) // O ponteiro [*num] recebe o valor de endereco da variavel [sair]. O ponteiro [*CabecaLista] recebe os valores de [CabecaLista].
{
	printf("\n\n------------------------\nEscolha uma das opcoes:\n\n0. Sair\n1. Insere Elemento na Lista\n2. Exibir Lista Criptografada\n3. Exibir Lista Descriptografada\n------------------------\n\n");
	scanf("%d", num); // Campo para digitar a opcao onde e disparada a funcao.

	switch(*num) // O ponteiro [*num] pega o valor de de [num] que e o mesmo valor de [sair] e chama a funcao escolhida.
	{
		case 0:
			printf("\n\n------------------------\nSaindo...\n------------------------\n\n");
			exit(1);
			break;
		case 1:
			InsereElemento(CabecaLista);
			break;
		case 2:
			ExibeCripto(CabecaLista);
			break;
		case 3:
			ExibeDescripto(CabecaLista);
			break;
		default:
			printf("\n\n------------------------\nOpcao Invalida!\n------------------------\n\n");
	}
}

int main() // O programa a rodar comeca aqui!
{
	node *CabecaLista = (node *) malloc(sizeof(node)); // Aqui e alocada a "Struct Criptography" atraves do comando [malloc], e o comando [sizeof] define a quantidade de memoria a ser alocada.
	CabecaLista -> proximo = NULL; // Aqui sao definidos os valores de proximo e anterior da "Struct Criptography", que e nulo ou [NULL].
	CabecaLista -> anterior = NULL;
	printf("\n------------------------\nSeja Bem Vindo(a)!\n------------------------\n");
	
	int sair = 1;
	do
	{
		Opcao(&sair, CabecaLista); // O [&sair] envia o endereco de memorio como parametro, e o valor do ponteiro de [CabecaLista].
	} while (sair != 0);
	
	free(CabecaLista);
	return 0;
}
