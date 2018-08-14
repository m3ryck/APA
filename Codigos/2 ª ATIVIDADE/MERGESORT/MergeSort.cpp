#include <iostream> 
#include <fstream>
#include <stdlib.h>
using namespace std;

void Printar(int vetoray[], int tam){

	for (int i = 0; i < tam; ++i)
	{
		cout << "Order: " << i+1 << " - Number: " << vetoray[i] << endl;
	}

}

void Merge(int vetor[], int inicio, int meio, int fim, int aux[]) {
    int indice = inicio;
    int jj = meio;
    for (int i = inicio; i < fim; ++i) {
        if ((indice < meio) && ((jj >= fim) || (vetor[indice] < vetor[jj]))) { //se o indice for menor que o meio
            aux[i] = vetor[indice];								//e o jj >= fim ou o conteudo do indice menor conteudo de jj
            ++indice;											//o i atual recebe o conteudo do indice, ja que ele é menor
        }														// incremento o i
        else {
            aux[i] = vetor[jj];									//se nao, o menor é o vetor(jj) , faz o i receber esse valor
            ++jj;												//e incrementa.
        }
    }
    for (int i = inicio; i < fim; ++i) {						//passando do vetor auxiliar pro vetor original
        vetor[i] = aux[i];
    }
}
void MergeSort(int vetor[], int inicio, int fim, int aux[]) {
    if ((fim - inicio) < 2) return;
    
    int meio = ((inicio + fim)/2);
    MergeSort(vetor, inicio, meio, aux);
    MergeSort(vetor, meio, fim, aux);
    Merge(vetor, inicio, meio, fim, aux);
}

int main() {


	char casodeteste[20]; 
	cout << "Digite um caso de teste: " << endl;
	cin >> casodeteste;

	int vetoray[100000]; 
	int linhas = 0; 

	 ifstream myReadFile;
	 myReadFile.open(casodeteste);
	 char output[1000];
	 if (myReadFile.is_open()) {
	 while (!myReadFile.eof()) {


	    myReadFile >> output;
	    vetoray[linhas] = atoi(output);
	   	linhas++;

	 }
	}
	myReadFile.close();

	int aux[linhas];
	MergeSort(vetoray, 0, linhas, aux);
	Printar(vetoray, linhas);
	return 0;
}
