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

static void Quick_Sort(int tabela[], int inf, int sup)
{

    int ii, /* Índice da esquerda */
        jj, /* Índice da direita */
        pivo, /* Índice do pivô */
        aux;
                                     /* Se a tabela está vazia ou contém apenas */
                                    /* um elemento, ela já está ordenada */

    if (inf >= sup){
        return; /* A tabela já está ordenada */
    } 
        
    pivo = inf;/* Nesta implementação, o pivô é sempre */
                /* o primeiro elemento da tabela */


    /* Início da operação de partição */
    for (ii = inf, jj = sup; ii < jj; ) {


        /* Enquanto os elementos da primeira metade */
        /* da tabela forem menores do que o pivô, */
        /* incrementa-se o índice esquerdo */
        while (tabela[ii] <= tabela[pivo] && ii < sup)
        ++ii;


        /* Enquanto os elementos da segunda metade */
        /* da tabela forem maiores do que o pivô, */
        /* decrementa-se o índice direito */
        while (tabela[jj] > tabela[pivo])
        --jj;


    /* Se os elementos nos índices esq e dir estiverem */
    /* em partições erradas, deve-se trocá-los de lugar */
        if (ii < jj){
            aux = tabela[ii];
            tabela[ii] = tabela[jj];
            tabela[jj] = aux;
        }


    }   

    aux = tabela[pivo];
    tabela[pivo] = tabela[jj];
    tabela[jj] = aux;

    /* Ordena recursivamente a primeira metade da tabela */
    Quick_Sort(tabela, inf, jj - 1);
    /* Ordena recursivamente a segunda metade da tabela */
    Quick_Sort(tabela, jj + 1, sup);
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