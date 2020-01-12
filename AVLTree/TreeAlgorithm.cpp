#include "TreeAlgorithm.h"

TreeAlgorithm::TreeAlgorithm(string treeName){
    _treeName = treeName;
    root = NULL;
}

void TreeAlgorithm::printTree(){

    cout << "***********PRINTING " << _treeName << " TREE************" << endl;
    queue <void*> nodeQueue;
    nodeQueue.push(root);
    void* myNode;
    int currentDepth;
    int prevDepth = 0;
    while (nodeQueue.size() != 0){
        myNode = nodeQueue.front();
        currentDepth = get_depth(myNode);
        if (currentDepth != prevDepth)
        {
            cout << "DEPTH " << currentDepth << ":" << endl;
            prevDepth = currentDepth;
        }
        printNode(myNode);
        updateQueue(&nodeQueue, myNode);
        nodeQueue.pop();
    }
    cout << "*****************************************" << endl;
    
}
