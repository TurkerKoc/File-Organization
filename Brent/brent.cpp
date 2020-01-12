#include "brent.h"
#include <iostream>
using namespace std;


int Brent::find_moving_cost(int key, int index) const
{
    int increment = h2(key);
    int currentIndex = index;
    int cost=0;
    while(data_vec[currentIndex].valid) //iterate until you find an empty address.
    {
        currentIndex=(currentIndex+increment)%data_vec.size();
        cost++;
    }
    return cost;
}
int Brent::h1(int key) const //key's mod
{
    return key%data_vec.size();
}
int Brent::h2(int key) const //key's increment
{
    int inc = key/data_vec.size();
    if(inc==0) inc=1;
    return inc;
}


Brent::Brent(int table_size){
    data_vec.resize(table_size,entry()); //resizing vector array for constant size hash table and calling constructor for making valids = false
}


void Brent::insert(int new_data)
{
    int dataMod = h1(new_data);
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
            //first find probNum(s) of new_data
            int increment=h2(new_data);
            int index=dataMod;
            int s=1;
            while(data_vec[index].valid) //iterate until you find an empty address.
            {
                index=(index+increment)%data_vec.size();
                s++;
            }
            bool isInserted = false;
            index=h1(new_data);
            for(int i=1;i<s;i++)
            {
                int cost = i+find_moving_cost(data_vec[index].data,index); //(i+j)
                if(cost<s)
                {
                    int MoveIncrement = h2(data_vec[index].data);
                    int currentIndex = index;
                    while(data_vec[currentIndex].valid) //iterate until you find an empty address.
                        currentIndex=(currentIndex+MoveIncrement)%data_vec.size();
                    int moveIndex=currentIndex;
                    int moveData = data_vec[index].data;
                    data_vec[moveIndex].data = moveData;
                    data_vec[moveIndex].valid=true;
                    data_vec[index].data=new_data;
                    data_vec[moveIndex].valid=true;
                    isInserted = true;
                    break;
                }
                index=(index+increment)%data_vec.size();
            }
            if(!isInserted)
            {
                index=(dataMod+increment)%data_vec.size();
                while(data_vec[index].valid) //iterate until you find an empty address.
                    index=(index+increment)%data_vec.size();
                
                data_vec[index].data=new_data; //then put data
                data_vec[index].valid=true;
            }
        }
        else
            cout<<"Hash Table is full\n";
    }
    
}



int Brent::find_num_probes(int key) const{
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



double Brent::find_average_num_probes() const{
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
