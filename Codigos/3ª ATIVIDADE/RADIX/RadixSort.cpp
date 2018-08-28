    #include <iostream> 
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#define MAX 100000
using namespace std;


void Printar(int array[], int tam){

    for (int i = 0; i < tam; ++i)
    {
        cout << "Order: " << i+1 << " - Number: " << array[i] << endl;
        
    }

}
/*
void CountingSort(int vetor[],int tam){
    int aux[MAX];

    int v_final[tam];

    for(int i=0;i<=MAX;i++){
        aux[i]=0;
    }

   for(int j=0; j <tam; j++){
        aux[vetor[j]]=aux[vetor[j]]+1;
        //{0,2,2,1,1,1,0}
   }

   for(int k=1;k<MAX;k++){
        aux[k]=aux[k]+aux[k-1];
        //{0,2,4,5,6,7,7}
   }

   for(int l=0;l<tam;l++){
      v_final[aux[vetor[l]]]=vetor[l];
        aux[vetor[l]]=aux[vetor[l]]-1;

   }


   Printar(v_final, tam);
 
}
*/
void CountingSort(int vetor[], int n, int e)
{
    int output[n];
    int i, count[10] = {0};
 
    for (i = 0; i < n; i++)
        count[(vetor[i]/e)%10]++;
 

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (vetor[i]/e)%10 ] - 1] = vetor[i];
        count[ (vetor[i]/e)%10 ]--;
    }
 
    for (i = 0; i < n; i++)
        vetor[i] = output[i];
}

void radixsort(int vetor[], int n)
{
     int max = vetor[0];
    for (int i = 1; i < n; i++)
        if (vetor[i] > max)
            max = vetor[i];
 
    for (int e = 1; max/e > 0; e =e*10)
        CountingSort(vetor, n, e);
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

    radixsort(array,linhas-1);

    
    Printar(array,linhas-1);
    return 0;
    



}