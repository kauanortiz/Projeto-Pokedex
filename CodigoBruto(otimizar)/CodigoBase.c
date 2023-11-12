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
    
    int integrante;

} Mochila;

typedef struct{

    int pokemon;

} Colecao;

void ler_nomes(char pokemon[], int size){

    setbuf(stdin, NULL);
    fgets(pokemon, size, stdin);
    pokemon[strcspn(pokemon, "\n")] = '\0';

}

void inserir_novo(Pokemon pokedex[], int tamanho){

        //inserção do nome
        printf("Insira o nome do Pokémon desejado para inserção: ");
        ler_nomes(pokedex[tamanho - 1].nome, 15);

        //inserção do número
        printf("Insira o número desse pokémon ");
        printf("(Obs: Necessita ser maior que %d pois é o número do último da lista): ",tamanho - 2);
        scanf("%d",&pokedex[tamanho - 1].numero);

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
        ler_nomes(pokedex[tamanho - 1].cor, 11);
        printf("\n");

        //inserção do tipo primário
        printf("Insira o tipo primário desse Pokémon: ");
        ler_nomes(pokedex[tamanho - 1].tipo1, 11);

        //inserção do tipo secundário
        printf("Insira o tipo secundário desse Pokémon, se não houver, pressione ""Enter"": ");
        ler_nomes(pokedex[tamanho - 1].tipo2, 11);
        printf("\n");

        if(strcmp(pokedex[tamanho - 1].tipo2, "\n") == 0){
            strcpy(pokedex[tamanho - 1].tipo2, "NULL");
        }

        //inserção do valor total
        printf("Insira o valor total desse Pokémon: ");
        scanf("%d",&pokedex[tamanho - 1].total);

        while(pokedex[tamanho - 1].total <= 0){
            printf("Valor inválido. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho - 1].total);
            printf("\n");
        }

        //inserção do HP total do Pokémon
        printf("Insira o HP total desse Pokémon: ");
        scanf("%d",&pokedex[tamanho - 1].hp);

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

        while(pokedex[tamanho - 1].sp_defense <= 0){
            printf("Defesa Esp. inválida. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho - 1].sp_defense);
            printf("\n");
        }

        printf("Por fim, insira sua velocidade: ");
        scanf("%d",&pokedex[tamanho - 1].speed);

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

        while(pokedex[tamanho - 1].peso <= 0.0){
            printf("Peso inválido. Insira um valor adequado: ");
            scanf("%f",&pokedex[tamanho - 1].peso);
            printf("\n");
        }

        printf("Insira a taxa de captura desse Pokémon: ");
        scanf("%d", &pokedex[tamanho - 1].catch_rate);
        printf("\n");

        while(pokedex[tamanho - 1].catch_rate <= 0){
            printf("Taxa de captura inválida. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho - 1].catch_rate);
            printf("\n");

        }
}

void listar_todos(Pokemon pokedex[], int tamanho){

    int opcao;
    int geracao_busca; //para caso opção 1 seja escolhida
    char busca_tipo[16]; //para caso opção 2 seja escolhida
    int achou = 0; //para efetivar o else da opção 2, caso a busca seja mal sucedida

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
        printf("\nAço\nAgua\nDragao\nEletrico\nFada\nFogo\nGelo\nFantasma\nInseto");
        printf("\nLutador\nNormal\nPedra\nPlanta\nPsiquico\nSombrio\nTerra\nVenenoso\nVoador\n");
        printf("\nInsira o tipo de Pokémon que deseja listar: ");
        ler_nomes(busca_tipo, 15);
        printf("\n");

        if(strcmp(busca_tipo, "Inseto") == 0){
            strcpy(busca_tipo, "Bug");
        }

        if(strcmp(busca_tipo, "Dragao") == 0){
            strcpy(busca_tipo, "Dragon");
        }

        if(strcmp(busca_tipo, "Eletrico") == 0){
            strcpy(busca_tipo, "Electric");
        }

        if(strcmp(busca_tipo, "Fogo") == 0){
            strcpy(busca_tipo, "Fire");
        }

        if(strcmp(busca_tipo, "Fantasma") == 0){
            strcpy(busca_tipo, "Ghost");
        }

        if(strcmp(busca_tipo, "Psiquico") == 0){
            strcpy(busca_tipo, "Psychic");
        }
        if(strcmp(busca_tipo, "Agua") == 0){
            strcpy(busca_tipo, "Water");
        }

        for(int i = 0; i < tamanho; i++){

            if(strcmp(pokedex[i].tipo1, busca_tipo) == 0 || strcmp(pokedex[i].tipo2, busca_tipo) == 0 ){

                achou++;

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

        if(achou == 0){
            printf("Tipo não encontrado.\n");
            printf("\n");
        }

        break;
    }

}

void buscar_pokemon(Pokemon pokedex[], int tamanho){

    int achou;
    char busca[16];

    printf("Insira o nome do Pokémon que deseja buscar na Pokédex: ");
    ler_nomes(busca, 15);


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
            printf("Altura (metros): %.2f.\n",pokedex[i].altura);
            printf("Peso (kg): %.2f.\n",pokedex[i].peso);
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

void alterar_pokemon(Pokemon pokedex[], int tamanho){

    int indice;
    int achou;

        printf("Digite o número do Pokémon que deseja alterar: ");
        scanf("%d",&indice);
        printf("\n");

        while(indice <= 0){
            printf("Valor inválido. Insira um valor válido.\n");
            scanf("%d",&indice);
        }

        for(int i = 1; i < tamanho; i++){

            if(indice == pokedex[i].numero){

                achou++;

                //alteração do nome
                printf("Qual o novo nome desse Pokémon? ");
                ler_nomes(pokedex[i].nome, 15);

                //alteração do número
                printf("Insira o novo número desse Pokémon ");
                printf("(Obs: Necessita ser diferente dos demais contidos na Pokédex): ");
                scanf("%d",&pokedex[i].numero);

                while(pokedex[i].numero <= (tamanho - 1)){
                    printf("Valor inválido. Insira um novo valor: ");
                    scanf("%d",&pokedex[i].numero);
                    printf("\n");
                }

                //alteração da geração
                printf("Insira a nova geração desse Pokémon: ");
                scanf("%d",&pokedex[i].geracao);

                while(pokedex[i].geracao <= 0){
                    printf("Valor inválido. Insira um novo valor: ");
                    scanf("%d",&pokedex[i].geracao);
                    printf("\n");
                }

                //alteração da cor
                printf("Insira a nova cor desse Pokémon: ");
                ler_nomes(pokedex[i].cor, 11);
                printf("\n");

                //alteração do tipo primário
                printf("Insira o novo tipo primário desse Pokémon: ");
                ler_nomes(pokedex[i].tipo1, 11);

                //alteração do tipo secundário
                printf("Insira o novo tipo secundário desse Pokémon, se não houver, pressione ""Enter"": ");
                ler_nomes(pokedex[i].tipo2, 11);
                printf("\n");

                if(strcmp(pokedex[i].tipo2, "\n") == 0){
                    strcpy(pokedex[i].tipo2, "NULL");
                }

                //alteração do valor total
                printf("Insira o novo valor total desse Pokémon: ");
                scanf("%d",&pokedex[i].total);

                while(pokedex[i].total <= 0){
                    printf("Valor inválido. Insira um valor adequado: ");
                    scanf("%d",&pokedex[i].total);
                    printf("\n");
                }

                //alteração do HP total do Pokémon
                printf("Insira o novo HP total desse Pokémon: ");
                scanf("%d",&pokedex[i].hp);

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

                while(pokedex[i].sp_defense <= 0){
                    printf("Defesa Esp. inválida. Insira um valor adequado: ");
                    scanf("%d",&pokedex[i].sp_defense);
                    printf("\n");
                }

                printf("Por fim, insira sua nova velocidade: ");
                scanf("%d",&pokedex[i].speed);

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

void excluir_pokemon(Pokemon pokedex[], int tamanho){

    int indice;
    int achou = 0;

    printf("Insira o número do Pokémon que deseja excluir: ");
    scanf("%d",&indice);

    for(int i = 0; i < tamanho; i++){
        if(indice == pokedex[i].numero){

            achou++;

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
        }
    }
    
    if(achou != 0){
        printf("Pokémon excluído com sucesso!\n");
        printf("\n");
    }else{
        printf("Pokémon não encontrado.\n");
    }

}

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

void inserir_colecao(Colecao minha_colecao[], int tamanho){

    int posicao;

    printf("Insira a posição que deseja preencher na coleção: ");
    scanf("%d",&posicao);

    while(posicao < 1 || posicao > 250){
        printf("Posição inválida. Insira um número entre 1 e 250: ");
        scanf("%d",&posicao);
        printf("\n");
    }

    while(minha_colecao[posicao].pokemon != 0){
        printf("Posição já preenchida. Insira uma nova posição: ");
        scanf("%d",&posicao);
        printf("\n");
    }

    printf("Insira o número do Pokémon que deseja adicionar a essa posição: ");
    scanf("%d",&minha_colecao[posicao].pokemon);
                
    for(int i = 1; i < 251; i++){
        if(i != posicao && minha_colecao[i].pokemon == minha_colecao[posicao].pokemon){
            printf("Pokémon já adicionado à coleção. Insira outro: ");
            scanf("%d",&minha_colecao[posicao].pokemon);
            i = 0; // Reinicia o loop para verificar desde o início
        }
    }               

    while(minha_colecao[posicao].pokemon <= 0 || minha_colecao[posicao].pokemon > tamanho - 1){
        printf("Pokémon inválido. Insira um número entre 1 e %d.\n",tamanho - 1);
        scanf("%d",&posicao);
        printf("\n");
    }

    printf("Pokémon adicionado com sucesso.\n");
    printf("\n");

}

void listar_colecao(Colecao minha_colecao[], Pokemon pokedex[]){

    int posicao;

    printf("Seus Pokémon listados são:\n");

    for(posicao = 1; posicao < 251; posicao++){

        if(minha_colecao[posicao].pokemon != 0){
            printf("Posição [%d]: %d, %s.\n",
            posicao, minha_colecao[posicao].pokemon, pokedex[minha_colecao[posicao].pokemon].nome);
        }
    }
    printf("\n");
}

void pesquisar_colecao(Colecao minha_colecao[], Pokemon pokedex[]){

    char busca_colecao[16];
    int posicao;
    int achou = 0; //para que as buscas sejam realizadas

    printf("Insira o nome do Pokémon que deseja procurar na lista: ");
    ler_nomes(busca_colecao, 15);

    for(posicao = 1; posicao < 251; posicao++){

        if(strcmp(busca_colecao,pokedex[minha_colecao[posicao].pokemon].nome) == 0){

            printf("Número: %d.\n",pokedex[minha_colecao[posicao].pokemon].numero);
            printf("Nome: %s.\n",pokedex[minha_colecao[posicao].pokemon].nome);
            printf("Tipo 1: %s.\n",pokedex[minha_colecao[posicao].pokemon].tipo1);
            printf("Tipo 2: %s.\n",pokedex[minha_colecao[posicao].pokemon].tipo2);
            printf("Total: %d.\n",pokedex[minha_colecao[posicao].pokemon].total);
            printf("Hp: %d.\n",pokedex[minha_colecao[posicao].pokemon].hp);
            printf("Ataque: %d.\n",pokedex[minha_colecao[posicao].pokemon].attack);
            printf("Defesa: %d.\n",pokedex[minha_colecao[posicao].pokemon].defense);
            printf("Ataque especial: %d.\n",pokedex[minha_colecao[posicao].pokemon].sp_attack);
            printf("Defesa especial: %d.\n",pokedex[minha_colecao[posicao].pokemon].sp_defense);
            printf("Velocidade: %d.\n",pokedex[minha_colecao[posicao].pokemon].speed);
            printf("Geração: %d°.\n",pokedex[minha_colecao[posicao].pokemon].geracao);
            printf("Lendário (0 = não e 1 = sim): %d.\n",pokedex[minha_colecao[posicao].pokemon].lendario);
            printf("Cor: %s.\n",pokedex[minha_colecao[posicao].pokemon].cor);
            printf("Altura (metros): %.2f.\n",pokedex[minha_colecao[posicao].pokemon].altura);
            printf("Peso (kg): %.2f.\n",pokedex[minha_colecao[posicao].pokemon].peso);
            printf("Taxa de captura: %d.\n",pokedex[minha_colecao[posicao].pokemon].catch_rate);
            printf("\n");

            achou++;
        }
    }

    if(achou == 0){
        printf("Pokémon indisponível na coleção.\n");
        printf("\n");
    }

}

void alterar_colecao(Colecao minha_colecao[]){

    int posicao;

    printf("Insira a posição da coleção que deseja alterar: ");
    scanf("%d",&posicao);

    if(minha_colecao[posicao].pokemon == 0){
        printf("Posição vazia.\n");
        printf("\n");

    }else{
        printf("Insira o número do novo Pokémon: ");
        scanf("%d",&minha_colecao[posicao].pokemon);
        printf("Pokémon alterado com sucesso.\n");
        printf("\n");
    }

}

void excluir_colecao(Colecao minha_colecao[]){
    
    int posicao;

    printf("Insira a posição da coleção que deseja excluir: ");
    scanf("%d",&posicao);

    if(minha_colecao[posicao].pokemon == 0){
        printf("Posição vazia.\n");
        printf("\n");

    }else{
        minha_colecao[posicao].pokemon = 0;
        printf("Pokémon excluído com sucesso.\n");
        printf("\n");
    }

}

/*Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) os Pokémons disponíveis para serem capturados.
Essa relação deve aumentar e diminuir dinamicamente.*/
int main(){

    int main_menu, menu_jogo, menu_poke, menu_mochila, menu_colecao; //opções criadas para manuseamento dos switches
    int tamanho = 722; //tamanho original de Pokémon na Pokédex + linha do cabeçalho
    char nickname[31]; //armazena o nickname do jogador
    char c; //variável que auxilia na contagem de linhas do novo arquivo

    Pokemon* pokedex = (Pokemon*)malloc(tamanho * sizeof(Pokemon));

        if(pokedex == NULL){
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }

    Mochila meu_time[7]; //armazena até 6 Pokémon no time
    Colecao minha_colecao[251]; //armazena até 250 Pokémon na coleção

    //inicia os integrantes do time como 0
    for(int i = 0; i < 7; i++){
        meu_time[i].integrante = 0;
    }

    //inicia os elementos da coleção como 0
    for(int i = 1; i < 251; i++){
        minha_colecao[i].pokemon = 0;
    }

    //cria dois arquivos, um para ler a Pokédex, e um para armazenar o progresso do jogador
    FILE* arq;
    FILE* arq_do_jogador;

    //exibe o menu principal
    printf("\nSeja bem-vindo treinador Pokémon, você deseja iniciar uma nova jornada ou continuar de onde parou? ");
    printf("\n1 - Novo jogo.\n2 - Carregar jogo.\n3 - Sair do jogo\n");
    printf("Insira sua opção: ");
    scanf("%d",&main_menu);

    //while para que a opção seja inserida corretamente
    while(main_menu < 1 || main_menu > 3){
        printf("Opção inválida. Insira novamente sua opção: ");
        scanf("%d",&main_menu);
    }

    //se opção 1 for escolhida, abre o arquivo .csv e cria um novo arquivo
    if(main_menu == 1){

        arq = fopen("pokedex.csv", "r");

        if(arq == NULL){
            printf("Erro na abertura do arquivo.\n");
            exit(1);
        }

    //pula a primeira linha do arquivo e começa a leitura dos dados
    fseek(arq, 174, SEEK_SET);

    for(int i = 1; i < tamanho; i++){

        fscanf(arq,"%d ,%[^ ]%*[ ],%[^ ]%*[ ],%[^ ]%*[ ], %d , %d , %d , %d , %d , %d , %d , %d , %d ,%[^ ]%*[ ], %f , %f , %d ",
        &pokedex[i].numero, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2,
         &pokedex[i].total, &pokedex[i].hp, &pokedex[i].attack, &pokedex[i].defense,
         &pokedex[i].sp_attack, &pokedex[i].sp_defense, &pokedex[i].speed, &pokedex[i].geracao,
         &pokedex[i].lendario, pokedex[i].cor, &pokedex[i].altura, &pokedex[i].peso,
         &pokedex[i].catch_rate);
    }

        printf("Insira seu nickname: ");
        ler_nomes(nickname, 30);
        strcat(nickname, ".data");
        arq_do_jogador = fopen(nickname, "w+b");
        printf("\n");


    //se opção dois for escolhida, abre o arquivo de progresso do jogador, e realiza as operações baseadas nesse arquivo
    }else if(main_menu == 2){

        printf("Insira seu nickname: ");
        ler_nomes(nickname, 30);
        strcat(nickname, ".data");
        arq_do_jogador = fopen(nickname, "r+b");

        if(arq_do_jogador == NULL){
            printf("Erro na abertura do arquivo.\n");
            exit(1);
        }
        printf("\n");
        
        //trecho do projeto que calcula as linhas do novo arquivo
        tamanho = 1;

        while((c = fgetc(arq_do_jogador)) != ';'){
    
        //se o ponteiro for igual a \n, uma linha é contabilizada
            if(c == '\n'){
                tamanho++;
            }       
        }
        //

        //realoca a memória com base nas linhas recalculadas
        pokedex = realloc(pokedex, tamanho * sizeof(Pokemon));

        //move o ponteiro de leitura de modo que a primeira linha não seja lida
        fseek(arq_do_jogador, 184, SEEK_SET);

        for(int i = 1; i < tamanho; i++){

            fscanf(arq_do_jogador,"%d,%*[ ]%[^,],%*[ ]%[^,],%*[ ]%[^,], %d, %d, %d, %d, %d, %d, %d, %d, %d,%*[ ]%[^,], %f , %f , %d",
            &pokedex[i].numero, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2,
            &pokedex[i].total, &pokedex[i].hp, &pokedex[i].attack, &pokedex[i].defense,
            &pokedex[i].sp_attack, &pokedex[i].sp_defense, &pokedex[i].speed, &pokedex[i].geracao,
            &pokedex[i].lendario, pokedex[i].cor, &pokedex[i].altura, &pokedex[i].peso,
            &pokedex[i].catch_rate);
        }

        //move o ponteiro de leitura de modo que o ";" que separa as informações não seja lido
        fseek(arq_do_jogador, 2, SEEK_CUR);

        fscanf(arq_do_jogador,"%d,%d,%d,%d,%d,%d",
        &meu_time[1].integrante, &meu_time[2].integrante, &meu_time[3].integrante,
        &meu_time[4].integrante, &meu_time[5].integrante, &meu_time[6].integrante);

        //move o ponteiro de leitura de modo que o ";" que separa as informações não seja lido
        fseek(arq_do_jogador, 2, SEEK_CUR);

        for(int i = 1; i < 251; i++){
            fscanf(arq_do_jogador,"%d",&minha_colecao[i].pokemon);
        }

    //se opção 3 for escolhida, fecha o programa
    }else{

        exit(1);

    }

    //exibe o menu de opções do jogo
    Menu:
    printf("Menu principal:\n");
    printf("1 - Mochila.\n2 - Coleção(PC).\n3 - Pokédex.\n4 - Sair.\n");
    printf("\n");
    printf("Insira sua opção: "); //armazena a opção do jogador
    scanf("%d",&menu_jogo);
    printf("\n");

    //controle para o usuário não inserir uma opção indisponível
    while(menu_jogo < 0 || menu_jogo > 4){
        printf("Opção inválida. Insira novamente sua opção: ");
        scanf("%d",&menu_jogo);
        printf("\n");
    }

    //se menu_jogo == 1, abre a mochila e permite ao usuário realizar operações de inserção e conferimento
    if(menu_jogo == 1){
        
        do{
            //exibe o menu de opções da mochila e verifica a opção inserida
            printf("Mochila:\n");
            printf("1 - Inserir Pokémon no time.\n2 - Visualizar time.\n3 - Alterar equipe.\n4 - Voltar.\n");
            printf("\n");
            printf("Insira sua opção: ");
            scanf("%d",&menu_mochila);
            printf("\n");

            while(menu_mochila < 0 || menu_mochila > 4){
                printf("Opção inválida. Insira novamente sua opção: ");
                scanf("%d",&menu_mochila);
                printf("\n");
            }

        switch(menu_mochila){

            //se opção da mochila for 1, insere o time
            case 1:

                inserir_no_time(meu_time, tamanho);

                break;

            //se opção da mochila for 2, exibe o time escolhido
            case 2:

                exibir_time(meu_time, pokedex);

                break;

            //permite alterar os membros do time
            case 3:

                alterar_time(meu_time, pokedex, tamanho);

            break;

            //fecha o programa
            case 4:

                goto Menu;

                break;
                
            }

        }while(menu_mochila != 4);


    //se menu_jogo == 2, permite o usuário realizar operações na coleção
    }else if(menu_jogo == 2){

        do{
            //exibe o menu de opções da coleção e verifica a opção inserida
            printf("Coleção:\n");
            printf("1 - Inserir Pokémon.\n2 - Listar coleção.\n3 - Pesquisar.\n4 - Alterar.\n5 - Excluir.\n6 - Voltar.\n");
            printf("\n");
            printf("Insira sua opção: ");
            scanf("%d",&menu_colecao);
            printf("\n");

            while(menu_colecao < 0 || menu_colecao > 6){
                printf("Opção inválida. Insira novamente sua opção: ");
                scanf("%d",&menu_colecao);
                printf("\n");
            }

            switch(menu_colecao){
                
                case 1: //inserir na coleção

                inserir_colecao(minha_colecao, tamanho);

                break;


                case 2: //listar

                listar_colecao(minha_colecao, pokedex);

                break;


                case 3: //pesquisar

                pesquisar_colecao(minha_colecao, pokedex);           

                break;


                case 4: //alterar

                alterar_colecao(minha_colecao);

                break;


                case 5: //excluir

                excluir_colecao(minha_colecao);
                
                break;


                case 6: //volta para o menu

                goto Menu;

                break;

            }

        }while(menu_colecao != 6);

    //se menu_jogo == 3, permite ao usuário realizar operações na Pokédex
    }else if(menu_jogo == 3){

        do{
        //exibe o menu de opções da Pokédex e verifica a opção inserida
        printf("Pokédex:\n");
        printf("1 - Inserir.\n2 - Listar.\n3 - Pesquisar.\n4 - Alterar.\n5 - Excluir.\n6 - Voltar. \n");
        printf("\n");
        printf("Insira sua opção: ");
        scanf("%d",&menu_poke);
        printf("\n");

        while(menu_poke < 1 || menu_poke > 6){
            printf("\nOpção inválida. Insira novamente sua opção: ");
            printf("\n");
            scanf("%d",&menu_poke);
        }

        //permite realizar operações de inserção, listar, pesquisar, alterar e excluir. além é claro de sair
        switch(menu_poke){

            case 1: //adicionar novo Pokémon
            tamanho++;
            pokedex = realloc(pokedex, tamanho * sizeof(Pokemon));

            inserir_novo(pokedex, tamanho);

            break;


            case 2: //listar todos os Pokémon

            listar_todos(pokedex, tamanho);            

            break;


            case 3: //buscar um Pokémon na Pokédex

            buscar_pokemon(pokedex, tamanho);

            break;


            case 4: //alterar dados de um Pokémon específico
            
            alterar_pokemon(pokedex, tamanho);

            break;


            case 5: //exclusão de um Pokémon

            excluir_pokemon(pokedex, tamanho);

            break;

            case 6: //volta para o menu

            goto Menu;

            break;

        }

        }while(menu_poke != 6);

    }else{

        //se opção do inicio for 1, salva os dados modificados no arquivo nomeado no inicio pelo jogador
        if(main_menu == 1){
            
            fprintf(arq_do_jogador, "numero ,nome           ,tipo1      ,tipo2      ,total ,hp  ,ataque ,defesa ,ataque_especial ,defesa_especial ,velocidade ,geracao ,lendario ,cor        ,altura_m ,peso_kg ,taxa_captura");
            for(int i = 1; i < tamanho; i++){
                fprintf(arq_do_jogador, "\n%7d,%15s,%11s,%11s,%6d,%4d,%7d,%7d,%16d,%16d,%11d,%8d,%9d,%11s, %7.2f , %6.2f ,%12d",
                pokedex[i].numero, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2,
                pokedex[i].total, pokedex[i].hp, pokedex[i].attack, pokedex[i].defense,
                pokedex[i].sp_attack, pokedex[i].sp_defense, pokedex[i].speed, pokedex[i].geracao,
                pokedex[i].lendario, pokedex[i].cor, pokedex[i].altura, pokedex[i].peso,
                pokedex[i].catch_rate);
            }

            fprintf(arq_do_jogador, "\n;");
            fprintf(arq_do_jogador, "\n%d,%d,%d,%d,%d,%d",
            meu_time[1].integrante, meu_time[2].integrante, meu_time[3].integrante,
            meu_time[4].integrante, meu_time[5].integrante, meu_time[6].integrante);

            fprintf(arq_do_jogador, "\n;");
            for(int i = 1; i < 251; i++){
                fprintf(arq_do_jogador, "\n%d",minha_colecao[i].pokemon);
            }

        //se opção do inicio for 2, sobrescreve os dados do arquivo salvo anteriormente
        }else if(main_menu == 2){
            
            fclose(arq_do_jogador);
            arq_do_jogador = fopen(nickname, "w+b");

            fprintf(arq_do_jogador, "numero ,nome           ,tipo1      ,tipo2      ,total ,hp  ,ataque ,defesa ,ataque_especial ,defesa_especial ,velocidade ,geracao ,lendario ,cor        ,altura_m ,peso_kg ,taxa_captura");
            for(int i = 1; i < tamanho; i++){
                fprintf(arq_do_jogador, "\n%7d,%15s,%11s,%11s,%6d,%4d,%7d,%7d,%16d,%16d,%11d,%8d,%9d,%11s, %7.2f , %6.2f ,%12d",
                pokedex[i].numero, pokedex[i].nome, pokedex[i].tipo1, pokedex[i].tipo2,
                pokedex[i].total, pokedex[i].hp, pokedex[i].attack, pokedex[i].defense,
                pokedex[i].sp_attack, pokedex[i].sp_defense, pokedex[i].speed, pokedex[i].geracao,
                pokedex[i].lendario, pokedex[i].cor, pokedex[i].altura, pokedex[i].peso,
                pokedex[i].catch_rate);
            }
        }
    }

    //fecha os arquivos e libera a memória alocada
    fclose(arq);
    fclose(arq_do_jogador);
    free(pokedex);

    return 0;

}