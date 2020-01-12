//
//  main.cpp
//  LW1-TurkerKoc-20170702037
//
//  Created by Türker on 14.10.2019.
//  Copyright © 2019 Türker. All rights reserved.
//

#include <iostream>
#include "lisch.h"
int main(int argc, const char * argv[]) {
    LISCH ht(11);
    ht.insert(58);
    ht.insert(60);
    ht.insert(35);
    ht.insert(68);
    ht.insert(6);
    ht.insert(53);
    ht.insert(19);
    ht.insert(10);
    ht.insert(43);
    ht.insert(21);
    ht.insert(32);
    std::cout<<"Number of probes for 10 is "<<ht.find_num_probes(10)<<".\n";
    std::cout<<"Number of probes for 32 is "<<ht.find_num_probes(32)<<".\n";
    std::cout<<"Number of probes for 68 is "<<ht.find_num_probes(68)<<".\n";
    std::cout<<"Average number of probes: "<<ht.find_average_num_probes()<<"\n";
    std::cout<<(ht.does_include(1)?"yes it incldues 1":"no\n");
    std::cout<<(ht.does_include(32)?"yes it incldues 32\n":"no");

    return 0;
}
