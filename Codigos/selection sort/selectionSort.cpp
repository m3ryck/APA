#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;


void selectionsort(int vector[],int tam){
	int i, j,aux, menor,j2;

	

	for(i=0;i<tam-1;i++){
		menor=vector[i];

		for(j=i+1;j<tam;j++){

			if(vector[j]<menor){
				menor=vector[j];
				j2=j;
			}
		}
			if(vector[i]>menor){
				aux=vector[j2];
				vector[j2]=vector[i];
				vector[i]=aux;
			}	

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

selectionsort(array,linhas);


for(int i=0;i<linhas;i++){
	printf("\n\n%d\n",array[i]);
}


}