#include <stdio.h>
#include "functions.h"
#include <stdlib.h>
#include <string.h>



//Funcao para alocar memoria para a matrix do tabuleiro.
char **alocarMatrixTabuleiro(int linhas, int colunas){
    //Cria um array de ponteiros que recebe ponteiros para valores do tipo char.
    char **matrixTabuleiro = (char**)malloc(linhas * sizeof(char *)); //"Linhas".
    for(int i=0; i<linhas; i++){
        //Aloca ponteiros do tipo char dentro do array de ponteiros, criando uma matrix representada por
        //"linhas-colunas".
        matrixTabuleiro[i] = (char*)malloc(colunas * sizeof(char)); //"Colunas".
    }
    return matrixTabuleiro; //Retorna a matrix com a quantidade de memoria necessaria.
}


//Funcao para liberar a memoria da matrix do tabuleiro. 
void liberarMatrixTabuleiro(char **matrixTabuleiro, int linhas){
    for(int i=0; i<linhas; i++){
        free(matrixTabuleiro[i]); //Libera a memoria dos ponteiros tipo char. "Colunas"
    }
    free(matrixTabuleiro);//Libera a memoria do array de ponteiros que recebe os ponteiros do tipo char. "Linhas"
}


//Funcao para preencher o tabuleiro.
void preencheMatrixTabuleiro(char **matrixTabuleiro, int linhas, int colunas){
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            if(j < colunas - 1){
                //Adiciona um espaco apos cada ponto, exceto no final.
                matrixTabuleiro[i][j] = '.';
            }
            else{
                //Nao adiciona espaco no final da linha.
                matrixTabuleiro[i][j] = '.';
            }
        }
    }
}

//Funcao para exibir o cabecalho do tabuleiro.
void exibirCabecalhoColunas(int colunas){
    printf("   "); //Espaco para alinhar com os elementos do tabuleiro.
    for(int i=0; i<colunas; i++){
        printf("%c  ", 'A' + i); // Exibe o rotulo da coluna.
    }
    printf("\n");
}

//Funcao para alocar as instrucoes laterais.
int **alocarInstrucoesLaterais(int maxColunas, int linhas){
    //Cria um array de ponteiros que recebe ponteiros para valores do tipo char.
    int **matrixRegrasLinhas = (int**)malloc(linhas * sizeof(int *)); //"Linhas".
    for(int i=0; i<linhas; i++){
        //Aloca ponteiros do tipo char dentro do array de ponteiros, criando uma matrix representada por
        //"linhas-colunas".
        matrixRegrasLinhas[i] = (int*)malloc(maxColunas * sizeof(int)); //"Colunas".
    }
    return matrixRegrasLinhas; //Retorna a matrix com a quantidade de memoria necessaria.
}


//Funcao para alocar as instrucoes acima do tabuleiro.
int **alocarInstrucoesAcima(int colunas, int maxLinhas){
    //Cria um array de ponteiros que recebe ponteiros para valores do tipo char.
    int **matrixRegrasColunas = (int**)malloc(maxLinhas * sizeof(int *)); //"Linhas".
    for(int i=0; i<maxLinhas; i++){
        //Aloca ponteiros do tipo char dentro do array de ponteiros, criando uma matrix representada por
        //"linhas-colunas".
        matrixRegrasColunas[i] = (int*)malloc(colunas * sizeof(int)); //"Colunas".
    }
    return matrixRegrasColunas; //Retorna a matrix com a quantidade de memoria necessaria.
}




























