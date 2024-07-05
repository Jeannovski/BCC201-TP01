#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
//Função espera receber argumentos da linha de comando, no caso, o nosso programa e o arquivo txt.

int main(int argc, char *argv[]){
    FILE *arquivo;
    char **matrixTabuleiro;
    int linhas, colunas;
    int **matrixRegrasLinhas, **matrixRegrasColunas;
    int maxColunas = 0, maxLinhas = 0, auxColunas, auxLinhas;

    //Abertura do arquivo e leitura de dados.


    //Verifica se há pelo menos um argumento além do nome do programa.
    if(argc == 2){
        //Armazena o arquivo txt em uma variavel, para ser acessado e lido depois.
        char *arquivoTxt = argv[1];
        //Abre o arquivo para leitura.
        FILE *arquivo = fopen(arquivoTxt, "r");

        //Verifica se o arquivo foi aberto com sucesso e realiza as operacoes necessarias.
        if(arquivo != NULL){
            //Le 2 inteiros apartir do arquivo, como o numero de linhas
            //e colunas esta na primeira linha do arquivo, facilita nosso trabalho. 
            if(fscanf(arquivo, "%d %d", &linhas, &colunas)==2){
                printf("Valores lidos: %d %d\n", linhas, colunas);
            }
            else{
                printf("Erro ao ler o numero de linhas e colunas.\n");
                //Fecha o arquivo.
                fclose(arquivo);
                return 1;
            }
          

            //Leitura do numero maximo de numeros nas instrucoes laterais, 
            //uso o nome de auxColunas e maxColunas, pois as instrucoes laterais sao
            //delimitadas pelas colunas, alem de acrescentar um espaco a mais para o cabecalho.

            for(int i=0; i<linhas; i++){
                fscanf(arquivo, "%d", &auxColunas);
                if(auxColunas>maxColunas){
                    maxColunas = auxColunas+1;
                }
            }
            

            //Leitura do numero maximo de numeros nas instrucoes acima do tabuleiro, 
            //uso o nome de auxLinhas e maxLinhas, pois as instrucoes acima do tabuleiro sao
            //delimitadas pelas linhas, alem de acrescentar um espaco a mais para o cabecalho.

            for(int i=0; i<colunas; i++){
                fscanf(arquivo, "%d", &auxLinhas);
                if(auxLinhas>maxLinhas){
                    maxLinhas = auxLinhas + 1;
                }
            }


            //Aloca memoria para o tabuleiro.
            matrixTabuleiro = alocarMatrixTabuleiro(linhas, colunas);
            //Aloca memoria para as matrizes de instrucoes.
            matrixRegrasLinhas = alocarInstrucoesLaterais(maxColunas, linhas);
            matrixRegrasColunas = alocarInstrucoesAcima(colunas, maxLinhas);

            fseek(arquivo, 0, SEEK_SET); //Volta ao inicio do arquivo para colocar os valores nas matrizes.
            fscanf(arquivo, "%*d%*d"); //Pula os dois primeiros numeros.
            fseek(arquivo, 1, SEEK_CUR); //Pula o bloco

            int *vetor;
            vetor = malloc(linhas * sizeof(int));



            // Pular a primeira coluna
            for (int i = 0; i < linhas; i++) {
                fscanf(arquivo, "%d", &vetor[i]); 
                //Armazena o numero de numeros que vai haver na instrucao
                //lateral, para depois, usar esse numero para ler a quantidade de numeros naquela linha.
                for(int j=0; j<vetor[i]; j++){
                    fscanf(arquivo, "%d", &matrixRegrasLinhas[i][j]);
                }
            }

            fseek(arquivo, 1, SEEK_CUR);//Pula o bloco.


            int *vetor2;
            vetor2 = malloc(colunas * sizeof(int));
            for(int i=0; i<colunas; i++){
                fscanf(arquivo, "%d", &vetor2[i]);
                for(int j=0; j<vetor2[i]; j++){
                    fscanf(arquivo, "%d", &matrixRegrasColunas[i][j]);
                }
            }

            fclose(arquivo);



            fseek(arquivo,0, SEEK_SET)//Volta ao inicio do arquivo novamente para a leitura da matriz principal.
            fscanf(arquivo, "%*d%*d")//Pula os dois primeiros numeros.

            //Le a matrix principal.
            for(int i=0; i<linhas; i++){
                for(int j=0; j<colunas; j++){
                    fscanf(arquivo, " %c", &matrixTabuleiro);
                }
            }

        }
        //Caso o arquivo .txt for NULL, imprimimos uma mensagem de erro e retornamos 1.
        else{
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }
    }
    //Caso a passagem de argumentos for incorreta, imprimimos uma mensagem falando que
    //o programa foi passado como parametro, porem, o arquivo .txt, nao. 
    else{
        printf("Uso: %s, porém, não há arquivo.txt\n", argv[0]);
        return 1; 
    }


    //Interacao com o usuario e recebimento de comandos.

























    return 0;// Final da funcao main.
}







