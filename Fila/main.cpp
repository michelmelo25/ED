#include <iostream>
#include <vector>

using namespace std;

struct Queue{

    int * _data;
    int _ultimo {0};
    int _max;
    int _primeiro = 0;

    Queue(int max){
        _max = max;
        _data = new int[_max];
    }

    ~Queue(){
        delete [] _data;
    }

    int &front(){
        static int dummy = 0;
        if(_ultimo == 0){
            return dummy;
        }
        return _data[_primeiro];
    }

    int &back(){
        static int dummy = 0;
        if(_ultimo == 0){
            return dummy;
        }
        return _data[_ultimo];
    }

    int * begin(){
        static int dummy = 0;
        if(_ultimo == 0){
            return &dummy;
        }
        return  &_data[_primeiro];
    }

    int * end(){
        static int dummy = 0;
        if(_ultimo == 0){
             return &dummy;
        }
        return &_data[_ultimo];
    }

    int size(){
        return _ultimo;
    }

    void remover_todos(int value){
        for(int i = 0; i < _ultimo; i++){
            if(_data[i] == value){
                remove(i);
                i--;
            }
        }
    }

    void realocar_fila(){
        cout << "Fila cheia, realocando memoria" << endl;
        int * aux = _data;
        _max = 2 * _max;
        _data = new int[_max];
        for(int i = 0; i < _ultimo; i++){
        _data[i] = aux[i];
        }
        delete [] aux;
    }
    void push(int value){
        if(_ultimo == _max){
            realocar_fila();
        }

        _data[_ultimo] = value;
        _ultimo++;
    }

    void pop(){
        if(_ultimo > 0){
            _primeiro++;
        }
    }

    int &get(int indice){
        return _data[indice];
    }

    void insert(int value, int pos){
        if(_ultimo == _max){
            realocar_fila();
        }
        if(_ultimo < _max){\
            int aux;
             _data[_ultimo] = value;
             _ultimo++;
            for(int i = _ultimo - 1; i > pos; i--){
                aux = _data[i - 1];
                _data[i - 1] = value;
                _data[i] = aux;
            }
         }
    }

    void remove(int pos){
           int i = pos;
           while (i < _ultimo){
               _data[i] = _data[i + 1];
               i++;
           }
           _ultimo--;
    }
};

int main(){
    Queue fila(3);
    fila.push(1);
    fila.push(2);
    fila.push(4);

    fila.push(9);
    fila.push(90);
    fila.push(5);
    fila.push(5);
    fila.push(2);
    fila.push(2);
    fila.push(9);
    fila.push(4);
    fila.push(2);
    fila.push(2);
    fila.push(9);
    fila.push(8);
    fila.pop();
    fila.insert(1,8);
    fila.remove(3);

    for(auto x : fila){
        cout << x << " ";
    }
    cout << endl;
    for(int i = 0; i < fila.size(); i++){
        cout << fila.get(i) << " ";
    }
    cout << endl;
    fila.remover_todos(2);
    for(int i = 0; i < fila.size(); i++){
        cout << fila.get(i) << " ";
    }
    cout << endl;
    cout << fila.get(4) << endl;
    cout << fila.front() << endl;
    cout << fila.back() << endl;
    cout << fila.begin() << endl;
    cout << fila.end() << endl;
    return 0;
}













