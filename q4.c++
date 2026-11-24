#include <iostream>
using namespace std;

struct No {
    int matricula;
    No *esquerda;
    No *direita;
};

bool buscar(No *raiz, int valor) {

    if (raiz == NULL) {
        return false;
    }

    if (raiz->matricula == valor) {
        return true;
    }

    if (valor < raiz->matricula) {
        return buscar(raiz->esquerda, valor);
    }

    return buscar(raiz->direita, valor);
}

int contarNos(No *raiz) {

    if (raiz == NULL) {
        return 0;
    }

    return 1 + contarNos(raiz->esquerda)
             + contarNos(raiz->direita);
}

bool verificarElementos(No *arvore1, No *arvore2) {

    if (arvore1 == NULL) {
        return true;
    }

    if (!buscar(arvore2, arvore1->matricula)) {
        return false;
    }

    return verificarElementos(arvore1->esquerda, arvore2) &&
           verificarElementos(arvore1->direita, arvore2);
}

bool mesmosElementos(No *arvore1, No *arvore2) {

    if (contarNos(arvore1) != contarNos(arvore2)) {
        return false;
    }

    return verificarElementos(arvore1, arvore2);
}

int main() {

    No *arvore1 = NULL;
    No *arvore2 = NULL;

    No *a = new No;
    No *b = new No;
    No *c = new No;

    a->matricula = 15;
    a->esquerda = b;
    a->direita = c;

    b->matricula = 10;
    b->esquerda = NULL;
    b->direita = NULL;

    c->matricula = 20;
    c->esquerda = NULL;
    c->direita = NULL;

    arvore1 = a;

    No *d = new No;
    No *e = new No;
    No *f = new No;

    d->matricula = 10;
    d->esquerda = NULL;
    d->direita = e;

    e->matricula = 15;
    e->esquerda = NULL;
    e->direita = f;

    f->matricula = 20;
    f->esquerda = NULL;
    f->direita = NULL;

    arvore2 = d;

    if (mesmosElementos(arvore1, arvore2)) {
        cout << "As arvores possuem os mesmos elementos.";
    }
    else {
        cout << "As arvores possuem elementos diferentes.";
    }

    return 0;
}