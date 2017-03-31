#include "libs/view.h"
#include "aluno/jogo_velha.h"
#include "aluno/exemplo_lab.h"
#include "aluno/teste_matrizes.h"

//Funcao para descobrir se o ponto pode virar caminho
bool eh_furavel(matchar mat, Par par){
    int cont = 0;
    int cont2 = 0;
    if(par.l <= 0 or par.l >= mat.sizeL() - 1){ 
        return false;
    }
    if(par.c <= 0 or par.c >= mat.sizeC() - 1){
        return false;
    }
    if(mat.get(par) == 'w'){
        return false;
    }

    if(mat.get(par.l, par.c - 1) == 'k') cont++;
    if(mat.get(par.l, par.c + 1) == 'k') cont++;
    if(mat.get(par.l - 1, par.c) == 'k') cont++;
    if(mat.get(par.l + 1, par.c) == 'k') cont++;

    if(mat.get(par.l, par.c - 1) == 'w') cont2++;
    if(mat.get(par.l, par.c + 1) == 'w') cont2++;
    if(mat.get(par.l - 1, par.c) == 'w') cont2++;
    if(mat.get(par.l + 1, par.c) == 'w') cont2++;

    if(cont2 > 1){
       return false;
    }
    if(cont >= 3){
       return true;
    } else {
      return false;
    }
}

//Funcao para embaralhar os posiveis caminho
vector<Par> shuffle(vector<Par> &vet){
    for(int i = 0; i < (int) vet.size(); i++){
        std::swap(vet[i], vet[rand() % (int) vet.size()]);
    }
    return vet;
}

//Funcao para pegar os pontos visinhos
vector<Par> pegar_vizinhos(Par par){
    vector<Par> vizinhos;
    vizinhos.push_back(Par(par.l, par.c - 1));
    vizinhos.push_back(Par(par.l, par.c + 1));
    vizinhos.push_back(Par(par.l - 1, par.c));
    vizinhos.push_back(Par(par.l + 1, par.c));
    return vizinhos;
}


//Funcao para criar o labirinto
bool queimar(matchar &mat, Par par){
/*    int cont = 0;
    if(mat.get(par.l, par.c - 1) == 'k') cont++;
    if(mat.get(par.l, par.c + 1) == 'k') cont++;
    if(mat.get(par.l - 1, par.c) == 'k') cont++;
    if(mat.get(par.l + 1, par.c) == 'k') cont++;

cont >= 3*/
    if(eh_furavel(mat, par) == true){
    if(mat.get(par) == 'k'){
        mat.get(par) = 'w';

        my_view->paint(mat);
        auto viz = pegar_vizinhos(par);
        vector<Par> fura;
        for(auto x : viz){
            if(eh_furavel(mat, x) == true){
                fura.push_back(x);
            }
        }
        shuffle(fura);
        for(auto x : fura){
            queimar(mat, x);
            if(queimar(mat, x)){
               mat.get(par) = 'y';
               my_view->paint(mat);
               return true;
            }
        }
        mat.get(par) = 'y';
        my_view->paint(mat);
     return false;
    }
    }
    return false;
}

//Funcao para achar o caminho entre dois pontos
bool viagem(matchar &mat, Par pi, Par pf){
    if(pi.l <= 0 or pi.l >= mat.sizeL() - 1){
        return false;
    }
    if(pi.c <= 0 or pi.c >= mat.sizeC() - 1){
        return false;
    }

    if(mat.get(pi) == 'y'){
    mat.get(pi) = 'm';
    my_view->paint(mat);

    if(mat.get(pf) == 'm'){
        mat.get(pf) = 'c';
        return true;
    }

    auto viz = pegar_vizinhos(pi);
    shuffle(viz);

    for(auto x : viz){
        if(viagem(mat, x, pf)){
            mat.get(pi) = 'c';
            my_view->paint(mat);
            return true;
        }
    }
  }
    return false;
}

//Funcao principal
int main(){
    matchar mat(20, 40, 'k');
    Par par(1, 1);
    queimar(mat, par);

    Par p = my_view->select_point(mat, "escolha onde comeca");
    Par m = my_view->select_point(mat, "escolha onde termina");
    viagem(mat, p, m);

    my_view->paint(mat);

    my_view->wait();
    return 0;
}























