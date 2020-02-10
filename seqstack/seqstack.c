/*************************************************************************
    > File Name: seqstack.c
# File Name: seqstack.c
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月23日 星期四 14时36分25秒
 ************************************************************************/

#include<stdlib.h>
#include<string.h>
#include"seqstack.h"
//创建栈
Seqstack * seqstack_create(){
	Seqstack *stack = (Seqstack *)malloc(sizeof(Seqstack));
	if(NULL == stack){
		return NULL;
	}
	memset(stack->data, 0, sizeof(stack->data));
	stack->top = -1;
	return stack;
}
//判断栈空
bool seqstack_is_empty(Seqstack *stack){
	if(NULL == stack){
		return true;
	}
	return stack->top == -1 ? true : false;
}
//判断栈满
bool seqstack_is_full(Seqstack *stack){
	if(NULL == stack){
		return false;
	}
	return stack->top == SIZE-1 ? true : false;
}
//获取栈元素长度
int seqstack_length(Seqstack *stack){
	if(NULL == stack){
		return -1;
	}
	return stack->top+1;
}
//入栈
bool seqstack_push(Seqstack *stack, data_t data){
	if(NULL == stack){
		return false;
	}
	if(seqstack_is_full(stack) == true){
		return false;
	}
	stack->data[++stack->top] = data;
	return true;
}
//出栈
bool seqstack_pop(Seqstack *stack, data_t *data){
	if(NULL == stack){
		return false;
	}
	if(seqstack_is_empty(stack) == true){
		return false;
	}
	*data = stack->data[stack->top--];
	return true;
}
//获取栈顶元素
bool seqstack_get(Seqstack *stack, data_t *data){
	if(NULL == stack){
		return false;
	}
	*data = stack->data[stack->top];
	return true;
}
//打印栈元素，从栈底到栈顶
void seqstack_print(Seqstack *stack){
	if(NULL == stack){
		return ;
	}
	int i=0;
	for(i=0;i<=stack->top;i++){
		printf("%d ", stack->data[i]);
	}
	printf("\n");
}

