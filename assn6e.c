#include<stdio.h>
#include<string.h>
#include<ctype.h>

char s[100][100];
int top=-1;

void push(char *x){ strcpy(s[++top],x); }
char* pop(){ return s[top--]; }

int main(){
    char exp[100],a[100],b[100],temp[100];
    int i;

    scanf("%s",exp);

    for(i=0;exp[i];i++){
        if(isalnum(exp[i])){
            temp[0]=exp[i];
            temp[1]='\0';
            push(temp);
        }
        else{
            strcpy(b,pop());
            strcpy(a,pop());

            sprintf(temp,"(%s%c%s)",a,exp[i],b);
            push(temp);
        }
    }

    printf("%s",pop());
}