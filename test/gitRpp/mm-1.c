#include<time.h>
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
void opration(void);
char symbol(int i);//����
float add(float a,float b), subtraction(float a,float b),multiplication(float a,float b),division(float a,float b);//�Ӽ��˳�
float calculate(int i,float a,float b);//����
int f = 0;//��¼����
double correct;//��ȷ��

int fangfa()
{
	float answer1;//��1
	float x,y,z;//����������
	int a,b,c;//������3�������
	int o,t;//one����� two�����
	char q1,q2;
	srand((unsigned)time(NULL));//ָ��
	do{
		a=rand()%100;//����100���ڵ������
		b=rand()%100;
		c=rand()%100;
		o=rand()%4;//������������
		t=rand()%4;//0��1��3��4��
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
	q1=symbol(o);//����1
	q2=symbol(t);//����2
	printf("%d %c %d %c %d = ",a,q1,b,q2,c);//�����Ŀ
	scanf("%f",&answer1);
	if(o==3&&t==3)
	{
		if((answer1-x)<0.01)
		{
			printf("��������ش���ȷ�ޣ�\n");
		}
		else
		{
			f++;
			printf("������˼����Ĵ��Ǵ��\n");
			printf("��ȷ���ǣ�%.1f\n",x);
		}
	}
	else
	{
		if((x-answer1)<0.01)
		{
			printf("����ˣ��������\n");
		}
		else
		{
			f++;
			printf("������˼����Ĵ��Ǵ��\n");
			printf("��ȷ���ǣ�%.1f\n",x);
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
	printf("*�����������Ŀ�ĸ�����");
	scanf("%d",&n);
	do{
		fangfa();
		i++;
	}while(i<n);
		printf("�����ȷ��Ϊ%.1lf%%\n",1.0*(n-f) / n * 100);
	system("pause");
}