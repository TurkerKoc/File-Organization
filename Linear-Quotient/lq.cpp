#include "lq.h"
#include <iostream>
using namespace std;
LQ::LQ(int table_size)
{
    data_vec.resize(table_size,lq_entry()); //resizing vector array for constant size hash table and calling constructor for making valids = false
}


void LQ::insert(int new_data)
{
    int dataMod = new_data%data_vec.size();
    if(!data_vec[dataMod].valid) //if base address is empty
    {
        data_vec[dataMod].data=new_data;
        data_vec[dataMod].valid=true;
    }
    else //check is there empty adress if yes find new position else hash is full
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
            int increment=new_data/data_vec.size();
            if(increment==0) increment=1;
            int index=(dataMod+increment)%data_vec.size();
            while(data_vec[index].valid) //iterate until you find an empty address.
                index=(index+increment)%data_vec.size();
            
            data_vec[index].data=new_data; //then put data
            data_vec[index].valid=true;
        }
        else
            cout<<"Hash Table is full\n";
    }
}



int LQ::find_num_probes(int key) const{
    int dataMod = key%data_vec.size();
    int numProbes = 1;
    int index=dataMod;
    int increment=key/data_vec.size();
    if(increment==0) increment=1;
    while(data_vec[index].data!=key) //assuming data is already in hash iterate until you find that data.
    {
        index=(index+increment)%data_vec.size();
        numProbes++;
    }
    return numProbes;
}



double LQ::find_average_num_probes() const
{
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

bool LQ::does_include(int key) const
{
    int index = key%data_vec.size();
    int increment = key/data_vec.size();
    if(increment==0) increment=1;
    int checkNum=1; //num of checking addresses if checkNum==size you checked all adresses)
    while(checkNum<=data_vec.size())
    {
        if(data_vec[index].data==key) //found data then return true
            return true;
        index=(index+increment)%data_vec.size();
        checkNum++;
    }
    return false; //if loop is finished then data is not in hash.
}
