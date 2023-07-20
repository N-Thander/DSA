#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char st[10];
int top = -1;

char pop();
void push(char);
int prec(char);
void int2post(char[], char[]);



char pop()
{
    return(st[top --]);
}

void push(char ch)
{
    st[++top] = ch;
}

int prec(char ch)
{
    switch (ch)
    {
    case '/':
    case '*':
        return 5;
    case '+':
    case '-':
        return 4;
    case '(':
        return 3;   
    }
}


void in2post(char infix[], char postfix[])
{
    char ch, x;
    int i, j, l;

    push('(');
    l = strlen(infix);
    infix[l] = ')';
    j = 0;
    for (i = 0; i <= l; i++)
    {
        ch = infix[i];
        switch (ch)
        {
        case '^':
        case '(':
            push (ch);
            break;
        case '/':
        case '*':
        case '+':
        case '-':
            while (prec(ch) <= prec(st[top]))
            {
                postfix[j++] == x;
            }
            break;            
        default:
            postfix[j++] = ch;
        }
    }    

postfix[j] = '\0';

}


int main()
{
    char infix[10], postfix[10];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    int2post(infix, postfix);
    
    printf("\nThe postfix expression is %s \n", postfix);
    return 0;

}
