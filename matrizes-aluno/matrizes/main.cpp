#include "libs/view.h"
#include "aluno/jogo_velha.h"
#include "aluno/exemplo_lab.h"
#include "aluno/teste_matrizes.h"

//for(int i = 0; i < 10; i++){
//    mat.get(i, i) = 'k';
//    my_view->paint(mat);
//}

//for(int i = 0; i < 10; i++){
//    mat.get(9 - i, i) = 'k';
//    my_view->paint(mat);
//}

//my_view->paint(mat);
//my_view->paint_brush(mat, "wrgbycmk");
//my_view->paint(mat);
//Par p = my_view->select_point(mat, "escolha um ponto verde");
//if(mat.get(p) != 'g'){
//    cout << "erro";
//}

vector<Par> pegar_vizinhos(Par par){
    vector<Par> vizinhos;
    vizinhos.push_back(Par(par.l, par.c - 1));
    vizinhos.push_back(Par(par.l, par.c + 1));
    vizinhos.push_back(Par(par.l - 1, par.c));
    vizinhos.push_back(Par(par.l + 1, par.c));
    return vizinhos;
}

void queimar(matchar &mat, Par par, Par m, bool &destino){
    if(par.l < 0 or par.l >= mat.sizeL()){
        return;
    }
    if(par.c < 0 or par.c >= mat.sizeC()){
        return;
    }
    if(mat.get(par) == 'g'){
        mat.get(par) = 'r';
        if(par == m){
            destino = true;
        }
        my_view->paint(mat);
        for(auto x : pegar_vizinhos(par)){
            queimar(mat, x, m, destino);
        }
    }
}

int main(){
    //ALUNO
    //aluno::queimada_aluno();
    bool destino = false;
    matchar mat(20, 40, 'g');
    my_view->paint_brush(mat, "wg");
    Par p = my_view->select_point(mat, "escolha onde comeca o fogo");
    Par m = my_view->select_point(mat, "escolha o segundo ponto");

    my_view->paint(mat);

    queimar(mat, p, m, destino);
    if(destino == true){
        cout << "segunto ponto ira queimar";
    } else {
        cout << "segundo ponto nao ira quimar";
    }

    my_view->wait();
    //jogo da velha
    //velha_main();
    //teste_matrizes();

    return 0;
}























