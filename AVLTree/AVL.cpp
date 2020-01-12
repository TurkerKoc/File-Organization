#include "AVL.h"
#include <iostream>
using namespace std;

void AVL::restructure(void* myNode)
{
    node* currentNode = (node*)myNode;
    node *temp = currentNode;
    while(temp!=NULL)
    {
        if((get_height(temp->right)-get_height(temp->left)==2)) //if right height - left height is 2
        {
            if((get_height(temp->right->right)-get_height(temp->right->left)<0)) //and the right height's right-left is smaller than 0 than it is rlr
                right_left_rotation(temp);
            else
                single_left_rotation(temp);
        }
        else if((get_height(temp->right)-get_height(temp->left)==-2))
        {
            if((get_height(temp->left->right)-get_height(temp->left->left)>0))
                left_right_rotation(temp);
            else
                single_right_rotation(temp);
        }
        temp=temp->top;
    }
}

void AVL::single_left_rotation(node* m){
    node *temp1 = m->right;
    node *temp2 = temp1->left;
    node *curTop = m->top;
    
    if(m==root) //if rotation is based on root change root and do rotation
    {
        root=temp1;
        temp1->top=m->top;
        temp1->left = m;
        if(m!=NULL)
            m->top = temp1;
        m->right = temp2;
        if(temp2!=NULL)
            temp2->top=m;
    }
    else //if rotation is not based on root then change top's and do rotation
    {
        if(curTop->right==m)
            curTop->right = temp1;
        else
            curTop->left = temp1;
        temp1->top=m->top;
        temp1->left = m;
        if(m!=NULL)
            m->top = temp1;
        m->right = temp2;
        if(temp2!=NULL)
            temp2->top=m;
    }
}

void AVL::single_right_rotation(node* n){
    node *temp1 = n->left;
    node *temp2 = temp1->right;
    node *curTop = n->top;
    
    if(n==root) //if rotation is based on root change root and do rotation
    {
        root=temp1;
        temp1->top=n->top;
        temp1->right = n;
        if(n!=NULL)
            n->top=temp1;
        n->left = temp2;
        if(temp2!=NULL)
            temp2->top=n;
    }
    else //if rotation is not based on root then change top's and do rotation
    {
        if(curTop->right==n)
            curTop->right = temp1;
        else
            curTop->left = temp1;
        temp1->top=n->top;
        temp1->right = n;
        if(n!=NULL)
            n->top=temp1;
        n->left = temp2;
        if(temp2!=NULL)
            temp2->top=n;
        
    }
}

void AVL::right_left_rotation(node* myNode){
    single_right_rotation(myNode->right);
    single_left_rotation(myNode);
}

void AVL::left_right_rotation(node* myNode){
    single_left_rotation(myNode->left);
    single_right_rotation(myNode);
}

int AVL::get_height(node* myNode){
    int left_height, right_height;

    if(!myNode)
        return 0;

    left_height = get_height(myNode->left);
    right_height = get_height(myNode->right);

    if(left_height > right_height)
        return left_height + 1;
    else
        return right_height + 1;
}

void AVL::insertKeyToTree(int key){
    node* current;
    node* top;
    node* newNode = new node;
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    if(root == NULL){
        newNode->top = NULL;
        root = newNode;
        return;
    }

    current = (node*) root;

    while(true){ // Find key insertion location
        if(current->key > key){
            if(current->left){
                current = current->left;
            }else{
                break;
            }
        }else{
            if(current->right){
                current = current->right;
            }else{
                break;
            }
        }
    }

    newNode->top = current;

    if(current->key > key){
        current->left = newNode;
        current = current->left;
    }else{
        current->right = newNode;
        current = current->right;
    }
  
    restructure(current);
  
}

void AVL::printNode(void* myNode){
    node* currentNode = (node*)myNode;
    cout << currentNode->key << endl;
}

void AVL::updateQueue(queue<void*> *nodeQueue, void* myNode){
    node* currentNode = (node*)myNode;
    if (currentNode->left != NULL)
        (*nodeQueue).push(currentNode->left);
    if (currentNode->right != NULL)
        (*nodeQueue).push(currentNode->right);
}

int AVL::get_depth(void* myNode){
    int depth =1;
    node* currentNode = (node*)myNode;
    while (currentNode->top != NULL){
        currentNode = currentNode->top;
        depth++;
    }
    return depth;
}

bool AVL::is_AVL(){

    int left_depth, right_depth;
    int height_difference;
    int child_diff;

    node* currentNode = (node*)root;

    queue <void*> nodeQueue;
    nodeQueue.push(currentNode);
    while (nodeQueue.size() != 0){
        currentNode = (node*) nodeQueue.front();
        left_depth = get_height(currentNode->left);
        right_depth = get_height(currentNode->right);
        height_difference = right_depth - left_depth;
        if (height_difference<-1 || height_difference>1){
            return false;
        }
        updateQueue(&nodeQueue, currentNode);
        nodeQueue.pop();
    }
    return true;
}
