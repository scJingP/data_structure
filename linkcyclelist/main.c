/*************************************************************************
    > File Name: main.c
# File Name: main.c
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月22日 星期三 10时48分45秒
 ************************************************************************/

#include<stdio.h>
#include"linklist.h"

int main(int argc, char *argv[])
{
	Linklist *link = linklist_create();
	int len = linklist_get_length(link);
	printf("len:%d\n", len);
	int i=0;
	while(i<10){
		linklist_insert(link, i, i);
		i++;
	}
	linklist_print(link);

	linklist_delete_byindex(link, 2);
	linklist_print(link);
	linklist_insert(link, 2, 1);
	linklist_print(link);
	linklist_delete_byvalue(link, 1);
	linklist_print(link);
	linklist_modify_byindex(link, 0, 8);
	linklist_print(link);
	linklist_modify_byvalue(link, 8, 88);
	linklist_print(link);
	int pos = 0,value = 0;
	pos = 1;
	Linklist *retnode = NULL;
	bool res = linklist_find_byindex(link, pos, &retnode);
	if(true == res){
		printf("pos:%d,value:%d\n", pos, retnode->data);
	}
	value = 88;
	res = linklist_find_byvalue(link, 88, &retnode, &pos);
	if(true == res){
		printf("value:%d, pos:%d\n", value, pos);
	}
	linklist_clear(link);
	len = linklist_get_length(link);
	printf("len:%d\n", len);
	
	linklist_destroy(&link);
	if(NULL == link){
		printf("link is already destroy\n");
	}
	return 0;
}
