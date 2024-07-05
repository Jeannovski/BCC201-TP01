// * Arquivo de cabecalho(header) com os prototipos das funcoes
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
char **alocarMatrixTabuleiro(int linhas, int colunas);
void liberarMatrixTabuleiro(char **matrix, int linhas);
void preencheMatrixTabuleiro(char **matrix, int linhas, int colunas);
void exibirCabecalhoColunas(int colunas);
int **alocarInstrucoesLaterais(int maxColunas, int linhas);
int **alocarInstrucoesAcima(int colunas, int maxLinhas);



















#endif

