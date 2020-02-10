/*************************************************************************
    > File Name: main.c
# File Name: main.c
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月21日 星期二 19时07分41秒
 ************************************************************************/

#include <stdio.h>
#include "seqlist.h"
bool condition_remove(data_t data){
	if(data == 50) return true;
}
void condition_modify(data_t* data){
	if(*data == 3) *data = 30;
}

int main(int argc, char *argv[])
{
	Seqlist *seq = seqlist_create();
	if(seq == NULL){
		printf("seq create fail\n");
	}else{
		if(seqlist_is_empty(seq) == true){
			printf("seq is empty\n");
		}
		int i=0;
		while(i<10){
			seqlist_insert(seq, i, i);
			i++;
		}
		seqlist_print(seq);
		seqlist_insert(seq, 5, 50);
		seqlist_print(seq);
		printf("index-3:%d\n",seqlist_getvalue_byindex(seq, 3));
		seqlist_remove_byindex(seq, 1);
		seqlist_print(seq);
		seqlist_remove_bycondition(seq, condition_remove);
		seqlist_print(seq);

		seqlist_traverse(seq, condition_modify);
		seqlist_print(seq);
		seqlist_modify_byindex(seq, 0, -1);
		seqlist_print(seq);
	}
	return 0;
}
