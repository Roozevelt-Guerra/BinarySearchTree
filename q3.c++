#include <iostream>
using namespace std;

struct No {
    int matricula;
    No *esquerda;
    No *direita;
};

bool verificarBST(No *raiz, int &anterior, bool &primeiro) {

    if (raiz == NULL) {
        return true;
    }

    if (!verificarBST(raiz->esquerda, anterior, primeiro)) {
        return false;
    }

    if (!primeiro && raiz->matricula <= anterior) {
        return false;
    }

    anterior = raiz->matricula;
    primeiro = false;

    return verificarBST(raiz->direita, anterior, primeiro);
}

int main() {

    No *raiz = new No;
    No *esq = new No;
    No *dir = new No;

    raiz->matricula = 15;
    raiz->esquerda = esq;
    raiz->direita = dir;

    esq->matricula = 10;
    esq->esquerda = NULL;
    esq->direita = NULL;

    dir->matricula = 20;
    dir->esquerda = NULL;
    dir->direita = NULL;

    int anterior = 0;
    bool primeiro = true;

    if (verificarBST(raiz, anterior, primeiro)) {
        cout << "A arvore e uma BST.";
    }
    else {
        cout << "A arvore nao e uma BST.";
    }

    return 0;
}
