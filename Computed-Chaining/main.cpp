//
//  main.cpp
//  lab5
//
//  Created by Türker on 23.11.2019.
//  Copyright © 2019 Türker. All rights reserved.
//

#include <iostream>
#include "computed_chaining.h"
using namespace std;
int main(int argc, const char * argv[]) {
    ComputedChaining cc(11);
//    cc.insert(27);
//    cc.insert(18);
//    cc.insert(29);
//    cc.insert(28);
//    cc.insert(39);
//    cc.insert(13);
//    cc.insert(16);
//    cc.insert(38);
//    cc.insert(53);
//    cc.insert(49);
    cc.insert(28);
    cc.insert(48);
    cc.insert(37);
    cc.insert(63);
    cc.insert(85);
    cc.insert(13);
    cc.insert(17);
    cc.insert(94);
    cc.insert(97);
    cc.insert(39);
    cc.insert(14);
    cout << cc;
    return 0;
}
