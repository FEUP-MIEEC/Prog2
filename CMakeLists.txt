cmake_minimum_required(VERSION 3.3)
project(Prog2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

add_executable(Extras_cores Extras/cores.c)
add_executable(0.1 Aula00_Conceitos_base/01.c)
add_executable(0.2 Aula00_Conceitos_base/02.c)
add_executable(0.3 Aula00_Conceitos_base/03.c)
add_executable(0.4 Aula00_Conceitos_base/04.c)
add_executable(0.5 Aula00_Conceitos_base/05.c)
add_executable(0.6 Aula00_Conceitos_base/06.c)
add_executable(0.7 Aula00_Conceitos_base/07.c)
add_executable(0.8 Aula00_Conceitos_base/08.c)
add_executable(0.9 Aula00_Conceitos_base/09.c)
add_executable(0.10 Aula00_Conceitos_base/10.c)
add_executable(0.11.1 Aula00_Conceitos_base/11_ADDREV.c)
add_executable(0.11.2 Aula00_Conceitos_base/11_HELLOKIT.c)
add_executable(1.1.1 Aula01_Ficheiros_e_Formatos_de_dados/01.1.c)
add_executable(1.1.3 Aula01_Ficheiros_e_Formatos_de_dados/01.3.c)
add_executable(1.2 Aula01_Ficheiros_e_Formatos_de_dados/02.c)
add_executable(1.3 Aula01_Ficheiros_e_Formatos_de_dados/03.c)
add_executable(1.4 Aula01_Ficheiros_e_Formatos_de_dados/04.c)
add_executable(1.5 Aula01_Ficheiros_e_Formatos_de_dados/05.c)
add_executable(2.1 Aula02_Alocacao_dinamica_de_memoria_e_vetores/01.c)
add_executable(2.2 Aula02_Alocacao_dinamica_de_memoria_e_vetores/02.c)
add_executable(2.3.2 Aula02_Alocacao_dinamica_de_memoria_e_vetores/03.2_.c Aula02_Alocacao_dinamica_de_memoria_e_vetores/vetor.c Aula02_Alocacao_dinamica_de_memoria_e_vetores/vetor.h)
add_executable(2.3.3 Aula02_Alocacao_dinamica_de_memoria_e_vetores/03.3_.c)
add_executable(3.1 Aula03_Vetores_e_algoritmos_de_pesquisa_e_ordenacao/01.c Aula03_Vetores_e_algoritmos_de_pesquisa_e_ordenacao/vetor.c Aula03_Vetores_e_algoritmos_de_pesquisa_e_ordenacao/vetor.h)
add_executable(3.2 Aula03_Vetores_e_algoritmos_de_pesquisa_e_ordenacao/02.c)
add_executable(3.e.3 Aula03_Vetores_e_algoritmos_de_pesquisa_e_ordenacao/Extras/03.c)
add_executable(4 Aula04_Listas_T1/lista-teste.c Aula04_Listas_T1/lista.c Aula04_Listas_T1/lista.h)
add_executable(5.1 Aula05_Filas_e_Pilhas/1/teste_armazem.c Aula05_Filas_e_Pilhas/1/armazem.h Aula05_Filas_e_Pilhas/1/armazem.c Aula05_Filas_e_Pilhas/1/contentor.h Aula05_Filas_e_Pilhas/1/contentor.c Aula05_Filas_e_Pilhas/1/fila_contentores.c Aula05_Filas_e_Pilhas/1/fila_contentores.h Aula05_Filas_e_Pilhas/1/pilha_contentores.c Aula05_Filas_e_Pilhas/1/pilha_contentores.h)
add_executable(MT1E1-1.1 Extras/Miniteste1-Exemplo1/1/prob1.c Extras/Miniteste1-Exemplo1/1/vetor.c Extras/Miniteste1-Exemplo1/1/vetor.h Extras/Miniteste1-Exemplo1/1/lista.c Extras/Miniteste1-Exemplo1/1/lista.h)
add_executable(MT1E1-1.2 Extras/Miniteste1-Exemplo1/2/prob2.c)
add_executable(MT1E1-2.1 Extras/Miniteste1-Exemplo2/1/prob1.c Extras/Miniteste1-Exemplo2/1/vetor.c Extras/Miniteste1-Exemplo2/1/vetor.h Extras/Miniteste1-Exemplo2/1/lista.c Extras/Miniteste1-Exemplo2/1/lista.h)
add_executable(MT1E1-2.2 Extras/Miniteste1-Exemplo2/2/prob2.c)
add_executable(6.Challenge Aula06_Challenge/challenge.c)
add_executable(7.1 Aula07_Arvores/arvores-teste.c Aula07_Arvores/avl.c Aula07_Arvores/avl.h Aula07_Arvores/bst.c Aula07_Arvores/bst.h)
add_executable(8 Aula08_Grafos_T2/grafo-teste.c Aula08_Grafos_T2/grafo.h Aula08_Grafos_T2/grafo.c Aula08_Grafos_T2/vetor.h Aula08_Grafos_T2/vetor.c)
add_executable(9 Aula09_Filas_de_Prioridade_e_Heaps/priorityqueue.c Aula09_Filas_de_Prioridade_e_Heaps/vetor.c Aula09_Filas_de_Prioridade_e_Heaps/vetor.h)
add_executable(10.1 Aula10_Tabelas_de_Dispersao/01.1.c Aula10_Tabelas_de_Dispersao/tabdispersao.c Aula10_Tabelas_de_Dispersao/tabdispersao.h)
add_executable(11 Aula11_SpellChecking_T3/spellChecker.c Aula11_SpellChecking_T3/tabdispersao.c Aula11_SpellChecking_T3/tabdispersao.h)
add_executable(MT2E2-1 Extras/Miniteste2-Exemplo2/prob1/prob1.c Extras/Miniteste2-Exemplo2/prob1/avl.c Extras/Miniteste2-Exemplo2/prob1/avl.h Extras/Miniteste2-Exemplo2/prob1/lista.c Extras/Miniteste2-Exemplo2/prob1/lista.h Extras/Miniteste2-Exemplo2/prob1/tabdispersao.c Extras/Miniteste2-Exemplo2/prob1/tabdispersao.h)
add_executable(MT2E2-2 Extras/Miniteste2-Exemplo2/prob2/prob2.c Extras/Miniteste2-Exemplo2/prob2/grafo.c Extras/Miniteste2-Exemplo2/prob2/grafo.h Extras/Miniteste2-Exemplo2/prob2/heap.h Extras/Miniteste2-Exemplo2/prob2/heap.c Extras/Miniteste2-Exemplo2/prob2/lista.h Extras/Miniteste2-Exemplo2/prob2/lista.c)
add_executable(MT2E1-1 Extras/Miniteste2-Exemplo1/prob1/prob1.c Extras/Miniteste2-Exemplo1/prob1/avl.c Extras/Miniteste2-Exemplo1/prob1/avl.h Extras/Miniteste2-Exemplo1/prob1/tabdispersao.h Extras/Miniteste2-Exemplo1/prob1/tabdispersao.c)
add_executable(MT2E1-2 Extras/Miniteste2-Exemplo1/prob2/prob2.c Extras/Miniteste2-Exemplo1/prob2/grafo.c Extras/Miniteste2-Exemplo1/prob2/grafo.h Extras/Miniteste2-Exemplo1/prob2/heap.c Extras/Miniteste2-Exemplo1/prob2/heap.h Extras/Miniteste2-Exemplo1/prob2/lista.c Extras/Miniteste2-Exemplo1/prob2/lista.h Extras/Miniteste2-Exemplo1/prob2/vetor.c Extras/Miniteste2-Exemplo1/prob2/vetor.h)