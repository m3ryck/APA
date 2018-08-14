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

void Group(int arr[], int Cabeca, int meio, int Rabo, int aux[]) {
    int inf = Cabeca;
    int sup = meio;
    for (int i = Cabeca; i < Rabo; ++i) {
        if ((inf < meio) && ((sup >= Rabo) || (arr[inf] < arr[sup]))) {
            aux[i] = arr[inf];
            ++inf;
        }
        else {
            aux[i] = arr[sup];
            ++sup;
        }
    }
    for (int i = Cabeca; i < Rabo; ++i) {
        arr[i] = aux[i];
    }
}

void MergeSort(int arr[], int Cabeca, int Rabo, int aux[]) {
    if ((Rabo - Cabeca) < 2) return;
    
    int meio = ((Cabeca + Rabo)/2);
    MergeSort(arr, Cabeca, meio, aux);
    MergeSort(arr, meio, Rabo, aux);
    Group(arr, Cabeca, meio, Rabo, aux);
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

	int aux[linhas];
	MergeSort(array, 0, linhas, aux);
	Printar(array, linhas);
	return 0;
}
