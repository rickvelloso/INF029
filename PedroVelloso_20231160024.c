// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do
//  trabalho

//  ----- Dados do Aluno -----
//  Nome: Pedro Henrique Barreto Velloso
//  email: pedrohenriquevelloso18@gmail.com
//  Matrícula: 20231160024
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include "PedroVelloso_20231160024.h" // Substitua pelo seu arquivo de header renomeado
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_string 500

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y) {
  int soma;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x) { // função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}

int teste(int a) {
  int val;
  if (a == 2)
    val = 3;
  else
    val = 4;

  return val;
}

DataQuebrada quebraData(char data[]) {
  DataQuebrada dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i;

  for (i = 0; data[i] != '/'; i++) {
    sDia[i] = data[i];
  }
  if (i == 1 || i == 2) { 
    sDia[i] = '\0';       
  } else {
    dq.valido = 0;
    return dq;
  }

  int j = i + 1; 
  i = 0;

  for (; data[j] != '/'; j++) {
    sMes[i] = data[j];
    i++;
  }

  if (i == 1 || i == 2) { 
    sMes[i] = '\0';       
  } else {
    dq.valido = 0;
    return dq;
  }

  j = j + 1; 
  i = 0;

  for (; data[j] != '\0'; j++) {
    sAno[i] = data[j];
    i++;
  }

  if (i == 2 || i == 4) { 
    sAno[i] = '\0';       
  } else {
    dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno);

  dq.valido = 1;

  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia,
mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa
podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */

int q1(char data[]) {
  int datavalida = 1;

  int monthCheck = 0;
  int dayCheck = 0;
  int yearCheck = 0;
  DataQuebrada dq = quebraData(data);
  if (dq.valido == 1) {
    if (dq.iAno < 100 && dq.iAno > -1) {
      dq.iAno += 2000;
      yearCheck = 1;
    }
    if (dq.iAno >= 1900 && dq.iAno <= 2101)
      yearCheck = 1;
    if (dq.iAno <= -1)
      yearCheck = 0;
    if (dq.iMes < 13 && dq.iMes > 0) {

      if (dq.iMes == 1 || dq.iMes == 3 || dq.iMes == 5 || dq.iMes == 7 ||
          dq.iMes == 8 || dq.iMes == 10 || dq.iMes == 12) {

        if (dq.iDia < 32 && dq.iDia > 0) {
          monthCheck = 1;
        }
      } else if (dq.iMes == 4 || dq.iMes == 6 || dq.iMes == 9 ||
                 dq.iMes == 11) {

        if (dq.iDia < 31 && dq.iDia > 0) {
          monthCheck = 1;
        }
      }
      if (dq.iMes == 2) {

        if (dq.iDia == 29) {
          if ((dq.iAno % 4 == 0 && dq.iAno % 100 != 0) ||
              (dq.iAno % 400 == 0)) {
            monthCheck = 1;
          }
        } else if (dq.iDia > 0 && dq.iDia < 29) {
          monthCheck = 1;
        }
      }
    } else
      monthCheck = 0;

    if (dq.iDia > 0 && dq.iDia < 32)
      dayCheck = 1;
    else
      dayCheck = 0;
  }
  if (dq.valido == 0)
    datavalida = 0;
  if (monthCheck == 1 && dayCheck == 1 && yearCheck == 1)
    datavalida = 1;
  else
    datavalida = 0;

  

  if (datavalida)
    return 1;
  else
    return 0;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em Anos, Meses e Dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis
 valores abaixo 1 -> cálculo de diferença realizado com sucesso 2 -> datainicial
 inválida 3 -> datafinal inválida 4 -> datainicial > datafinal Caso o cálculo
 esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos
 com os valores correspondentes.

 */
int verificaAnoBi(int ano) {
  if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
    return 1;
  } else {
    return 0;
  }
}
DiasMesesAnos q2(char datainicial[], char datafinal[]) {

  DiasMesesAnos dma;

  if (q1(datainicial) == 0) {
    dma.retorno = 2;
    return dma;
  } else if (q1(datafinal) == 0) {
    dma.retorno = 3;
    return dma;
  } else {

    DataQuebrada datainicio, datafim;
    datainicio = quebraData(datainicial);
    datafim = quebraData(datafinal);
    int diastotais1 =
        datainicio.iDia + ((datainicio.iMes * 30) + (datainicio.iAno * 365));
    int diastotais2 =
        datafim.iDia + ((datafim.iMes * 30) + (datafim.iAno * 365));

    if (diastotais1 > diastotais2) {
      dma.retorno = 4;
      return dma;
    }

    int chegou = 0;
    int diaspassados = 0;
    int anoinicio = datainicio.iAno;
    int mesinicio = datainicio.iMes;
    int diainicio = datainicio.iDia;
    int diasNosMeses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (chegou == 0) {

      int trocaAno = 0;
      if (verificaAnoBi(datainicio.iAno) == 1) {
        diasNosMeses[1] = 29;
      } else {
        diasNosMeses[1] = 28;
      }

      while (trocaAno == 0 && chegou == 0) {

        datainicio.iDia++;
        diaspassados++;
        if (datainicio.iDia > diasNosMeses[datainicio.iMes - 1]) {
          datainicio.iDia = 1;
          datainicio.iMes++;
        }

        if (datainicio.iDia == 31 && datainicio.iMes == 12) {
          trocaAno = 1;
        }

        if (datainicio.iDia == datafim.iDia &&
            datainicio.iMes == datafim.iMes &&
            datainicio.iAno == datafim.iAno) {
          chegou = 1;
        }
      }

      if (chegou == 0) {
        diaspassados++;
        datainicio.iDia = 1;
        datainicio.iMes = 1;
        datainicio.iAno++;
      }
    }
    int bissexto = 0;
    int acabou = 0;
    int i = mesinicio - 1;
    dma.qtdAnos = 0;
    dma.qtdDias = 0;
    dma.qtdMeses = 0;
    while (acabou == 0) {
      if (verificaAnoBi(anoinicio) == 1) {

        diasNosMeses[1] = 29;
      } else {
        diasNosMeses[1] = 28;
      }

      if (i == 11) {
        diaspassados -= diasNosMeses[i];
        i = 0;
        dma.qtdMeses++;
        anoinicio++;
      }

      if (diaspassados >= diasNosMeses[i]) {
        dma.qtdMeses++;
        diaspassados -= diasNosMeses[i];
        i++;

        if (dma.qtdMeses == 12) {
          dma.qtdMeses = 0;
          dma.qtdAnos = 1;
        }

      } else {

        dma.qtdDias = diaspassados;
        acabou = 1;
      }
    }

    dma.retorno = 1;
    return dma;
  }
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa
 Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar
 diferenças entre maiúsculos e minúsculos. Se isCaseSensitive != 1, a pesquisa
 não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive) {
  int qtdOcorrencias = 0;
  char string[500];
  strcpy(string, texto);
  if (isCaseSensitive != 1) {
    if (c >= 'A' && c <= 'Z') {
      c += 32;
    }
    for (int i = 0; string[i] != '\0'; i++) {
      if (string[i] >= 65 && string[i] <= 90) {
        string[i] += 32;
      }
    }
  }

  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] == c)
      qtdOcorrencias++;
  }
  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros
 (posicoes) que irá guardar as posições de início e fim de cada ocorrência da
 palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída
 correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do
 vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve
 ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a
 segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente.
 Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como
 há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da
 seguinte forma: posicoes[0] = 13; posicoes[1] = 16; Observe que o índice da
 posição no texto deve começar ser contado a partir de 1. O retorno da função,
 n, nesse caso seria 1;

 */

