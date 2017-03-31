#include <iostream>

using namespace std;

const int VAZIO = -1;
const int APAGADO = -2;

struct Item{
    int value;
    int key;

    Item(){
        this->value = 0;
        this->key = VAZIO;
    }
};

struct HashTable{
    int size;
    int max;
    Item * data;

    HashTable(int max){
        this->max = max;
        this->data = new Item[max];
    }

    ~ HashTable(){
        delete [] data;
    }

    Item * find(int key){
        int pos = key % this->max;
        while (true) {
            if(this->data[pos].key == key)
                return &this->data[pos];
            if(this->data[pos].key == VAZIO)
                return &this->data[pos];
            pos = (pos + 1) % this->max;
        }
    }

    void realocar(){
        auto vetaux = this->data;
        this->max = this->max * 2;
        this->data = new Item[this->max];

        for(int i = 0; i < max/2; i++){
            if(vetaux[i].key != VAZIO && vetaux[i].key != APAGADO)
                insert(vetaux[i].key, vetaux[i].value);
        }
        delete [] vetaux;
    }

    bool insert(int key, int value){
        if(this->size > (this->max / 2))
            realocar();

        int pos = key % this->max;

        while (true) {
            if(this->data[pos].key == VAZIO || this->data[pos].key == APAGADO){
                this->data[pos].key = key;
                this->data[pos].value = value;
                this->size++;
                return true;
            }
            pos = (pos + 1) % this->max;
        }
        return false;
    }

    bool remove(int kay){
        auto pos = find(kay);
        if(pos->key == kay){
            pos->key = APAGADO;
            return true;
        }
        return false;
    }

    void show(){
        cout << "| ";
        for(int i = 1; i <= max; i++){
            cout << i - 1 << ", " << this->data[i - 1].key << ", " << this->data[i - 1].value << " | ";
            if((i % 5) == 0 && i != max)
                cout << endl << "| ";
        }
        cout << endl;
    }
};

int main(){
    //cout << "Hello World!" << endl;
    HashTable has(5);
    has.insert(2,7);
    has.insert(3,9);
    has.insert(5,1);
    has.insert(8,2);
    has.insert(10,15);
    has.insert(15, 10);
    has.show();

    return 0;
}
