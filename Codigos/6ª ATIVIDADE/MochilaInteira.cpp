#include <iostream>
#include <algorithm>

using namespace std;

int MochilaDinamica(int n, int M, int weigth[], int value[])
{
    int G[n+1][M+1];
    int i, j;
    int valorFinal;
    int postos[n];

   for (i=0;i<=n;i++)  { 
       for (j=0;j<=M;j++)   {
           if (i==0||j==0) {
               G[i][j] = 0;
           }
           else if (weigth[i-1]<=j) { 
            

                 G[i][j] = max(G[i-1][j],value[i-1] + G[i-1][j-weigth[i-1]]); 
           }                                                             
           else {                                                      
                 G[i][j] = G[i-1][j];                                
           }                                                          
       }
   } 

    valorFinal = G[n][M];
    cout << "CARGA NA MOCHILA " << valorFinal << endl;
    cout << endl << "ITENS ADICIONADOS "<< endl;


    j = M;
    for (i=n;valorFinal>0&&i>0;i--) { 
        if (valorFinal == G[i-1][j])
            continue; 
        else {
            cout << "ITEM " << i << ", POSSUI:" << endl;
            cout << "WEIGTH: " << weigth[i-1] << " VALUE: " << value[i-1] << endl;

            valorFinal = valorFinal - value[i - 1]; 
            j = j - weigth[i - 1]; 
        }
    }

}

int main(void)
{   
    int value[] = {3,4,5,3};
    int weigth[] = {3,2,4,3};
    int M = 6;
    int n = sizeof(value)/sizeof(value[0]);
    MochilaDinamica(n,M,weigth,value);
    return 0;
}
