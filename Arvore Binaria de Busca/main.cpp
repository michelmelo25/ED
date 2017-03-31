#include <iostream>
#include <sstream>

using namespace std;

struct Node{
    int value;
    Node * left;
    Node * right;

    Node(int value = 0){
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

struct Btree{
    Node * root;

    Btree(){
        this->root = nullptr;
    }

    ~Btree(){
        clear();
    }

    void apagar(Node * node){
        if(node == nullptr)
            return;
        apagar(node->left);
        apagar(node->right);
        delete node;
    }

    void clear(){
        apagar(root);
        root = nullptr;
    }

    void rshow(Node * node, int nivel){
        if(node == nullptr)
            return;
        rshow(node->left, nivel + 1);
        if(node == nullptr){
            cout << string(4 * nivel, ' ') << '#' << endl;
        }else{
            cout << string(4 * nivel, ' ') << node->value << endl;
        }
        rshow(node->right, nivel + 1);
    }

    void show(){
        rshow(root, 0);
    }

    Node ** smart_find(Node ** casa, int value){
        auto node = *casa;
        if(node == nullptr || node->value == value)
            return casa;
        if(node->value > value)
            return smart_find(&node->right, value);
        if(node->value < value)
            return smart_find(&node->left, value);
    }

    Node * find(int value){
        auto node = smart_find(&root, value);
        return *node;
    }

    void insert(int value){
        auto casa = smart_find(&root,value);
        if(*casa == nullptr)
            *casa = new Node(value);
    }

    void r_remove(Node ** casa){
        auto node = *casa;

        if(node->left == nullptr && node->right == nullptr){
            *casa = nullptr;
            delete node;
            return;
         }
        if(node->left == nullptr && node->right != nullptr){
            *casa = node->right;
            delete node;
            return;
         }
        if(node->left != nullptr && node->right == nullptr){
            *casa = node->left;
            delete node;
            return;
         }

         node = node->right;
        while (node->left != nullptr) {
            node = node->left;
        }
        (*casa)->value = node->value;
        //(*casa)->right = nullptr;
        cout << node->value << endl;
        r_remove(&node);

    }

    bool remove(int value){
        auto casa = smart_find(&root,value);
        if(*casa != nullptr){
            r_remove(casa);
            return true;
        }
        return false;
    }

    void clone_elo(Node ** elo, Node * other){
        if(other == nullptr)
            return;
        *elo = new Node(other->value);
        clone_elo(&(*elo)->left, other->left);
        clone_elo(&(*elo)->right, other->right);
    }

    Node * clone(Node * other){
        if(other == nullptr)
            return nullptr;
        Node * node = new Node(other->value);
        node->left = clone(other->left);
        node->right = clone(other->right);
        return node;
    }

    void clone(Btree other){
        root = clone(other.root);
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
        return requals(node->left, other->left) && requals(node->right, other->right);
    }

    bool equals(Btree other){
        return requals(root, other.root);
    }
};

int main(){
    Btree tree;
    Btree arvore;

    tree.insert(5);
    tree.insert(8);
    tree.insert(3);
    tree.insert(2);
    tree.insert(9);
    tree.insert(10);
    tree.insert(7);
    tree.show();
    cout << endl;
    tree.remove(8);
   tree.show();
   tree.remove(9);
   tree.show();
   tree.remove(5);
   tree.show();

    //arvore.clone(tree);
    //arvore.clone_elo(&arvore.root, tree.root);
    //cout << endl;
    //arvore.show();
    //cout << endl;
   // cout << tree.equals(arvore) << endl;
   // tree.insert(4);
   // tree.show();
   // cout << tree.equals(arvore) << endl;
    //cout << "Hello World!" << endl;
    return 0;
}
