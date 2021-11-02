#include <stdio.h>

int MaxConsequnceSum(int arr[],int n);
/*
给定以序列数：序列{ -2, 11, -4, 13, -5, -2 } ，求其最大之列和 
连续子列{ 11, -4, 13 }有最大的和20；
思路：
用一个数组存储该序列，用2个for循环，第一个for循环用于确定一个子列的最左边的元素，第2个for循环用于从确定的元素开始
向右进行遍历，找到以该元素确定的子列最大的序列和，如何找到呢，只需要定义2个变量，一个变量用于进行累加操作，另一个
变量记录最大子列和 
设计：
1.
int MaxConsequnceSum(int arr[],int n)//传入一个数组，以及数组的大小 
1-1：

int maxSum = 0;//记录最大子列和	 
for(int i = 0; i < n; i++){
    int sum = 0;//用于进行累加操作
    for(int j = i; j < n; j++){
         sum += arr[j];
		 if(sum > maxSum)
		 		maxSum = sum; 
	}
}
return maxSum; 
*/
int main(void) {
	int k;
	scanf("%d", &k);
	int arr[k];
	for(int i = 0; i < k; i++){
		scanf("%d",&arr[i]);
	}
	
//	int arr[] = { -2, 11, -4, 13, -5, -2 };
	int maxSum = MaxConsequnceSum(arr,k);
	printf("%d\n",maxSum);
	return 0;
}
int MaxConsequnceSum(int arr[],int n) {	
	int flag = 0;//判断是否全为负数，全为负数，直接返回0 
	for(int z = 0; z < n; z++) {
		if(arr[z] > 0){
			flag = 0;	  
			break;
		}else {
			flag = 1;
		} 
	}
	if(flag == 1) {//判断是否全为负数，全为负数，直接返回0
		return 0; 
	}
	
	int maxSum = 0;//记录最大子列和	 
	for(int i = 0; i < n; i++){
		int sum = 0;//用于进行累加操作
		for(int j = i; j < n; j++){
		     sum += arr[j];
			 if(sum > maxSum)
	 		 		maxSum = sum; 
		}
	}
	return maxSum; 
}
