#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class TreeAlgorithm{

    protected:
        virtual int get_depth(void*) = 0;
        virtual void restructure(void*) = 0;
        virtual void printNode(void*) = 0;
        virtual void updateQueue(queue<void*>*, void*) = 0;
    

    public:
        TreeAlgorithm(string);
        void printTree();
        virtual void insertKeyToTree(int) = 0;
    

    public:
        void* root;
        string _treeName;


};
