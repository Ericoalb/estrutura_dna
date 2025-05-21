#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 2


long int Entrada(char dna[TAM][101]);
void MoverGap(char dna[TAM][101]);
void InserirTraco(char dna[TAM][101]);
void Alinhar(char dna[TAM][101], long int maior);
int SomaPeso(char dna[TAM][101]);
void Imprimir(char dna[TAM][101], int resul);

int main()
{
    
    // Declarando minha matriz de string
    char dna[2][101];

    // Cada linha recebe uma string completa, e seu tamanho é definido pelas colunas
    // dna[2][101];
    //     i   j,  i = linhas e j colunas;
    // dna[i] = significa que passo receber até duas entradas de strings
    // dna[j] = define otamanho másimo da minha string;

    long int maior = 0; 
    maior = Entrada(dna);
    //printf("%ld\n", maior);
    MoverGap(dna);
    //InserirTraco(dna);
    Alinhar(dna, maior);
    
    int resul = SomaPeso(dna);

    Imprimir(dna, resul);
    

    return 0;
}


long int Entrada(char dna[TAM][101])
{
    long int maior = 0;

   for(int i = 0; i < TAM; i++)
    {
        // Lendo as entrdas do usuário
        fgets(dna[i], 101, stdin);
        dna[i][strcspn(dna[i], "\n")] = '\0'; // trocando o "\n" pelo '\0';

        // Verificando o maior strlen(retrna o tamanho da sting) e logo apos salvo na variável maior;
        if(strlen(dna[i]) > maior)
        {
            maior = strlen(dna[i]);
        }
    } 

    //printf("\n%s\n%s\n", dna[0], dna[1]);

    return maior;
}

void MoverGap(char dna[TAM][101])
{
    char temp[201];
    char auxi[201];
    int j = 0;
    for (int i = 0; i < TAM; i++)
    {
        j = 0;
        while(dna[i][j] != '\0')
        {
            if(dna[i][j] == ' ')
            {
                strcpy(temp, dna[i]);
                dna[i][strcspn(dna[i], " ")] = '\0';
                
                int k = 0;
                int l = j + 1;

                while(temp[l] != '\0')
                {
                    auxi[k] = temp[l];
                    
                    k++, l++;
                }
                auxi[k] = '\0';
                
                strcat(dna[i], auxi);

            }
            
            j++;
        }


    }
}

void InserirTraco(char dna[TAM][101])
{
    int j;

    for (int i = 0; i < TAM; i++)
    {
        j = 0;
        while(dna[i][j] != '\0')
        {
            if(dna[i][j] == ' ')
            {
                dna[i][j] = '-';
            }
            
            j++;
        }


    }

    return;
}



void Alinhar(char dna[TAM][101], long int maior)
{

    // Os Gaps devem ser inseridos no Início da sequência!

    long int dif;
    char temp[200]; //Criando um array temporário com o tamanho da diferança;

    for(int i = 0; i < TAM; i++)
    {
        //Verificando se o tamanho da string é menor que o maior tamanho salvo
        // Dessa forma conseguimos igualar tods os tamanhos;
        if(strlen(dna[i]) < maior)
        {
            dif = maior - strlen(dna[i]); //Salvando a siferença entre a string é o maior tamanho
            

            for(int j = 0; j <= (dif + 1); j++) // For para adicionar os gaps na string temp
            {
                if(j == dif)
                {
                    temp[j] = '\0';
                    strcat(temp, dna[i]); //Concatenando as string temp com dna
                    strcpy(dna[i], temp); // Salvando a string já com os tamanhos certos na matriz de setring
                }

                else
                {
                    temp[j] = '-';
                }
            }
        }
    }

    return;
}



int SomaPeso(char dna[TAM][101])
{

    // Pesos para Compração das bases nirogenadas;
    // Alpha(Se as bases forem iguas, +1)
    // Beta (Se as bases forem diferentes, 0);
    // Gama (Se existe um gap "-" e uma base nirogenada, -1)


    int a = 0, b = 0, g = 0;
    int resul;
    int k = 0;


    // Repetição para efetuar as comparaçõeos dos pares, e fazer os calculos 
    while(dna[0][k] != '\0')
    {
        for(int i = 0; i < TAM - 1; i++)
        {
            for(int j = i + 1; j < TAM; j++)
            {
                if(dna[i][k] == dna[j][k] && dna[i][k] != '-') a++;
                else if(dna[i][k] == '-' && dna[j][k] != '-') g++;
                else if(dna[i][k] != '-' && dna[j][k] == '-') g++;
            }
        }
        
        k++;
    }

    resul = (a) + (g * -1);

    return resul;
}



void Imprimir(char dna[TAM][101], int resul)
{
    
    printf("\nAlinhamento Multiplo!\n");
    
    for(int i = 0; i < TAM; i++)
    {
        printf("%s\n", dna[i]);
    }

    printf("\nResultado dos Calculos dos Pesos: %d\n", resul);

    return;
}

