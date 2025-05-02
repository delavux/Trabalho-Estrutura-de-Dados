#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int gerarMatricula() {
    int i, matricula;
    for (i = 0; i < 5; i++) { //Criando a matricula
        matricula = rand() % 100000; // Convertendo int's para strings
    }
        
    return matricula;
}

int gerarIndex (const char *fileName) {
    int index = 0;
    int i;
    FILE *arquivo = fopen(fileName, "r"); //abre o arquivo em modo de leitura
    if (arquivo == NULL) { //checa se o arquivo foi aberto
        printf("Erro ao abrir o arquivo.\n"); 
        return -1;
    }
    while ((i = fgetc(arquivo)) != EOF) { //inicia um looping verificando cada caractere, enquanto não encontrar um fim do arquivo
        if (i == '\n') {
            index++; //adicionando 1 ao index toda vez que o codigo achar uma quebra de linha
        }
    }
    fclose(arquivo);
    return index;
}

int main() {

    srand(time(NULL)); //Gerando a seed para o srand baseado no tempo no sistema operacional

    const char *mainFName = "Arquivo.csv";

    
    char nome[50], materia[100], matricula[6];

    FILE *arquivo = fopen(mainFName, "r+"); //Tentando abrir o arquivo

    if (arquivo == NULL) { //Verificando se o arquivo foi aberto
        printf("Criando Arquivo.\n");
        arquivo = fopen(mainFName, "w"); //Craiando um arquivo caso não seja encontrado
        if (arquivo == NULL) {
            printf("Erro ao criar o arquivo");
            return 1;
        }
        
    } else {
        printf("Arquivo encontrado. Pronto para manipulação\n");
    }

    fclose(arquivo); // Fechando o arquivo para que possa ser aberto de diferentes formas futuramente

    //Arquivo aberto ou Criado

    //Estrutura CSV ==> index,nome,materia,matricula (Ex 0,Eduardo,Biologia,25209) 
    
    int opt;
    do { //iniciando o menu do programa
        printf("\nMenu:\n");
        printf("1- Ver matriculas existentes\n");
        printf("2- Adicionar matricula\n");
        printf("3- Ornizar itens\n");
        printf("4. Remover matriculas existentes\n");
        printf("5. Sair\n");
        printf("Escolha uma das opçôes abaixo: ");
        scanf("%d", &opt);
        int i;
        

        switch (opt) {
            case 1:
                // Código para Ver alunos matriulados
                break;
            case 2:
              printf("Digite o nome do aluno: ");
              scanf("%s", &nome);
              printf("Digite a materia em que o aluno sera matriculado: ");
              scanf("%s", &materia);

                arquivo = fopen(mainFName, "a"); //Abrindo o arquivo em modo append
                fprintf(arquivo, "%d,%s,%s,%d\n", gerarIndex(mainFName), nome, materia, gerarMatricula()); // Construção da linha
                fclose(arquivo); //Fechando o arquivo 
              
                break;
            case 3:
                // Código para reorganizar as matriculas que tem salvas
                break;
            case 4:
                // Código para remover uma das matriculas existentes
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("erro. Tente novamente.\n");
        }
    } while (opt != 5);

    //Finalizando o programa
    if (arquivo != NULL){
    fclose(arquivo);
    }
   return 0;
}
