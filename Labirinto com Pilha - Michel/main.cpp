#include "libs/ed_base.h"
#include "libs/ed_mat.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

int nlinhas = 20;
int ncolunas = 35;

const char PAREDE = 'k';
const char VAZIO = 'w';

//r red
//g green
//b blue
//m magenta
//c cyan -
//y yellow
//w white
//k black

vector<Par> vizinhos(Par par){
    vector<Par> vizinhos;
    vizinhos.push_back(Par(par.l, par.c - 1));
    vizinhos.push_back(Par(par.l, par.c + 1));
    vizinhos.push_back(Par(par.l - 1, par.c));
    vizinhos.push_back(Par(par.l + 1, par.c));
    return vizinhos;
}

vector<Par> shuffle(vector<Par> &vet){
    for(int i = 0; i < (int) vet.size(); i++){
        std::swap(vet[i], vet[rand() % (int) vet.size()]);
    }
    return vet;
}

//Funcao para saber quais paredes podem ser furadas
bool eh_furavel(matchar &mat, Par p){
    int cont = 0;
    if(!mat.equals(p, PAREDE))
        return false;
    for(auto &viz : vizinhos(p)){
        if(mat.equals(viz, PAREDE))
            cont++;
    }
    return (cont >= 3);
}

//Funcao que sortei a parede que sera furada
int sortear(int x){
    return rand() % x;
}

//Funcao para mostrar o labirinto
void mostrar_lab(matchar &mat, stack<Par> pilha){
    mat_draw(mat);
    while (!pilha.empty()){
        mat_focus(pilha.top(), 'y');
        pilha.pop();
    }
    ed_show();
}

//Funcao para saber se o proximo ponto e camino
Par eh_caminho(matchar mat, Par p){
    Par caminho; //cria um struc de par
    for(auto viz : vizinhos(p)){ //para car um dos vizinhos do ponto
        if(mat.get(viz) == VAZIO){ //esse vizinho pode ser caminho
            caminho = viz; //variavel caminho recebe o ponto
        }
    }
    return caminho; //retorna o caminho
}

//Funcao para mostrar o caminho de volta
void volta(matchar &mat, stack<Par> pilha){
   while(!pilha.empty()){ //enquato a pilha nao for vazia
       mat_focus(pilha.top(), 'y');
       mostrar_lab(mat, pilha);
       mat.get(pilha.top()) = 'c'; //pinta o ponto de ciano
       pilha.pop(); //retira o ponto da pilha
       mostrar_lab(mat, pilha); //mostra o labirinto
   }
}

//Funcao para achar o caminho entre dois pontos
bool viagem(matchar &mat, stack<Par> &pilha, Par pont_um, Par pont_dois){
    pilha.push(pont_um); //coloca o ponto inicial na pilha
    mat.get(pilha.top()) = 'm'; //pinta o ponto de magenta
    mostrar_lab(mat, pilha); //mostra o labirinto

    while(!pilha.empty()){ //enquanto a pilha nao for vazia
        Par caminho; //cria uma struct de par
        caminho = eh_caminho(mat, pilha.top()); //atribui o caminho na variavel caminho

        if(mat.is_inside(caminho)){ //o ponto caminho esta na matriz
            if(mat.get(caminho) == VAZIO){ //o ponto caminho realmente é caminho
                pilha.push(caminho); //coloca o ponto na pilha
                mostrar_lab(mat, pilha);
                mat.get(caminho) = 'm'; //pinta o ponto de magenta
                mostrar_lab(mat, pilha); //mostra o labirinto
                if(mat.get(pont_dois) == 'm'){ //o ponto final foi pintado de magenta
                    volta(mat, pilha); //chama a funcao que mostra o caminho de volta
                    return true; //retorna vertade
                }
            } else{ //se nao for realmente caminho
                pilha.pop(); //retire o ponto da pilha
                mostrar_lab(mat, pilha);
            }
      } else{ // se nao estiver na matriz
            pilha.pop(); //retire o ponto da pilha
            mostrar_lab(mat, pilha);
        }
    }
    return true; // retorna verdade
}

//Criando o labirinto
void criar_lab(matchar &mat, stack<Par> &pilha){
    mat.get(Par(1, 1)) = VAZIO;
    pilha.push(Par(1, 1));
    mostrar_lab(mat, pilha);

    while(!pilha.empty()){
        vector<Par> furaveis;
        for(auto viz : vizinhos(pilha.top()))
            if(eh_furavel(mat, viz))
                furaveis.push_back(viz);
        if(furaveis.size() == 0){
            pilha.pop();
            mostrar_lab(mat, pilha);
        }else{
            //selecionar um dos vizinhos furaveis
            Par sortudo = furaveis[sortear(furaveis.size())];
            mat.get(sortudo) = VAZIO;
            pilha.push(sortudo);
            mostrar_lab(mat, pilha);
        }

    }
    mostrar_lab(mat, pilha);
}

bool dentro_mat(matchar mat, Par p){
    if(p.l > 0 && p.l <= mat.sizeL() -1){
        if(p.c > 0 && p.c <= mat.sizeC() -1){
           if(mat.get(p) == VAZIO){
               return true;
           }
        }
    }
 return false;
}

int main(){
    stack<Par> pilha;
    matchar mat(nlinhas, ncolunas, PAREDE);
    criar_lab(mat, pilha);

    Par pont_um = mat_get_click(mat, "Selecione onde comeca");
    Par pont_dois = mat_get_click(mat, "Selecione o segundo ponto");

    if(dentro_mat(mat, pont_um) == true){
        if(dentro_mat(mat, pont_dois) == true){
          viagem(mat, pilha, pont_um, pont_dois);
        }
    }

    mat_draw(mat);
    ed_show();

    ed_lock();

    return 0;
}


