#include <iostream>

using namespace std;

struct Node{
    int value;
    Node * next;
    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }
};

//lista simples sem cabeca
struct SList{
    Node * head;
    int _size = 0;
    SList(){
        head = nullptr;
    }

    Node begin(){
        return head;
    }

    int rsize(Node * node){
        if(node->next == nullptr){
            return 0;
        }
        return 1 + rsize(node->next);
    }

    int size(){
        if(head == nullptr){
            return 0;
        }
        return 1 + rsize(head);

    }

    void push_front (int value){
        Node * node = new Node(value, head);
        head = node;
    }

    void pop_front (){
        if(head == nullptr){
            return;
        }
        auto aux = head;
        head = head->next;
        delete aux;
    }

    void rpush_back(Node * node, int value){
        if(node->next == nullptr){
            node->next = new Node(value, nullptr);
        }
        rpush_back(node->next, value);
    }

    void push_back(int value){
        if(head == nullptr){
            Node * node = new Node(value, nullptr);
            return;
        }
        rpush_back(head, value);
    }

    void rpop_back(Node * node){
        if(node->next->next == nullptr){
           delete node->next;
           node->next = nullptr;
           return;
        }
        rpop_back(node->next);
    }

    void pop_back(){
        if(head == nullptr){
            return;
        }
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        rpop_back(head);
    }

    Node * rfind(Node * node, int value){
        if(node->value == value){
            return node;
        }
        rfind(node->next, value);
    }

    Node * find(int value){
        if(head->value == value){
            return head;
        }
        return rfind(head->next, value);
    }

    bool erase(int value){
        auto node = head;
        if(node == nullptr){
            return false;
        }
        if(head->value == value){
            auto aux = head;
            head = head->next;
            delete aux;
            return true;
        }
        while(node->next != nullptr){
            if(node->next->value == value){
                auto aux = node->next;
                node->next = node->next->next;
                delete aux;
                return true;
            }
            node = node->next;
        }
    }

    bool erase(Node * node){
        auto nod = head;
        if(nod == nullptr){
            return false;
        }
        while (nod->next != nullptr) {
            if(nod == node){
                if(node->next != nullptr){

                }
            }
        }
    }

    void print(){
        auto node = head;
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }

    bool insert(Node * node, int value){
           (void) node;
           (void) value;
           return false;
       }
};

int somar_todos(int num){
    int soma = 0;
    if(num == 0)
       return 0;
    soma += num%10;
    return soma += somar_todos(num/10);
}

int inverte(int num){
    int soma = 0;
    if(num == 0)
       return 0;
    soma = (num % 10);
    return soma * 10 + somar_todos(num/10);
}

int main()
{
//    SList lista;
//    for(int i = 0; i < 10; i += 2)
//        lista.push_front(i);
//    lista.print();
//    lista.pop_front();
//    lista.print();
//    lista.push_back(7);
//    lista.print();

    cout << somar_todos(2345) << endl << inverte(2345);
    return 0;
}
