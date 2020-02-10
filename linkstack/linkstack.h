/*************************************************************************
    > File Name: linkstack.h
# File Name: linkstack.h
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月23日 星期四 19时15分31秒
 ************************************************************************/

#include<stdio.h>
typedef enum bool {false = 0, true = 1} bool;
typedef int data_t;
typedef struct linkstack{
	data_t data;
	struct linkstack *next;
}Linkstack;
//创建栈
Linkstack * linkstack_create();
//判断栈空
bool linkstack_is_empty(Linkstack *top);
//获取栈元素个数
int linkstack_length(Linkstack *top);
//入栈
bool linkstack_push(Linkstack *top, data_t data);
//出栈
bool linkstack_pop(Linkstack *top, data_t *data);
//获取栈顶元素
bool linkstack_get(Linkstack *top, data_t *data);
//打印栈元素,从栈顶到栈底
void linkstack_print(Linkstack *top);
