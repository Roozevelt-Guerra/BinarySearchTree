#include <iostream>
using namespace std;

struct No {
    int matricula;
    No *esquerda;
    No *direita;
};

No* inserirIterativo(No *raiz, int valor) {

    No *novo = new No;

    novo->matricula = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;

    if (raiz == NULL) {
        return novo;
    }

    No *atual = raiz;
    No *anterior = NULL;

    while (atual != NULL) {

        anterior = atual;

        if (valor < atual->matricula) {
            atual = atual->esquerda;
        }
        else if (valor > atual->matricula) {
            atual = atual->direita;
        }
        else {
            delete novo;
            return raiz;
        }
    }

    if (valor < anterior->matricula) {
        anterior->esquerda = novo;
    }
    else {
        anterior->direita = novo;
    }

    return raiz;
}

int main() {

    No *raiz = NULL;

    raiz = inserirIterativo(raiz, 15);
    raiz = inserirIterativo(raiz, 10);
    raiz = inserirIterativo(raiz, 20);
    raiz = inserirIterativo(raiz, 5);
    raiz = inserirIterativo(raiz, 12);

    cout << "Insercoes realizadas!";

    return 0;
}