#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "AVL.h"

int main( int argc, char *argv[] ){
    
    AVL avl;
    
    avl.insertKeyToTree(50);
    avl.insertKeyToTree(75);
    avl.insertKeyToTree(100); // Single Left Rotation
    avl.insertKeyToTree(25);
    avl.insertKeyToTree(60);
    avl.insertKeyToTree(15); // Single Right Rotation
    avl.insertKeyToTree(55);
    avl.insertKeyToTree(70);
    avl.insertKeyToTree(52); // Single Right Rotation
    avl.insertKeyToTree(57);
    avl.insertKeyToTree(54); // Right Left Rotation
    avl.insertKeyToTree(53); // Right Left Rotation
    avl.insertKeyToTree(65); // Right Left Rotation
    avl.insertKeyToTree(120); // Single Left Rotation
    avl.insertKeyToTree(20); // Left Right Rotation
    avl.insertKeyToTree(22);
    avl.insertKeyToTree(30);
    avl.insertKeyToTree(10);
    avl.insertKeyToTree(24); // Left Right Rotation


    if(avl.is_AVL() == false)
        cout << "  AVL  PROBLEM";

    avl.printTree();

    return 0;
}
