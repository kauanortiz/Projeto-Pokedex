#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{

    int numero, geracao;
    char nome[15], cor[11], tipo1[11], tipo2[11];
    int hp_total, attack, defense, sp_attack, sp_defense, speed;
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
    scanf("%d", &opcao);

    if(opcao < 1 || opcao > 6){
        printf("Opção inválida. Insira novamente sua opção: ");
        scanf("%d", &opcao);
    }

    switch(opcao){

        case 1:
        
        //fecha o arquivo e abre como append
        fclose(arq);
        fopen("C:\\Users\\kauan\\Documents\\Projetos\\pokedex.csv", "a");
        
        //inserção do nome
        printf("Insira o nome do Pokémon desejado para inserção: ");
        setbuf(stdin, NULL);
        fgets(pokemon_i.nome, 14, stdin);
        pokemon_i.nome[strcspn(pokemon_i.nome, "\n")] = '\0';

        //inserção do número
        printf("Insira o número desse pokémon ");
        printf("(Obs: Necessita ser maior que 722 é o número do último da lista): ");
        scanf("%d",&pokemon_i.numero);

        if(pokemon_i.numero <= 722){
            printf("Valor inválido. Insira um novo valor: ");
            scanf("%d",&pokemon_i.numero);
        }

        //inserção da geração
        printf("Insira a geração desse Pokémon: ");
        scanf("%d", &pokemon_i.geracao);

        if(pokemon_i.geracao <= 0){
            printf("Valor inválido. Insira um novo valor: ");
            scanf("%d",&pokemon_i.geracao);
        }

        //inserção da cor
        printf("Insira a cor desse Pokémon: ");
        setbuf(stdin, NULL);
        fgets(pokemon_i.cor, 10, stdin);
        pokemon_i.cor[strcspn(pokemon_i.cor, "\n")] = '\0';

        //inserção do tipo primário
        printf("Insira o tipo primário desse Pokémon: ");
        setbuf(stdin, NULL);
        fgets(pokemon_i.tipo1, 10, stdin);
        pokemon_i.tipo1[strcspn(pokemon_i.tipo1, "\n")] = '\0';

        //inserção do tipo secundário
        printf("Insira o tipo secundário desse Pokémon, se não houver, pressione ""Enter"": ");
        setbuf(stdin, NULL);
        fgets(pokemon_i.tipo2, 10, stdin);
        pokemon_i.tipo2[strcspn(pokemon_i.tipo2, "\n")] = '\0';

        if(strcmp(pokemon_i.tipo2, '\n') == 0){
            pokemon_i.tipo2[11] = "Nenhum";
        }

        //inserção do HP total do Pokémon
        printf("Insira o HP total desse Pokémon: ");
        scanf("%d", &pokemon_i.hp_total);

        if(pokemon_i.hp_total <= 0){
            printf("HP inválido. Insira um valor adequado: ");
            scanf("%d", &pokemon_i.hp_total);
        }

        //inserção de stats
        printf("Insira seu ataque e defesa respectivamente: ");
        printf("Ataque: ");
        scanf("%d", &pokemon_i.attack);

        if(pokemon_i.attack <= 0){
            printf("Ataque inválido. Insira um valor adequado: ");
            scanf("%d", &pokemon_i.attack);
        }

        printf("Defesa: ");
        scanf("%d", &pokemon_i.defense);

        if(pokemon_i.defense <= 0){
            printf("Defesa inválida. Insira um valor adequado: ");
            scanf("%d",&pokemon_i.defense);
        }

        printf("Insira seu ataque e defesa especial respectivamente: ");
        printf("Ataque Esp.: ");
        scanf("%d", &pokemon_i.sp_attack);

        if(pokemon_i.sp_attack <= 0){
            printf("Ataque Esp. inválido. Insira um valor adequado: ");
            scanf("%d", &pokemon_i.sp_attack);
        }

        printf("Defesa Esp.: ");
        scanf("%d", &pokemon_i.sp_defense);

        if(pokemon_i.sp_defense <= 0){
            printf("Defesa Esp. inválida. Insira um valor adequado: ");
            scanf("%d",&pokemon_i.sp_defense);
        }

        printf("Por fim, insira sua velocidade: ");
        scanf("%d", &pokemon_i.speed);

        if(pokemon_i.speed <= 0){
            printf("Velocidade inválida. Insira um valor adequado: ");
            scanf("%d", &pokemon_i.speed);
        }

        //lendário ou não?
        printf("Esse Pokémon é lendário? Para ""Sim"", insira 1, e para ""Não"", insira 0: ");
        scanf("%d", &pokemon_i.lendario);

        if(pokemon_i.lendario != 0 || pokemon_i.lendario != 1){
            printf("Insira um valor igual a 0 ou 1.");
            scanf("%d", &pokemon_i.lendario);
        }

        //inserção altura e peso
        printf("Insira a altura e peso do Pokémon respectivamente: ");
        printf("Altura: ");
        scanf("%f", &pokemon_i.altura);

        if(pokemon_i.altura <= 0.0){
            printf("Altura inválida. Insira um valor adequado: ");
            scanf("%d", &pokemon_i.altura);
        }

        printf("Peso: ");
        scanf("%f", &pokemon_i.peso);

        if(pokemon_i.peso <= 0.0){
        printf("Peso inválido. Insira um valor adequado: ");
        scanf("%d", &pokemon_i.peso);
        }

    }

}
int main(){


    return 0;
}