/*************************************************************************
    > File Name: main.c
# File Name: main.c
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月27日 星期一 10时27分42秒
 ************************************************************************/

#include<stdio.h>
#include"sequeue.h"
int main(int argc, char *argv[])
{
	Sequeue *seq = sequeue_create();
	if(NULL == seq){
		printf("seq create fail\n");
		return -1;
	}
	int i=0;
	while(i++<10){
		sequeue_enqueue(seq, i);
	}
	sequeue_print(seq);
	i=0;
	data_t data = 0;
	while(i++<5){
		bool res = sequeue_dequeue(seq, &data);
		if(true == res){
			printf("dequeue %d\n", data);
		}
	}
	printf("\n");
	sequeue_print(seq);
}
