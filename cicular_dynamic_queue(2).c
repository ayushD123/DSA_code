#include <stdio.h>
#include <stdlib.h>


struct cQueue {
	int f, r, n, cap;
	int * arr;
};

typedef struct cQueue Q;

int deQueue(Q *p);


Q * newQueue(int cap) {
	Q *p = (Q *) malloc(sizeof(Q));
	p->f = -1;
	p->r = -1;
	p->n = 0;
	p->cap = cap;
	p->arr = (int *) malloc(sizeof(int) * cap);
	return p;
}

int enQueue(Q *p, int ele) {
	if(p->n < p->cap) {
		if(p->f == -1) p->f = 0;					// First time push.
		p->r = (++(p->r)) % p->cap;
		(p->n)++;
		p->arr[p->r] = ele;
		return ele;
	}
	else {											// Increase queue size, replace contents
		// later
		printf("Queue overflow ! Resizing...\n");
		Q *t = newQueue(p->cap * 2);
		for(; p->n > 0;) enQueue(t, deQueue(p));
		p->f = t->f;
		p->r = t->r;
		p->n = t->n;
		p->cap = t->cap;
		p->arr = t->arr;
		free(t->arr);
		free(t);
		printf("    Resizing Success !\n");
		return enQueue(p, ele);
	}
}

int deQueue(Q *p) {
	if(p->n > 0) {
		p->f = (++(p->f)) % p->cap;;
		(p->n)--;
		printf("Deletion success.\n");
		return p->arr[(p->f)+1];
	}
	else {
		printf("Queue Underflow !\n");
		return 0;
	}
}

int peek(Q *p) {
	if(p->n > 0) {
		return p->arr[p->f];
	}
	else {
		printf("Queue Underflow !\n");
		return 0;
	}
}

void display(Q *p) {
	int i, j;
	if(p->n > 0) {
		if(p->r < p->f) {
			for(i = p->f; i < p->cap; i++) printf("  %d,", p->arr[i]);
			for(i = 0; i <= p->r; i++) printf("  %d,", p->arr[i]);
			return;
		} else for(i = p->f; i <= p->r; i++) printf("  %d,", p->arr[i]);
	}
	else {
		printf("Queue Empty !\n");
		return;
	}
}

void insert(Q *p, FILE *f) {
	int e;
	printf("Enter Integer Element to be inserted : ");
	//scanf("%d", &e);
	fscanf(f, "%d", &e);
	printf("%d\n", e);
	if(enQueue(p, e) != 0 || e == 0) printf("Insertion success.\n");
	else printf("Insertion unsuccessful.\n");

}

int main() {
	Q *p = newQueue(4);
	int ch;
	
	FILE *f = fopen("data.txt", "r");
	if(f == 0) {
		printf("Unable to open file.\n");
		return 0;
	}
	
	while(1) {
		printf("\n\n1.  Insert element.\n2.  Delete element.\n3.  Display.\n4.  Exit\nEnter choice : ");
		//scanf("%d", &ch);
		fscanf(f, "%d", &ch);
		printf("%d\n", ch);
		switch (ch) {
			case 1: insert(p, f); break;
			case 2: deQueue(p); break;
			case 3: display(p); break;
			default : return 0;
		}
	}
	
	return 0;
}



