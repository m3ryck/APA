#include <stdio.h>
#include <stdlib.h>


#define INF 9999
#define V 4


void display_MST(int grafo[V][V], int marked_Cell[V][V]) {
	
	int r, c;

	for (r = 0; r < V-1; r++) {
		for (c = r+1; c < V; c++) {
			if(marked_Cell[r][c]) {
				printf("Edge: %d -- %d\tWeight: %d\n", r, c, grafo[r][c]);
			}
		}
	}

}


void prim(int grafo[V][V]) {

	int i, r, c,
		solved = 0,
		count = 0,
		min,
		expected_R,
		expected_C;

	int marked_Cell[V][V] = {{0}};

	int marked_Vertex[V] = {0};
	marked_Vertex[0] = 1;

	
	while(!solved) {

		min = INF;
		count = 0;
		expected_R = -1;
		expected_C = -1;

		for (r = 0; r < V; r++) {

			if (marked_Vertex[r] == 1) {

				for (c = r; c < V; c++) {

					if (grafo[r][c] != 0 && grafo[r][c] < min && !marked_Cell[r][c]) {

						min = grafo[r][c];
						expected_R = r;
						expected_C = c;

					}

				}

			}

		}


		if (expected_R != -1 && expected_C != -1) {
			marked_Cell[expected_R][expected_C] = 1;
			marked_Cell[expected_C][expected_R] = 1;
			marked_Vertex[expected_R] = 1;
			marked_Vertex[expected_C] = 1;
		}


		for (i = 0; i < V; i++) {
			if (marked_Vertex[i]) {
				count++;
			}
		}
		if (count == V) {
			solved = 1;
		}

	}

	display_MST(grafo, marked_Cell);

}


int main(void) {
	
	int grafo[V][V] = {
		{0, 23, 17, 19},
		{23, 0, 22, 20},
		{17, 22, 0, 25},
		{19, 20, 25, 0}
	};

	prim(grafo);

	return 0;
}
