/*************************************************************************
    > File Name: seqstack.h
# File Name: seqstack.h
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月23日 星期四 19时09分32秒
 ************************************************************************/

#include<stdio.h>

#define SIZE 10
typedef enum bool {false = 0, true = 1} bool;
typedef int data_t;
typedef struct seqstack{
	data_t data[SIZE];
	int top;
}Seqstack;
//创建栈
Seqstack * seqstack_create();
//判断栈空
bool seqstack_is_empty(Seqstack *stack);
//判断栈满
bool seqstack_is_full(Seqstack *stack);
//获取栈元素长度
int seqstack_length(Seqstack *stack);
//入栈
bool seqstack_push(Seqstack *stack, data_t data);
//出栈
bool seqstack_pop(Seqstack *stack, data_t *data);
//获取栈顶元素
bool seqstack_get(Seqstack *stack, data_t *data);
//打印栈元素，从栈底到栈顶
void seqstack_print(Seqstack *stack);
