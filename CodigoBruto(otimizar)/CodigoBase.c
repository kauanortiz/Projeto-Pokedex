/*Teste p/ início do projeto*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    int numero, geracao, total, lendario;
    char nome[16], cor[12], tipo1[12], tipo2[12];
    int hp, attack, defense, sp_attack, sp_defense, speed;
    float altura, peso;
    int catch_rate;
    int pre_evol, prox_evol;

} Pokemon;

typedef struct{
    
    Pokemon Time[5];

} Mochila;

void ler_nomes(char pokemon[]){

    setbuf(stdin, NULL);
    fgets(pokemon, 15, stdin);
    pokemon[strcspn(pokemon, "\n")] = '\0';

}

void listar_todos(Pokemon pokedex[], int tamanho){

    int opcao;
    int geracao_busca; //para caso opção 1 seja escolhida
    char busca_tipo[16]; //para caso opção 2 seja escolhida

    printf("Filtros para listagem de Pokémon: ");
    printf("\n1 - Por geração.\n2 - Por tipo.\n");
    printf("Insira o filtro desejado: ");
    scanf("%d",&opcao);
    printf("\n");

    switch(opcao){

        case 1:

        printf("Insira qual geração deseja exibir: ");
        scanf("%d",&geracao_busca);

        while(geracao_busca <= 0){
            printf("Valor inválido. Insira um valor adequado: ");
            scanf("%d",&geracao_busca);
            printf("\n");
        }

        for(int i = 0; i < tamanho; i++){

            if(pokedex[i].geracao == geracao_busca){

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
        }

        break;

        case 2:

        printf("Tipos de Pokémon: ");
        printf("\nAço\nBug(inseto)\nDragon(dragão)\nElectric(elétrico)\nFada\nFire(fogo)\nGelo\nGhost(fantasma)\n");
        printf("Lutador\nNormal\nPedra\nPlanta\nPsychic(psiquíco)\nSombrio\nTerra\nVenenoso\nVoador\nWater(água)\n");
        printf("Insira o tipo de Pokémon que deseja listar: ");
        ler_nomes(busca_tipo);
        printf("\n");

        if(strcmp(busca_tipo, "Inseto") == 0){
            strcpy("Bug",busca_tipo);
        }

        if(strcmp(busca_tipo, "Dragão") == 0){
            strcpy("Dragon",busca_tipo);
        }

        if(strcmp(busca_tipo, "Elétrico") == 0){
            strcpy("Electric",busca_tipo);
        }

        if(strcmp(busca_tipo, "Fogo") == 0){
            strcpy("Fire",busca_tipo);
        }

        if(strcmp(busca_tipo, "Fantasma") == 0){
            strcpy("Ghost",busca_tipo);
        }

        if(strcmp(busca_tipo, "Psiquíco") == 0){
            strcpy("Psychic",busca_tipo);
        }
        if(strcmp(busca_tipo, "Água") == 0){
            strcpy("Water",busca_tipo);
        }

        for(int i = 0; i < tamanho; i++){

            if(strcmp(pokedex[i].tipo1, busca_tipo) == 0 || strcmp(pokedex[i].tipo2, busca_tipo) == 0 ){

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
        }
    }

}

void buscar_pokemon(Pokemon pokedex[], int tamanho, char busca[]){

    int achou;

    printf("Insira o nome do Pokémon que deseja buscar na Pokédex: ");
    ler_nomes(busca);


    for(int i = 1; i < tamanho; i++){

        if(strcmp(busca, pokedex[i].nome) == 0){

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

            achou++;

        }
    }

        if(achou == 0){
            printf("Pokémon não encontrado.\n");
            printf("\n");
        }
}

void alterar_pokemon(Pokemon pokedex[], int tamanho, int indice){

    int achou;

        printf("Digite o número do Pokémon que deseja alterar: ");
        scanf("%d",&indice);
        printf("\n");

        for(int i = 1; i < tamanho; i++){

            if(indice == pokedex[i].numero){

                achou++;

                //alteração do nome
                printf("Qual o novo nome desse Pokémon? ");
                ler_nomes(pokedex[i].nome);

                //alteração do número
                printf("Insira o novo número desse Pokémon ");
                printf("(Obs: Necessita ser diferente dos demais contidos na Pokédex): ");
                scanf("%d",&pokedex[i].numero);
                printf("\n");

                while(pokedex[i].numero <= (tamanho - 1)){
                    printf("Valor inválido. Insira um novo valor: ");
                    scanf("%d",&pokedex[i].numero);
                    printf("\n");
                }

                //alteração da geração
                printf("Insira a nova geração desse Pokémon: ");
                scanf("%d",&pokedex[i].geracao);
                printf("\n");

                while(pokedex[i].geracao <= 0){
                    printf("Valor inválido. Insira um novo valor: ");
                    scanf("%d",&pokedex[i].geracao);
                    printf("\n");
                }

                //alteração da cor
                printf("Insira a nova cor desse Pokémon: ");
                ler_nomes(pokedex[i].cor);
                printf("\n");

                //alteração do tipo primário
                printf("Insira o novo tipo primário desse Pokémon: ");
                ler_nomes(pokedex[i].tipo1);

                //alteração do tipo secundário
                printf("Insira o novo tipo secundário desse Pokémon, se não houver, pressione ""Enter"": ");
                ler_nomes(pokedex[i].tipo2);
                printf("\n");

                if(strcmp(pokedex[i].tipo2, "\n") == 0){
                    strcpy(pokedex[i].tipo2, "NULL");
                }

                //alteração do valor total
                printf("Insira o novo valor total desse Pokémon: ");
                scanf("%d",&pokedex[i].total);
                printf("\n");

                while(pokedex[i].total <= 0){
                    printf("Valor inválido. Insira um valor adequado: ");
                    scanf("%d",&pokedex[i].total);
                    printf("\n");
                }

                //alteração do HP total do Pokémon
                printf("Insira o novo HP total desse Pokémon: ");
                scanf("%d",&pokedex[i].hp);
                printf("\n");

                while(pokedex[i].hp <= 0){
                    printf("HP inválido. Insira um valor adequado: ");
                    scanf("%d",&pokedex[i].hp);
                    printf("\n");
                }

                //alteração de stats
                printf("Insira seu novo ataque e defesa respectivamente: ");
                printf("\nAtaque: ");
                scanf("%d",&pokedex[i].attack);

                while(pokedex[i].attack <= 0){
                    printf("Ataque inválido. Insira um valor adequado: ");
                    scanf("%d",&pokedex[i].attack);
                }

                printf("Defesa: ");
                scanf("%d",&pokedex[i].defense);
                printf("\n");

                while(pokedex[i].defense <= 0){
                    printf("Defesa inválida. Insira um valor adequado: ");
                    scanf("%d",&pokedex[i].defense);
                    printf("\n");
                }

                printf("Insira seu novo ataque e defesa especial respectivamente: ");
                printf("\nAtaque Esp.: ");
                scanf("%d",&pokedex[i].sp_attack);

                while(pokedex[i].sp_attack <= 0){
                    printf("Ataque Esp. inválido. Insira um valor adequado: ");
                    scanf("%d",&pokedex[i].sp_attack);
                }

                printf("Defesa Esp.: ");
                scanf("%d",&pokedex[i].sp_defense);
                printf("\n");

                while(pokedex[i].sp_defense <= 0){
                    printf("Defesa Esp. inválida. Insira um valor adequado: ");
                    scanf("%d",&pokedex[i].sp_defense);
                    printf("\n");
                }

                printf("Por fim, insira sua nova velocidade: ");
                scanf("%d",&pokedex[i].speed);
                printf("\n");

                while(pokedex[i].speed <= 0){
                    printf("Velocidade inválida. Insira um valor adequado: ");
                    scanf("%d",&pokedex[i].speed);
                    printf("\n");
                }

                //lendário ou não?
                printf("Esse Pokémon é lendário? Para ""Sim"", insira 1, e para ""Não"", insira 0: ");
                scanf("%d",&pokedex[i].lendario);
                printf("\n");

                while(pokedex[i].lendario != 0 && pokedex[i].lendario != 1){
                    printf("Insira um valor igual a 0 ou 1.");
                    scanf("%d",&pokedex[i].lendario);
                    printf("\n");
                }

                //alteração de altura e peso
                printf("Insira a nova altura e peso do Pokémon respectivamente: ");
                printf("\nAltura: ");
                scanf("%f",&pokedex[i].altura);

                while(pokedex[i].altura <= 0.0){
                    printf("Altura inválida. Insira um valor adequado: ");
                    scanf("%f",&pokedex[i].altura);
                }

                printf("Peso: ");
                scanf("%f",&pokedex[i].peso);
                printf("\n");

                while(pokedex[i].peso <= 0.0){
                    printf("Peso inválido. Insira um valor adequado: ");
                    scanf("%f",&pokedex[i].peso);
                    printf("\n");
                }

                printf("Insira a nova taxa de captura desse Pokémon: ");
                scanf("%d", &pokedex[i].catch_rate);
                printf("\n");

                while(pokedex[i].catch_rate <= 0){
                    printf("Valor inválido. Insira um valor adequado: ");
                    scanf("%d",&pokedex[i].catch_rate);
                    printf("\n");
                }
            }
        }

        if(achou == 0){
            printf("Pokémon não encontrado.\n");
            printf("\n");
        }

}


/*Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) os Pokémons disponíveis para serem capturados.
Essa relação deve aumentar e diminuir dinamicamente.*/
int main(){

    int opcao; //switch
    int tamanho = 722; //tamanho original de Pokémon na Pokédex
    char busca[16]; //utilizado para realizar a busca no tópico 3
    int indice; //indice usado nos tópicos 4 e 5 para que as buscas sejam realizadas

    Pokemon* pokedex = (Pokemon*)malloc(tamanho * sizeof(Pokemon));

    if(pokedex == NULL){
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }

    FILE* arq = fopen("pokedex.csv", "r");

    if(arq == NULL){
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    fseek(arq, 174, SEEK_SET);

    for(int i = 1; i < tamanho; i++){

        fscanf(arq,"%d ,%[^ ]%*[ ],%[^ ]%*[ ],%[^ ]%*[ ], %d , %d , %d , %d , %d , %d , %d , %d , %d ,%[^ ]%*[ ], %f , %f , %d ",
        &pokedex[i].numero, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2,
         &pokedex[i].total, &pokedex[i].hp, &pokedex[i].attack, &pokedex[i].defense,
         &pokedex[i].sp_attack, &pokedex[i].sp_defense, &pokedex[i].speed, &pokedex[i].geracao,
         &pokedex[i].lendario, pokedex[i].cor, &pokedex[i].altura, &pokedex[i].peso,
         &pokedex[i].catch_rate);
    }

    do{

    printf("Menu opções:\n");
    printf("1 - Inserir.\n2 - Listar.\n3 - Pesquisar.\n4 - Alterar.\n5 - Excluir.\n6 - Sair.\n");
    printf("\n");
    printf("Insira sua opção: ");
    scanf("%d",&opcao);
    printf("\n");

    if(opcao < 1 || opcao > 6){
        printf("\nOpção inválida. Insira novamente sua opção: ");
        printf("\n");
        scanf("%d",&opcao);
    }

    switch(opcao){

        case 1: //adicionar novo Pokémon

        tamanho++;
        pokedex = realloc(pokedex, tamanho * sizeof(Pokemon));
        
        //inserção do nome
        printf("Insira o nome do Pokémon desejado para inserção: ");
        ler_nomes(pokedex[tamanho - 1].nome);
        printf("\n");

        //inserção do número
        printf("Insira o número desse pokémon ");
        printf("(Obs: Necessita ser maior que %d pois é o número do último da lista): ",tamanho - 2);
        scanf("%d",&pokedex[tamanho - 1].numero);
        printf("\n");

        while(pokedex[tamanho - 1].numero <= tamanho  - 2){
            printf("Valor inválido. Insira um novo valor: ");
            scanf("%d",&pokedex[tamanho - 1].numero);
            printf("\n");
        }

        //inserção da geração
        printf("Insira a geração desse Pokémon: ");
        scanf("%d",&pokedex[tamanho - 1].geracao);

        while(pokedex[tamanho - 1].geracao <= 0){
            printf("Valor inválido. Insira um novo valor: ");
            scanf("%d",&pokedex[tamanho - 1].geracao);
            printf("\n");
        }

        //inserção da cor
        printf("Insira a cor desse Pokémon: ");
        ler_nomes(pokedex[tamanho - 1].cor);
        printf("\n");

        //inserção do tipo primário
        printf("Insira o tipo primário desse Pokémon: ");
        ler_nomes(pokedex[tamanho - 1].tipo1);

        //inserção do tipo secundário
        printf("Insira o tipo secundário desse Pokémon, se não houver, pressione ""Enter"": ");
        ler_nomes(pokedex[tamanho - 1].tipo2);
        printf("\n");

        if(strcmp(pokedex[tamanho - 1].tipo2, "\n") == 0){
            strcpy(pokedex[tamanho - 1].tipo2, "NULL");
        }

        //inserção do valor total
        printf("Insira o valor total desse Pokémon: ");
        scanf("%d",&pokedex[tamanho - 1].total);
        printf("\n");

        while(pokedex[tamanho - 1].total <= 0){
            printf("Valor inválido. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho - 1].total);
            printf("\n");
        }

        //inserção do HP total do Pokémon
        printf("Insira o HP total desse Pokémon: ");
        scanf("%d",&pokedex[tamanho - 1].hp);
        printf("\n");

        while(pokedex[tamanho - 1].hp <= 0){
            printf("HP inválido. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho - 1].hp);
            printf("\n");
        }

        //inserção de stats
        printf("Insira seu ataque e defesa respectivamente: ");
        printf("\nAtaque: ");
        scanf("%d",&pokedex[tamanho - 1].attack);

        while(pokedex[tamanho - 1].attack <= 0){
            printf("Ataque inválido. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho - 1].attack);
        }

        printf("Defesa: ");
        scanf("%d",&pokedex[tamanho - 1].defense);
        printf("\n");

        while(pokedex[tamanho - 1].defense <= 0){
            printf("Defesa inválida. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho - 1].defense);
            printf("\n");
        }

        printf("Insira seu ataque e defesa especial respectivamente: ");
        printf("\nAtaque Esp.: ");
        scanf("%d",&pokedex[tamanho - 1].sp_attack);

        while(pokedex[tamanho - 1].sp_attack <= 0){
            printf("Ataque Esp. inválido. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho - 1].sp_attack);
        }

        printf("Defesa Esp.: ");
        scanf("%d",&pokedex[tamanho - 1].sp_defense);
        printf("\n");

        while(pokedex[tamanho - 1].sp_defense <= 0){
            printf("Defesa Esp. inválida. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho - 1].sp_defense);
            printf("\n");
        }

        printf("Por fim, insira sua velocidade: ");
        scanf("%d",&pokedex[tamanho - 1].speed);
        printf("\n");

        while(pokedex[tamanho - 1].speed <= 0){
            printf("Velocidade inválida. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho - 1].speed);
            printf("\n");
        }

        //lendário ou não?
        printf("Esse Pokémon é lendário? Para ""Sim"", insira 1, e para ""Não"", insira 0: ");
        scanf("%d",&pokedex[tamanho - 1].lendario);
        printf("\n");

        while(pokedex[tamanho - 1].lendario != 0 && pokedex[tamanho - 1].lendario != 1){
            printf("Insira um valor igual a 0 ou 1.");
            scanf("%d",&pokedex[tamanho - 1].lendario);
            printf("\n");
        }

        //inserção altura e peso
        printf("Insira a altura e peso do Pokémon respectivamente: ");
        printf("\nAltura: ");
        scanf("%f",&pokedex[tamanho - 1].altura);

        while(pokedex[tamanho - 1].altura <= 0.0){
            printf("Altura inválida. Insira um valor adequado: ");
            scanf("%f",&pokedex[tamanho - 1].altura);
            printf("\n");
        }

        printf("Peso: ");
        scanf("%f",&pokedex[tamanho - 1].peso);
        printf("\n");

        while(pokedex[tamanho - 1].peso <= 0.0){
            printf("Peso inválido. Insira um valor adequado: ");
            scanf("%f",&pokedex[tamanho - 1].peso);
            printf("\n");
        }

        printf("Insira a taxa de captura desse Pokémon: ");
        scanf("%d", &pokedex[tamanho - 1].catch_rate);
        printf("\n");

        while(pokedex[tamanho - 1].catch_rate <= 0){
            printf("Altura inválida. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho - 1].catch_rate);
            printf("\n");

        }

        break;


        case 2: //listar todos os Pokémon

            listar_todos(pokedex, tamanho);            

        break;


        case 3: //buscar um Pokémon na Pokédex

        buscar_pokemon(pokedex, tamanho, busca);

        break;


        case 4: //alterar dados de um Pokémon específico
        
        alterar_pokemon(pokedex, tamanho, indice);

        break;


        case 5: //exclusão de um Pokémon

        printf("Insira o número do Pokémon que deseja excluir: ");
        scanf("%d",&indice);

        if(indice <= 0 || indice > (tamanho - 1)){
            printf("Valor inválido. Insira um novo valor: ");
            scanf("%d",&indice);
            printf("\n");
        }

        pokedex[indice].nome[0] = '\0';
        pokedex[indice].tipo1[0] = '\0';
        pokedex[indice].tipo2[0] = '\0';
        pokedex[indice].total = 0;
        pokedex[indice].hp = 0;
        pokedex[indice].attack = 0;
        pokedex[indice].defense = 0;
        pokedex[indice].sp_attack = 0;
        pokedex[indice].sp_defense = 0;
        pokedex[indice].speed = 0;
        pokedex[indice].geracao = 0;
        pokedex[indice].lendario = 0;
        pokedex[indice].cor[0] = '\0';
        pokedex[indice].altura = 0.0;
        pokedex[indice].peso = 0.0;
        pokedex[indice].catch_rate = 0;

        printf("Pokémon excluído com sucesso!\n");
        printf("\n");

        break;

    }

    }while(opcao != 6);

    fclose(arq);
    free(pokedex);

    return 0;

}