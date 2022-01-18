/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdlib.h>
#include <stdio.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

typedef struct node nd;




nd* insert_at_first (nd * root)
{
  nd *temp = (nd *)malloc(sizeof(nd));
  temp->right = NULL;
  temp->left = NULL;
  scanf ("%d", &(temp->data));
  if (root == NULL)
    {
      return temp;
    }
  root->left = temp;
  temp->right = root;
  return temp;
}


nd* insert_at_rear (nd* root)
{
  nd *temp = (nd*)malloc(sizeof(nd));
  temp->right = NULL;
  temp->left = NULL;
  scanf("%d", &(temp->data));

  if (root == NULL)
    {
      return temp;
    }
  nd *p = root;
  while ((p->right)!=NULL)
    {
        p=p->right;
    }
    
    p->right=temp;
    temp->left=p;
    return root;
}

int length(nd* root){
    nd* p=root;
    int cnt=0;
    while(p!=NULL){
        cnt++;
        p=p->right;
    }
    return cnt;
}

nd* insert_at_pos(nd* root){
    int pos;
    printf("Enter pos:");
    scanf("%d",&pos);
    if(pos==1){
        return insert_at_first (root);
    }else if(pos==(length(root)+1)){
        return insert_at_rear (root);
    }else if(pos<1 && pos>(pos+1)){
        printf("Invalid  pos!!! \n");
        return root;
    }else{
        nd *temp =(nd*) malloc (sizeof (nd));
    temp->right = NULL;
    temp->left = NULL;
    scanf ("%d", &(temp->data));
    nd* p=root;
    int cnt=length(root);
    int i=1;
    while(i<(pos-1)){
        i++;
        p=(p->right);
    }
    
    temp->right=p->right;
    p->right->left=temp;
    p->right=temp;
    temp->left=p;
    return root;
    }
        
    
}
void display(nd* root){
    nd* p=root;
    //int cnt=0;
    if(p==NULL){
        printf("List empty\n");
        return;
    }else{
        while(p!=NULL){
        printf("%d\t",p->data);
        p=(p->right);
    }
    printf("\n");
    }
    
    //return cnt;
}


nd* delete_f(nd* root){
    if(root==NULL){
        printf("Deletion not possible\n");
        return root;
    }
    nd* temp=root;
    printf("deleted node:%d \n",root->data);
    root=temp->right;
    temp->right=NULL;
    root->left=NULL;
    return root;
    
}
nd* delete_r(nd* root){
    if(root==NULL){
        printf("Deletion not possible\n");
        return root;
    }
    nd* p=root;
    
    
    while((p->right)!=NULL){
        p=p->right;
    }
    printf("deleted node:%d \n",p->data);
    (p->left)->right=NULL;
    p->left=NULL;
    free(p);
    
    
    return root;
    
}

nd* delete_at_pos(nd* root){
    if(root==NULL){
        printf("Deletion not possible\n");
        return root;
    }
    nd* p=root;
    int pos;
    printf("ENter POsition:");
    scanf("%d",&pos);
    if(pos==1){
        return delete_f(root);
    }else if(pos==(length(root))){
        return delete_r(root);
    }else{
         int i=1;
         while(i<(pos)){
             p=p->right;
             i++;
         }
         printf("Deleted Node-%d",p->data);
         p->left->right=p->right;
         p->right->left=p->left;
         p->left=NULL;
         p->right=NULL;
    
    return root;
    }
    
   
    
}






    



int main ()
{
  //printf ("Hello World");
  nd* root=NULL;
  
  while(1){
      int n;
      printf("1-Insert At Front \n");
      printf("2-Insert At rear \n");
      printf("3-Insert At pos \n");
      printf("4-Display \n");
      printf("5-Count \n");
      printf("6-Delete From Front \n");
      printf("7-Delete From rear \n");
      printf("8-Delete at pos \n");
      scanf("%d",&n);
      switch(n){
            case 1:
                root=insert_at_first(root);
                break;
            case 2:
                root=insert_at_rear(root);
                break;
            case 3:
                root=insert_at_pos(root);
                break;
            case 4:
                display(root);
                break;
            case 5:
                printf("%d\n",length(root));
                break;
            case 6:
                root=delete_f(root);
                break;
            case 7:
                root=delete_r(root);
                break;
            case 8:
                root=delete_at_pos(root);
                break;
            default:exit(1);
      }
  }

  return 0;
}
