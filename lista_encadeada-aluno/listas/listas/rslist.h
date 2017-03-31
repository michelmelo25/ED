#ifndef RSLIST_H
#define RSLIST_H


#include "snode.h"
#include <iostream>

using namespace std;

//single list implementada recursivamente
//Os métodos _ são como privados
//Coloco-os antes dos metodos principais por questões didáticas.

class rslist{
protected:
    snode * head;//no antes do inicio da lista

public:
    //inicia a lista
    rslist(){
        head = new snode(0);
    }

    //remove os elementos e depois remove a cabeça
    ~rslist(){
        clear();
        delete(head);
    }

    //metodo recursivo utilizado no construtor de cópia
    snode * _clone(snode * other);

    //contrutor de cópia
    rslist(const rslist& other);

    void _print(snode * node);

    //imprime a lista
    void print();

    int _size(snode * n);

    int size();

    //retorna o primeiro valido ou nullptr se vazio
    snode * front();

    snode * _back(snode * n);

    //retorna o ultimo valido ou nullptr se vazio
    snode * back();

    void push_front(int value);

    snode * _push_back(snode * n, int value);

    void push_back(int value);

    //insere todos os elementos do vetor na fila
    void push_back_all(int vet[], int tam);

    void pop_front();

    void _pop_back(snode * n);

    void pop_back();

    bool _equals(snode *one, snode *two);

    //verifica e retorna se dois vetores sao iguais
    bool equals(rslist * other);

    //retorna o enesimo no ou nullptr se fora dos limites
    snode * _get(snode *n, int indice);

    snode * get(int indice);

    snode * _find(snode * n, int value);

    //retorna a primeira ocorrencia do valor
    snode * find(int value);

    snode * _remove(snode * n, int value);

    //retorna o no anterior ao removido ou nullptr se nao encontrou
    snode * remove(int value);

    //remove todos os nós com esse valor
    void remove_all(int value);

    //remove o no indice ind, onde 0 é o primeiro valido.
    //retorna o nó antes do no removido ou nullptr
    snode * remove_pos(int ind);

    //remove os elementos das seguintes posicoes
    void remove_all_pos(int posicoes[], int qtd);

    void _clear(snode *n);

    //remove todos os elementos menos a cabeça
    void clear();

    //qual o valor do elemento apos o fim da lista
    snode * end();
};

#endif // RSLIST_H
