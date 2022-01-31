#include <stdio.h>
#include <stdlib.h>
int QS = 3;
int * insert(int [], int * ,int *, int *);
void del(int [], int *, int *);
void display(int [], int, int);
int main() {
int *q= (int *) malloc(sizeof(int)*QS);
int r=-1,f=0,cnt=0;
int ch;
while(1) {
printf("1: Insert\n2: Delete\n3: Display\n4: Exit\n");
printf("Enter choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: q=insert(q, &f, &r,&cnt); break;
case 2: del(q,&f,&cnt); break;
case 3: display(q,f,cnt); break;
default: exit(0); } } }

int * insert(int q[],int *f,int *r,int *cnt) {
int ele; int *p=q,i,j;

if((*cnt) == QS)
{
printf("Queue Overflow...\n");
//Create a new array of twice the capacity.
p = (int *) malloc(sizeof(int)* (*cnt)*2);
if (*r > *f)
for(i=(*f); i<=(*r); i++)
p[i] = q[i];
else
{

for(i=*f , j=0; i<=QS-1; i++,j++)
p[j]=q[i];

for(i=0; i<=(*r); i++, j++)

p[j]=q[i];
} // END OF ELSE PART
q=p;
(*f) = 0; (*r) = QS-1;
printf("After doubling and rearranging\n");
for(i=0;i<QS;i++)
printf("%d ",q[i]);
QS *= 2;
}
(*r) = ((*r)+ 1 ) % QS;
printf("enter the ele\n");
scanf("%d",&ele);
q[*r]=ele;
(*cnt)++;
return p;
}
void del(int q[],int *f,int *cnt)
{
if((*cnt) == 0)
{printf("Queue is empty\n"); return;}
printf("Element deleted from circular queue is %d\n",q[(*f)]);
(*f) = ((*f) + 1) % QS;
(*cnt)--;
}

void display(int q[], int f, int cnt)
{
int i,j;
if (cnt==0)
{ printf("Circular Queue is empty\n"); return;}
printf("Circular Queue contents are\n");
for(i=f,j=0;j<cnt;j++)
{
printf("%d : %d\n",i,q[i]);
i = (i + 1) % QS;
} }