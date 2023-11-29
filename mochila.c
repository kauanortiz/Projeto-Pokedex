#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mochila.h"

/*nserir_no_time essa é uma função para adicionar a mochila o pokemon desejado, 
mostra tambem caso o pokemon ja tenha sido add ao time e caso o pokemon não seja valido*/
void inserir_no_time(Mochila meu_time[], int tamanho){

    if(meu_time[1].integrante != 0){
        printf("Time já preenchido.\n");
        printf("\n");

        return;
    }

    for(int i = 1; i < 7; i++){
        printf("Insira o número do %d° Pokémon do time: ",i);
        scanf("%d",&meu_time[i].integrante);

        while(meu_time[i].integrante == meu_time[i - 1].integrante ){
            printf("Pokémon já adicionado ao time. Insira outro: ");
            scanf("%d",&meu_time[i].integrante);
            printf("\n");
        }
        while(meu_time[i].integrante <= 0 || meu_time[i].integrante > tamanho){
            printf("Pokémon inválido. Insira um número válido: ");
            scanf("%d",&meu_time[i].integrante);
            printf("\n");
        }
    }

    printf("\n");

}

//Exibir_time tem objetivo de exibir os pokemons ja cadastrados na mochila
void exibir_time(Mochila meu_time[], Pokemon pokedex[]){

    if(meu_time[1].integrante == 0){
        printf("Time ainda não preenchido.\n");
        printf("\n");

    }else{
        for(int i = 1; i < 7; i++){
            printf("%d° Pokémon: %s.\n",i, pokedex[meu_time[i].integrante].nome);
        }
        printf("\n");
    }
}

//Alterar_time verifica o time se foi preenchido, caso tenha sido altera o pokemon especifico
void alterar_time(Mochila meu_time[], Pokemon pokedex[], int tamanho){

    int alterar;

    if(meu_time[1].integrante == 0){
        printf("Time ainda não preenchido.\n");
        printf("\n");

    return;

    }else{

        printf("Time atual:\n");

        for(int i = 1; i < 7; i++){
            printf("[%d]: %s.\n",i, pokedex[meu_time[i].integrante].nome);
        }
        printf("\n");
    }

    printf("Qual deles deseja alterar? ");
    scanf("%d",&alterar);
    printf("\n");

    while(alterar < 1 || alterar > 6){

        printf("Valor inválido. Insira novamente: ");
        scanf("%d",&alterar);
        printf("\n");
    }
    printf("Qual o número do Pokémon que deseja colocar no lugar de %s? ", pokedex[meu_time[alterar].integrante].nome);
    scanf("%d",&meu_time[alterar].integrante);
    printf("\n");

    while(meu_time[alterar].integrante <= 0 || meu_time[alterar].integrante > tamanho){
        printf("Pokémon inválido. Insira um número válido: ");
        scanf("%d",&meu_time[alterar].integrante);
        printf("\n");
    }
    printf("Pokémon alterado com sucesso.\n");
    printf("\n");
}
