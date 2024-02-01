#include <stdio.h>  
#include <stdlib.h>
#include <signal.h>  
#include <time.h>



void signal_handle(int sig_num)  
{  
    if(sig_num == SIGUSR1)  
    {  
        printf("Capture SIGUSR1\n");  
    }  
    printf("signal_handle running ...\n");  
}  

int main(int argc,char **argv)  
{  
    signal(SIGUSR1, signal_handle);  
    while(1)   
    {  
        sleep(100);  
    }  
    return 0 ;  
}
