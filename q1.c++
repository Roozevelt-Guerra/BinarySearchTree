#include <iostream>
using namespace std;

struct No {
    int matricula;
    No *esquerda;
    No *direita;
};

No* inserir(No *raiz, int valor) {

    if (raiz == NULL) {
        No *novo = new No;

        novo->matricula = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;

        return novo;
    }

    if (valor < raiz->matricula) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    else if (valor > raiz->matricula) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

void preOrdem(No *raiz) {

    if (raiz != NULL) {
        cout << raiz->matricula << " ";
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void emOrdem(No *raiz) {

    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        cout << raiz->matricula << " ";
        emOrdem(raiz->direita);
    }
}

void posOrdem(No *raiz) {

    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        cout << raiz->matricula << " ";
    }
}

int main() {

    No *raiz = NULL;

    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 25);

    cout << "Pre-ordem: ";
    preOrdem(raiz);

    cout << "\nEm ordem: ";
    emOrdem(raiz);

    cout << "\nPos-ordem: ";
    posOrdem(raiz);

    return 0;
}