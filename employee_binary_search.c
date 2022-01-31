#include<stdio.h>
#include<stdlib.h>

struct employee{
    int eid;
    char name[20];
};
typedef struct employee emp;

emp* insert(emp* t,int *n){
    scanf("%d",n);
    t=(emp*)malloc((*n)*(sizeof(emp)));
    for(int i=0;i<(*n);i++)
{
    scanf("%d %s",&(t[i].eid),t[i].name);
}
    return t;
    
}
void display(emp* t,int n){
    // scanf("%d",n);
    // t=(emp*)malloc((*n)*(sizeof(emp));
    for(int i=0;i<(n);i++)
{
    printf("%d %s",(t[i].eid),t[i].name);
    printf("\n");
}
    
    
}

void search(emp* t,int n){
    int low=0;
    int high=n-1;
    int idd;
    printf("Enter Employee need to be find:\n");
    scanf("%d",&idd);
    int mid;
    while(low<=high){
        mid=(high+low)/2;
        if(idd==t[mid].eid){
            printf("Employee %s has id-%d",t[mid].name,t[mid].eid);
            return;
        }else if(idd>t[mid].eid){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    printf("No such Employee with this id");
    
}


int main()
{
    emp* t=0;
    int n=0;
    t=insert(t,&n);
    display(t,n);
    search(t,n);
    search(t,n);

return 0;
}