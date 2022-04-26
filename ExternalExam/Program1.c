#include <stdio.h>
#include <string.h>
int top = -1, top1 = -1;
#define MAX 100
char str[MAX];
char arr[MAX];
char rev[MAX];
int flag = 0;
int l, i;
void push(char c)
{
	top++;
	if (top == MAX)
		printf("Stack full");
	else
		arr[top] = c;
}
void push1(char d)
{
	top1++;
	if (top1 == MAX)
		printf("Stack full");
	else
		rev[top1] = d;
}
char pop()
{
	return arr[top--];
}
char pop1()
{
	return rev[top1--];
}
void isPalindrome(int m)
{
	for (i = 0; i < m; i++)
	{
		char e = pop();
		char f = pop1();
		if (e == f)
			flag = 1;
		else
		{
			flag = 0;
			break;
		}
	}

	if (flag == 1)
		printf("Palindrome\n");
	else
		printf("Not Palindrome\n");
}
int main()
{
	printf("Enter the string : ");
	scanf("%[^\n]", str);
	l = strlen(str);
	for (i = 0; i < l; i++)
		push(str[i]);
	for (i = l - 1; i >= 0; i--)
		push1(str[i]);
	isPalindrome(l);
	return 0;
}