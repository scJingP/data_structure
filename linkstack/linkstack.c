/*************************************************************************
    > File Name: linkstack.c
# File Name: linkstack.c
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月23日 星期四 15时30分00秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"linkstack.h"

//创建栈
Linkstack * linkstack_create(){
	Linkstack *top = (Linkstack *)malloc(sizeof(Linkstack));
	if(NULL == top){
		return NULL;
	}
	top->data = -1;
	top->next = NULL;
	return top;
}
//判断栈空
bool linkstack_is_empty(Linkstack *top){
	if(NULL == top){
		return false;
	}
	return top->next == NULL ? true : false;
}
//获取栈元素个数
int linkstack_length(Linkstack *top){
	if(NULL == top){
		return -1;
	}
	Linkstack *p = top->next;
	int len = 0;
	while(p != NULL){
		len++;
		p = p->next;
	}
	return len;
}
//入栈
bool linkstack_push(Linkstack *top, data_t data){
	if(NULL == top){
		return false;
	}
	Linkstack *new = (Linkstack *)malloc(sizeof(Linkstack));
	new->data = data;
	new->next = top->next;
	top->next = new;
	return true;
}
//出栈
bool linkstack_pop(Linkstack *top, data_t *data){
	if(NULL == top){
		return false;
	}
	if(linkstack_is_empty(top) == true){
		return false;
	}
	Linkstack *p = top->next;
	*data = p->data;
	top->next = p->next;
	free(p);
	p = NULL;
	return true;
}
//获取栈顶元素
bool linkstack_get(Linkstack *top, data_t *data){
	if(NULL == top){
		return false;
	}
	if(linkstack_is_empty(top) == true){
		return false;
	}
	*data = top->next->data;
	return true;
}
//打印栈元素,从栈顶到栈底
void linkstack_print(Linkstack *top){
	if(NULL == top){
		return;
	}
	Linkstack *p = top->next;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
