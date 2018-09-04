#include <iostream> 
#include <fstream>
#include <stdlib.h>
using namespace std;

void Printsort(int vetor[], int tam){

	for (int i = 0; i < tam; ++i)
	{
		cout << "Order: " << i+1 << " - Number: " << vetor[i] << endl;
	}

}

void heapify(int vetor[], int n, int i)
{
   int Pai = i;
   int filho_esq = 2*i + 1;
   int filho_dir = 2*i + 2;

   if (filho_esq < n && vetor[filho_esq] > vetor[Pai])
     Pai = filho_esq;

   if (filho_dir < n && vetor[filho_dir] > vetor[Pai])
     Pai = filho_dir;

   if (Pai != i)
   {
     swap(vetor[i], vetor[Pai]);
     heapify(vetor, n, Pai);
   }
}

void heap_Sort(int vetor[], int n)
{
   for (int i = n / 2 - 1; i >= 0; i--)
     heapify(vetor, n, i);

   for (int i=n-1; i>=0; i--)
   {
     swap(vetor[0], vetor[i]);
     
     heapify(vetor, i, 0);
   }
}




int main() {

	char casodeteste[20]; 
	cout << "Digite um caso de teste: " << endl;
	cin >> casodeteste;

	int array[100000]; 
	int linhas = 0; 

	 ifstream myReadFile;
	 myReadFile.open(casodeteste);
	 char output[1000];
	 if (myReadFile.is_open()) {
	 while (!myReadFile.eof()) {


	    myReadFile >> output;
	    array[linhas] = atoi(output);
	   	linhas++;

	 }
	}
	myReadFile.close();
	heap_Sort(array, linhas);
	Printsort(array, linhas);
	return 0;
}