int q4(char *strTexto, char *strBusca, int posicoes[30]) {
  int Tamanho;
  int aux, i, j, ver, k;
  int Qtd, especial;
  char text[250], busca[30];
  strcpy(text, strTexto);
  strcpy(busca, strBusca);
  int qtdOcorrencias = 0;
  for (Tamanho = 0; busca[Tamanho] != '\0'; Tamanho++) {
  }
  Qtd = 0;
  especial = 0;
  for (i = 0; text[i] != '\0'; i++) {
    if (text[i] == -61) {
      especial++;
    }
    if (text[i] == busca[0]) {
      k = 0;
      aux = i + 1 - especial;
      j = i;
      ver = 0;
      while (text[j] == busca[k]) {
        ver++;
        j++;
        k++;
        i++;
      }
      if (ver == Tamanho) {
        posicoes[Qtd] = aux;
        posicoes[Qtd + 1] = aux + Tamanho - 1;
        qtdOcorrencias++;
        i--;
        Qtd += 2;
      }
    }
  }

  return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num) {
  int digitoinvertido = 0;

  int divisor = 1;
  int i = 0;
  int local = 0;
  int j = 0;
  int result = 0;

  while (divisor <= num) {
    divisor = divisor * 10;
  }

  divisor = divisor / 10;
  local = 1;

  while (divisor > 0) {

    result = num / divisor;
    num = num % divisor;
    result = result * local;
    divisor = divisor / 10;
    local *= 10;
    digitoinvertido = digitoinvertido + result;
  }

  return digitoinvertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca) {
  int qtdOcorrencias = 0;
  int ultimoDigito = 0;
  int i = 1;
  while (numerobase > 0) {
    if (numerobusca <= i) {
      if (i > 1) {
        ultimoDigito = numerobase % i;
      } else {
        ultimoDigito = numerobase % 10;
      }

      if (ultimoDigito == numerobusca) {
        qtdOcorrencias++;
        if (numerobusca > 9) {
          numerobase = numerobase / (i / 10);
        }
      }

      numerobase = numerobase / 10;
    } else {
      i = i * 10;
    }
  }

  return qtdOcorrencias;
}
