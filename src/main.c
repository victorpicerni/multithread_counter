/* multithread_counter
 * Victor Hugo Picerni 
 * RA 187930
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 4

/*Definindo variáveis globais*/
pthread_mutex_t trava;
int palavra;
int total_palavras;
int num;
char c;

/*definindo variaveis compartilhadas*/
int pare = 0;
int resultado = 0;

/*definindo tamanho do vetor como 100*/
int mem_compartilhada[100];

/*definindo a função para identificar numeros primos*/
unsigned long int primo(unsigned long int num){
  if (num == 1 || num == 0)
    return 0;
  for (unsigned long int i = 2 ; i < num ; i++){
    if (num%i == 0){
    return 0;
  }
 }
return 1;
}

/*Definindo a função do thread*/

void* funcao_thread(void *arg) {

/*enquanto a variavel compartilhada de parada for diferente de 1, o thread continua rodando*/
while (pare !=1) {

  pthread_mutex_lock(&trava);/*esperar cada thread rodar, para não ter conflito nas variáveis*/
  
  if (palavra==total_palavras) {

    pare = 1; /*quando ler todas as palavras, a variavel de parada é setada*/

    }

  resultado+= primo(mem_compartilhada[palavra]); /*identifica e soma os primos*/
  palavra++;

  pthread_mutex_unlock(&trava);/*libera para o proximo thread*/

  }

  return NULL;
}

int main (int argc, char **argv) {

/*Definindo o vetor de entrada dos números*/
  do 
  {
  scanf("%d", &num);
  mem_compartilhada[total_palavras] = num;
  total_palavras++;
  } while (c = getchar() != '\n');

/*definindo a quantidade de threads que irão iniciar*/
  pthread_t threads[MAX_THREADS];
  int thread_args[MAX_THREADS];

/*iniciando cada thread de acordo com a quantidade de numeros a serem apresentados*/
  for (int i = 0; i < MAX_THREADS; i++ && i <= total_palavras) {
    thread_args[i] = i;
    pthread_create(&(threads[i]), NULL, funcao_thread, &(thread_args[i])); /*criando os threads*/
  }

/* Esperando threads terminarem! */
     for (int i = 0; i < MAX_THREADS; i++) {
     pthread_join(threads[i],NULL);

} 
/*finalizando*/
  printf("%d\n", resultado);
  return 0;


}
