#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM 6

void *thread_function(void *arg);

int main()
{
    int res;
    pthread_t a_thread[NUM];
    void *thread_result;
    uintptr_t index;

    srand(time(NULL));
    for (index = 0; index < NUM; ++index)
    {
        // 请添加代码，创建多个线程，线程的函数体为thread_function，index为线程下标序号
        res = pthread_create(&a_thread[index], NULL, thread_function, (void *)index);
        if (res != 0)
        {
            perror("Thread create failed!");
            exit(EXIT_FAILURE);
        }
        sleep(1);
    }

    printf("Waiting for threads to finished...\n");
    for (index = NUM - 1; index >= 0; --index)
    {
        // 请添加代码，等待所有线程结束
        res = pthread_join(a_thread[index], &thread_result);
        if (res == 0)
        {
            printf("Picked up a thread:%d\n", index + 1);
        }
        else
        {
            perror("pthread_join failed\n");
        }
        if (index == 0) {
            break;
        }
    }
    printf("All done\n");
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
    uintptr_t my_number = (uintptr_t)arg;
    int rand_num;

    printf("thread_function is running. Argument was %d\n", my_number);
    // 请添加代码，设置线程随机睡眠时间rand_num
    rand_num = rand() % NUM  + 1;
    sleep(rand_num);
    printf("Bye from %d\n", my_number);
    pthread_exit(NULL);
}
