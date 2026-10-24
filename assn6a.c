#include<stdio.h>
#include<ctype.h>

char s[100];
int top=-1;

void push(char x){ s[++top]=x; }
char pop(){ return s[top--]; }

int priority(char x){
    if(x=='+'||x=='-') return 1;
    if(x=='*'||x=='/') return 2;
    if(x=='^') return 3;
    return 0;
}

int main(){
    char in[100],out[100];
    int i,j=0;
    scanf("%s",in);

    for(i=0;in[i];i++){
        if(isalnum(in[i]))
            out[j++]=in[i];
        else if(in[i]=='(')
            push(in[i]);
        else if(in[i]==')'){
            while(s[top]!='(') out[j++]=pop();
            pop();
        }
        else{
            while(top!=-1 && priority(s[top])>=priority(in[i]))
                out[j++]=pop();
            push(in[i]);
        }
    }

    while(top!=-1) out[j++]=pop();
    out[j]='\0';

    printf("%s",out);
}