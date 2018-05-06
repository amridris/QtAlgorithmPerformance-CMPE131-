#ifndef AVLTREE_H
#define AVLTREE_H
#include<string>
#include<avlnode.h>

class AVLtree
{
public:
    AVLtree();
    ~AVLtree();
    bool insert(int r, double price);
    void printBalance();

private:
    AVLnode *root;

    AVLnode* rotateLeft(AVLnode *a);
    AVLnode* rotateRight(AVLnode *a);
    AVLnode* rotateLeftThenRight(AVLnode *a);
    AVLnode* rotateRightThenLeft(AVLnode *a);
    void reBalance(AVLnode *n);
    int height(AVLnode *n);
    void setBalance(AVLnode *n);
    void printBalance(AVLnode *n);
    void clearNode(AVLnode *n);
};

#endif // AVLTREE_H
