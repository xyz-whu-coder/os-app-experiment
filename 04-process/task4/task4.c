#include "stdio.h"
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int count = 1;
    int child;
    // 请添加代码，创建子进程
    child = vfork();
    if (child == 0)
    {
        // 子进程
        int i;
        for (i = 0; i < 20; i++)
        {
            // 请添加代码，输出子进程的pid和自加变量i的值
            printf("This is son, his count is: %d. and his pid is: %d\n", i, getpid());
        }
        exit(0);
    }
    else
    {
        // 父进程
        printf("This is father, his count is: %d, his pid is: %d\n", count, getpid());
    }
}
