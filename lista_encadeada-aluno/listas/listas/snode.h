#ifndef SNODE_H
#define SNODE_H


struct snode{
    int value;
    snode * next{nullptr};

    snode(int value = 0){
        this->value = value;
    }
};

#endif // SNODE_H
