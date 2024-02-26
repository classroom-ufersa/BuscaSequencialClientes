/*Arquivo interface do algoritmo de busca sequencial de cliente*/

/*Definição de novo tipo: cliente*/
typedef struct cliente Cliente;


/**
 * @brief Imprime um cabeçalho formatado.
 * 
 * Esta função imprime um cabeçalho formatado com o tipo de linha e um título.
 * 
 * @param[in] linha A string que representa o caractere utilizado para desenhar a linha do cabeçalho.
 * @param[in] titulo O título do cabeçalho a ser impresso.
 */
void cabecalho(char* linha, char* titulo);

/**
 * @brief Espera o usuário pressionar enter para continuar.
 * 
 * Esta função serve para esperar o usuário apertar Enter para ir para a próxima função.
 * 
 * @param[in] none Sem parametros.
 * @return sem retornos
 */
void pressiona_enter();


/**
 * @brief Verifica se uma string contém apenas caracteres numéricos.
 * 
 * Esta função verifica se uma string contém apenas caracteres numéricos (dígitos de 0 a 9).
 * 
 * @param[in] str A string a ser verificada.
 * @return 1 se a string contém apenas dígitos numéricos, 0 caso contrário.
 */
int numero_inteiroc(char *str);


/**
 * @brief Verifica se um código de cliente existe no arquivo 'clientes.txt'.
 * 
 * Esta função verifica se um código de cliente fornecido existe no arquivo 'clientes.txt'.
 * 
 * @param[in] codigo_digitado O código do cliente digitado no teclado a ser verificado.
 * @return 1 se o código existe no arquivo, 0 caso contrário.
 */
int verifica_codigo(char *codigo_digitado);


/**
 * @brief Adiciona um novo cliente à lista.
 * 
 * Esta função adiciona um novo cliente ao arquivo clientes.txt .
 * 
 * @param none sem parâmetros.
 * @return sem retornos.
 */
void adiciona_cliente();


/**
 * @brief Realiza uma busca por código em um arquivo de clientes.
 *
 * Esta função permite ao usuário buscar por um cliente através de seu código em um arquivo cliente.txt
 *
 * @note O arquivo de clientes deve estar formatado com cada linha representando um cliente e com os campos
 * separados por tabulação.
 *
 * @note O código fornecido deve conter apenas números.
 * 
 * @param none sem parâmetros.
 * @return sem retornos.
 */
void procura_codigo();

/**
 * @brief Verifica se uma string contém apenas letras ou espaços.
 *
 * Esta função verifica se uma string contém apenas letras (maiúsculas ou minúsculas)
 * ou espaços. Ela percorre cada caractere da string e verifica se é uma letra ou um espaço.
 *
 * @param str A string a ser verificada.
 * @return Retorna 1 se a string contém apenas letras ou espaços e 0 caso contrário.
 */
int contem_apenas_letras(char *str);


/**
 * @brief Realiza uma busca por nome em um arquivo de clientes.
 *
 * Esta função permite ao usuário buscar por um cliente através do seu nome em um arquivo de clientes.
 *
 * @note O arquivo de clientes deve estar formatado com cada linha representando um cliente e com os campos
 * separados por tabulação.
 *
 * @note O nome fornecido deve conter apenas letras do alfabeto.
 * 
 * @param none sem parâmetros.
 * @return sem retornos.
 */
void procura_nome();


/**
 * @brief Lista todos os clientes armazenados em um arquivo.
 *
 * Esta função lê o arquivo de clientes e exibe na saída padrão todos os clientes armazenados.
 *
 *
 * @note O arquivo de clientes deve estar formatado com cada linha representando um cliente e com os campos
 * separados por tabulação.
 * 
 * @param none sem parâmetros.
 * @return sem retornos.
 */
void lista_clientes();


/**
 * @brief Imprime um menu.
 * 
 * Esta função imprime um menu que será usado para a navegação do usuário.
 * 
 * @param[in] none Sem parâmetros.
 * @return sem retornos.
 */
void menu();
