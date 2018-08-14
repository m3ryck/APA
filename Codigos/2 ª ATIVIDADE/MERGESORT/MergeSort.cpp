#include <iostream> 
#include <fstream>
#include <stdlib.h>
using namespace std;

void Printar(int array[], int tam){

	for (int i = 0; i < tam; ++i)
	{
		cout << "Order: " << i+1 << " - Number: " << array[i] << endl;
	}

}

void Merge(int arr[], int Cabeca, int meio, int fim, int aux[]) {
    int i = Cabeca;
    int j = meio;
    for (int i = Cabeca; i < fim; ++i) {
        if ((i < meio) && ((j >= fim) || (arr[i] < arr[j]))) {
            aux[i] = arr[i];
            ++i;
        }
        else {
            aux[i] = arr[j];
            ++j;
        }
    }
    for (int i = Cabeca; i < fim; ++i) {
        arr[i] = aux[i];
    }
}

void MergeSort(int arr[], int Cabeca, int fim, int aux[]) {
    if ((fim - Cabeca) < 2) return;
    
    int meio = ((Cabeca + fim)/2);
    MergeSort(arr, Cabeca, meio, aux);
    MergeSort(arr, meio, fim, aux);
    Merge(arr, Cabeca, meio, fim, aux);
}


int main() {

	/*
int array[]={9,8,7,6,5,4,3,2,1,0};

Quick_Sort(array, 0, 9);
Printar(array, 10);
*/

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

	int aux[linhas];
	MergeSort(array, 0, linhas, aux);
	Printar(array, linhas);
	return 0;
}
