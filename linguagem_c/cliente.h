/*Arquivo interface do algoritmo de busca sequencial de cliente*/

/*Definição de novo tipo: cliente*/
typedef struct cliente Cliente;

/* Função responsável pela busca sequencial de clientes a partir do seu código*/
void procura_codigo();


/* Função responsável pela busca sequencial de clientes a partir do seu nome*/
void procura_nome();


int numero_inteiroc(char *str);

int verifica_codigo(char *codigo_digitado);

void cabecalho(char* linha, char* titulo);

void menu();