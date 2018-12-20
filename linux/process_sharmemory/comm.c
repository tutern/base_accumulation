#include "comm.h"

static int commShmid(int size,int flag)
{
		//printf("%s %d ...\n", __FUNCTION__, __LINE__);
    key_t key=ftok(PATHNAME,PROJ_ID);

    if(key>0)
    {
      return shmget(key,size,flag);
    }
    else
    {
        perror("ftok error:");
        return -1;
    }
}

int CreatShmid(int size)
{
    //return commShmid(size,IPC_CREAT|IPC_EXCL|0666);
    return commShmid(size,IPC_CREAT|0666);
}

int GetShmid(int size)
{
    return commShmid(size,IPC_CREAT|0666);
}

int Destory(int shmid)
{
    return shmctl(shmid,IPC_RMID,0);
}

