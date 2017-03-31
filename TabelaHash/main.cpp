#include <iostream>

using namespace std;

const int VAZIO = -1;
const int APAGADO = -2;

struct Item{
    int key;
    int value;

    Item(int key = VAZIO, int value = 0){
        this->key = key;
        this->value = value;
    }
};

struct HashTable{
    int max;
    int size;
    Item * data;

    HashTable(int max){
        this->max = max;
        this->data = new Item[max];
    }

    ~HashTable(){
        delete [] data;
    }

    void show(){
        cout << endl << "|";
        for(int i = 0; i < max; i++){
            cout << i << "," << data[i].key << "," << data[i].value << "|";
        }
        cout << endl;
    }

    //retorna o endereco do elemento ou null
    Item * find(int key){
        int pos = key % this->max;
        while (true) {//continue buscando
            if(this->data[pos].key != VAZIO)
                break;
            if(this->data[pos].key == key)
                break;
            pos = (pos + 1) % this->max;
        }
        if(data[pos].key == key)
            return &data[pos];
        return nullptr;
    }

    bool remove(int key){
        auto pos = find(key);
        if(pos != nullptr){
            pos->key = APAGADO;
            this->size--;
            return true;
        }
        return false;
    }

    void dobrar(){
        auto vetaux = this->data;
        this->max = this->max * 2;
        this->data = new Item[max];
        for(int i = 0; i < this->max/2; i++){
            if((vetaux[i].key != APAGADO) && (vetaux[i].key != VAZIO))
                insert(vetaux[i].key, vetaux[i].value);
        }
        delete [] vetaux;
    }

    bool insert(int key, int value){
        if(this->size >= (max/2))
            dobrar();

        int pos = key % this->max;
        while (true) {
            if((this->data[pos].key == VAZIO) || (this->data[pos].key == APAGADO)){
                this->data[pos].key = key;
                this->data[pos].value = value;
                this->size++;
                return true;
            }
            if(this->data[pos].key == key)
                break;
            pos = (pos + 1) % this->max;
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    HashTable tab(5);
    tab.insert(5,111);
    tab.show();
    tab.insert(4,543);
    tab.show();
    tab.insert(1,35463);
    tab.show();
    tab.remove(5);
    tab.insert(6,435);
    tab.show();
    tab.insert(8,3345);
    tab.show();
    return 0;
}
