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




int main() {

/*
int array[]={4,1,6,10,0};

Quick_Sort(array, 0, 4);

//Quick_Sort(array, 0, 4);
//Printar(array, 5);


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

    Quick_Sort(array, 0, linhas-1);
    Printar(array, linhas);
    return 0;

}