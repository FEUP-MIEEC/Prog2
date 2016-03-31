/********************************************************************/
/*                define estrutura armazem e funcoes                */
/********************************************************************/

#ifndef ARMAZEM_H

#include "contentor.h"
#include "fila_contentores.h"
#include "pilha_contentores.h"

/**
 * \brief estrutura armazem
 */
typedef struct {

	/** \brief numero maximo de pilhas de contentores (tamanho da fila) */
	int comprimento;

	/** \brief numero maximo de contentores numa pilha (tamanho da pilha) */
	int altura;

	/** \brief fila de pilhas de contentores (coluna) */
	fila* contentores;

} armazem;

/* alinea b) */
/**
 *  \brief cria um novo armazem vazio
 *  \param comprimento valor maximo do comprimento da fila de pilhas de contentores
 *  \param altura valor maximo da altura das pilhas de contentores
 *  \return apontador para o armazem ou NULL se erro na alocacao de memoria
 */
armazem* armazem_novo(int comprimento, int altura);

/* alinea c) */
/**
 *  \brief verifica se o armazem esta' vazio
 *  \param armz apontador para o armazem
 *  \return 1 se armazem vazio; 0 se contem contentores
 */
int armazem_vazio(armazem* armz);

/* alinea d) */
/**
 *  \brief verifica se o armazem pode receber mais contentores
 *  \param armz apontador para o armazem
 *  \return 1 se armazem nao pode receber mais contentores; 0 se pode
 */
int armazem_cheio(armazem* armz);

/* alinea e) */
/**
 *  \brief empilha contentor no armazem
 *  \param armz apontador para o armazem
 *  \param contr apontador para o contentor
 *  \return 1 se contentor foi descarregado; 0 se armazem cheio
 *  \remark contentor e' carregado na primeira pilha; quando a pilha
 *    esta' completa comeca a empilhar noutra;
 */
int armazenar_contentor(armazem* armz, contentor* contr);

/* alinea f) */
/**
 *  \brief retira um contentor do armazem para o navio
 *  \param armz apontador para o armazem
 *  \return apontador para o contentor retirado ou NULL se armazem vazio
 *  \remark contentor e' retirado da pilha mais proxima do navio
 */
contentor* expedir_contentor(armazem* armz);

#define ARMAZEM_H
#endif
