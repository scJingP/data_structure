/*************************************************************************
    > File Name: linkqueue.c
# File Name: linkqueue.c
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月24日 星期五 13时00分40秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef enum bool {false = 0, true = 1} bool;
typedef int data_t;
typedef struct linklist{
	data_t data;
	struct linklist *next;
}Linklist;
typedef struct linkqueue{
	Linklist *front;
	Linklist *rear;
}Linkqueue;

//创建链式队列
Linkqueue* linkqueue_create(){
	Linkqueue *que = (Linkqueue *)malloc(sizeof(Linkqueue));
	if(NULL == que){
		return NULL;
	}
	Linklist* head = (Linklist *)malloc(sizeof(Linklist));
	head->data = -1;
	head->next = NULL;
	que->front = que->rear = head;
	return que;
}
//判断队列是否为空
bool linkqueue_is_empty(Linkqueue *que){
	if(NULL == que || NULL == que->front || NULL == que->rear){
		return true;
	}
	return que->front == que->rear ? true : false;
}
//获取队列元素长度
int linkqueue_length(Linkqueue *que){
	if(NULL == que || NULL == que->front || NULL == que->rear){
		return -1;
	}
	int len=0;
	Linklist *p = que->front->next;
	while(p != NULL){
		len++;
		p = p->next;
	}
	return len;
}
//入对
bool linkqueue_enqueue(Linkqueue *que, data_t data){
	if(NULL == que || NULL == que->front || NULL == que->rear){
		return false;
	}
	Linklist *new = (Linklist *)malloc(sizeof(Linklist));
	new->data = data;
	new->next = NULL;
	if(NULL == new){
		return false;
	}
	que->rear->next = new;
	que->rear = new;
	return true;
}
//出对
bool linkqueue_dequeue(Linkqueue *que, data_t *data){
	if(NULL == que || NULL == que->front || NULL == que->rear){
		return false;
	}
	if(linkqueue_is_empty(que) == true){
		return false;
	}
	Linklist *head = que->front;
	Linklist *p1 = head->next;
	*data = head->next->data;
	head->next = head->next->next;
	free(p1);
	if(NULL == head->next){
		que->rear = que->front;
	}
	return true;
}
//获取对首元素
//清空队列
bool linkqueue_clear(Linkqueue *que){
	if(NULL == que || NULL == que->front || NULL == que->rear){
		return false;
	}
	if(linkqueue_is_empty(que) == true){
		return false;
	}
	Linklist *p = que->front->next;
	Linklist *p_next = NULL;
	while(p != NULL){
		p_next = p->next;
		free(p);
		p = p_next;
	}
	return true;
}
//销毁队列
//打印队列，从对首到对尾
void linkqueue_print(Linkqueue *que){
	if(NULL == que || NULL == que->front || NULL == que->rear){
		return ;
	}
	if(linkqueue_is_empty(que) == true){
		return ;
	}
	Linklist *p = que->front->next;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	Linkqueue *que = linkqueue_create();
	int i=0;
	while(i++<10){
		linkqueue_enqueue(que,i);
	}
	linkqueue_print(que);
	i=0;
	data_t data;
	bool res = false;
	while(i++<12){
		res = linkqueue_dequeue(que, &data);
		if(true == res){
			printf("%d\n", data);
		}
	}
	linkqueue_print(que);
}
