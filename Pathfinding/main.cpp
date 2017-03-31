#include "libs/ed_base.h"
#include "libs/ed_mat.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

int nlinhas = 15;
int ncolunas = 20;

//r red
//g green
//b blue
//m magenta
//c cyan -
//y yellow
//w white
//k black

vector<Par> pegar_vizinhos(Par par){
    vector<Par> vizinhos;
    vizinhos.push_back(Par(par.l, par.c - 1));
    vizinhos.push_back(Par(par.l - 1, par.c - 1));
    vizinhos.push_back(Par(par.l - 1, par.c));
    vizinhos.push_back(Par(par.l - 1, par.c + 1));
    vizinhos.push_back(Par(par.l, par.c + 1));
    vizinhos.push_back(Par(par.l + 1, par.c + 1));
    vizinhos.push_back(Par(par.l + 1, par.c));
    vizinhos.push_back(Par(par.l + 1, par.c - 1));
    return vizinhos;
}

void mostrar(matchar &mat, Par p, matriz<int> &dist){

    mat_draw(mat);
    mat_focus(p, 'y');
    mat_draw(dist);
    ed_show();
}

//void encontar_caminho(matchar &mat, matriz<int> dist, Par inicio, Par destino){
//    while (mat.get(inicio) != 'b') {

//    }
//}

void viagem(matriz<int> &dist, matchar &mat, Par p, Par inicio){
    if(dist.get(p) == dist.get(inicio)){
        return;
    }
        for(auto x : pegar_vizinhos(p)){
            if(mat.is_inside(x) && dist.is_inside(x)){
                if(dist.get(x) < dist.get(p) && dist.get(x) != -1){
                    mat.get(x) = 'y';
                    mat.get(p) = 'y';
                    mat_draw(mat);
                    mat_draw(dist);
                    ed_show();
                    viagem(dist, mat, x, inicio);
                    return;
                }
            }
        }
}

bool pintar(matchar &mat, Par par, char cor, matriz<int> &dist, Par dest){
    if(mat.is_inside(par)){
    queue<Par> fila;

    mat.get(par) = 'c';
    dist.get(par) = 0;
    fila.push(par);
    mostrar(mat, par, dist);
    while(!fila.empty()){
        for(auto vizinho : pegar_vizinhos(fila.front())){
            if(mat.is_inside(vizinho)){
                if(mat.get(vizinho) == cor){
                    if(mat.get(dest) == 'r'){
                        return true;
                    }
                    fila.push(vizinho);
                    dist.get(vizinho) = dist.get(fila.front()) + 1;
                    mat.get(vizinho) = 'c';
                    mostrar(mat, vizinho, dist);
                }
          }
        }
        mat.get(fila.front()) = 'r';
        mostrar(mat, fila.front(), dist);
        fila.pop();
    }
  }
  return false;
}



int main(){
    matchar mat(nlinhas, ncolunas, 'g');
    matriz<int> dist(nlinhas, ncolunas, -1);
    char cor;
    mat_paint_brush(mat, "wg");
    mat_draw(mat);
    ed_show();
    Par p = mat_get_click(mat, "Escolha onde comeca a pintar.");
    Par dest = mat_get_click(mat, "Escolha onde termina a pintar.");
    cor = mat.get(p);
    bool achou = pintar(mat, p, cor, dist, dest);
    if(achou){
	viagem(dist, mat, dest, p);
}
    ed_lock();

    return 0;
}


