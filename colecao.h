#ifndef COLECAO_H
#define COLECAO_H

typedef struct{

    int numero, geracao, total, lendario;
    char nome[16], cor[12], tipo1[12], tipo2[12];
    int hp, attack, defense, sp_attack, sp_defense, speed;
    float altura, peso;
    int catch_rate;
    int pre_evol, prox_evol;

} Pokemon;

typedef struct{ 
    
    int integrante;

} Mochila;

typedef struct{

    int numero_pokemon;

} Colecao;

void inserir_colecao(Colecao minha_colecao[], Pokemon pokedex[], int tamanho, int tamanho_colecao);
void listar_colecao(Colecao minha_colecao[], Pokemon pokedex[], int tamanho_colecao);
void pesquisar_colecao(Colecao minha_colecao[], Pokemon pokedex[], int tamanho_colecao);
void alterar_colecao(Colecao minha_colecao[], int tamanho, int tamanho_colecao);
void excluir_colecao(Colecao minha_colecao[], int tamanho_colecao);

#endif