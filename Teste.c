/*Teste p/ início do projeto*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{

    int numero, geracao, total, lendario;
    char nome[16], cor[12], tipo1[12], tipo2[12];
    int hp, attack, defense, sp_attack, sp_defense, speed;
    float altura, peso;
    int catch_rate;
    int pre_evol, prox_evol;

} Pokemon;

typedef struct{
    
    Pokemon pokemon_no_time[5];

} Mochila;

/*Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) os Pokémons disponíveis para serem capturados.
Essa relação deve aumentar e diminuir dinamicamente.*/
int main(){

    int opcao;
    int tamanho = 722;
    int busca;

    Pokemon* pokedex = (Pokemon*)malloc(tamanho * sizeof(Pokemon));
    if(pokedex == NULL){
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }

    FILE* arq = fopen("C:\\Users\\kauan\\Documents\\Projetos\\pokedex.csv", "r");

    if(arq == NULL){

        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    for(int i = 1; i < tamanho; i++){
        fscanf(arq,"%d,%15[^,],%11[^,],%11[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%s,%f,%f,%d",
        &pokedex[i].numero, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2,
         &pokedex[i].total, &pokedex[i].hp, &pokedex[i].attack, &pokedex[i].defense,
         &pokedex[i].sp_attack, &pokedex[i].sp_defense, &pokedex[i].speed, &pokedex[i].geracao,
         &pokedex[i].lendario, pokedex[i].cor, &pokedex[i].altura, &pokedex[i].peso,
         &pokedex[i].catch_rate);
    }

    printf("Menu opções:\n");
    printf("1 - Inserir.\n2 - Listar.\n3 - Pesquisar.\n4 - Alterar.\n5 - Excluir.\n6 - Sair.\n");

    printf("Insira sua opção: ");
    scanf("%d",&opcao);

    if(opcao < 1 || opcao > 6){
        printf("Opção inválida. Insira novamente sua opção: ");
        scanf("%d",&opcao);
    }

    do{
    switch(opcao){

        case 1:

        tamanho++;
        pokedex = realloc(pokedex, tamanho * sizeof(Pokemon));
        
        //inserção do nome
        printf("Insira o nome do Pokémon desejado para inserção: ");
        setbuf(stdin, NULL);
        fgets(pokedex[tamanho].nome, 14, stdin);
        pokedex[tamanho].nome[strcspn(pokedex[tamanho].nome, "\n")] = '\0';

        //inserção do número
        printf("Insira o número desse pokémon ");
        printf("(Obs: Necessita ser maior que 721 pois é o número do último da lista): ");
        scanf("%d",&pokedex[tamanho].numero);

        if(pokedex[tamanho].numero <= 721){
            printf("Valor inválido. Insira um novo valor: ");
            scanf("%d",&pokedex[tamanho].numero);
        }

        //inserção da geração
        printf("Insira a geração desse Pokémon: ");
        scanf("%d",&pokedex[tamanho].geracao);

        if(pokedex[tamanho].geracao <= 0){
            printf("Valor inválido. Insira um novo valor: ");
            scanf("%d",&pokedex[tamanho].geracao);
        }

        //inserção da cor
        printf("Insira a cor desse Pokémon: ");
        setbuf(stdin, NULL);
        fgets(pokedex[tamanho].cor, 10, stdin);
        pokedex[tamanho].cor[strcspn(pokedex[tamanho].cor, "\n")] = '\0';

        //inserção do tipo primário
        printf("Insira o tipo primário desse Pokémon: ");
        setbuf(stdin, NULL);
        fgets(pokedex[tamanho].tipo1, 10, stdin);
        pokedex[tamanho].tipo1[strcspn(pokedex[tamanho].tipo1, "\n")] = '\0';

        //inserção do tipo secundário
        printf("Insira o tipo secundário desse Pokémon, se não houver, pressione ""Enter"": ");
        setbuf(stdin, NULL);
        fgets(pokedex[tamanho].tipo2, 10, stdin);
        pokedex[tamanho].tipo2[strcspn(pokedex[tamanho].tipo2, "\n")] = '\0';

        if(strcmp(pokedex[tamanho].tipo2, "\n") == 0){
            strcpy(pokedex[tamanho].tipo2, "NULL");
        }

        //inserção do valor total
        printf("Insira o valor total desse Pokémon: ");
        scanf("%d",&pokedex[tamanho].total);

        if(pokedex[tamanho].total <= 0){
            printf("Valor inválido. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho].total);
        }

        //inserção do HP total do Pokémon
        printf("Insira o HP total desse Pokémon: ");
        scanf("%d",&pokedex[tamanho].hp);

        if(pokedex[tamanho].hp <= 0){
            printf("HP inválido. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho].hp);
        }

        //inserção de stats
        printf("Insira seu ataque e defesa respectivamente: ");
        printf("Ataque: ");
        scanf("%d",&pokedex[tamanho].attack);

        if(pokedex[tamanho].attack <= 0){
            printf("Ataque inválido. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho].attack);
        }

        printf("Defesa: ");
        scanf("%d",&pokedex[tamanho].defense);

        if(pokedex[tamanho].defense <= 0){
            printf("Defesa inválida. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho].defense);
        }

        printf("Insira seu ataque e defesa especial respectivamente: ");
        printf("Ataque Esp.: ");
        scanf("%d",&pokedex[tamanho].sp_attack);

        if(pokedex[tamanho].sp_attack <= 0){
            printf("Ataque Esp. inválido. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho].sp_attack);
        }

        printf("Defesa Esp.: ");
        scanf("%d",&pokedex[tamanho].sp_defense);

        if(pokedex[tamanho].sp_defense <= 0){
            printf("Defesa Esp. inválida. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho].sp_defense);
        }

        printf("Por fim, insira sua velocidade: ");
        scanf("%d",&pokedex[tamanho].speed);

        if(pokedex[tamanho].speed <= 0){
            printf("Velocidade inválida. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho].speed);
        }

        //lendário ou não?
        printf("Esse Pokémon é lendário? Para ""Sim"", insira 1, e para ""Não"", insira 0: ");
        scanf("%d",&pokedex[tamanho].lendario);

        if(pokedex[tamanho].lendario != 0 && pokedex[tamanho].lendario != 1){
            printf("Insira um valor igual a 0 ou 1.");
            scanf("%d",&pokedex[tamanho].lendario);
        }

        //inserção altura e peso
        printf("Insira a altura e peso do Pokémon respectivamente: ");
        printf("Altura: ");
        scanf("%f",&pokedex[tamanho].altura);

        if(pokedex[tamanho].altura <= 0.0){
            printf("Altura inválida. Insira um valor adequado: ");
            scanf("%f",&pokedex[tamanho].altura);
        }

        printf("Peso: ");
        scanf("%f",&pokedex[tamanho].peso);

        if(pokedex[tamanho].peso <= 0.0){
        printf("Peso inválido. Insira um valor adequado: ");
        scanf("%f",&pokedex[tamanho].peso);
        }

        break;

        case 2:
        for(int i = 0; i < tamanho; i++){

            printf("Número: %d.\n",pokedex[i].numero);
            printf("Nome: %s.\n",pokedex[i].nome);
            printf("Tipo 1: %s.\n",pokedex[i].tipo1);
            printf("Tipo 2: %s.\n",pokedex[i].tipo2);
            printf("Total: %d.\n",pokedex[i].total);
            printf("Hp: %d.\n",pokedex[i].hp);
            printf("Ataque: %d.\n",pokedex[i].attack);
            printf("Defesa: %d.\n",pokedex[i].defense);
            printf("Ataque especial: %d.\n",pokedex[i].sp_attack);
            printf("Defesa especial: %d.\n",pokedex[i].sp_defense);
            printf("Velocidade: %d.\n",pokedex[i].speed);
            printf("Geração: %d°.\n",pokedex[i].geracao);
            printf("Lendário (0 = não e 1 = sim): %d.\n",pokedex[i].lendario);
            printf("Cor: %s.\n",pokedex[i].cor);
            printf("Altura (metros): %f.\n",pokedex[i].altura);
            printf("Peso (kg): %f.\n",pokedex[i].peso);
            printf("Taxa de captura: %d.\n",pokedex[i].catch_rate);
            printf("\n");

        }

        break;

        case 3:

        printf("Insira o número do Pokémon que deseja buscar na Pokédex: ");
        scanf("%d",&busca);

        if(busca <= 0 || busca > tamanho){
            printf("Número inválido.\nInsira um número entre 1 e %d.\n",tamanho);
            scanf("%d",&busca);
        }else{
            printf("Número: %d.\n",pokedex[busca].numero);
            printf("Nome: %s.\n",pokedex[busca].nome);
            printf("Tipo 1: %s.\n",pokedex[busca].tipo1);
            printf("Tipo 2: %s.\n",pokedex[busca].tipo2);
            printf("Total: %d.\n",pokedex[busca].total);
            printf("Hp: %d.\n",pokedex[busca].hp);
            printf("Ataque: %d.\n",pokedex[busca].attack);
            printf("Defesa: %d.\n",pokedex[busca].defense);
            printf("Ataque especial: %d.\n",pokedex[busca].sp_attack);
            printf("Defesa especial: %d.\n",pokedex[busca].sp_defense);
            printf("Velocidade: %d.\n",pokedex[busca].speed);
            printf("Geração: %d°.\n",pokedex[busca].geracao);
            printf("Lendário (0 = não e 1 = sim): %d.\n",pokedex[busca].lendario);
            printf("Cor: %s.\n",pokedex[busca].cor);
            printf("Altura (metros): %f.\n",pokedex[busca].altura);
            printf("Peso (kg): %f.\n",pokedex[busca].peso);
            printf("Taxa de captura: %d.\n",pokedex[busca].catch_rate);
            printf("\n");
        }
    }
    }while(opcao != 6);

    fclose(arq);
    free(pokedex);

    return 0;

}