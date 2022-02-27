#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int array[10];
	int top;
};

void push(struct stack *s, char ch)
{
	s->top++;
	s->array[s->top] = ch;
}

void pop(struct stack *s)
{
	s->top--;
}

void main()
{
	struct stack s;
	char exp[20];
	int i;
	
	s.top = -1;
	
	printf("Enter the expression : ");
	scanf("%s", exp);
	
	for( i = 0; exp[i] != '\0'; i++)
	{
		if(exp[i] == '(')
		{
			push(&s, exp[i]);
		}
		else
		{
			if(exp[i] == ')')
			{
				pop(&s);
			}
		}
	}
	if(s.top == -1)
	{
		printf("Expression is completely parenthesis\n");
	}
	else
	{
		printf("Expression is not parenthesis\n");
	}
}
