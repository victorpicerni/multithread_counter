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


pthread_mutex_t trava;
int palavra;
int total_palavras;

int num;
char c;

int pare = 0;
int resultado = 0;

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
int* N = (int*)arg;
*N = 60;
while (pare !=1) {

  pthread_mutex_lock(&trava);
  
  if (palavra==total_palavras) {

    pare = 1;

    }

  resultado+= primo(mem_compartilhada[palavra]);
  palavra++;

  pthread_mutex_unlock(&trava);

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

  pthread_t threads[MAX_THREADS];
  int thread_args[MAX_THREADS];

  for (int i = 0; i < MAX_THREADS; i++) {
    thread_args[i] = i;
    pthread_create(&(threads[i]), NULL, funcao_thread, &(thread_args[i]));
  }

/* Esperando threads terminarem! */
     for (int i = 0; i < MAX_THREADS; i++) {
     pthread_join(threads[i],NULL);

}
  printf("%d\n", resultado);
  return 0;


}
