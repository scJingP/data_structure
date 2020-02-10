/*************************************************************************
    > File Name: sequeue.h
# File Name: sequeue.h
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月27日 星期一 10时29分16秒
 ************************************************************************/

#include<stdio.h>

typedef enum bool {false = 0, true = 1} bool;

#define SIZE 10
typedef int data_t;
typedef struct sequeue{
	data_t data[SIZE];
	int front;
	int rear;
}Sequeue;
//创建队列
Sequeue* sequeue_create();
//判断队列是否为空
bool sequeue_is_empty(Sequeue *seq);
//判断队列是否为满
bool sequeue_is_full(Sequeue *seq);
//入对
bool sequeue_enqueue(Sequeue *seq, data_t data);
//出对
bool sequeue_dequeue(Sequeue *seq, data_t* data);
//打印队列元素，从对首到对尾
void sequeue_print(Sequeue *seq);
