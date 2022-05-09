#include <iostream>

using namespace std;
// ============================================================ //
void quickSort(int *vetor, int inicio, int fim)
{
    int i = inicio;
    int j = fim;
    int pivot = vetor[(i + j) / 2];
    int temporario;

    while (i <= j)
    {
        while (vetor[i] < pivot)
            i++;
        while (vetor[j] > pivot)
            j--;
        if (i <= j)
        {
            temporario = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temporario;
            i++;
            j--;
        }
    }
    if (j > inicio)
        quickSort(vetor, inicio, j);
    if (i < fim)
        quickSort(vetor, i, fim);
}
// ============================================================ //
void merge(int *vetor, int baixo, int meio, int alto)
{
    int temporario[alto + 1];
    int i = baixo;
    int j = meio + 1;
    int k = 0;

    while (i <= meio && j <= alto)
    {
        if (vetor[i] <= vetor[j])
            temporario[k++] = vetor[i++];
        else
            temporario[k++] = vetor[j++];
    }
    while (i <= meio)
        temporario[k++] = vetor[i++];
    while (j <= alto)
        temporario[k++] = vetor[j++];
    k--;
    while (k >= 0)
    {
        vetor[k + baixo] = temporario[k];
        k--;
    }
}

void mergeSort(int *vetor, int baixo, int alto)
{
    int meio;

    if (baixo < alto)
    {
        meio = (baixo + alto) / 2;
        mergeSort(vetor, baixo, meio);
        mergeSort(vetor, meio + 1, alto);
        merge(vetor, baixo, meio, alto);
    }
}

// ============================================================ //
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

// ============================================================ //

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

// ============================================================ //

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

// ============================================================ //

string imprimeVetor(int *vetor, int tamanhoVetor){
    for(int i=0; i < tamanhoVetor; i++){
        cout << vetor[i] << " ";
    }
}

// ============================================================ //
int main(){

    int n=14;
    int vet[] = {44, 3,6,5,1,2,8,7,9,4,10,13,12,11};

    //selecao(vet,n);
    //insertionSort(vet,n);
    //bubbleSort(vet,n);
    //mergeSort(vet, 0, n - 1);

    quickSort(vet, 0, n-1);

    imprimeVetor(vet, n);

    return 0;
}