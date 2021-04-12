#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
 
struct Child {
    long long val;   
    struct Child *next;
};
 
struct Child *c;
long long n;
 
void InitChild(struct Child **Top){
    struct Child *p;    
    p=(struct Child *) malloc(sizeof(struct Child));
    p->val=1;
    p->next=NULL;
    *Top=p;
    
    for(long long i=2;i<=n;i++)
    {           
        p->next=(struct Child *) malloc(sizeof(struct Child));
        p=p->next;
        p->val=i;
    };
    p->next=*Top;   
}
 
long long DelChild(struct Child **curr){
    struct Child *tmp,*p;
    long long d;
    p=*curr;
    tmp=p->next;
    p->next=tmp->next;
    p=p->next;
    d=tmp->val;
    *curr=p;
    free(tmp);  
    return d;
 
}
int main(){ 
    long long q,k;
    struct Child *Top;
    
    c=NULL;
    scanf("%ld",&n);
    InitChild(&Top);
 
    for(k=0;k<n;k++)
        printf("%d ", DelChild(&Top));      
 
    system("pause"); 
    return 0;
}
