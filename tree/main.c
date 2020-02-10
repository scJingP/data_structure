/*************************************************************************
    > File Name: main.c
# File Name: main.c
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月27日 星期一 10时40分52秒
 ************************************************************************/

#include<stdio.h>

#include"tree.h"
#include"sequeue.h"
int main(int argc, char *argv[])
{
	Tree *root = tree_create(1, 10);
	if(NULL == root){
		printf("tree create fail\n");
	}
	tree_dlr(root);
	printf("\n");
	tree_ldr(root);
	printf("\n");
	tree_lrd(root);
	printf("\n");
	//层次遍历
	printf("层次遍历：\n");
	tree_level(root);
	printf("\n");
	return 0;
}
