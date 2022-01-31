#include<stdio.h>
#include<stdlib.h>

struct address   
{  
    char city[20];  
    int pin;  
    char phone[14];  
};  
typedef struct address ad;
struct employee  
{  
    char name[20];  
    struct address add;  
};  
typedef struct employee emp;

emp* insert(emp* t,int *n){
    scanf("%d",n);
    t=(emp*)malloc((*n)*(sizeof(emp)));
    for(int i=0;i<(*n);i++)
{
    scanf("%s %s %d %s",(t[i].name),t[i].add.city,&(t[i].add.pin),(t[i].add.phone));
}
    return t;
    
}
void display(emp* t,int n){
    // scanf("%d",n);
    // t=(emp*)malloc((*n)*(sizeof(emp));
    for(int i=0;i<(n);i++)
{
    printf("%s %s %d %s",(t[i].name),t[i].add.city,(t[i].add.pin),(t[i].add.phone));
    printf("\n");
}
    
    
}


int main()
{
 //   emp* t=0;
 emp* t=0;
    int n=0;
    t=insert(t,&n);
    display(t,n);
   

return 0;
}