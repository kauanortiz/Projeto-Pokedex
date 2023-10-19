/*Teste p/ início do projeto*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{

    int numero, geracao;
    char nome[15], cor[10], tipo1[10], tipo2[10];
    int total, attack, defense, sp_attack, speed;
    bool lendario;
    float altura, peso;
    float catch_rate;
    int pre_evol, prox_evol;

} Pokemon;

typedef struct{
    
    Pokemon pokemon_no_time[5];

} Mochila;

void abrir_arquivo(FILE* arq){
    arq = fopen("C:\\Users\\kauan\\Documents\\Projetos\\pokedex.csv", "r");

    if(arq == NULL){

        printf("Erro na abertura do arquivo.\n");
        exit(1);

    }
}

/*Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) os Pokémons disponíveis para serem capturados.
Essa relação deve aumentar e diminuir dinamicamente.*/
void cadastro(FILE* arq){

    int opcao;
    Pokemon pokemon_i;

    printf("Menu opções:\n");
    printf("1 - Inserir.\n2 - Listar.\n3 - Pesquisar.\n4 - Alterar.\n5 - Excluir.\n");

    printf("Insira sua opção: ");
    scanf("%d",opcao);

    if(opcao < 1 || opcao > 6){
        printf("Opção inválida. Insira novamente sua opção: ");
        scanf("%d",opcao);
    }

    switch(opcao){

        case 1:
        fclose(arq);
        fopen("C:\\Users\\kauan\\Documents\\Projetos\\pokedex.csv", "a");
        
        printf("Insira o nome do Pokémon desejado para inserção: ");
        setbuf(stdin, NULL);
        fgets(pokemon_i.nome, 14, stdin);
        pokemon_i.nome[strcspn(pokemon_i.nome, "\n")] = '\0';

        printf("Insira o número desse pokémon ");
        printf("(Obs: Necessita ser maior que 722 é o número do último da lista): ");
        scanf("%d",&pokemon_i.numero);

        if(pokemon_i.numero <= 722){
            printf("Valor inválido. Insira um novo valor: ");
            scanf("%d",&pokemon_i.numero);
        }

        printf("Insira a geração desse pokémon: ");
        scanf("%d", pokemon_i.geracao);

    }

}

int main(){

    FILE* arq;
    abrir_arquivo(arq);
    cadastro(arq);

    return 0;
}