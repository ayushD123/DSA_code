#include<stdio.h>
#include<stdlib.h>

int* insert(int *a,int *n){

    scanf("%d",n);
    a=(int*)malloc((*n)*(sizeof(int)));
    for(int i=0;i<(*n);++i){
        scanf("%d",a+i);
    }
    return a;
}
void display(int *a,int n){
    for(int i=0;i<n;++i){
        printf("%d \t",*(a+i));
    }
    printf("\n");
}

int* insert_at_pos(int *a,int *n){
    printf("enter position-\n");
    int x,ele;
    scanf("%d",&x);
    printf("enter element-\n");
    scanf("%d",&ele);
    for(int i=(*n)-1;i>=(x-1);i--){
        a[i+1]=a[i];
    }
    a[x-1]=ele;
    (*n)++;
    return a;
}
int* delete_at_pos(int *a,int *n){
    printf("enter position-\n");
    int x;
    scanf("%d",&x);
    // printf("enter element-\n");
    // scanf("%d",&ele);
    for(int i=(x)-1;i<((*n)-1);i++){
        a[i]=a[i+1];
    }
   // a[x-1]=ele;
    (*n)--;
    return a;
}
    


int main()
{
    int *a=0;
    int n=0;
    a=insert(a,&n);
    display(a,n);
    a=insert_at_pos(a,&n);
     display(a,n);
     a=delete_at_pos(a,&n);
     display(a,n);

return 0;
}