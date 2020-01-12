//
//  main.cpp
//  File-Lab3
//
//  Created by Türker on 27.10.2019.
//  Copyright © 2019 Türker. All rights reserved.
//

#include <iostream>
#include "brent.h"
using namespace std;
int main(int argc, const char * argv[]) {
//    Brent ht(11);
//    ht.insert(27);
//    ht.insert(18);
//    ht.insert(29);
//    ht.insert(28);
//    ht.insert(39);
//    ht.insert(13);
//    ht.insert(16);
    Brent ht(11);
//    ht.insert(59);
//    ht.insert(30);
//    ht.insert(19);
//    ht.insert(44);
//    ht.insert(84);
//    ht.insert(60);
//    ht.insert(7);
//    ht.insert(98);
//    ht.insert(24);
//    ht.insert(74);
//    ht.insert(37);
////    ht.insert(48);
//    ht.insert(115);
    cout<<"index  "<<"data  "<<"probes\n";
    for(int i=0;i<ht.data_vec.size();i++)
    {
        cout<<i<<"      "<<ht.data_vec[i].data<<"     "<<ht.find_num_probes(ht.data_vec[i].data)<<"\n";
    }
//    ht.insert(12);
    cout<<"Average number of probes: "<<ht.find_average_num_probes()<<"\n";
    return 0;
}
