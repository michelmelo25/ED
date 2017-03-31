#include <iostream>
#include <sstream>

using namespace std;

struct Node{
    int value;
    Node * next;
    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }
};

struct List{
    Node * head;

    List(Node * head = nullptr){
        this->head = head;
    }

    int rsize(Node * node){
        if(node == nullptr)
            return 0;
        return 1 + rsize(node->next);
    }

    int size(){
        if(this->head == nullptr)
            return 0;
        return 1 + rsize(this->head->next);
    }

    Node * rinset(int value, Node * node){
        if(node == nullptr){
            return new Node(value);
        }
        if(node->value > value){
            return new Node(value, node);
        }
        node->next = rinset(value, node->next);
        return node;
    }

    void insert(int value){
        this->head = rinset(value, this->head);
    }

    Node * rremove(int value, Node * node){
        if(node->value == value){
            auto next = node->next;
            delete node;
            return next;
        }
        node->next = rremove(value, node->next);
        return node;
    }

    void remove(int value){
        if(this->head == nullptr)
            return;
        this->head = rremove(value, this->head);
    }

    bool requals(Node * node, Node * other){
        if((node == nullptr) && (other == nullptr))
            return true;
        if((node != nullptr) && (other == nullptr))
            return false;
        if((node == nullptr) && (other != nullptr))
            return false;
        if(node->value != other->value)
            return false;
        return requals(node->next, other->next);
    }

    bool equals(List &other){
        return requals(this->head, other.head);
    }

    Node * rclone(Node * other){
        if(other == nullptr)
            return nullptr;
        auto node = new Node(other->value);
        node->next = rclone(other->next);
        return node;
    }

    void clone(List &other){
        head = rclone(other.head);
    }

    void rshow(Node * node){
        if(node == nullptr)
            return;
        cout << node->value <<  " ";
        rshow(node->next);
    }

    void show(){
        cout << "[ ";
        rshow(this->head);
        cout << "]" << endl;
    }

    void print(){
        auto node = head;
        while (true) {
           if(node == nullptr)
               return;
           cout << node->value <<  " ";
           node = node->next;
        }
    }
};

int main(){
    List lista;
    List other;
    lista.insert(5);
    lista.insert(8);
    lista.insert(3);
    lista.insert(4);
    lista.insert(2);
    lista.insert(9);
    lista.insert(1);
    lista.insert(7);
    lista.insert(6);
    lista.show();
    other.clone(lista);
    other.show();   
    if(lista.equals(other)){
        cout << "Iguais" << endl;
    }else{
        cout << "Diferentes" << endl;
    }

    lista.remove(5);
    lista.show();
    if(lista.equals(other)){
        cout << "Iguais" << endl;
    }else{
        cout << "Diferentes" << endl;
    }

    cout << lista.size() << endl;
    //cout << "Hello World!" << endl;
    return 0;
}
