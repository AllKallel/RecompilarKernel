// Exemplo pratico disciplina de sistemas operacionais
// Professor Diego Nunes Molinos
// Objetivo:
//	   - Introduzir os conceitos de threads na pratica;
//	   - Observar o comportamento das threads;
//	   - Reforcar o conceito de enderecamento de processo e threads;
//         - Verificar tempo de execucao atraves da funcao time;


//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message_function(void *ptr);

main()
{
    pthread_t thread1, thread2; //declaração dos descritores - criação das threads
    const char *message1 = "Thread 1";
    const char *message2 = "Thread 2";
    int iret1, iret2;
    
    iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
    if(iret1)
    {
	fprintf(stderr, "Error - pthread_create() return code? %d\n",iret1);
	exit(EXIT_FAILURE);
    }
    
    iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);
    {
	fprintf(stderr, "Error - Pthread_create() return code? %d\n", iret2);
	exit(EXIT_FAILURE);
	
    }
    
    printf("pthread_create() for thread 1 returns: %d\n", iret1);
    printf("pthread_create() for thread 1 returns: %d\n", iret2);
    
    
    pthread_join( thread1, NULL); //controla a execução das threads
    pthread_join( thread2, NULL); //controla a execução das threads
    
    exit(EXIT_SUCCESS);
    
}

void *print_message_functional( void *ptr)
{
    char *message;
    message = (char *) ptr;
    printf("%s \n", message);
}    
	
	
    	
