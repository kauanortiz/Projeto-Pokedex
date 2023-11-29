#ifndef MOCHILA_H
#define MOCHILA_H

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

void inserir_no_time(Mochila meu_time[], int tamanho);
void exibir_time(Mochila meu_time[], Pokemon pokedex[]);
void alterar_time(Mochila meu_time[], Pokemon pokedex[], int tamanho);

#endif