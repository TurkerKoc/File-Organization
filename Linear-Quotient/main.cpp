//
//  main.cpp
//  TurkerKoc-Lab2
//
//  Created by Türker on 26.10.2019.
//  Copyright © 2019 Türker. All rights reserved.
//

#include <iostream>
#include "lq.h"
using namespace std;
int main(int argc, const char * argv[]) {
//    LQ ht(11);
//    ht.insert(27);
//    ht.insert(18);
//    ht.insert(29);
//    ht.insert(28);
//    ht.insert(39);
//    ht.insert(13);
//    ht.insert(16);
//    ht.insert(42);
//    ht.insert(17);
////    ht.insert(172);
////    ht.insert(133);
//    cout<<"index  "<<"data  "<<"probes\n";
//    for(int i=0;i<ht.data_vec.size();i++)
//    {
//        cout<<i<<"      "<<ht.data_vec[i].data<<"     "<<ht.find_num_probes(ht.data_vec[i].data)<<"\n";
//    }
//    cout<<ht.does_include(17)<<"\n";
//    cout<<ht.does_include(177)<<"\n";
////    ht.insert(12);
//    cout<<"Average number of probes: "<<ht.find_average_num_probes()<<"\n";
    LQ ht(11);
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
    cout<<"index  "<<"data  "<<"probes\n";
    for(int i=0;i<ht.data_vec.size();i++)
    {
        cout<<i<<"      "<<ht.data_vec[i].data<<"     "<<ht.find_num_probes(ht.data_vec[i].data)<<"\n";
    }
    cout<<"Does include 17: "<<(ht.does_include(17)?("yes\n"):("no\n"));
    cout<<"Does include 123: "<<(ht.does_include(123)?("yes\n"):("no\n"));
    ht.insert(12);
    cout<<"Average number of probes: "<<ht.find_average_num_probes()<<"\n";

    
    return 0;
}
