
/* fork() -> Llamada de sistema que crea un proceso, el proceso hijo es una copia del proceso padre solo
que cada uno tiene su PID (proceso ID) y su PPID (parent process ID)*/
// fork() en C al final es una funcion y devuelve un int
// devuelve -1  -> Hubo un error en la creacion del proceso
//si devuelve 0  -> Es pq se creo el proceso hijo
// si devuelve 1+ -> Es pq es el ID del proceso padre
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
    time_t currentTime;  
    time(&currentTime);
    int fork_result;   
    printf("Bienvenido al programa\n\n");
    printf("%-20s %-8s %-8s %10s\n", "Process Type", "PID", "PPID", "Time");
    printf("%-20s %-8d %-8d %10s", "System Proccess", getpid() , getppid(), ctime(&currentTime));   
    
    for(int i=0; i<3; i++)
    {
         fork_result = fork();
         if(fork_result==0)
            { 
                printf("%-20s %-8d %-8d %10s", "System Proccess", getpid() , getppid(), ctime(&currentTime)); 
            }   
    }
        
}