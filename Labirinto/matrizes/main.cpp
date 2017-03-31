#include "libs/ed_base.h"
#include "libs/ed_mat.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int nlinhas = 20;
int ncolunas = 35;

//r red
//g green
//b blue
//m magenta
//c cyan -
//y yellow
//w white
//k black

bool pode_furar(Par x, matchar mat){
    if(mat.get(x) == 'w'){
        return false;
    }
    if(x.l <= 0 || x.c <= 0){
        return false;
    }
    if(x.l <= 0 || x.l >= mat.sizeL()){
        return false;
    }
    if(x.c <= 0 || x.c >= mat.sizeC()){
        return false;
    }
    if(x.c <= 1 || x.c >= mat.sizeC()){
        return false;
    }
    if(mat.get(x.l + 1, x.c) == 'w' || mat.get(x.l - 1, x.c) == 'w'){
        return false;
    }
    if(mat.get(x.l, x.c + 1) == 'w' || mat.get(x.l, x.c - 1) == 'w'){
        return false;
    }
    return true;
}

//bool pode_furar(){
//    if(lad.l < 1 || lad.l >= mat.sizeL())
//        return false;

//}

vector<Par> eh_furavel(vector<Par> par, matchar mat){
    vector<Par> fura;
    for(auto x : par){
        if(pode_furar(x, mat) == true){
        fura.push_back(x);
        }
    }
    return fura;
}


vector<Par> pegar_vizinhos(Par par){
    vector<Par> vizinhos;
    vizinhos.push_back(Par(par.l, par.c - 1));
    vizinhos.push_back(Par(par.l, par.c + 1));
    vizinhos.push_back(Par(par.l - 1, par.c));
    vizinhos.push_back(Par(par.l + 1, par.c));
    return vizinhos;
}

//Deichar os pares aleatorios
vector<Par> shuffle(vector<Par> &vet){
    for(int i = 0; i < (int) vet.size(); i++){
        std::swap(vet[i], vet[rand() % (int) vet.size()]);
    }
    return vet;
}

bool queimar(matchar &mat, Par p){
    if(p.l <= 0 || p.l >= mat.sizeL())
        return 0;
    if(p.c <= 0 || p.c >= mat.sizeC())
        return 0;

    mat_draw(mat); //Printa na tela a matriz
    mat_focus(p, 'y'); //mostra na tela o foco da proxima acao
    ed_show();

    //se for parede
    if(mat.get(p) == 'k'){
        //para cada um dos vizinhos de p
//        for(auto par : pegar_vizinhos(p)){
//            if(mat.equals(par, 'b')) //Se o par for Agua
//                //retorne sem queimar
//                return 0;
//        }

        mat.get(p) = 'w';//abre caminho na parede
//        if(mat.get(destino) == 'w'){
//            return true;
//        }
        mat_draw(mat); //printa na tela a matriz
        ed_show();
        auto viz = pegar_vizinhos(p); //pega os pontos adjacentes
        auto furavel = eh_furavel(viz, mat); //pega os adjacentes que podem virar caminho
        shuffle(furavel); //enbaralha os adjacentes furaveis
        for(auto par : furavel){
            queimar(mat, par);
           if(queimar(mat, par)){
               mat.get(p) = 'y';
               mat_draw(mat);
               ed_show();
               return true;
           }
        }

//        mat.get(p) = 'y';//antes da recursão
//        mat_draw(mat); //Pinta na tela a matriz
//        ed_show();


    return false;

}
    return 0;
}



int main(){
    matchar mat(nlinhas, ncolunas, 'k');
   // mat_paint_brush(mat, "gw");
//    Par p = mat_get_click(mat, "Escolha onde comeca o fogo.");
//    Par destino = mat_get_click(mat, "Escolha o segundo ponto");

//    if(queimar(mat, p, destino) == true){
//        cout << "O segundo ponto quimou" << endl;
//    } else {
//        cout << "O segundo ponto nao queimou" << endl;
//    }
    Par p(1, 1);
    queimar(mat, p);
    mat_draw(mat);

    ed_lock();

    return 0;
}


