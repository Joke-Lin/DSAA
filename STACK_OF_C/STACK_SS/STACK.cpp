#include<stdio.h>
#include<stdlib.h>

#define max 100

typedef struct
{
	int number[max];
	int top;
}stack;

int push(stack *p,int n)
{
	if(p->top==max-1)
	{
		printf("the stack is full\n");
		return false;
	}
	else
	{
		p->number[p->top] = n;
		p->top++;
		printf("push the %d successfully top is %d\n",n,p->top);
		return true;
	}
}

int pop(stack *p,int n)
{
	if(p->top==0)
	{
		printf("the stack is empty now\n");
	}
	else
	{
		for(int i = p->top-1;i>=p->top-n;i--)
		{
			printf("pop the %d successfully\n",p->number[i]);
		}
		printf("the rest is %d\n",p->top-n);
		p->top -= n;
	}
}

void show(stack *p)
{
	if(p->top==0)
	{
		printf("the stack is empty now\n");
		return;
	}
	else
	{
		printf("top is %d\n",p->top);
		for(int i = 0;i < p->top;i++)
		{
			printf("%d ",p->number[i]);
		}
		printf("\n");
		return;
	}
}

int main()
{
	stack *p = (stack*)malloc(sizeof(stack));
	p->top = 0;
	printf("1 push\n2 pop\n0 break\n3 show all\n");
    char c;
	while((c = getchar())!='0')
	switch(c)
	{
		case '1':
			int number;
			printf("how many and what do you want to push\n");
			scanf("%d",&number);
			printf("what do you want to push\n");
			for(int i = 0;i<number;i++)
			{
				int n;
				scanf("%d",&n);
				push(p,n);
			}
			break;
		case '2':
			int a;
			scanf("%d",&a);
			pop(p,a);
			break;
		case '3':
			show(p);
			break;
	}
	return 0; 
} 
