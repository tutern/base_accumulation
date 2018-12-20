#touch shm.txt
#chmod 777 shm.txt

gcc -E comm.c -o c.i
gcc -S c.i -o c.s
gcc -c c.s -o c.o

gcc -E process_write.c -o w.i
gcc -S w.i -o w.s
gcc -c w.s -o w.o

gcc c.o w.o -o w.out

gcc -E process_read.c -o r.i
gcc -S r.i -o r.s
gcc -c r.s -o r.o

gcc c.o r.o -o r.out


./w.out
./r.out


#print log

#A
#AA
#AAA
#AAAA
#.......

##ipcs -a  查看 ipcs 相关信息
#ipcsrm -m pid  删除一个正在运行的进程 不知道可以用 ps -ef 查看 pid
