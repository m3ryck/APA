#include <stdio.h>
#include <stack>
 
#define fori(i, b, n) for(int i = b; i<n; ++i)


using namespace std;
 
 
typedef struct {
    int v1;
    int v2;
    int weight;
    
}aresta;
 
int cycle[101];	
void unir(int v1, int v2); 
int pai(int x);				
void countSort( aresta *A, int tamanho_Vetor );	
 
 
int main (){
 
    int n, m;
 
    scanf("%d %d", &n, &m);

    aresta arestas[m];
 

	fori(i, 0, n){ 
		cycle[i] = i;
	}
 
 
	fori(i, 0, m){
		scanf("%d %d %d", &arestas[i].v1, &arestas[i].v2, &arestas[i].weight);
	}
 
 	countSort(arestas, m);
 
 
	fori(i, 0, m){
 
		if ( pai(arestas[i].v1) != pai(arestas[i].v2) ){ 
 
			if(arestas[i].v1 < arestas[i].v2){
				printf("%d %d\n", arestas[i].v1, arestas[i].v2);
			}
			else{
				printf("%d %d\n", arestas[i].v2, arestas[i].v1);
			}
 
			unir(arestas[i].v1, arestas[i].v2);
		}
 
	}
	printf("\n");
}
 
 
 
 
 
void unir(int v1, int v2){
    cycle[pai(v1)] = pai(v2);
}
 
 
 
 
int pai(int v){
 
    if (cycle[v] == v){
        return v;
	}
 
    cycle[v] = pai(cycle[v]);
 
    return cycle[v];
}
 
 
 
 
void countSort( aresta *A, int tamanho_Vetor ){
	stack<aresta> weight[101]; 
 
 
	fori(i, 0, tamanho_Vetor){
		weight[A[i].weight].push(A[i]);
	}
 
	int j=0;
	for(int i=0; i<tamanho_Vetor; i++){
		while( weight[j].empty() ){ 
			j++;
		}
 
		A[i] = weight[j].top();
		weight[j].pop();
		j--;
	}
 
 
}

