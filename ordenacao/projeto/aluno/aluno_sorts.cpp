
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <SFML/Graphics.hpp>

#include "../libs/sortview.h"
#include "../libs/player.h"

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

void select_sort(std::vector<int> &vet){
    int tam = vet.size();
    for(int i = 0; i < tam - 1; i++){
        int indice = i;
        for(int j = i + 1; j < tam; j++){
            sview.show(vet, {i, j, indice}, "gbr");
            if(vet[j] < vet[indice]){
                indice = j;
                sview.show(vet, {i, j, indice}, "gbr");
            }
        }
        std::swap(vet[i], vet[indice]);
    }
}

void select_sortin(std::vector<int> &vet){
    int tam = vet.size();
    for(int i = tam - 1; i >= 0; i--){
        int indice = i;
        for(int j = i - 1; j >= 0; j--){
            sview.show(vet, {i, j, indice}, "gbr");
            if(vet[j] > vet[indice])
                indice = j;
        }
        std::swap(vet[i], vet[indice]);
    }
}

void select_sort_duplo(std::vector<int> &vet){
    int tam = vet.size();
    for(int i = 0; i < tam; i++, tam--){
        int menor = i;
        int maior = i;
        for(int j = i; j < tam; j++){
            if(vet[j] > vet[maior]){
                maior = j;
            }else if(vet[j] < vet[menor]){
                menor = j;
            }
            sview.show(vet, {i, j, menor, maior}, "gbrm");
        }
        if(maior == i && menor == tam - 1){
            std::swap(vet[maior], vet[menor]);
        }else{
            std::swap(vet[i], vet[menor]);
            if(maior == i)
                maior = menor;
            std::swap(vet[tam - 1], vet[maior]);
        }
        sview.show(vet, {i, tam - 1, menor, maior}, "gbrm");
    }
}

void bubble_sort(std::vector<int> &vet){
    int tam = vet.size();
    for(int i = tam - 1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(vet[j] > vet[j + 1])
                std::swap(vet[j], vet[j + 1]);
            sview.show(vet, {j, j + 1}, "gr");
        }
    }
}

void insertion(std::vector<int> &vet){
    int tam = vet.size();
    for(int i = 1; i < tam; i++){
        for(int j = i; j >= 1; j--){
            sview.show(vet, {j, j - 1}, "gr");
            if(vet[j] < vet[j - 1]){
               std::swap(vet[j], vet[j - 1]);
               sview.show(vet, {j, j - 1}, "gr");
             }else{
                break;
            }
        }
    }
}

void intercalo(std::vector<int> &vet, int inicio, int meio ,int fim){
    std::vector<int> aux;
    aux.reserve(fim - inicio);
    int i = inicio;
    int m = meio;
    while ((meio - i > 0) && (fim - m > 0)){
        if(vet[i] < vet[m]){
            aux.push_back(vet[i]);
            i++;
        }else{
            aux.push_back(vet[m]);
            m++;
        }
    }

    while((meio - i) > 0){
        aux.push_back(vet[i]);
        i++;
    }
    while ((fim - m) > 0){
        aux.push_back(vet[m]);
        m++;
    }
    for(int i = 0; i < aux.size(); i++){
        vet[inicio + i] = aux[i];
    }
}

void merge_sort(std::vector<int> &vet, int inicio, int fim){
    if(fim == inicio + 1)
        return;
        int meio = (fim + inicio)/2;
        merge_sort(vet, inicio, meio);
        merge_sort(vet, meio, fim);
        intercalo(vet, inicio, meio, fim);
     sview.show(vet);
}

void quick_sort(std::vector<int> &vet, int inicio, int fim){
    int c = inicio;
    int f = fim;
    int pivo = inicio;
    sview.show(vet,{pivo, inicio, fim , f, c}, "yrrgb");
    while (f >= c) {
        while (vet[c] < vet[pivo] && (c <= fim)) {
            c++;
            sview.show(vet,{pivo, inicio, fim , f, c}, "yrrgb");
        }
        while (vet[f] > vet[pivo] && (f >= inicio)) {
            f--;
            sview.show(vet,{pivo, inicio, fim , f, c}, "yrrgb");
        }
        if(f >= c){
            sview.show(vet,{pivo, inicio, fim , f, c}, "yrrcc");
            std::swap(vet[c], vet[f]);
            sview.show(vet,{pivo, inicio, fim , f, c}, "yrrmm");
            c++;
            sview.show(vet,{pivo, inicio, fim , f, c}, "yrrgb");
            f--;
            sview.show(vet,{pivo, inicio, fim , f, c}, "yrrgb");
        }
        sview.show(vet,{pivo, inicio, fim , f, c}, "yrrgb");
    }
    if(f - inicio >= 1)
        quick_sort(vet, inicio, f);
    if(fim - c >= 1)
        quick_sort(vet, c, fim);
}


std::vector<int> init_vet(int qtd, int min, int max){
    std::vector<int> vet;
    vet.reserve(qtd);
    for(int i = 0; i < qtd; i++){
        vet.push_back(rand() % (max - min + 1) + min);
    }
    return vet;
}

void merge(std::vector<int> &vet, int inicio, int fim){

}

int main_sorts(){
    srand(time(NULL));
    my_player->autoplay = true;
    sview.set_bar_view();
    sview.set_thickness(8);

    std::vector<int> vet = init_vet(70, 50, 300);

   // minimum_sort(vet);
  // select_sort(vet);
   //select_sortin(vet);
   //select_sort_duplo(vet);
   //bubble_sort(vet);
   //insertion(vet);
   //merge_sort(vet, 0, vet.size());
    quick_sort(vet, 0, vet.size() - 1);
    my_player->wait();
    return 0;
}


int main(){
    main_sorts();
}
