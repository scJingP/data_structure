/*************************************************************************
    > File Name: main.c
# File Name: main.c
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月23日 星期四 19时06分40秒
 ************************************************************************/

#include<stdio.h>
#include"seqstack.h"
int main(int argc, char *argv[])
{
	Seqstack *stack = seqstack_create();
	if(NULL == stack){
		printf("stack create fail\n");
		return -1;
	}
	int i=0;
	while(i<12){
		seqstack_push(stack, i);
		i++;
	}
	seqstack_print(stack);

	i=0;
	data_t data;
	bool res = false;
	while(i<12){
		res = seqstack_pop(stack, &data);
		if(true == res){
			printf("%d\n", data);
		}
		i++;
	}
	seqstack_print(stack);
}
