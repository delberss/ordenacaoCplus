#include <iostream>

using namespace std;

void selecao(int vet[],int n){
    // PEGA O PRIMEIRO ELEMENTO, ASSUME ELE COMO MENOR
    // VAI VASCULHANDO O RESTO DO VETOR PARA ACHAR QUAL O MENOR
    // COM ISSO, FAZ A TROCA, COLOCANDO O MENOR SEMPRE NAS PRIMEIRAS POSICOES NA ORDEM

    int menor, auxiliar;

    for(int i=0;i<n-1;i++){
        menor=i;
        for(int j=i+1 ; j<n ; j++){
            if(vet[menor] > vet[j])
                menor=j;
        }
        if(i!=menor){
            auxiliar=vet[i];
            vet[i]=vet[menor];
            vet[menor]=auxiliar;
        }
    }
}

void insertionSort(int *vetor, int tamanho){
    // EXEMPLO JOGAR CARTAS,
    // VOCÊ PEGA A PRIMEIRA, E O RESTO, VC OLHA SE É MENOR QUE A QUE VOCE SELECIONOU, SE SIM, BOTA ATRAS

    int auxiliar;

    for(int i=0; i < tamanho-1; i++){

        for(int j=i+1; j > 0; j--){
            if(vetor[j] < vetor[j-1]){
                auxiliar = vetor[j];
                vetor[j] = vetor[j-1];
                vetor[j-1] = auxiliar;
            }
        }

    }
}

void bubbleSort(int *vetor, int tamanhoVetor){
    int auxiliar;
    for(int i=0; i < tamanhoVetor; i++){

        for(int j=0; j < tamanhoVetor-1; j++){

            if(vetor[j] > vetor[j+1]){
                auxiliar = vetor[j+1];
                vetor[j+1] = vetor[j];
                vetor[j] = auxiliar;
            }
        }
    }
};

string imprimeVetor(int *vetor, int tamanhoVetor){
    for(int i=0; i < tamanhoVetor; i++){
        cout << vetor[i] << " ";
    }
}

int main(){

    int n=13;
    int vet[] = {3,6,5,1,2,8,7,9,4,10,13,12,11};

    //selecao(vet,n);
    insertionSort(vet,n);
    //bubbleSort(vet,n);

    imprimeVetor(vet, n);

    return 0;
}