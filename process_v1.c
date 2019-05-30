// Exemplo pratico disciplina de sistemas operacionais
// Professor Diego Nunes Molinos
// Objetivo:
//	   - Introduzir os conceitos de processos na pratica;
//	   - Observar o comportamento dos processos pai e filho;
//	   - Reforcar o conceito de enderecamento de processo;
//         - Verificar tempo de execucao atraves da funcao time;		


//Biblioteca necessarias para trabalhar com processos e execucao de programas
//externos
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
    pid_t pid, tmp;
    int status;
    
    pid=fork(); //fork() chamada de sistema que permite a criacao deum processo
    
    if(pid == 0) //verifica se o processo foi criado com sucesso
    {
	printf("Processo Filho: PID=%d, %d\n", getpid(),pid); //imprime o PID do processo
	sleep(5); //funcao SLEEP - processo vai para o estado sleep
	execl("/bin/ls","ls","ls",NULL); // funcao que executa um programa externo
	
    
    }else
    if (pid > 0)
    {
	printf("Processo Pai: PID=%d, %d\n", getpid(), pid); // imprime o processo pai
	tmp=wait(&status); // coloca o processo na condicao de wait
	printf("Processo Filho (%d) terminou\n", tmp); //imprime
	printf("Processo Pai terminou\n");
	
    }
    //exit(1);
    getchar();
}