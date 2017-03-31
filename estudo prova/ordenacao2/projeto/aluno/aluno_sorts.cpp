
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <SFML/Graphics.hpp>

#include "../libs/sortview.h"
#include "../libs/player.h"

using namespace std;
static SortView sview;

void minimum_sort(std::vector<int> &vet){
    int tam = vet.size();
    for(int i = 0; i < tam - 1; i++){
        for(int j = i + 1; j < tam; j++){
            sview.show(vet, {i, j}, "gb");
            if(vet[j] < vet[i]){
                sview.show(vet, {i, j}, "rb");
                std::swap(vet[i], vet[j]);
                sview.show(vet, {i, j}, "cb");
            }
        }
    }
}

std::vector<int> init_vet(int qtd, int min, int max){
    std::vector<int> vet;
    vet.reserve(qtd);
    for(int i = 0; i < qtd; i++){
        vet.push_back(rand() % (max - min + 1) + min);
    }
    return vet;
}

void intercalo(vector<int> &vet, int inicio, int meio, int fim){
    vector<int> aux;
    aux.reserve(fim - inicio);
    int i = inicio;
    int m = meio;

    while ((meio - i > 0) && (fim - m > 0)) {
       if(vet[i] < vet[m]){
           aux.push_back(vet[i]);
           i++;
       }else{
           aux.push_back(vet[m]);
           m++;
       }
    }
    while (meio - i > 0) {
        aux.push_back(vet[i]);
        i++;
    }
    while (fim - m > 0) {
        aux.push_back(vet[m]);
        m++;
    }
    for(int i = 0; i < aux.size(); i++)
        vet[inicio + i] = aux[i];
}

void merge_sort(vector<int> &vet, int inicio, int fim){
    if(fim == inicio + 1)
        return;
    int meio = (fim + inicio) / 2;
    merge_sort(vet, inicio, meio);
    merge_sort(vet, meio, fim);
    intercalo(vet, inicio, meio, fim);
    sview.show(vet);
}

void quick_sort(vector<int> &vet, int inicio, int fim){
    int i = inicio;
    int f = fim;
    int pivo = inicio;
    sview.show(vet,{pivo,i,f}, "ygm");

    while (f >= i) {
        while (vet[i] < vet[pivo]) {
            i++;
            sview.show(vet,{pivo,i,f}, "ygm");
        }
        while (vet[f] > vet[pivo]) {
            f--;
            sview.show(vet,{pivo,i,f}, "ygm");
        }
        if(f >= i){
            swap(vet[f], vet[i]);
            sview.show(vet,{pivo,i,f}, "ybb");
            i++;
            sview.show(vet,{pivo,i,f}, "ygm");
            f--;
            sview.show(vet,{pivo,i,f}, "ygm");
        }
    }

    if(f - inicio >= 1)
        quick_sort(vet, inicio, f);
    if(fim - i >= 1)
        quick_sort(vet, i, fim);
}

void intercalador(vector<int> &vet, int inicio, int meio, int fim){
    vector<int> aux;
    aux.reserve(fim - inicio);
    int i = inicio;
    int m = meio;
    while ((meio - i > 0) && (fim - m > 0)) {
        if(vet[i] < vet[m]){
            aux.push_back(vet[i]);
            i++;
        }else{
            aux.push_back(vet[m]);
            m++;
        }
    }
    while (meio - i > 0) {
        aux.push_back(vet[i]);
        i++;
    }
    while (fim - m > 0) {
        aux.push_back(vet[m]);
        m++;
    }

    for(int i = 0; i < aux.size(); i++){
        vet[inicio + i] = aux[i];
    }
}

void meerge_sort(vector<int> &vet, int inicio, int fim){
    if(fim == inicio + 1)
        return;
    int meio = (fim + inicio) / 2;
    meerge_sort(vet, inicio, meio);
    meerge_sort(vet, meio, fim);
    intercalador(vet, inicio, meio, fim);
    sview.show(vet);
}

void quickk_sort(vector<int> &vet, int inicio, int fim){
    int i = inicio;
    int f = fim;
    int pivo = inicio;
    sview.show(vet, {pivo,i,f}, "yrm");

    while (f >= i) {
        while (vet[i] < vet[pivo]) {
            i++;
            sview.show(vet, {pivo,i,f}, "yrm");
        }
        while (vet[f] > vet[pivo]) {
            f--;
            sview.show(vet, {pivo,i,f}, "yrm");
        }
        if( f >= i){
            sview.show(vet, {pivo,i,f}, "ybb");
            swap(vet[i], vet[f]);
            sview.show(vet, {pivo,i,f}, "ybb");
            i++;
            sview.show(vet, {pivo,i,f}, "yrm");
            f--;
            sview.show(vet, {pivo,i,f}, "yrm");
        }
    }
    if(f- inicio >= 1)
        quickk_sort(vet,inicio,f);
    if(fim - i >= 1)
        quickk_sort(vet,i,fim);
}

void new_intercalador(vector<int> &vet, int inicio, int meio, int fim){
    vector<int> aux;
    aux.reserve(fim - inicio);
    int c = inicio;
    int m = meio;

    while ((meio - c > 0) && (fim - m > 0)) {
        if(vet[c] < vet[m]){
            aux.push_back(vet[c]);
            c++;
        }else{
            aux.push_back(vet[m]);
            m++;
        }
    }
    while (meio - c > 0) {
        aux.push_back(vet[c]);
        c++;
    }
    while (fim - m > 0) {
        aux.push_back(vet[m]);
        m++;
    }
    for(int i = 0; i < aux.size(); i++){
        vet[inicio + i] = aux[i];
    }
}

void new_merge(vector<int> &vet, int inicio, int fim){
    if(fim == inicio + 1)
        return;
    int meio = (fim + inicio) / 2;
    new_merge(vet, inicio, meio);
    new_merge(vet, meio, fim);
    new_intercalador(vet, inicio, meio, fim);
    sview.show(vet);
}

int main_sorts(){
    srand(time(NULL));
    my_player->autoplay = true;
    sview.set_bar_view();
    sview.set_thickness(8);

    std::vector<int> vet = init_vet(70, 50, 300);

    //minimum_sort(vet);
    //merge_sort(vet, 0, vet.size());
   //quick_sort(vet, 0, vet.size());
    //meerge_sort(vet,0,vet.size());
    //quickk_sort(vet,0,vet.size());
    new_merge(vet,0,vet.size());
    my_player->wait();
    return 0;
}


int main(){
    main_sorts();
}

