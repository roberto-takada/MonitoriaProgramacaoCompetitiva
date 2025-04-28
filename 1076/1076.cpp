#include <iostream>

using namespace std;

void PercorreAdj(int (&matriz)[49][49], int origem, int (&vetVertices)[49], int* movimentos, int numVertices, int *contador){
    vetVertices[origem] = (*contador)++;
    for(int i = 0; i < numVertices; i++){
        if(matriz[origem][i] == 1){
            if(vetVertices[i] == -1){
                (*movimentos)++;
                PercorreAdj(matriz, i, vetVertices, movimentos, numVertices, contador);
                (*movimentos)++;
            }
        }
    }
}

int main(){
    int origem, casos, matrizAdj[49][49], posX, posY, vetVertices[49], contador = 0, movimentos = 0, numVertices, numArestas;
    cin >> casos;
    while(casos != 0){
        contador = 0;
        movimentos = 0;
        cin >> origem >> numVertices >> numArestas;
        for(int i = 0; i < numVertices; i++){
            for(int j = 0; j < numVertices; j++){
                matrizAdj[i][j] = 0;
            }
        }
        for(int i = 0; i < numArestas; i++){
            cin >> posX >> posY;
            matrizAdj[posX][posY] = 1;
            matrizAdj[posY][posX] = 1;
        }
        for(int i = 0; i < numVertices; i++){
            vetVertices[i] = -1;
        }
        PercorreAdj(matrizAdj, origem, vetVertices, &movimentos, numVertices, &contador);
        cout << movimentos << endl;
        casos--;
    }


    return 0;
}