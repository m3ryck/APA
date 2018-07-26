#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void insertionSort(int vetor[], int tam){
	int i, j, k , atual, aux;
	
	for(i=0;i<=tam-1;i++){

		atual=vetor[i+1];


		for(j=i+1;j>=0 && atual<vetor[i];j--){

				vetor[j] = vetor[j-1];

			}
		
		vetor[j+1]=atual;
		
	}
}



int main(){



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

insertionSort(array,linhas);


for(int i=0;i<linhas;i++){
	printf("\n\n%d\n",array[i]);
}


}