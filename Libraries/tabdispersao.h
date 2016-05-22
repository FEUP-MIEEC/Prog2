/*****************************************************************/
/*       Tabela de Dispersao | PROG2 | MIEEC | 2015/16           */
/*****************************************************************/

#ifndef TABDISPERSAO_H
#define TABDISPERSAO_H

#define TABDISPERSAO_EXISTE     (1)
#define TABDISPERSAO_OK   		(0)
#define TABDISPERSAO_INVALIDA   (-1)
#define TABDISPERSAO_ERRO       (-2)
#define TABDISPERSAO_NAOEXISTE  (-3)

#define TAMANHO_CHAVE	 25
#define TAMANHO_VALOR	100

/* tabela de dispersao de strings baseada em encadeamento */

typedef unsigned long hash_func(const char *, int);

/** \brief conteudo individual da tabela de dispersao:
 * cada objeto tem uma chave e um texto associado
 */
typedef struct
{
	char chave[TAMANHO_CHAVE];
	char valor[TAMANHO_VALOR];
} objeto;

/** \brief elemento da tabela de dispersao */
typedef struct elem
{
	objeto* obj;
	struct elem * proximo;
} elemento;

/**
 * \brief A estrutura tabela_dispersao para armazenar dados relativos a uma tabela de dispersao
 */
struct tab_dispersao
{
	hash_func *hfunc;		/* apontador para a funcao a ser usada (hash_djbm, hash_krm, ...) */
	elemento **elementos;	/* vetor de elementos */
	int tamanho;			/* tamanho do vetor de elementos */
};

/**
 * \brief tabela_dispersao ADT
 */
 typedef struct tab_dispersao tabela_dispersao;

/**
 * \brief cria uma tabela de dispersao
 * \param tamanho tamanho da tabela de dispersao
 * \param hash_func apontador para funcao de dispersao a ser usada nesta tabela
 * \return uma tabela de dispersao vazia que usa a funcao de dispersao escolhida
 */
tabela_dispersao* tabela_nova(int tamanho, hash_func *hfunc);

/**
 * \brief elimina uma tabela, libertando toda a memoria ocupada
 * \param td tabela de dispersao a ser apagada da memoria
 * \remark apagar _todos_ os elementos anteriormente alocados na memoria
 */
void tabela_apaga(tabela_dispersao *td);

/**
 * \brief adiciona um novo objeto 'a tabela; se a chave ja' existir atualiza o texto associado com o novo texto
 * \param td tabela onde adicionar o objeto
 * \param valor objeto a ser adicionado
 * \return se o valor for adicionado correctamente, a funcao retorna TABDISPERSAO_OK
 * \return caso contrario deve devolver TABDISPERSAO_ERRO ou TABDISPERSAO_INVALIDA
 * \remark valor deve ser copiado para outro local em memoria.
 */
int tabela_adiciona(tabela_dispersao *td, const char *chave, const char *valor);

/**
 * \brief remove um valor da tabela
 * \param td tabela de onde remover o valor
 * \param chave chave do objeto a ser removido da tabela
 * \return TABDISPERSAO_NAOEXISTE se o valor passado como argumento nao existir na tabela
 * \return ou TABDISPERSAO_OK se o valor foi removido correctamente
 * \return ou TABDISPERSAO_INVALIDA se a tabela não existe
 */
int tabela_remove(tabela_dispersao *td, const char *chave);

/**
 * \brief verifica se um valor existe na tabela
 * \param td tabela onde procurar o valor
 * \param valor objeto a ser procurado
 * \return TABDISPERSAO_NAOEXISTE se o valor nao existir
 * \return ou TABDISPERSAO_EXISTE se o valor existir
 * \return ou TABDISPERSAO_INVALIDA se a tabela não existe
 */
int tabela_existe(tabela_dispersao *td, const char *chave);

/**
 * \brief devolve o valor correspondente 'a chave
 * \param td tabela onde procurar o objeto
 * \param chave chave do objeto a ser procurado
 * \return apontador para a string valor se existir, ou NULL se nao existir objeto ou tabela
 */
const char* tabela_valor(tabela_dispersao *td, const char *chave);

/**
 * \brief apaga todos os valores correntemente na tabela, ficando a tabela vazia
 * \param td tabela a ser esvaziada
 * \return TABDISPERSAO_OK ou TABDISPERSAO_INVALIDA de acordo com o resultado
 */
int tabela_esvazia(tabela_dispersao *td);

/**
 * \brief determina o numero de elementos na tabela de dispersao
 * \param td tabela de dispersao
 * \return numero de elementos na tabela 
 * \return ou TABDISPERSAO_NAOEXISTE se a tabela não existe
 */
int tabela_numelementos(tabela_dispersao *td);

/**
 * \brief devolve um vetor com os elementos da tabela de dispersao
 * \param td tabela de dispersao
 * \return vetor com os objetos da tabela ou NULL se nao existir tabela ou tabela vazia
 */
objeto* tabela_elementos(tabela_dispersao *td, int *n);

/**
 * \brief calcula hash com base na seguinte formula:
 *            hash(i) = hash(i-1) + chave[i]
 *    em que hash(0) = 7
 *
 * \param chave string para a qual se pretende calcular o chave de hash
 * \param tamanho da tabela de dispersão
 * \remark chave[i] e' o caracter no indice de i da chave
 */
unsigned long hash_krm(const char* chave, int tamanho);

/**
 * \brief calcula hash com base na seguinte formula:
 *            hash(i) = hash(i-1)* 31 (+) chave[i]
 *        em que hash(0) = 5347
 *
 * \param chave string para o qual se pretende calcular o chave de hash
 * \param tamanho da tabela de dispersão
 * \remark chave[i] e' o caracter no indice de i da chave
 * \remark (+) representa "ou exclusivo" que em C e' indicado por ^
 */
unsigned long hash_djbm(const char *chave, int tamanho);

/**
 * Esta funcao imprime o estado actual da tabela para o ecra
 * \param td Tabela a ser mostrada no ecra
 */
void mostraTabela(tabela_dispersao *td);

#endif
