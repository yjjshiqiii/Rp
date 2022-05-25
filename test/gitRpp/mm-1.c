#include<time.h>
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
void opration(void);
char symbol(int i);//符号
float add(float a,float b), subtraction(float a,float b),multiplication(float a,float b),division(float a,float b);//加减乘除
float calculate(int i,float a,float b);//计算
int f = 0;//记录错题
double correct;//正确率

int fangfa()
{
	float answer1;//答案1
	float x,y,z;//计算的替代符
	int a,b,c;//产生的3个随机数
	int o,t;//one计算符 two计算符
	char q1,q2;
	srand((unsigned)time(NULL));//指针
	do{
		a=rand()%100;//产生100以内的随机数
		b=rand()%100;
		c=rand()%100;
		o=rand()%4;//运算符随机产生
		t=rand()%4;//0加1减3乘4除
		if(o>1){
			y=(float)a;
			z=(float)b;
			x=calculate(o,y,z);
			y=x;
			z=(float)c;
			x=calculate(t,y,z);
		}
		else
		{
			if(t<2)
			{
				y=(float)a;
			    z=(float)b;
			    x=calculate(o,y,z);
			    y=x;
			    z=(float)c;
			    x=calculate(t,y,z);
			}
			else
			{
				y=(float)b;
			    z=(float)c;
		    	x=calculate(o,y,z);
			    y=(float)a;
			    z=x;
		    	x=calculate(t,y,z);
			}
		}
	}while(x<0.0);
	q1=symbol(o);//符号1
	q2=symbol(t);//符号2
	printf("%d %c %d %c %d = ",a,q1,b,q2,c);//输出题目
	scanf("%f",&answer1);
	if(o==3&&t==3)
	{
		if((answer1-x)<0.01)
		{
			printf("你真棒，回答正确噢！\n");
		}
		else
		{
			f++;
			printf("不好意思，你的答案是错的\n");
			printf("正确答案是：%.1f\n",x);
		}
	}
	else
	{
		if((x-answer1)<0.01)
		{
			printf("答对了，你真棒！\n");
		}
		else
		{
			f++;
			printf("不好意思，你的答案是错的\n");
			printf("正确答案是：%.1f\n",x);
		}
	}
	return f;

}
float calculate(int i,float a,float b)
{
	float x;
	switch(i)
	{
	case 0:
		x=add(a,b);
		break;
	case 1:
		x=subtraction(a,b);
		break;
	case 2:
		x=multiplication(a,b);
		break;
	case 3:
		x=division(a,b);
		break;
	default:
		break;
	}
	return x;
}
float add(float a,float b)
{
	float x;
	x=a+b;
	return x;
}
float subtraction(float a,float b)
{
	float x;
	x=a-b;
	return x;
}
float multiplication(float a,float b)
{
	float x;
	x=a*b;
	return x;
}
float division(float a,float b)
{
	float x;
	x=a/b;
	return x;
}
char symbol(int i)
{
	char op;
	switch(i)
	{
	case 0:
		op='+';
		break;
	case 1:
		op='-';
		break;
	case 2:
		op='*';
		break;
	default:
		op='/';
		break;
	}
	return op;
}
int main()
{
   
	int n,i=0;
	printf("*请输入计算题目的个数：");
	scanf("%d",&n);
	do{
		fangfa();
		i++;
	}while(i<n);
		printf("你的正确率为%.1lf%%\n",1.0*(n-f) / n * 100);
	system("pause");
}