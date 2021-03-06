#include <iostream>

using namespace std;

struct BNode{
    int value;

    BNode * left{nullptr};
    BNode * right{nullptr};
    BNode(int value = 0){
        this->value = value;
    }
};

struct BTree{
    BNode * root;
    BTree(){
        root = new BNode(8);
        root->left = new BNode(5);
        root->right = new BNode(4);
        root->left->left = new BNode(9);
        root->left->right = new BNode(7);
        root->right->right = new BNode(11);
        root->left->right->left = new BNode(1);
        root->left->right->right = new BNode(12);
        root->right->right->left = new BNode(3);
        root->left->right->right->left = new BNode(2);
    }

    void rserialize(BNode * node, ostream & of){
        if(node ==  nullptr){
            of << "# ";
            return;
        }
        of << node->value << " ";
        rserialize(node->left, of);
        rserialize(node->right, of);
    }

    string serialize(){
        stringstream ss;
            rserialize(root, ss);
    }

    bool requals(BNode * node, BNode * other){
        if(node == nullptr && other == nullptr)
            return true;
        if((node != nullptr) || (other != nullptr))
            return false;
        if(node->value != other ->value)
            return false;
        return requals(node->left, other->left) && requals(node->right, other->right);
    }

    bool equals(BTree other){
        return requals(root, other.root);
    }

    void clone2(BNode ** elo, BNode * other){
        if(other == nullptr)
            return;
        (*elo) = new BNode(other->value);
        clone2(&(*elo)->left, other->left);
        clone2(&(*elo)->right, other->right);

    }

    BNode * clone(BNode * other){
        if(other == nullptr)
            return nullptr;
        BNode * node = new BNode(other->value);
        node->left = clone(other->left);
        node->right = clone(other->right);
        return node;
    }

    BTree(BTree other){
       // root = cloone(other.root);
        clone2(&root, other.root);
    }

    void apagar(BNode * node){
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

    ~BTree(){
        clear();
    }

    void rshow(BNode * node, int nivel){
        if(node == nullptr)
            return;
        rshow(node->left, nivel + 1);
        cout << string(4 * nivel, ' ') << node->value << endl;
        rshow(node->right, nivel + 1);
    }

    int rsoma(BNode * node){
        if(node == nullptr)
            return 0;
        return node->value + rsoma(node->left) + rsoma(node->right);
    }
};

int main()
{
    BTree tree;
    tree.rshow(tree.root, 0);

    cout << endl << tree.rsoma(tree.root) << endl;

    //cout << "Hello World!" << endl;
    return 0;
}
