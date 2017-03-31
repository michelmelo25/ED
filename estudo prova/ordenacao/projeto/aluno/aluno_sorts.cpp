
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

void bobble_sort(vector<int> &vet){
    int tam = vet.size();
    for (int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(vet[j] > vet[j + 1]){
                sview.show(vet, {i, j, j+1}, "rgb");
                std::swap(vet[j], vet[j+1]);
                sview.show(vet, {i, j, j+1}, "rgb");
            }
        }
    }

}

void select_sort(vector<int> &vet){
    int tam = vet.size();
    for(int i = tam - 1; i >= 0; i--){
        int indice = i;
        for(int j = 0; j < i; j++){
            if(vet[j] > vet[indice])
                indice = j;
            sview.show(vet, {i, j, indice}, "rbg");
        }
        swap(vet[i], vet[indice]);
        sview.show(vet, {i, indice}, "rg");
    }
}

void select_sort_duplo(vector<int> &vet){
    int tam = vet.size();
    for(int i = 0; i < tam; i++, tam--){
        int maior = i;
        int menor = i;
        for(int j = i; j < tam; j++){
            if(vet[j] > vet[maior])
                maior = j;
            if(vet[j] < vet[menor])
                menor = j;
            sview.show(vet, {i,tam,j,maior,menor}, "rrygb");
        }
        if((maior == i) && (menor == tam - 1)){
            swap(vet[maior], vet[menor]);
            sview.show(vet, {i,tam,maior,menor}, "rrgb");
        }else{
            swap(vet[menor], vet[i]);
            sview.show(vet, {i,tam,maior,menor}, "rrgb");
            if(maior == i)
                maior = menor;
            swap(vet[maior], vet[tam - 1]);
            sview.show(vet, {i,tam,maior,menor}, "rrgb");
        }
    }
}

void insertion(vector<int> &vet){
    int tam = vet.size();
    for(int i = 1; i < tam; i++){
        for(int j = i; j >= 1; j--){
            if(vet[j] < vet[j - 1]){
                swap(vet[j], vet[j - 1]);
                sview.show(vet, {j - 1}, "m");
            }else{
                break;
            }
        }
    }
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
    for(int i = 0; i < aux.size(); i++){
        vet[inicio + i] = aux[i];
    }

}

void merge_sort(vector<int> &vet, int inicio, int fim){
    if(fim == inicio + 1)
        return;
    int meio = (fim + inicio) / 2;
    merge_sort(vet, inicio, meio);
    merge_sort(vet, meio, fim);
    //inplace_merge(vet.begin() + inicio, vet.begin() + meio, vet.begin() + fim);
    intercalo(vet, inicio, meio, fim);
    sview.show(vet);//"m"
}

void quick_sort(vector<int> &vet, int inicio, int fim){
    int i = inicio;
    int f = fim;
    int pivo = inicio;
    sview.show(vet,{i,f,pivo}, "rmy");
    while (f >= i) {
        while(vet[i] < vet[pivo]){
            i++;
           sview.show(vet,{i,f,pivo}, "rmy");
        }
        while (vet[f] > vet[pivo]) {
            f--;
            sview.show(vet,{i,f,pivo}, "rmy");
        }
        if(f >= i){
            swap(vet[f], vet[i]);
            sview.show(vet,{pivo,i,f}, "ybb");
            i++;
            sview.show(vet,{i,f,pivo}, "rmy");
            f--;
            sview.show(vet,{i,f,pivo}, "rmy");
        }
    }
    if(f - inicio >= 1)
        quick_sort(vet, inicio, f);
    if(fim - i >= 1)
        quick_sort(vet, i, fim);
}

int main_sorts(){
    srand(time(NULL));
    my_player->autoplay = true;
    sview.set_bar_view();
    sview.set_thickness(8);

    std::vector<int> vet = init_vet(70, 50, 300);

    //minimum_sort(vet);
    //bobble_sort(vet);
    //select_sort(vet);
    //select_sort_duplo(vet);
    //insertion(vet);
    //merge_sort(vet, 0, vet.size());
    quick_sort(vet, 0, vet.size() - 1);
    my_player->wait();
    return 0;
}


int main(){
    main_sorts();
}

