#include <stdio.h>
int max_num(int a,int b,int c)//返回3个数中的最大值
{
    int max;
    max = a;
    if(max<b)
        max = b;
    if(max<c)
        max = c;
    return max;
}
int max_subset(int A[],int left,int right)
{
    int mid,i;
    int max_left,max_right;//左半部分和右半部分最大值
    int max_left_border=0,max_right_border=0;//包括左边界和右边界的最大值
    int sum_left_border=0,sum_right_border=0;//包括左边界和右边界的值
    if(left==right){
        return A[left];
    }
    mid = (left+right)/2;
    max_left = max_subset(A,left,mid);
    max_right = max_subset(A,mid+1,right);
    for(i=mid;i>=left;i--){
        sum_left_border += A[i];
        if(sum_left_border>max_left_border){
            max_left_border = sum_left_border;
        }
    }
    for(i=mid+1;i<=right;i++){
        sum_right_border += A[i];
        if(sum_right_border>max_right_border){
            max_right_border = sum_right_border;
        }
    }
    return max_num(max_left,max_right,max_left_border+max_right_border);
}
int main()
{
    int A[] = {1,2,8,-3,-8,-2,6,10,5,-6};
    int max;
    max = max_subset(A,0,9);
    printf("%d ",max);
    return 0;
}