#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 3


typedef struct no
{
    char dna[101];
    long int tam;
    struct no *proximo;

}No;


void Entrada(No **lista)
{
    for(int i = 0; i < TAM; i++)
    {
        No *novo = malloc(sizeof(No));

        fgets(novo->dna, 101, stdin);
        novo->dna[strcspn(novo->dna, "\n")] = '\0';
        novo->tam = strlen(novo->dna);
        if(novo)
        {
            if(*lista == NULL)
            {
                novo->proximo = *lista;
                *lista = novo;
            }
    
            else
            {
                No *auxi = *lista;
                while(auxi->proximo != NULL)
                {
                    auxi = auxi->proximo;
                }

                auxi->proximo = novo;
                novo->proximo = NULL;
            }
        }
    
        else
        {
            printf("Erro ao alocar memporia!\n");
        }

    }

    return;

}


void Imprimir(No *lista)
{
    if(lista == NULL)
    {
        printf("Lista vazia!\n");
    }

    else
    {
        while(lista != NULL)
        {
            printf("%s\n", lista->dna);
            lista = lista->proximo;
        }
    }
}

long int EncontrarMaior(No *lista)
{
    long int maior = 0;

    if(lista == NULL)
    {
        return 0;
    }

    else
    {

        while(lista != NULL)
        {
            if(lista->tam > maior)
            {
                maior = lista->tam;
            }

            lista = lista->proximo;
        }
    }


    return maior;
}


void Alinhar(No *lista)
{
    if(lista == NULL)
    {
        printf("Lista vazia\n");
    }

    else
    {
        long int maior = EncontrarMaior(lista);
        int i = 0;
        while(lista != NULL)
        {
             //Verificando se o tamanho da string é menor que o maior tamanho salvo
            if(maior > lista->tam)
            {
                long int dif;
                char temp[101]; //Criando um array temporário com o tamanho da diferança;

                dif = maior - strlen(lista->dna); //Salvando a siferença entre a string é o maior tamanho
                        
                for(int j = 0; j <= (dif + 1); j++) // For para adicionar os gaps na string temp
                {
                    if(j == dif)
                    {
                        temp[j] = '\0';
                        strcat(temp, lista->dna); //Concatenando as string temp com dna
                        strcpy(lista->dna, temp); // Salvando a string já com os tamanhos certos na matriz de setring
                    }

                    else
                    {
                        temp[j] = '-';
                    }
                }                                    
            }

            lista = lista->proximo;
        }
    }
}


int SomaPeso(No *lista)
{
    // Pesos para Compração das bases nirogenadas;
    // Alpha(Se as bases forem iguas, +1)
    // Beta (Se as bases forem diferentes, 0);
    // Gama (Se existe um gap "-" e uma base nirogenada, -1)
    
    int a = 0, b = 0, g = 0;
    int resul;
    int k = 0;


    if(lista == NULL)
    {
        printf("Lista Vazia!\n");
    }

    else
    {
        int i = 0;
        No *auxi = lista;

        while(lista->dna[i] != '\0')
        {
            No *auxi2 = auxi;

            while(auxi2 != NULL)
            {
                while(auxi->proximo != NULL)
                {
                    if(auxi2->dna[i] == auxi->proximo->dna[i] && auxi2->dna[i] != '-') a++;
                    else if (auxi2->dna[i] == '-' && auxi->proximo->dna[i] != '-') g++;
                    else if (auxi2->dna[i] != '-' && auxi->proximo->dna[i] == '-') g++;
                    auxi = auxi->proximo;
                }
                
                auxi = auxi2->proximo;
                auxi2 = auxi;
            }
            auxi = lista;
            i++;
        }
    }

    resul = (a) + (g * -1);
    printf("%d\n%d\n", a, g);
    return resul;

    
}
int main()
{
    No *dna = NULL;

    Entrada(&dna);
    Alinhar(dna);
    printf("\nAlinhamento Multiplo!\n");
    Imprimir(dna);
    printf("\nResultado dos Calculos dos Pesos: %d\n", SomaPeso(dna));
    return 0;
}