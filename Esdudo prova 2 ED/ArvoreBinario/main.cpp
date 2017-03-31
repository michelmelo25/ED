#include <iostream>

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

struct Tree{
    Node * root {nullptr};

    Tree(){
        this->root = nullptr;
    }

    ~Tree(){
        clear();
    }

    void rclear(Node * node){
        rclear(node->left);
        rclear(node->right);
        delete node;
    }

    void clear(){
        rclear(root);
        delete root;
    }

    Node ** smart_find(Node ** casa, int value){
        auto node = *casa;
        if((node == nullptr) || (value == node->value))
            return &node;
        if(value > node->value)
            return smart_find(&node->right, value);
        if(value < node->value)
            return smart_find(&node->left, value);
    }

    void insert(int value){
        auto elem = smart_find(&root, value);
        if(*elem == nullptr)
            *elem = new Node(value);
    }

    bool rremove(Node ** casa){
        auto node = *casa;
        if(node->left == nullptr && node->right == nullptr){
            (*casa) = nullptr;
            delete node;
            return true;
        }
        if(node->left != nullptr && node->right == nullptr){
            (*casa) = node->left;
            delete node;
            return true;
        }
        if(node->left == nullptr && node->right != nullptr){
            (*casa) = node->right;
            delete node;
            return true;
        }

        auto sucessor = &node->right;
        while ((*sucessor)->left != nullptr) {
            sucessor = &(*sucessor)->left;
        }
        (*casa)->value = (*sucessor)->value;
        return rremove(sucessor);
    }

    bool remove(int value){
        rremove(smart_find(&root, value));
    }

    void rclone (Node ** node, Node ** other){
        if(other == nullptr)
            return;
        (*node) = new Node((*other)->value);
        rclone(&(*node)->left, &(*other)->left);
        rclone(&(*node)->right, &(*other)->right);
    }

    void clone(Tree other){
        rclone(&root, &other.root);
    }

    void rshow(Node * node, int nivel){
        if(node == nullptr)
            return;
        rshow(node->left, nivel + 1);
        cout << string(4 * nivel, ' ') << node->value;
        rshow(node->right, nivel + 1);
    }

    void show(){
        rshow(root, 0);
    }
};

int main(){
    //cout << "Hello World!" << endl;

    Tree arvore;
    arvore.insert(5);

    arvore.show();
    return 0;
}
