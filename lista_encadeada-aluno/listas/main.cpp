#include <iostream>
#include "listas/slist.h"
#include "listas/rslist.h"
#include "listas/dlist.h"

using namespace std;

//definindo a lista a ser testada
//typedef dlist mylist;
typedef slist mylist;
//typedef rslist mylist;

//prototipos
void test0();
void test1();
void test2();
void test3();
void test4();
void test5();

int main(){
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}

void test0(){
    cout << "test0 :";
    mylist lista;
    lista.push_front(3);
    lista.push_back(4);

    cout << (lista.back()->value == 4);
    cout << (lista.front()->value == 3);

    lista.push_back(5);
    lista.push_front(2);
    cout << (lista.back()->value == 5);
    cout << (lista.front()->value == 2);
    lista.pop_back();
    lista.pop_front();
    cout << (lista.back()->value == 4);
    cout << (lista.front()->value == 3);


    cout << endl;
}

//push_back, equals, size, push_back_all
void test1(){
    cout << "test1 :";
    mylist listaA;
    mylist listaB;

    for(int i = 0; i < 10; i++){
        listaA.push_back(i);
    }//0 1 2 3 4 5 6 7 8 9

    int vet[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    listaB.push_back_all(vet, 10);
    cout << listaA.equals(&listaB);

    listaB.front()->value = 4;

    cout << !listaA.equals(&listaB);

    listaB.pop_front();

    cout << !listaA.equals(&listaB);

    cout << (listaA.size() == 10);
    cout << (listaB.size() == 9);
    cout << endl;
}

//push_back, push_front, pop_back, pop_front
void test2(){
    cout << "test2 :";
    mylist lista;
    lista.push_back(0);//0
    lista.push_back(1);//0 1
    lista.push_back(2);//0 1 2
    lista.push_front(3);//3 0 1 2

    cout << (lista.front()->value == 3);
    cout << (lista.back()->value == 2);
    lista.pop_back();
    lista.pop_front();
    cout << (lista.front()->value == 0);
    cout << (lista.back()->value == 1);
    cout << endl;
}

//remove, remove_all
void test3(){
    cout << "test3 :";
    mylist lista;
    int vet[] = {3, 2, 1, 4, 2, 5};
    lista.push_back_all(vet, 6);

    lista.remove(3);//2 1 4 2 5
    lista.remove(1);//2 4 2 5
    lista.remove(5);//2 4 2
    lista.remove(9);//2 4 2

    lista.push_back(2);//2 4 2 2
    lista.remove_all(2);//4
    cout << (lista.size() == 1);
    cout << (lista.front()->value == 4);
    cout << endl;
}

//remove_all_pos
void test4(){
    cout << "test4 :";
    mylist lista;
    int vet[] = {3, 2, 1, 4, 2, 5};
    lista.push_back_all(vet, 6);

    int posicoes[] = {1, 2, 4};

    lista.remove_all_pos(posicoes, 3);//sobra 3 4 5
    cout << (lista.size() == 3);
    cout << (lista.front()->value == 3);
    lista.pop_front();
    cout << (lista.front()->value == 4);

    cout << (lista.back()->value == 5);
    cout << endl;
}

//find, get
void test5(){
    cout << "test5 :";
    mylist lista;
    int vet[] = {3, 2, 1, 5};
    lista.push_back_all(vet, 4);
    lista.find(3)->value = 7;//7 2 1 5
    lista.find(2)->value = 9;//7 9 1 5
    lista.find(5)->value = 6;//7 9 1 6
    cout << (lista.get(0)->value == 7);
    cout << (lista.get(1)->value == 9);
    cout << (lista.get(3)->value == 6);
    cout << (lista.get(9) == lista.end());
    cout << endl;
}













