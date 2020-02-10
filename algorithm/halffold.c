/*************************************************************************
    > File Name: halffold.c
# File Name: halffold.c
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月27日 星期一 16时35分32秒
 ************************************************************************/

#include<stdio.h>

int halffold(int *a, int len, int val){
	if(len <= 0){
		return -1;
	}
	int low,high,mid;
	low=0;
	high=len-1;
	mid=(low+high)/2;
	while(low <= high){
		if(val == a[mid]) 
			return mid;
		else if(val > a[mid])
			low = mid+1;
		else if(val < a[mid])
			high = mid-1;
		mid = (low+high)/2;
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int a[] = {3, 12, 18, 20, 32, 55, 60, 68, 80, 86, 90, 100};
	int len = sizeof(a) / sizeof(a[0]);
	int val = 80;
	int pos = halffold(a, len, val);
	if(-1 == pos){
		printf("no find %d\n", val);
		return -1;
	}
	printf("pos:%d, val:%d\n", pos, a[pos]);
	return 0;
}
