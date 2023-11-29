#ifndef POKEDEX_h
#define POKEDEX_H

typedef struct{

    int numero, geracao, total, lendario;
    char nome[16], cor[12], tipo1[12], tipo2[12];
    int hp, attack, defense, sp_attack, sp_defense, speed;
    float altura, peso;
    int catch_rate;
    int pre_evol, prox_evol;

} Pokemon;

void ler_nomes(char numero_pokemon[], int size);
void inserir_novo(Pokemon pokedex[], int tamanho);
void listar_todos(Pokemon pokedex[], int tamanho);
void buscar_pokemon(Pokemon pokedex[], int tamanho);
void alterar_pokemon(Pokemon pokedex[], int tamanho);
void excluir_pokemon(Pokemon pokedex[], int tamanho);

#endif