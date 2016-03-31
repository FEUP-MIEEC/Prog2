/**************************************************************/
/*                  define estrutura contentor                */
/**************************************************************/

#ifndef CONTENTOR_H

/**
 * estrutura contentor
 */
typedef struct {
	char* destino;
	float valor;
} contentor;

/**
 *  \brief cria um novo contentor
 *  \param dest destino do contentor
 *  \param val valor das mercadorias no contentor
 *  \return apontador para o contentor; NULL se erro
 */
contentor* contentor_novo(char* dest, float val);

/**
 *  \brief apaga contentor (liberta memoria correspondente)
 *  \param contr apontador para o contentor
 *  \remark se contr = NULL retorna sem fazer nada
 */
void contentor_apaga(contentor* contr);

/**
 *  \brief imprime dados do contentor
 *  \param contr apontador para o contentor
 */
void contentor_imprime(contentor* contr);

#define CONTENTOR_H
#endif