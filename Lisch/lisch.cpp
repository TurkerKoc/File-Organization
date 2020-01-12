#include "lisch.h"
#include <iostream>

LISCH::LISCH(int table_size)
{
    data_vec.resize(table_size,lisch_entry());
    for(int i=0;i<data_vec.size();i++)
        data_vec[i].link = -1;
}


void LISCH::insert(int new_data)
{
    int dataMod = new_data%data_vec.size();
    if(!data_vec[dataMod].valid)
    {
        data_vec[dataMod].data=new_data;
        data_vec[dataMod].valid=true;
    }
    else
    {
        int i=data_vec.size()-1;
        while(data_vec[i].valid&&i>=0)
        {
            i--;
        }
        if(i>0)
        {
            data_vec[i].data=new_data;
            data_vec[i].valid=true;
            int index = dataMod;
            while(data_vec[index].link!=-1)
                index = data_vec[index].link;
            data_vec[index].link=i;
        }
        else if(i==0&&!data_vec[i].valid)
        {
            data_vec[i].data=new_data;
            data_vec[i].valid=true;
            int index = dataMod;
            while(data_vec[index].link!=-1)
                index = data_vec[index].link;
            data_vec[index].link=i;        }
        else
            std::cout<<"Hash table is full!\n";
    }
}



int LISCH::find_num_probes(int key) const
{
    int dataMod = key%data_vec.size();
    int numProbes = 1;
    int index = dataMod;
    while(data_vec[index].data!=key)
    {
        index = data_vec[index].link;
        numProbes++;
    }
    return numProbes;
}



double LISCH::find_average_num_probes() const
{
    double sumOfProbes = 0;
    for(int i=0;i<data_vec.size();i++)
    {
        sumOfProbes+=find_num_probes(data_vec[i].data);
    }
    return sumOfProbes/data_vec.size();
}


bool LISCH::does_include(int key) const
{
    for(int i=0;i<data_vec.size();i++)
    {
        if(data_vec[i].data==key)
            return true;
    }
    return false;
}
