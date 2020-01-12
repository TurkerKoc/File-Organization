#ifndef TREE_ALGORITHM
#define TREE_ALGORITHM
#include "TreeAlgorithm.h"
#endif

struct node{
    int key;
    node* top;
    node* left;
    node* right;
};

class AVL : public TreeAlgorithm{

    private:
        int get_depth(void*);
        int get_height(node*);
        void restructure(void*);
        void single_left_rotation(node*);
        void single_right_rotation(node*);
        void right_left_rotation(node*);
        void left_right_rotation(node*);
        void printNode(void*);
        void updateQueue(queue<void*>*, void*);
        

    public:
        AVL() : TreeAlgorithm("AVL"){};
        void insertKeyToTree(int);
        bool is_AVL();
};
