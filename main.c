#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

/*Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) os Pokémons disponíveis para serem capturados.
Essa relação deve aumentar e diminuir dinamicamente.*/
int main(){

    int main_menu, menu_jogo, menu_poke, menu_mochila, menu_colecao; //opções criadas para manuseamento dos switches
    int tamanho = 722, tamanho_colecao = 6; //tamanho original de Pokémon na Pokédex + linha do cabeçalho e tamanho da coleção
    char nickname[31]; //armazena o nickname do jogador

    //cria dois arquivos, um para ler a Pokédex, e um para armazenar o progresso do jogador
    FILE* arq;
    FILE* arq_do_jogador;

    Pokemon* pokedex = (Pokemon*)malloc(tamanho * sizeof(Pokemon)); //aloca a memória que será utilizada na Pokédex de maneira dinâmica
    Colecao* minha_colecao = (Colecao*)malloc(tamanho_colecao * sizeof(Colecao)); //aloca a memória que será utilizada na Coleção de maneira dinâmica
    Mochila meu_time[7]; //armazena até 6 Pokémon no time

    //verifica se as alocações dinâmicas foram realizadas corretamente
    if(pokedex == NULL || minha_colecao == NULL){
        printf("Memória insuficiente!\n");
        exit(1);
    }

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
    
    //colocar dentro de main_menu == 1
    //inicia os integrantes do time como 0
    for(int i = 0; i < 7; i++){
        meu_time[i].integrante = 0;
    }
    
    for(int i = 1; i < tamanho_colecao; i++){
        minha_colecao[i].numero_pokemon = 0;
    }

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

    //fecha o arquivo que abre a pokedex.csv
    fclose(arq);

        printf("Insira seu nickname: ");
        ler_nomes(nickname, 30);
        strcat(nickname, ".dat");
        arq_do_jogador = fopen(nickname, "wb");
        printf("\n");


    //se opção dois for escolhida, abre o arquivo de progresso do jogador, e realiza as operações baseadas nesse arquivo
    }else if(main_menu == 2){

        printf("Insira seu nickname: ");
        ler_nomes(nickname, 30);
        strcat(nickname, ".dat");
        arq_do_jogador = fopen(nickname, "rb");

        if(arq_do_jogador == NULL){
            printf("Erro na abertura do arquivo.\n");
            exit(1);
        }
        printf("\n");

        fread(&tamanho, sizeof(int), 1, arq_do_jogador);
        fread(&tamanho_colecao, sizeof(int), 1, arq_do_jogador);

        //realoca a memória com base nas linhas recalculadas
        pokedex = realloc(pokedex, tamanho * sizeof(Pokemon));
        minha_colecao = realloc(minha_colecao, tamanho_colecao * sizeof(Colecao));

        if(pokedex == NULL || minha_colecao == NULL){

            printf("Erro na realocação de memória.\n");
            exit(1);
        }
        
        fread(pokedex, sizeof(Pokemon), tamanho, arq_do_jogador);
        fread(meu_time, sizeof(Mochila), 7, arq_do_jogador);
        fread(minha_colecao, sizeof(Colecao), tamanho_colecao, arq_do_jogador);


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
                
                if(minha_colecao[tamanho_colecao - 1].numero_pokemon != 0){
                    minha_colecao = realloc(minha_colecao, (tamanho_colecao + 5) * sizeof(Colecao));

                //inicializa os novos espaços com 0
                for(int i = tamanho_colecao; i < tamanho_colecao + 5; i++){
                    minha_colecao[i].numero_pokemon = 0;
                }

                // Atualiza o tamanho da coleção
                tamanho_colecao += 5;

                }
               
                inserir_colecao(minha_colecao, pokedex, tamanho, tamanho_colecao);

                break;


                case 2: //listar

                listar_colecao(minha_colecao, pokedex, tamanho_colecao);

                break;


                case 3: //pesquisar

                pesquisar_colecao(minha_colecao, pokedex, tamanho_colecao);           

                break;


                case 4: //alterar

                alterar_colecao(minha_colecao, tamanho, tamanho_colecao);

                break;


                case 5: //excluir

                excluir_colecao(minha_colecao, tamanho_colecao);
                
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

        //se o arquivo do jogador for diferente de NULL, salva o progresso, exibe uma opção de exportar csv, fecha os arquivos e libera a memória alocada
        if(arq_do_jogador != NULL){

            salvar_progresso(arq_do_jogador, pokedex, minha_colecao, meu_time, tamanho, tamanho_colecao, nickname);
            fclose(arq_do_jogador);
            
            exportar_csv(pokedex, minha_colecao, meu_time, tamanho, tamanho_colecao);

        }
    }
    
    return 0;

}