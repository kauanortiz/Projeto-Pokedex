/*Biblioteca com funções relacionadas a manipulação de dados da Pokédex*/


//estrutura que define todos os dados necessários de um Pokémon
typedef struct{

    int numero, geracao, total, lendario;
    char nome[16], cor[12], tipo1[12], tipo2[12];
    int hp, attack, defense, sp_attack, sp_defense, speed;
    float altura, peso;
    int catch_rate;
    int pre_evol, prox_evol;

} Pokemon;

//recebe um nome e salva-o
void ler_nomes(char codigo_pokemon[], int size);

//insere um novo Pokémon na Pokédex
void inserir_novo(Pokemon pokedex[], int tamanho);

//lista os Pokémon por geração ou tipo
void listar_todos(Pokemon pokedex[], int tamanho);

//pede o nome do Pokémon e busca na Pokédex, em seguida exibe seus dados
void buscar_pokemon(Pokemon pokedex[], int tamanho, char busca[]);

//altera os dados de um Pokémon
void alterar_pokemon(Pokemon pokedex[], int tamanho);

//exclui os dados de Pokémon da Pokédex
void excluir_pokemon(Pokemon pokedex[], int tamanho);