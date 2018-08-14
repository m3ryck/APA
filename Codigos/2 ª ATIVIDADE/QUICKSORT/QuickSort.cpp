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

void Quick_Sort(int *arr, int Ponta_Esq, int Ponta_Dir){

    int min = ((Ponta_Esq+Ponta_Dir)/2);//meio do vetor;

    int i = Ponta_Esq; // Atribuindo a I e a J as Extremidades do Vetor
    int j = Ponta_Dir;

    int pivo = arr[min]; // selecionando o elemento do meio como pivo

    int aux;

    while(Ponta_Esq<j || i<Ponta_Dir) {
        while(arr[i]<pivo) {i++;
        printf("\ntestando\n");}
        while(arr[j]>pivo) {j--;
        printf("\ntestando 2\n");}

        if(i<=j){
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
            i++;
            j--;
        }
        else{
            if(Ponta_Esq<j)
                Quick_Sort(arr, Ponta_Esq, j);
            if(i<Ponta_Dir)
                Quick_Sort(arr,i,Ponta_Dir);
            return;
        }
    }
}

int main() {

int array[]={9,8,7,6,5,4,3,2,1,0};

Quick_Sort(array, 0, 9);
Printar(array, 10);

/*
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

    Quick_Sort(array, 0, linhas-1);
    Printar(array, linhas);
    return 0;
    */
}