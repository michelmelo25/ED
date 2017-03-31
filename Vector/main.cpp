#include <iostream>
#include <vector>

using namespace std;

struct Vector{

    int * _data;
    int _size {0};
    int _max;

    Vector(int max){
        _max = max;
        _data = new int[_max];
    }

    ~Vector(){
        delete [] _data;
    }

    int &front(){
        static int dummy = 0;
        if(_size == 0){
            return dummy;
        }
        return _data[0];
    }

    int &back(){
        static int dummy = 0;
        if(_size == 0){
            return dummy;
        }
        return _data[_size - 1];
    }

    int * begin(){
        static int dummy = 0;
        if(_size == 0){
            return &dummy;
        }
        return  &_data[0];
    }

    int * end(){
        static int dummy = 0;
        if(_size == 0){
             return &dummy;
        }
        return &_data[_size];
    }

    int size(){
        return _size;
    }

    void remover_todos(int value){
        for(int i = 0; i < _size; i++){
            if(_data[i] == value){
                remove(i);
                i--;
            }
        }
    }

    void realocar_vetor(){
        cout << "Vector cheio, realocando memoria" << endl;
        int * aux = _data;
        _max = 2 * _max;
        _data = new int[_max];
        for(int i = 0; i < _size; i++){
        _data[i] = aux[i];
        }
        delete [] aux;
    }
    void push_back(int value){
        if(_size == _max){
            realocar_vetor();
        }

        _data[_size] = value;
        _size++;
    }

    void pop_back(){
        if(_size > 0){
            _size--;
            _data[_size] = 0;
        }
    }

    int &get(int indice){
        return _data[indice];
    }

    void insert(int value, int pos){
        if(_size == _max){
            realocar_vetor();
        }
        if(_size < _max){\
            int aux;
             _data[_size] = value;
             _size++;
            for(int i = _size - 1; i > pos; i--){
                aux = _data[i - 1];
                _data[i - 1] = value;
                _data[i] = aux;
            }
         }
    }

    void remove(int pos){
           int i = pos;
           while (i < _size){
               _data[i] = _data[i + 1];
               i++;
           }
           _size--;
    }
};

int main(){
    Vector vector(3);
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(4);

    vector.push_back(9);
    vector.push_back(90);
    vector.push_back(5);
    vector.push_back(5);
    vector.push_back(2);
    vector.push_back(2);
    vector.push_back(9);
    vector.push_back(4);
    vector.push_back(2);
    vector.push_back(2);
    vector.push_back(9);
    vector.push_back(8);
    vector.pop_back();
    vector.insert(1,8);
    vector.remove(3);

    for(auto x : vector){
        cout << x << " ";
    }
    cout << endl;
    for(int i = 0; i < vector.size(); i++){
        cout << vector.get(i) << " ";
    }
    cout << endl;
    vector.remover_todos(2);
    for(int i = 0; i < vector.size(); i++){
        cout << vector.get(i) << " ";
    }
    cout << endl;
    cout << vector.get(4) << endl;
    cout << vector.front() << endl;
    cout << vector.back() << endl;
    cout << vector.begin() << endl;
    cout << vector.end() << endl;
    return 0;
}













