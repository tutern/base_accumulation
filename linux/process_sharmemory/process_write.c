#include "comm.h"

#include <unistd.h> //add for sleep
#include<stdlib.h> //add for system("XXXX")

int main()
{
    int shmid=CreatShmid(4097);

    system("ipcs -a");
    if(shmid>0)
    {
        int i=0;
        char *addr=shmat(shmid,NULL,0);
        while(i<20)
        {
            addr[i++]='A';
            addr[i]='\0';
            sleep(1);
        }
        if(shmdt(addr)==-1)
        {
            perror("shmat failed!");
            return -3;
        }

    }
    else
    {
        perror("CreatShmid error: ");
        //return -1;
    }


    if(Destory(shmid)<0)
    {
        perror("Destory error:");
        return -2;
    }
    return 0;
}
