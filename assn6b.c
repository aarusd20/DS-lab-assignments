#include<stdio.h>
#include<string.h>
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
    char in[100],out[100],rev[100];
    int i,j=0,n;

    scanf("%s",in);
    n=strlen(in);

    for(i=0;i<n;i++){
        if(in[i]=='(') rev[n-i-1]=')';
        else if(in[i]==')') rev[n-i-1]='(';
        else rev[n-i-1]=in[i];
    }
    rev[n]='\0';

    for(i=0;i<n;i++){
        if(isalnum(rev[i]))
            out[j++]=rev[i];
        else if(rev[i]=='(')
            push(rev[i]);
        else if(rev[i]==')'){
            while(s[top]!='(') out[j++]=pop();
            pop();
        }
        else{
            while(top!=-1 && priority(s[top])>priority(rev[i]))
                out[j++]=pop();
            push(rev[i]);
        }
    }

    while(top!=-1) out[j++]=pop();
    out[j]='\0';

    for(i=n-1;i>=0;i--)
        printf("%c",out[i]);
}