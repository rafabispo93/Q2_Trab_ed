/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: rafael
 *
 * Created on 29 de Abril de 2017, 16:09
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void stop(const char *msg)
{
    printf("%s", msg);
    abort();
}

#define MAX_SIZE 256
double stack[MAX_SIZE];
int top;

void push(double v)
{
  if (top >= MAX_SIZE)
    stop("Pilha cheia\n");
  stack[top++] = v;
}

double pop()
{
  if (!top)
    stop("Pilha vazia\n");
  return stack[--top];
}

double calculate(char *s)
{
    double a, b;
    int i;
    char *ch, *separator = " \t\n\r\f";
    //strtok quebra a string de acordo com a variavel separator
    for (s = strtok(s, separator); s; s = strtok(0, separator)) {
      a = strtod(s, &ch);
      if (ch > s)
        push(a);
    #define operate(x)  b = pop(), a = pop(), push(x)
    else
      if (*s == '+')
        operate(a + b);
    else
      if (*s == '-')
        operate(a - b);
    else
      if (*s == '*')
        operate(a * b);
    else
      if (*s == '/')
        operate(a / b);
		// else if (*s == '^')	operate(pow(a, b));
    #undef operate
    else {
      printf("'%c': ", *s);
      stop("Operação desconhecida\n");
    }
}

	return pop();
}

int main(void)
{
    char s[50];
    printf("Digite a expressao separando os digitos com espaco: ");
    scanf("%99[^\n]", &s);
    printf("Resultado da operação : %g\n", calculate(s));
    return 0;
}
