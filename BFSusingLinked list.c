#include <stdio.h>
#include <stdlib.h>

#define NUM_VERTEX 10

struct Vertex {
	char name;
	int mark;
	struct Node* list;
};
struct Node {
	struct Vertex* vertex;
	struct Node* next;
};
struct Queue {
};
typedef struct Vertex Vertex;
typedef struct Node Node;

Vertex* new_vertex(char name) {
	Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
	vertex->name = name;
	vertex->list = 0;
	return vertex;
}

void do_connect(Vertex* a, Vertex* b) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->vertex = b;
	node->next = a->list;
	a->list = node;
}

void connect(Vertex* a, Vertex* b) {
	do_connect (a, b);
	do_connect (b, a);
}

void visit(Vertex* vertex) {
	printf ("\n%5d. %c", vertex->mark, vertex->name);
}

void do_dfs(Vertex *vertex, int* count) {
	Node* p = vertex->list;
	vertex->mark = ++(*count);
	visit (vertex);
	while (p != 0) {
		if (!p->vertex->mark) {
			do_dfs (p->vertex, count);
		}
		p = p->next;
	}
}
void dfs(Vertex *graph[]) {
	int i;
	int count = 0;
	for (i = 0; i < NUM_VERTEX; i ++) {
		graph[i]->mark = 0;
	}
	// each vertex dfs it
	for (i = 0; i < NUM_VERTEX; i ++) {
		if (graph[i]->mark == 0) {
			do_dfs (graph[i], &count);
		}
	}
}

void do_bfs(Vertex *vertex, int* count) {
	Node *initialQueue, *front, *rear, *p, *temp;
	Vertex *w;

	vertex->mark = ++(*count);
	visit (vertex);

	initialQueue = (Node*)malloc(sizeof(Node));
	initialQueue->vertex = vertex;
	initialQueue->next = 0;
	front = initialQueue;
	rear  = initialQueue;

	while (front != 0) {
		p = front->vertex->list;
		while (p != 0) {
			w = p->vertex;
			if (w->mark == 0) {
				Node* nextQueue;
				w->mark = ++(*count);
				visit (w);
				nextQueue = (Node*)malloc(sizeof(Node));
				nextQueue->vertex = w;
				nextQueue->next = 0;
				rear->next = nextQueue;
				rear = nextQueue;
			}
			p = p->next;
		}
		temp = front;
		front = front->next;
		free (temp);
	}
}
void bfs(Vertex *graph[]) {
	int i;
	int count = 0;
	for (i = 0; i < NUM_VERTEX; i ++) {
		graph[i]->mark = 0;
	}
	for (i = 0; i < NUM_VERTEX; i ++) {
		if (graph[i]->mark == 0) {
			do_bfs (graph[i], &count);
		}
	}
}

int main() {

	Vertex *graph[NUM_VERTEX] = {
		new_vertex('A'),
		new_vertex('B'),
		new_vertex('C'),
		new_vertex('D'),
		new_vertex('E'),
		new_vertex('F'),
		new_vertex('G'),
		new_vertex('H'),
		new_vertex('I'),
		new_vertex('J')
	};

	// connect the vertices
	connect(graph[0], graph[2]);
	connect(graph[0], graph[3]);
	connect(graph[0], graph[4]);
	connect(graph[1], graph[4]);
	connect(graph[1], graph[5]);
	connect(graph[2], graph[3]);
	connect(graph[2], graph[5]);
	connect(graph[4], graph[5]);
	connect(graph[6], graph[7]);
	connect(graph[6], graph[9]);
	connect(graph[7], graph[8]);
	connect(graph[8], graph[9]);
	printf ("DFS: ");
	dfs (graph);

	printf ("\n\n");
	printf ("BFS: ");
	bfs (graph);

	printf ("\n\nAnd that's it!!");
	getchar ();

}
