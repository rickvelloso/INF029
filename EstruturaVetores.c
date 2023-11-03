#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

typedef struct AuxS {
  int *aux;
  int tamanho;
  int quantidade;
} AuxS;

AuxS mainArray[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho) {
  int retorno = 0;

  // se posição é um valor válido {entre 1 e 10}
  // o tamanho ser muito grande
  if (posicao < 1 || posicao > TAM) {
    return POSICAO_INVALIDA;
  }
  // a posicao pode já existir estrutura auxiliar
  else if (mainArray[posicao - 1].aux != NULL) {
    return JA_TEM_ESTRUTURA_AUXILIAR;
  }

  // deu tudo certo, crie
  else if (tamanho < 1) {
    return TAMANHO_INVALIDO;
  }

  // criar posição no vetor principal
  mainArray[posicao - 1].aux = malloc(tamanho * sizeof(int));
  mainArray[posicao - 1].tamanho = tamanho;

  if (!mainArray[posicao - 1].aux) {
    return SEM_ESPACO_DE_MEMORIA;
  }
  return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor) {
  int retorno = 0;
  int posicao_invalida = 0;

  if (posicao < 1 || posicao > TAM) {
    return POSICAO_INVALIDA;
  } else {
    // testar se existe a estrutura auxiliar
    if (mainArray[posicao - 1].aux != NULL) {
      if (mainArray[posicao - 1].quantidade != mainArray[posicao - 1].tamanho) {
        mainArray[posicao - 1].aux[mainArray[posicao - 1].quantidade] = valor;
        mainArray[posicao - 1].quantidade++; // adiciono o valor
        return SUCESSO;
      } else {
        return SEM_ESPACO;
      }
    } else {
      return SEM_ESTRUTURA_AUXILIAR;
    }
  }
  return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar
da seguinte forma [3, 8, 7,  ,  ,  ]. Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao) {
  int retorno = SUCESSO;

  if (posicao < 1 || posicao > TAM) {
    retorno = POSICAO_INVALIDA;
  } else if (mainArray[posicao - 1].aux == NULL) {
    retorno = SEM_ESTRUTURA_AUXILIAR;
  } else if (mainArray[posicao - 1].quantidade == 0) {
    retorno = ESTRUTURA_AUXILIAR_VAZIA;
  } else {
    mainArray[posicao - 1].quantidade--;
    retorno = SUCESSO;
  }
  return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições
anteriores ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o
valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ] Obs. Esta é
uma exclusão lógica Rertono (int) SUCESSO - excluido com sucesso 'valor' da
estrutura na posição 'posicao' ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
  int retorno = SUCESSO;
  int achei = 0;

  if (posicao < 1 || posicao > 10) {
    return POSICAO_INVALIDA;
  }

  else if (mainArray[posicao - 1].aux == NULL) {
    return SEM_ESTRUTURA_AUXILIAR;
  }

  else if (mainArray[posicao - 1].quantidade == 0) {
    return ESTRUTURA_AUXILIAR_VAZIA;
  }

  for (int i = 0; i < mainArray[posicao - 1].quantidade; i++) {
    if (mainArray[posicao - 1].aux[i] == valor) {
      achei = 1;
      break;
    }
  }

  if (!achei) {
    return NUMERO_INEXISTENTE;
  }

  for (int j = 0; j < mainArray[posicao - 1].quantidade; j++) {
    mainArray[posicao - 1].aux[j] = mainArray[posicao - 1].aux[j + 1];
  }
  mainArray[posicao - 1].quantidade--;

  return SUCESSO;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao) {
  int retorno = 0;
  if (posicao < 1 || posicao > 10) {
    retorno = POSICAO_INVALIDA;
  } else
    retorno = SUCESSO;
  return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar POSICAO_INVALIDA -
Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
  // dado uma posição quais são os dados que já tem na estrutura

  int retorno = 0;
  if (posicao < 1 || posicao > TAM) {
    return POSICAO_INVALIDA;
  }
  if (mainArray[posicao - 1].aux == NULL) {
    return SEM_ESTRUTURA_AUXILIAR;
  }

  for (int i = 0; i < mainArray[posicao - 1].quantidade; i++) {
    vetorAux[i] = mainArray[posicao - 1].aux[i];
  }
  return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao
(1..10)'. os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao
(1..10)' SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar POSICAO_INVALIDA -
Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
  int retorno = 0;
  if (posicao < 1 || posicao > 10) {
    return POSICAO_INVALIDA;
  } else if (mainArray[posicao - 1].aux == NULL) {
    return SEM_ESTRUTURA_AUXILIAR;
  } else {

    for (int i = 0; i < mainArray[i].quantidade; i++) {
      vetorAux[i] = mainArray[posicao - 1].aux[i];
    }

    for (int i = 1; i < mainArray[i].quantidade; i++) { // bubble sort
      for (int j = 0; j < mainArray[i].quantidade - 1; j++) {
        if (vetorAux[j] > vetorAux[j + 1]) {
          int temp = vetorAux[j];
          vetorAux[j] = vetorAux[j + 1];
          vetorAux[j + 1] = temp;
        }
      }
    }
    return SUCESSO;
  }
  return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
  int posicao, i, j;
  int indice = 0;

  for (posicao = 0; posicao < TAM; posicao++) {
    if (mainArray[posicao].quantidade > 0) {

      for (i = 0; i < mainArray[posicao].quantidade; i++) {
        vetorAux[indice] = mainArray[posicao].aux[i];
        indice++;
      }
    }
  }
  if (indice == 0) {
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  } else {

    return SUCESSO;
  }
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
  int posicao, i, j;
  int indice = 0;
  for (posicao = 0; posicao < TAM; posicao++) {
    if (mainArray[posicao].quantidade > 0) {

      for (i = 0; i < mainArray[posicao].quantidade; i++) {
        vetorAux[indice] = mainArray[posicao].aux[i];
        indice++;
      }
    }
  }
  for (i = 1; i < indice; i++) { // bubble sort
    for (j = 0; j < indice - 1; j++) {
      if (vetorAux[j] > vetorAux[j + 1]) {
        int temp = vetorAux[j];
        vetorAux[j] = vetorAux[j + 1];
        vetorAux[j + 1] = temp;
      }
    }
  }

  if (indice == 0) {
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  } else {
    return SUCESSO;
  }
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o
novo tamanho 'novoTamanho' + tamanho atual Suponha o tamanho inicial = x, e novo
tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser
sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
  novoTamanho = novoTamanho + mainArray[posicao - 1].tamanho;
  if (posicao < 1 || posicao > TAM) {
    return POSICAO_INVALIDA;
  }
  if (mainArray[posicao - 1].aux == NULL) {
    return SEM_ESTRUTURA_AUXILIAR;
  }
  if (novoTamanho < 1) {
    return NOVO_TAMANHO_INVALIDO;
  }

  mainArray[posicao - 1].aux =
      realloc(mainArray[posicao - 1].aux, (novoTamanho * sizeof(int)));

  mainArray[posicao - 1].tamanho = novoTamanho;

  if (!mainArray[posicao - 1].aux) {
    return SEM_ESPACO_DE_MEMORIA;
  }

  return SUCESSO;
}
/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da
posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da
estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao) {
  if (posicao < 1 || posicao > TAM) {
    return POSICAO_INVALIDA;
  }
  if (mainArray[posicao - 1].aux == NULL) {
    return SEM_ESTRUTURA_AUXILIAR;
  }

  if (mainArray[posicao - 1].quantidade > 0) {
    if (mainArray[posicao - 1].tamanho < mainArray[posicao - 1].quantidade)
      mainArray[posicao - 1].quantidade = mainArray[posicao - 1].tamanho;
  } else {
    return ESTRUTURA_AUXILIAR_VAZIA;
  }
  return mainArray[posicao - 1].quantidade;
  return SUCESSO;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes
em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *criarElemento(int valor) {
  No *novo = (No *)malloc(sizeof(No));
  if (novo == NULL) {
    exit(1);
  }
  novo->valor = valor;
  novo->prox = NULL;
  return novo;
}

void inserirFinalComCabecote(No *inicio, int valor) {

  No *aux;
  No *novo = criarElemento(valor);

  if (inicio->prox == NULL) {
    inicio->prox = novo;
  } else {
    aux = inicio->prox;

    while (aux->prox != NULL)
      aux = aux->prox;

    aux->prox = novo;
  }
}
No *montarListaEncadeadaComCabecote() {
  No *novo = (No *)malloc(sizeof(No));
  return novo;
}

No *CriarLista(int valor) {
  No *novo = (No *)malloc(sizeof(No));
  novo->valor = valor;
  novo->prox = NULL;

  return novo;
}

void inserirNoFim(No **head, int valor) {
  No *novo = CriarLista(valor);

  No *atual = *head;

  while (atual->prox != NULL) {
    atual = atual->prox;
  }

  atual->prox = novo;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em
vetorAux. Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) {
  for (int i = 0; i < 10; i++) {
    if (mainArray[i].quantidade != 0) {
      for (int j = 0; j < mainArray[i].quantidade; j++) {
        inserirNoFim(&inicio, mainArray[i].aux[j]);
      }
    }
  }

  No *current = inicio->prox;
  int i = 0;
  while (current != NULL) {
    vetorAux[i] = current->valor;
    current = current->prox;
    i++;
  }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio) { *inicio = NULL; }

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar() {
  for (int i = 0; i < TAM; i++) {
    mainArray[i].aux = NULL;
    mainArray[i].quantidade = 0;
    mainArray[i].tamanho = 0;
  }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar() {
  for (int i = 0; i < 10; i++) {
    free(mainArray[i].aux);
  }
}