#include "comm.h"
#include <unistd.h> //add for sleep
#include <errno.h> //add for errno

int main()
{

    int shmid=GetShmid(4097);

    if(shmid>0)
    {
        int i=0;
        char *addr=shmat(shmid,NULL,0);

        //printf("start 222... %p \n", addr);
        //printf("start 222... %d \n", errno);

        if(addr == NULL)
        {
        	printf("add is null return \n");
        	perror("shmat error:");
        	return -1;
        }

        while(i<20)
        {
            printf("%s\n",addr);
            sleep(1);
            i++;
        }
        if(shmdt(addr)==-1)
        {
            perror("shmdt:");
            //return-1;
        }
    }
    else
    {
        perror("GetShmid:");
      //return -2;
    }
    return 0;
}

