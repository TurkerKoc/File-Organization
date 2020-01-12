#include "bdt.h"
#include<iostream>
#include<vector>
using namespace std;



BDT::BDT(int table_size) {
    data_vec.resize(table_size,entry()); //resizing vector array for constant size hash table and calling constructor for making valids = false
}


int BDT::h1(int key) const //key's mod
{
    return key%data_vec.size();
}
int BDT::h2(int key) const //key's increment
{
    int inc = key/data_vec.size();
    if(inc==0) inc=1;
    return inc;
}


void BDT::insert(int new_data)
{
    int dataMod = h1(new_data);
    if(!data_vec[dataMod].valid) //if base address is empty
    {
        data_vec[dataMod].data=new_data;
        data_vec[dataMod].valid=true;
    }
    else
    {
        bool isEmpty=false;
        for(int i=0;i<data_vec.size();i++) //loop for checking hash has an empty address
        {
            if(!data_vec[i].valid)
            {
                isEmpty=true;
                break;
            }
        }
        if(isEmpty) //if there is an empty adress since our hash table size is prime we will find that addrs.
        {
            //tree is used as complete binary tree in an array logic
            vector<pair<int, int>> tree; //pair.first for coming data, pair.second for index we are at
            int curIndex=dataMod; //is the index we are at
            int currentMatch=data_vec[dataMod].data; //is the data we are at
            int currentMatchInc=h2(currentMatch); //is the inc of data we are at
            int currentData=new_data; //is the data we are trying to move
            int currentInc=h2(currentData); //is the inc of data we are trying to move
            int treeConsIndex=0;
            tree.push_back(make_pair(new_data,dataMod)); //tree.first = data to insert, tree.second = index we are trying to insert

            while(true)
            {

                //if left  index is empty make swaps(from bottom to up);
                if(data_vec[(curIndex+currentInc)%data_vec.size()].valid==false)
                {
                    //since left is empty put currentData to left and keep going to top
                    data_vec[(curIndex+currentInc)%data_vec.size()].data = currentData;
                    data_vec[(curIndex+currentInc)%data_vec.size()].valid=true;
                    while(treeConsIndex>0)
                    {
                        //parent of a node is i/2 when i is odd , i/2 - 1 if i is even
                        int a;
                        if(treeConsIndex%2==0)
                            a=(treeConsIndex/2)-1;
                        else
                            a=treeConsIndex/2;
                        //if coming data to parent is equal to current keep going to top
                        if(tree[a].first==tree[treeConsIndex].first)
                            treeConsIndex=a;
                        else //else swap data's and keep going up
                        {
                            treeConsIndex=a;
                            data_vec[tree[treeConsIndex].second].data=tree[treeConsIndex].first;
                            data_vec[tree[treeConsIndex].second].valid=true;
                        }
                    }
                    break; //finish loop
                }
                //if right index is empty make swaps(from bottom to up);
                else if(data_vec[(curIndex+currentMatchInc)%data_vec.size()].valid==false)
                {
                    //since right is empty put currentMatch data to the right and put curData to curIndex then keep going to up
                    data_vec[(curIndex+currentMatchInc)%data_vec.size()].data = currentMatch;
                    data_vec[(curIndex+currentMatchInc)%data_vec.size()].valid=true;
                    data_vec[curIndex].data = currentData;
                    data_vec[curIndex].valid=true;
                    while(treeConsIndex>0)
                    {
                        //parent of a node is i/2 when i is odd , i/2 - 1 if i is even
                        int a;
                        if(treeConsIndex%2==0)
                            a=(treeConsIndex/2)-1;
                        else
                            a=treeConsIndex/2;
                        //if coming data to parent is equal to current keep going to top
                        if(tree[a].first==tree[treeConsIndex].first)
                            treeConsIndex=a;
                        else //else swap data's and keep going up
                        {
                            treeConsIndex=a;
                            data_vec[tree[treeConsIndex].second].data=tree[treeConsIndex].first;
                            data_vec[tree[treeConsIndex].second].valid = true;
                        }
                    }
                    break; //finish loop
                }
                //if left and right is not empty put keep going down
                tree.push_back(make_pair(currentData,(curIndex+currentInc)%data_vec.size()));
                tree.push_back(make_pair(currentMatch,(curIndex+currentMatchInc)%data_vec.size()));
                
                treeConsIndex++; //increment it for inserting tree elements in array consecutively

                //update current's
                currentData=tree[treeConsIndex].first;
                currentInc=h2(currentData);
                curIndex=tree[treeConsIndex].second;
                currentMatch=data_vec[curIndex].data;
                currentMatchInc=h2(currentMatch);

                
            }
        }
        else //hash is full
            cout<<"Hash Table is full\n";
    }
}



int BDT::find_num_probes(int key) const {
    int dataMod = h1(key);
    int numProbes = 1;
    int index=dataMod;
    int increment=h2(key);
    while(data_vec[index].data!=key) //assuming data is already in hash iterate until you find that data.
    {
        index=(index+increment)%data_vec.size();
        numProbes++;
    }
    return numProbes;
    
}



double BDT::find_average_num_probes() const {
    double sumOfProbes = 0;
    double currentDataNum = 0;
    for(int i=0;i<data_vec.size();i++)
    {
        if(data_vec[i].valid) //if current hash address has data
        {
            sumOfProbes+=find_num_probes(data_vec[i].data); //find prob and add it to the sum
            currentDataNum++; //inc data number;
        }
    }
    return sumOfProbes/currentDataNum; //return average probe
}
