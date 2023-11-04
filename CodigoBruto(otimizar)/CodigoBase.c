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
    
    Pokemon pokemon_no_time[5];

} Mochila;

/*Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) os Pokémons disponíveis para serem capturados.
Essa relação deve aumentar e diminuir dinamicamente.*/
int main(){

    int opcao; //switch
    int tamanho = 722; //tamanho original de Pokémon na Pokédex
    int indice; //indice usado nos tópicos 3, 4 e 5 para que as buscas sejam realizadas

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
        setbuf(stdin, NULL);
        fgets(pokedex[tamanho - 1].nome, 14, stdin);
        pokedex[tamanho - 1].nome[strcspn(pokedex[tamanho - 1].nome, "\n")] = '\0';

        //inserção do número
        printf("Insira o número desse pokémon ");
        printf("(Obs: Necessita ser maior que %d pois é o número do último da lista): ",tamanho - 2);
        scanf("%d",&pokedex[tamanho - 1].numero);
        printf("\n");

        if(pokedex[tamanho - 1].numero <= tamanho  - 2){
            printf("Valor inválido. Insira um novo valor: ");
            scanf("%d",&pokedex[tamanho - 1].numero);
            printf("\n");
        }

        //inserção da geração
        printf("Insira a geração desse Pokémon: ");
        scanf("%d",&pokedex[tamanho - 1].geracao);

        if(pokedex[tamanho - 1].geracao <= 0){
            printf("Valor inválido. Insira um novo valor: ");
            scanf("%d",&pokedex[tamanho - 1].geracao);
        }

        //inserção da cor
        printf("Insira a cor desse Pokémon: ");
        setbuf(stdin, NULL);
        fgets(pokedex[tamanho - 1].cor, 10, stdin);
        pokedex[tamanho - 1].cor[strcspn(pokedex[tamanho - 1].cor, "\n")] = '\0';
        printf("\n");

        //inserção do tipo primário
        printf("Insira o tipo primário desse Pokémon: ");
        setbuf(stdin, NULL);
        fgets(pokedex[tamanho - 1].tipo1, 10, stdin);
        pokedex[tamanho - 1].tipo1[strcspn(pokedex[tamanho - 1].tipo1, "\n")] = '\0';

        //inserção do tipo secundário
        printf("Insira o tipo secundário desse Pokémon, se não houver, pressione ""Enter"": ");
        setbuf(stdin, NULL);
        fgets(pokedex[tamanho - 1].tipo2, 10, stdin);
        pokedex[tamanho - 1].tipo2[strcspn(pokedex[tamanho - 1].tipo2, "\n")] = '\0';
        printf("\n");

        if(strcmp(pokedex[tamanho - 1].tipo2, "\n") == 0){
            strcpy(pokedex[tamanho - 1].tipo2, "NULL");
        }

        //inserção do valor total
        printf("Insira o valor total desse Pokémon: ");
        scanf("%d",&pokedex[tamanho - 1].total);
        printf("\n");

        if(pokedex[tamanho - 1].total <= 0){
            printf("Valor inválido. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho - 1].total);
            printf("\n");
        }

        //inserção do HP total do Pokémon
        printf("Insira o HP total desse Pokémon: ");
        scanf("%d",&pokedex[tamanho - 1].hp);
        printf("\n");

        if(pokedex[tamanho - 1].hp <= 0){
            printf("HP inválido. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho - 1].hp);
            printf("\n");
        }

        //inserção de stats
        printf("Insira seu ataque e defesa respectivamente: ");
        printf("\nAtaque: ");
        scanf("%d",&pokedex[tamanho - 1].attack);

        if(pokedex[tamanho - 1].attack <= 0){
            printf("Ataque inválido. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho - 1].attack);
        }

        printf("Defesa: ");
        scanf("%d",&pokedex[tamanho - 1].defense);
        printf("\n");

        if(pokedex[tamanho - 1].defense <= 0){
            printf("Defesa inválida. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho - 1].defense);
            printf("\n");
        }

        printf("Insira seu ataque e defesa especial respectivamente: ");
        printf("\nAtaque Esp.: ");
        scanf("%d",&pokedex[tamanho - 1].sp_attack);

        if(pokedex[tamanho - 1].sp_attack <= 0){
            printf("Ataque Esp. inválido. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho - 1].sp_attack);
        }

        printf("Defesa Esp.: ");
        scanf("%d",&pokedex[tamanho - 1].sp_defense);
        printf("\n");

        if(pokedex[tamanho - 1].sp_defense <= 0){
            printf("Defesa Esp. inválida. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho - 1].sp_defense);
            printf("\n");
        }

        printf("Por fim, insira sua velocidade: ");
        scanf("%d",&pokedex[tamanho - 1].speed);
        printf("\n");

        if(pokedex[tamanho - 1].speed <= 0){
            printf("Velocidade inválida. Insira um valor adequado: ");
            scanf("%d",&pokedex[tamanho - 1].speed);
            printf("\n");
        }

        //lendário ou não?
        printf("Esse Pokémon é lendário? Para ""Sim"", insira 1, e para ""Não"", insira 0: ");
        scanf("%d",&pokedex[tamanho - 1].lendario);
        printf("\n");

        if(pokedex[tamanho - 1].lendario != 0 && pokedex[tamanho - 1].lendario != 1){
            printf("Insira um valor igual a 0 ou 1.");
            scanf("%d",&pokedex[tamanho - 1].lendario);
            printf("\n");
        }

        //inserção altura e peso
        printf("Insira a altura e peso do Pokémon respectivamente: ");
        printf("\nAltura: ");
        scanf("%f",&pokedex[tamanho - 1].altura);

        if(pokedex[tamanho - 1].altura <= 0.0){
            printf("Altura inválida. Insira um valor adequado: ");
            scanf("%f",&pokedex[tamanho - 1].altura);
        }

        printf("Peso: ");
        scanf("%f",&pokedex[tamanho - 1].peso);
        printf("\n");

        if(pokedex[tamanho - 1].peso <= 0.0){
        printf("Peso inválido. Insira um valor adequado: ");
        scanf("%f",&pokedex[tamanho - 1].peso);
        printf("\n");
        }

        break;

        case 2: //listar todos os Pokémon

        for(int i = 1; i < tamanho; i++){

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

        case 3: //buscar um Pokémon na Pokédex

        printf("Insira o número do Pokémon que deseja buscar na Pokédex: ");
        scanf("%d",&indice);
        printf("\n");

        if(indice <= 0 || indice > (tamanho - 1)){
            printf("Valor inválido. Insira um novo valor: ");
            scanf("%d",&indice);
            printf("\n");
        }

        if(pokedex[indice].hp == 0){
            printf("Pokémon excluído.\n");
            printf("\n");
            break;
        }

        if(indice <= 0 || indice > tamanho){
            printf("Número inválido.\nInsira um número entre 1 e %d.\n",tamanho);
            scanf("%d",&indice);

        }else{
            printf("Número: %d.\n",pokedex[indice].numero);
            printf("Nome: %s.\n",pokedex[indice].nome);
            printf("Tipo 1: %s.\n",pokedex[indice].tipo1);
            printf("Tipo 2: %s.\n",pokedex[indice].tipo2);
            printf("Total: %d.\n",pokedex[indice].total);
            printf("Hp: %d.\n",pokedex[indice].hp);
            printf("Ataque: %d.\n",pokedex[indice].attack);
            printf("Defesa: %d.\n",pokedex[indice].defense);
            printf("Ataque especial: %d.\n",pokedex[indice].sp_attack);
            printf("Defesa especial: %d.\n",pokedex[indice].sp_defense);
            printf("Velocidade: %d.\n",pokedex[indice].speed);
            printf("Geração: %d°.\n",pokedex[indice].geracao);
            printf("Lendário (0 = não e 1 = sim): %d.\n",pokedex[indice].lendario);
            printf("Cor: %s.\n",pokedex[indice].cor);
            printf("Altura (metros): %f.\n",pokedex[indice].altura);
            printf("Peso (kg): %f.\n",pokedex[indice].peso);
            printf("Taxa de captura: %d.\n",pokedex[indice].catch_rate);
            printf("\n");

        }

        break;

        case 4: //alterar dados de um Pokémon específico
        
        printf("Digite o número do Pokémon que deseja alterar: ");
        scanf("%d",&indice);
        printf("\n");

        if(indice <= 0 || indice > (tamanho - 1)){
            printf("Valor inválido. Insira um novo valor: ");
            scanf("%d",&indice);
            printf("\n");
        }

        //alteração do nome
        printf("Qual o novo nome desse Pokémon? ");
        setbuf(stdin, NULL);
        fgets(pokedex[indice].nome, 14, stdin);
        pokedex[indice].nome[strcspn(pokedex[indice].nome, "\n")] = '\0';

        //alteração do número
        printf("Insira o novo número desse Pokémon ");
        printf("(Obs: Necessita ser diferente dos demais contidos na Pokédex): ");
        scanf("%d",&pokedex[indice].numero);
        printf("\n");

        if(pokedex[indice].numero <= (tamanho - 1)){
            printf("Valor inválido. Insira um novo valor: ");
            scanf("%d",&pokedex[indice].numero);
            printf("\n");
        }

        //alteração da geração
        printf("Insira a nova geração desse Pokémon: ");
        scanf("%d",&pokedex[indice].geracao);

        if(pokedex[indice].geracao <= 0){
            printf("Valor inválido. Insira um novo valor: ");
            scanf("%d",&pokedex[indice].geracao);
        }

        //alteração da cor
        printf("Insira a nova cor desse Pokémon: ");
        setbuf(stdin, NULL);
        fgets(pokedex[indice].cor, 10, stdin);
        pokedex[indice].cor[strcspn(pokedex[indice].cor, "\n")] = '\0';
        printf("\n");

        //alteração do tipo primário
        printf("Insira o novo tipo primário desse Pokémon: ");
        setbuf(stdin, NULL);
        fgets(pokedex[indice].tipo1, 10, stdin);
        pokedex[indice].tipo1[strcspn(pokedex[indice].tipo1, "\n")] = '\0';

        //alteração do tipo secundário
        printf("Insira o novo tipo secundário desse Pokémon, se não houver, pressione ""Enter"": ");
        setbuf(stdin, NULL);
        fgets(pokedex[indice].tipo2, 10, stdin);
        pokedex[indice].tipo2[strcspn(pokedex[indice].tipo2, "\n")] = '\0';
        printf("\n");

        if(strcmp(pokedex[indice].tipo2, "\n") == 0){
            strcpy(pokedex[indice].tipo2, "NULL");
        }

        //alteração do valor total
        printf("Insira o novo valor total desse Pokémon: ");
        scanf("%d",&pokedex[indice].total);
        printf("\n");

        if(pokedex[indice].total <= 0){
            printf("Valor inválido. Insira um valor adequado: ");
            scanf("%d",&pokedex[indice].total);
            printf("\n");
        }

        //alteração do HP total do Pokémon
        printf("Insira o novo HP total desse Pokémon: ");
        scanf("%d",&pokedex[indice].hp);
        printf("\n");

        if(pokedex[indice].hp <= 0){
            printf("HP inválido. Insira um valor adequado: ");
            scanf("%d",&pokedex[indice].hp);
            printf("\n");
        }

        //alteração de stats
        printf("Insira seu novo ataque e defesa respectivamente: ");
        printf("\nAtaque: ");
        scanf("%d",&pokedex[indice].attack);

        if(pokedex[indice].attack <= 0){
            printf("Ataque inválido. Insira um valor adequado: ");
            scanf("%d",&pokedex[indice].attack);
        }

        printf("Defesa: ");
        scanf("%d",&pokedex[indice].defense);
        printf("\n");

        if(pokedex[indice].defense <= 0){
            printf("Defesa inválida. Insira um valor adequado: ");
            scanf("%d",&pokedex[indice].defense);
            printf("\n");
        }

        printf("Insira seu novo ataque e defesa especial respectivamente: ");
        printf("\nAtaque Esp.: ");
        scanf("%d",&pokedex[indice].sp_attack);

        if(pokedex[indice].sp_attack <= 0){
            printf("Ataque Esp. inválido. Insira um valor adequado: ");
            scanf("%d",&pokedex[indice].sp_attack);
        }

        printf("Defesa Esp.: ");
        scanf("%d",&pokedex[indice].sp_defense);
        printf("\n");

        if(pokedex[indice].sp_defense <= 0){
            printf("Defesa Esp. inválida. Insira um valor adequado: ");
            scanf("%d",&pokedex[indice].sp_defense);
            printf("\n");
        }

        printf("Por fim, insira sua nova velocidade: ");
        scanf("%d",&pokedex[indice].speed);
        printf("\n");

        if(pokedex[indice].speed <= 0){
            printf("Velocidade inválida. Insira um valor adequado: ");
            scanf("%d",&pokedex[indice].speed);
            printf("\n");
        }

        //lendário ou não?
        printf("Esse Pokémon é lendário? Para ""Sim"", insira 1, e para ""Não"", insira 0: ");
        scanf("%d",&pokedex[indice].lendario);
        printf("\n");

        if(pokedex[indice].lendario != 0 && pokedex[indice].lendario != 1){
            printf("Insira um valor igual a 0 ou 1.");
            scanf("%d",&pokedex[indice].lendario);
            printf("\n");
        }

        //alteração de altura e peso
        printf("Insira a nova altura e peso do Pokémon respectivamente: ");
        printf("\nAltura: ");
        scanf("%f",&pokedex[indice].altura);

        if(pokedex[indice].altura <= 0.0){
            printf("Altura inválida. Insira um valor adequado: ");
            scanf("%f",&pokedex[indice].altura);
        }

        printf("Peso: ");
        scanf("%f",&pokedex[indice].peso);
        printf("\n");

        if(pokedex[indice].peso <= 0.0){
        printf("Peso inválido. Insira um valor adequado: ");
        scanf("%f",&pokedex[indice].peso);
        printf("\n");
        }

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
