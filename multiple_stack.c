#include <stdio.h>
#define MS 10 
#define MST 2
typedef struct {
int key;
} element;
element memory[MS];
int top[MST];
int b_uf[MST],b_of[MST];
int n=MST; 
void push(int i, element item)
{
if (top[i] == b_of[i]-1)
{
printf("%d th Stack full\n",i);
return;
}
memory[ ++top[i] ] = item;
}

void pop(int i)
{
if (top[i] == b_uf[i])
{ printf("stack empty\n"); return; }
printf("%d th stack content is %d\n", i, (memory[top[i]--]).key );
}
void display(int i)
{
int j;
if (top[i] == b_uf[i])
{ printf("stack empty"); return; }
printf("Contents of stack %d are\n",i);
for(j=top[i];j>b_uf[i];j--)
printf("%d\n",(memory[j]).key);
}
int main()
{
int j,ch,stno;
element ele;
top[0] = b_uf[0] = -1;
for(j=1; j<n;j++)
{
b_of[j-1] = (MS/n)*j;
top[j] = b_of[j-1]-1;
b_uf[j] = top[j];
}
b_of[n-1] = MS;
printf("st-no\ttop\tST_UF\tST-OF\n");
for(j=0;j<n;j++)
printf(" %d\t%d\t%d\t%d\n",j+1,top[j],b_uf[j],b_of[j]);

for(j=0; ;)
{
printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
scanf("%d",&ch);
if (ch==4) return 0;
printf("Enter stack no in range %d to %d\n",0,n-1);
scanf("%d",&stno);
switch(ch)
{
case 1: ele.key=j; j++;
push(stno,ele);
break;
case 2: pop(stno);
break;
case 3: display(stno);
break;
}
}
return 0;
}
