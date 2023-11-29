#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colecao.h"

//Inserir_coleção adiciona um novo pokemon a sua coleção
void inserir_colecao(Colecao minha_colecao[], Pokemon pokedex[], int tamanho, int tamanho_colecao){

    int novo_numero;
    int achou = 0;

    printf("Insira o número do Pokémon que deseja adicionar na coleção: ");
    scanf("%d",&novo_numero);

    for(int i = 1; i < tamanho; i++){
        if(novo_numero == pokedex[i].numero){
            achou++;
        }
    }
    if(achou == 0){
        printf("Pokémon inválido. Insira um valor válido: ");
        scanf("%d", &novo_numero);
    }else{

    //verifica se o novo número já existe na coleção
    int numero_existente = 0;
    for(int i = 1; i < tamanho_colecao; i++){
        if(minha_colecao[i].numero_pokemon == novo_numero){
            numero_existente = 1;
            break;
        }
    }

    if(numero_existente){
        printf("Esse Pokémon já está na coleção.\n");
    }else{

        //encontra um espaço vazio na coleção para adicionar o novo Pokémon
        for(int i = 1; i < tamanho_colecao; i++){
            if(minha_colecao[i].numero_pokemon == 0){
                minha_colecao[i].numero_pokemon = novo_numero;
                printf("Pokémon adicionado à coleção com sucesso!\n");
                break;
            }
        }
    }
    }

}

//Listar_coleção verifica se a minha coleção não esta vazia, se não estiver lista em ordem os pokemons
void listar_colecao(Colecao minha_colecao[], Pokemon pokedex[], int tamanho_colecao){

    int preenchido = 0;

    for(int i = 1; i < tamanho_colecao; i++){
        if(minha_colecao[i].numero_pokemon != 0){
            preenchido++;
        }
    }

    if(preenchido == 0){
        printf("Coleção vazia.\n");
        printf("\n");
        
        return;

    }else{

        printf("Seus Pokémon listados são:\n");

        for(int i = 1; i < tamanho_colecao; i++){

            if(minha_colecao[i].numero_pokemon != 0){
                printf("Posição [%d]: %d, %s.\n",
                i, minha_colecao[i].numero_pokemon, pokedex[minha_colecao[i].numero_pokemon].nome);
            }
        }
        printf("\n");
    }
}

//Pesquisar_coleção faz uma pesquisa pra ver se encontra o pokemon buscado dentro da coleção 
void pesquisar_colecao(Colecao minha_colecao[], Pokemon pokedex[], int tamanho_colecao){

    char busca_colecao[16];
    int achou = 0; //para que as buscas sejam realizadas

    printf("Insira o nome do Pokémon que deseja procurar na lista: ");
    ler_nomes(busca_colecao, 15);
    
    for(int i = 1; i < tamanho_colecao; i++){

        if(strcmp(busca_colecao,pokedex[minha_colecao[i].numero_pokemon].nome) == 0){

            printf("Número: %d.\n",pokedex[minha_colecao[i].numero_pokemon].numero);
            printf("Nome: %s.\n",pokedex[minha_colecao[i].numero_pokemon].nome);
            printf("Tipo 1: %s.\n",pokedex[minha_colecao[i].numero_pokemon].tipo1);
            printf("Tipo 2: %s.\n",pokedex[minha_colecao[i].numero_pokemon].tipo2);
            printf("Total: %d.\n",pokedex[minha_colecao[i].numero_pokemon].total);
            printf("Hp: %d.\n",pokedex[minha_colecao[i].numero_pokemon].hp);
            printf("Ataque: %d.\n",pokedex[minha_colecao[i].numero_pokemon].attack);
            printf("Defesa: %d.\n",pokedex[minha_colecao[i].numero_pokemon].defense);
            printf("Ataque especial: %d.\n",pokedex[minha_colecao[i].numero_pokemon].sp_attack);
            printf("Defesa especial: %d.\n",pokedex[minha_colecao[i].numero_pokemon].sp_defense);
            printf("Velocidade: %d.\n",pokedex[minha_colecao[i].numero_pokemon].speed);
            printf("Geração: %d°.\n",pokedex[minha_colecao[i].numero_pokemon].geracao);
            printf("Lendário (0 = não e 1 = sim): %d.\n",pokedex[minha_colecao[i].numero_pokemon].lendario);
            printf("Cor: %s.\n",pokedex[minha_colecao[i].numero_pokemon].cor);
            printf("Altura (metros): %.2f.\n",pokedex[minha_colecao[i].numero_pokemon].altura);
            printf("Peso (kg): %.2f.\n",pokedex[minha_colecao[i].numero_pokemon].peso);
            printf("Taxa de captura: %d.\n",pokedex[minha_colecao[i].numero_pokemon].catch_rate);
            printf("\n");

            achou++;
        }
    }

    if(achou == 0){
        printf("Pokémon indisponível na coleção.\n");
        printf("\n");
    }

}

//Alterar_coleção verifica se está preenchida a minha_coleção e caso esteja permite alterar um pokemon especifico
void alterar_colecao(Colecao minha_colecao[], int tamanho, int tamanho_colecao){

    int busca;
    int novo_numero;
    int achou = 0;
    int preenchido = 0;

    for(int i = 1; i < tamanho_colecao; i++){
        if(minha_colecao[i].numero_pokemon != 0){
            preenchido++;
        }
    }

    if(preenchido == 0){
        printf("Coleção vazia.\n");
        printf("\n");
        
        return;

    }else{

        printf("Insira o número do Pokémon da coleção que deseja alterar: ");
        scanf("%d",&busca);

        for(int i = 1; i < tamanho_colecao; i++){
            
            if(minha_colecao[i].numero_pokemon == busca){

                printf("Insira o número do novo Pokémon: ");
                scanf("%d",&novo_numero);

                while(novo_numero <= 0 || novo_numero > tamanho - 1){
                    printf("Pokémon inválido. Insira um valor entre 1 e %d: ",tamanho - 1);
                    scanf("%d",&novo_numero);
                }

                achou++;

                minha_colecao[i].numero_pokemon = novo_numero;
                printf("Pokémon alterado com sucesso.\n");
                printf("\n");

                break;

            }        
        }
        if(achou == 0){

                printf("Pokémon indisponível na coleção.\n");

        }
    }
}

//Excluir_coleção verifica para ver se a coleção nao esta vazia e caso não esteja permite excluir um pokemon da coleção
void excluir_colecao(Colecao minha_colecao[], int tamanho_colecao){
    
    int busca;
    int achou = 0;
    int preenchido = 0;

    for(int i = 1; i < tamanho_colecao; i++){
        if(minha_colecao[i].numero_pokemon != 0){
            preenchido++;
        }
    }

    if(preenchido == 0){
        printf("Coleção vazia.\n");
        printf("\n");
        
        return;

    }else{

        printf("Insira o número do Pokémon da coleção que deseja excluir: ");
        scanf("%d",&busca);

        for(int i = 1; i < tamanho_colecao; i++){
            
            if(minha_colecao[i].numero_pokemon == busca){
                minha_colecao[i].numero_pokemon = 0;
                achou++;
            
                printf("Pokémon excluído com sucesso.\n");
                printf("\n");
                
            }           
        }
        
        if(achou == 0){
            
            printf("Pokémon indisponível na coleção.\n");
            
        }
    }
    
}
