#include <stdio.h>  
#include<stdlib.h>
  
 
struct node{  
    int data;  
    struct node *next;  
};      
   
typedef struct node nd;


   

nd* addNode(nd* head,int data) {
    nd* temp=(nd*)malloc(sizeof(nd));
    temp->data=data;
    if(head==NULL){
        return temp;
    }else{
        temp->next=head;
        return temp;
    }
    
}  
nd * concatenate (nd *head1, nd *head2)
{
                nd *p;
                if (head1==NULL)                            

                                return (head2);
                if (head2==NULL)                    
                                return (head1);
               
                p=head1;                        
               
                while (p->next!=NULL)                
                                p=p->next;
                p->next=head2;                           
                
                return (head1);
}
   

 
   
 
void display(nd* head) {  
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty \n");  
        return;  
    }  
    while(current != NULL) {  
     
        printf("%d ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  
      
int main()  
{  
     nd* h=NULL;
     nd* t=NULL;
     
     t=addNode(t,7);
      t=addNode(t,8);
       t=addNode(t,9);
        t=addNode(t,10);
        
    
    
    h=addNode(h,1);  
    h=addNode(h,3);  
    h=addNode(h,3);  
    h=addNode(h,5);  
    h=addNode(h,6);  
    
    printf("Original list: \n");  
    display(h); 
    display(t);
    h=concatenate(h,t); 
    
     
    
     
    
      

    
      

    printf("after concataion list: \n");  
    display(h);  
          
    return 0;  
}  