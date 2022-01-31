#include <stdio.h>  
#include<stdlib.h>
 
struct node{  
    int data;  
    struct node *next;  
};      
typedef struct node nd;
   

struct node *head, *tail = NULL;  
   
  
nd* addNode(nd* head,int data) {  
      
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    newNode->next = NULL;  
      
     
    if(head == NULL) {  
        
        head = newNode;  
        tail = newNode;  
    }  
    else {  
        
        tail->next = newNode;  
        
        tail = newNode;  
    }  
    return head;
}  
   
     
    void sortList(nd* head) {  
        
        struct node *current = head, *index = NULL;  
        int temp;  
          
        if(head == NULL) {  
            return;  
        }  
        else {  
            while(current != NULL) {  
                
                index = current->next;  
                  
                while(index != NULL) {  
         
                    if(current->data > index->data) {  
                        temp = current->data;  
                        current->data = index->data;  
                        index->data = temp;  
                    }  
                    index = index->next;  
                }  
                current = current->next;  
            }      
        }  
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
    
    h=addNode(h,9);  
    h=addNode(h,7);  
    h=addNode(h,2);  
    h=addNode(h,5);  
    h=addNode(h,4);  
      
     
    printf("Original list: \n");  
    display(h);  
      

    sortList(h)  ;
      

    printf("Sorted list: \n");  
    display(h);  
          
    return 0;  
}  