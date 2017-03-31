#include <lib/pen.h>
#include <iostream>

using namespace std;

static int cont = 4;

void Arvore(Pen &p, float lado){
    if(lado < 5){
        if(((rand() % 100) > 3) == 0){
            p.setColor(255, 0, 0);
            p.circle(8);
        }
        return;
    }
    int ang = 30;
    p.walk(lado);
    p.right(ang);
    Arvore(p, lado * 0.7);
    p.left(2 * ang);
    p.setColor(255, 255, 255);
    Arvore(p, lado * 0.7);
    p.right(ang);
    p.setColor(166, 166, 166);
    p.walk(-lado);
}

void fazer_quadrado(Pen &p, float lado){
    p.up();
    p.setHeading(135);
    p.walk(lado * 0.75);
    p.setHeading(0);
    p.down();
    for(int i = 0; i < 4; i++){

        p.walk(lado);
        p.right(90);
    }
    p.up();
    p.right(45);
    p.walk(lado * 0.75);

}

void expiral_de_quadrado(Pen &p, float lado){
    int j = 1;


    for(int i = 0; i < 1200; i++){
        p.up();
        p.walk(2 + i/3);

        if(i == j){
            fazer_quadrado(p, j/5);

            j = j * 5;
        }
        p.walk(-2 - i/3);
        p.right(1);
        p.down();






    }

}

void Triangulo(Pen &p, float lado){
    if(lado < 5){
        return;
    }
    for(int i = 0; i < 3; i++){
        p.walk(lado);
        p.right(120);
        Triangulo(p, lado/2);
    }
}

void gelo(Pen &p, float lado){
    if(lado < 1){
        return;
    }

    for(int i = 0; i < 5; i++){

        p.walk(lado);
        gelo(p, lado*0.35);


        p.walk(-lado);
        p.right(72);
    }
}


void rotacao(Pen &p, float lado){
    p.setColor(rand() % 255, rand() % 255,rand() % 255);
    if(lado < 20){
        return;
    }
    if(lado < 100){
        p.setThickness(1);
    }
    p.walk(lado);
    p.right(90);
    rotacao(p, lado*0.98);
}

void trigo(Pen &p, float lado){
    cont--;
    if(cont < 0){
        return;
    }
    float aux = lado;
    for(int i = 0; i < 1; i++){
        p.walk(aux);
        p.right(45);
        aux = lado/4;
        for(int j = 0; j < 4; j++){
            p.walk(aux);
            p.right(90);
            for(int k = 0; k < 4; k++){
                p.walk(aux*0.5);
                p.right(90);
                p.walk(aux*0.5);
                p.up();
                p.left(180);
                p.walk(aux*0.5);
                p.right(90);
                p.down();
            }
            //p.up();
            p.setColor(255,000,000);
            p.left(180);
            p.walk(aux*2);
            p.right(90);
            // p.down();
        }
        p.setColor(000,000,255);
        p.left(180);
        p.walk(lado);
        p.left(45);
        p.right(180);
    }
    trigo(p, lado);
}

void quad(Pen &p, float lado){
    for(int i = 0; i <= 3; i++){
        p.walk(lado);
        p.right(90);

    }
}

void circulo(Pen &p, float lado){
    if(lado < 4){
         return;
        }

        for(int i = 0; i < 6; i++){

            p.up();
            p.walk(lado);
            p.down();
            p.circle(lado/3);
            circulo(p, lado/3);
            p.up();
            p.walk(-lado);
            p.right(60);
        }
    }


void quadrado(Pen &p, float lado){
    if(lado < 5){
        return;
    }
    quad(p, lado);
    p.left(90);
    p.walk(lado/4);
   // quadrado(p, lado/2);
}

void fractal(){
   Pen p(720, 720);

   //Arvore
//   p.setXY(650, 700);
//   p.setHeading(90);
//   p.setSpeed(3);
//   p.setThickness(2);
//   Arvore(p, 200);

   //Triangulo
//   p.setXY(100,100);
//   p.setHeading(0);
//   p.setSpeed(10);
//   p.setThickness(3);
//   Triangulo(p, 550);

   //Rotacao
//   p.setXY(100,30);
//   p.setHeading(0);
//   p.setSpeed(50);
//   p.setThickness(3);
//   rotacao(p, 550);

   //Trigo - imcompleto
//   p.setXY(400, 600);
//   p.setHeading(90);
//   p.setSpeed(8);
//   p.setThickness(1);
//   trigo(p, 130);

   //Quadrado - imcompleto
//     p.setXY(200, 100);
//     p.setHeading(0);
//     p.setSpeed(50);
//     p.setThickness(1);
//     quadrado(p, 400);

   //Circulo
//   p.setXY(450, 360);
//   p.setHeading(0);
//   p.setSpeed(50);
//   p.setThickness(1);
//   p.circle(250);
//   circulo(p, 250);

   //expiral de quadrados
//   p.setHeading(0);
//   p.setThickness(1);
//   p.setSpeed(200);
//   expiral_de_quadrado(p, 400);

   //Gelo
     p.setXY(300, 300);
     p.setHeading(0);
     p.setSpeed(0);
     p.setThickness(1);
     p.right(90);
     gelo(p, 200);

   p.wait();
}

int main(){
    fractal();
    return 0;
}

/*
    int op = 0;

    while ((op >= 0) && (op <= 2)) {
        cout << "Fractais" << endl;
        cout << "1 - Arvore" << endl;
        cout << "2 - Triangulo" << endl;
        cout << "0 - Sair" << endl;
        cin >> op;
        switch (op) {
            case 1:
                //Arvore
                p.setXY(650, 700);
                p.setHeading(90);
                p.setSpeed(10);
                p.setThickness(3);
                Arvore(p, 200);
                p.wait();
                break;
            case 2:
                //Triangulo
                p.setXY(100,100);
                p.setHeading(0);
                p.setSpeed(10);
                p.setThickness(3);
                Triangulo(p, 550);
                p.wait();
                break;
             case 0:
                //Sair
                return;
                break;
        }
    }
*/
