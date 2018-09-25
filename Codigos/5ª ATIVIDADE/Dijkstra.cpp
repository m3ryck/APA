#include <stdio.h>
#include <vector>
#include <list>	
 
#define fori(i, b, n) for(int i = b; i<n; ++i)
#define inf 10000002 

 
using namespace std;
 
int weights[251][251];
list<int> index;	
list<int>::iterator it, aux;
 
int main(){
 
	int n, m, v1, v2, weight, explore, menor, start, end, cost, vis;
 
	scanf("%d %d", &n, &m);
 
	start = 0;
	end = n;
 
	vector<int> adj[n+1];
	int estimate[n+1];
	bool open[n+1];
 
	fori(i, 0, n+1){
		estimate[i] = inf;
		open[i] = true;
	}
 
	fori(i, 0, m){
		scanf("%d %d %d", &v1, &v2, &weight); 
 
		weights[v1][v2] = weight;
		weights[v2][v1] = weight;
 
		adj[v2].push_back(v1);
		adj[v1].push_back(v2);	
	}
 
 
 
 
 
	estimate[start] = 0;
	index.push_back(start);
 
	while( !index.empty()){
		menor = inf;
		for( it = index.begin(); it != index.end(); ++it){
			vis = (*it);
			if(estimate[vis] < menor){
				menor = estimate[vis];
				explore = vis;
				aux = it;
			}			
		}
 
		index.erase(aux);
		open[explore] = false;
 
 
		fori(i, 0, int(adj[explore].size())){
			vis = adj[explore][i];
 
			if(open[vis]){
				cost = weights[explore][vis] + estimate[explore];
 
				if(estimate[vis] == inf){
					estimate[vis] = cost;
					index.push_back(vis);
				}
				else{
					if(cost < estimate[vis]){
						estimate[vis] = cost;
					}
				}
			}
		}
	}
 
 
 
 
	if(estimate[end] == inf){
		printf("NO\n");	
	}
	else{
		printf("%d\n", estimate[end]);
	}
 
	index.clear();
 
}
