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

    maior = Entrada(dna); // Lendo minha entrada e retornando o tamanho da maior sequência  do dna
    
    MoverGap(dna); // Procuro espaço na fita do dna, caso exista retiramos e inserimos um tracinho na frente
 
    Alinhar(dna, maior); //Alinhamos as duas sequências de dna para ficarem do mesmo tamanho
    
    int resul = SomaPeso(dna); //Retorna a soma dos pessos 

    Imprimir(dna, resul); // Imprimo o alinhamento de resultado da soma;
    

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

    // Função de mover o espaço em branco e inserir '-' no inicio da string;
    char temp[201];
    char auxi[201];

    int j = 0;

    for (int i = 0; i < TAM; i++) // Repetição para Percorrer as linhas da matriz
    {
        j = 0;
        while(dna[i][j] != '\0') //Repetição para percorrer as colunas da linha fixada
        {
            if(dna[i][j] == ' ') //caso tenha espaço na sequência de dna
            {
                strcpy(temp, dna[i]); //Copio a string completa para o a string  temp
                dna[i][strcspn(dna[i], " ")] = '\0'; //Subustituindo o espaço em branco pelo '\0' que indica o final da string
                
                int k = 0;  // indice da minha string auxiliar
                int l = j + 1; //salvando o índice no qual queremos copiar

                while(temp[l] != '\0') // percorrendo a sting temp até achar o final da string
                {
                    auxi[k] = temp[l];  //Atribuindo os Caracteres de temp para a string auxiliar
                    
                    k++, l++; // incrementando os indices k e l
                }
                auxi[k] = '\0'; // Informando o final da string
                
                strcat(dna[i], auxi); //Copiando a conteúdo da sting auxi para a matriz dna[i];

            }
            
            j++; // Incrementando J
        }


    }
}

void InserirTraco(char dna[TAM][101])
{

    int j;
    for (int i = 0; i < TAM; i++)  // Repetição para percorrer as linhas da matriz
    {
        j = 0;
        while(dna[i][j] != '\0') // Percorro a coluna da matriz na qual a linha está fixada
        {
            if(dna[i][j] == ' ')  //Caso seja um espaço em Branco substituo para um '-';
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

