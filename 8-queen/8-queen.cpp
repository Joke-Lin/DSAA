//�˻ʺ�������һ�����϶����������⣬�ǻ����㷨�ĵ������⡣��
//������ʮ��������������ѧ�Ҹ�˹1850�������
//��8X8��Ĺ��������ϰڷŰ˸��ʺ�ʹ�䲻�ܻ��๥����
//�����������ʺ󶼲��ܴ���ͬһ�С�ͬһ�л�ͬһб��(�Խ���)�ϣ����ж����ְڷ���

#include<stdio.h>
#include<stdlib.h>

#define max 8

int queen[max],sum = 0;

void show()  //���queen 
{
	for(int i = 0;i < max;i++)
	{
		printf("(%d,%d)  ",i+1,queen[i]);
	}
	printf("\n");
	sum++;
}

int check(int n) //��鵱ǰ�ܷ���� 
{
	for(int i = 0;i < n;i++)
	{
		if(queen[i]==queen[n]||abs(queen[i]-queen[n])==(n-i))
		{
			return 0;
		}
	}	
	return 1;
}

void putqueen(int n)
{
	int N = n-1;
	for(int i = 1;i <= max;i++)
	{
		queen[N] = i;
		if(check(N))              //������Է��� 
		{
			if(n == max) show(); //�����˴�ӡ 
			else putqueen(n+1);  //û����ͷ���һ�� 
		}
	}
	return;
}

int main()
{
	putqueen(1);
	printf("the sum is %d",sum);
	return 0;
}
