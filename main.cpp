#include <iostream>

using namespace std;

// ============================================================= //
void heapify(int vetor[], int tam, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < tam && vetor[l] > vetor[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < tam && vetor[r] > vetor[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(vetor[i], vetor[largest]);

        // Recursively heapify the affected sub-tree
        heapify(vetor, tam, largest);
    }
}

// main function to do heap sort
void heapSort(int vetor[], int tam)
{
    // Build heap (rearrange array)
    for (int i = tam / 2 - 1; i >= 0; i--)
        heapify(vetor, tam, i);

    // One by one extract an element from heap
    for (int i=tam-1; i>=0; i--)
    {
        // Move current root to end
        swap(vetor[0], vetor[i]);

        // call max heapify on the reduced heap
        heapify(vetor, i, 0);
    }
}


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
    //quickSort(vet, 0, n-1);

    heapSort(vet, n);

    imprimeVetor(vet, n);

    return 0;
}