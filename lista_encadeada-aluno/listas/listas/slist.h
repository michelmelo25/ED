#ifndef SLIST_H
#define SLIST_H

#include "snode.h"
#include <iostream>

//Essa é uma lista simples com cabeça.
//A cabeça é um nó fixo de marcação que nunca é alterado.
//O primeiro elemento da lista é head->next
//O ultimo elemento válido da lista aponta pra nullptr
class slist{
protected:
    snode * head;//no antes do inicio da lista

public:
    //inicia a lista
    slist(){
        head = new snode(0);
        head->next = nullptr;
    }

    //remove os elementos e depois remove a cabeça
    ~slist(){
        clear();
        delete(head);
    }

    //imprime os elementos
    void print();

    //retorna o tamanho da lista
    int size();

    //retorna o primeiro valido ou nullptr se vazio
    snode * front();

    //retorna o ultimo valido ou nullptr se vazio
    snode * back();

    void push_front(int value);

    void push_back(int value);

    //insere todos os elementos do vetor na fila
    void push_back_all(int vet[], int tam);

    void pop_front();

    void pop_back();

    //verifica e retorna se dois vetores sao iguais
    bool equals(slist * other);

    //retorna o enesimo no ou nullptr se fora dos limites
    snode * get(int indice);

    //retorna a primeira ocorrencia do valor
    snode * find(int value);

    //retorna o no anterior ao removido ou nullptr se nao encontrou
    snode * remove(int value);

    //remove todos os nós com esse valor
    void remove_all(int value);

    //remove o no indice ind, onde 0 é o primeiro valido.
    //retorna o nó antes do no removido ou nullptr
    snode * remove_pos(int ind);

    //remove os elementos das seguintes posicoes
    void remove_all_pos(int posicoes[], int qtd);

    //remove todos os elementos menos a cabeça
    void clear();

    //qual o valor do elemento apos o fim da lista
    snode * end();

};
#endif // SINGLELIST_H
