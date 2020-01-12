//
//  main.cpp
//  Lab4-ht-TurkerKoc
//
//  Created by Türker on 9.11.2019.
//  Copyright © 2019 Türker. All rights reserved.
//

#include <iostream>
#include "BDT.h"
using namespace std;
int main(int argc, const char * argv[]) {
    BDT ht(11);
    ht.insert(59);
    ht.insert(30);
    ht.insert(19);
    ht.insert(44);
    ht.insert(84);
    ht.insert(60);
    ht.insert(7);
    ht.insert(98);
    ht.insert(24);
    ht.insert(74);
    ht.insert(37);

//    ht ht(11);
//    ht.insert(61);
//    ht.insert(34);
//    ht.insert(38);
//    ht.insert(17);
//    ht.insert(16);
//    ht.insert(43);
//    ht.insert(13);
//    ht.insert(18);
//    ht.insert(56);
//    ht.insert(11);
//    ht.insert(15);
    
//    ht.insert(27);
//    ht.insert(18);
//    ht.insert(29);
//    ht.insert(28);
//    ht.insert(39);
//    ht.insert(13);
//    ht.insert(16);
    

        cout<<"index  "<<"data  "<<"probes\n";
        for(int i=0;i<ht.data_vec.size();i++)
        {
            cout<<i<<"      "<<ht.data_vec[i].data<<"     "<<ht.find_num_probes(ht.data_vec[i].data)<<"\n";
        }
        cout<<"Average number of probes: "<<ht.find_average_num_probes()<<"\n";
    return 0;
}
