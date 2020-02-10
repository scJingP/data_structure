/*************************************************************************
    > File Name: sequeue.c
# File Name: sequeue.c
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月24日 星期五 10时14分42秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"sequeue.h"

//创建队列
Sequeue* sequeue_create(){
	Sequeue *que = (Sequeue *)malloc(sizeof(Sequeue));
	if(NULL == que){
		return NULL;
	}
	memset(que->data, 0, sizeof(que->data));
	que->front = que->rear = 0;
	return que;
}
//判断队列是否为空
bool sequeue_is_empty(Sequeue *seq){
	if(NULL == seq){
		return false;
	}
	return seq->front == seq->rear ? true : false;
}
//判断队列是否为满
bool sequeue_is_full(Sequeue *seq){
	if(NULL == seq){
		return false;
	}
	return (seq->rear+1)%SIZE == seq->front ? true : false;
}
//入对
bool sequeue_enqueue(Sequeue *seq, data_t data){
	if(NULL == seq){
		return false;
	}
	if(sequeue_is_full(seq) == true){
		return false;
	}
	seq->data[seq->rear] = data;
	seq->rear = (seq->rear + 1) % SIZE;
	return true;
}
//出对
bool sequeue_dequeue(Sequeue *seq, data_t* data){
	if(NULL == seq){
		return false;
	}
	if(sequeue_is_empty(seq) == true){
		return false;
	}
	*data = seq->data[seq->front];
	seq->front = (seq->front+1)%SIZE;
	return true;
}
//打印队列元素，从对首到对尾
void sequeue_print(Sequeue *seq){
	if(NULL == seq){
		printf("seq is null\n");
		return ;
	}
	if(sequeue_is_empty(seq) == true){
		printf("seq is empty\n");
		return ;
	}
	int i=seq->front;
	while(i != seq->rear){
		printf("%d ", seq->data[i]);
		i = (i+1)%SIZE;
	}
	printf("\n");
}
//获取对的元素

