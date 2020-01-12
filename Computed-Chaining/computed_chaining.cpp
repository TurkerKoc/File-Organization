#include "computed_chaining.h"
#include <assert.h>


int ComputedChaining::h1(int key) {
    return key%data.size();
}

int ComputedChaining::h2(int key) {
    int inc = key/data.size();
    if(inc==0) inc=1;
    return inc;
}


void ComputedChaining::insert(int key) {
    int dataMod = h1(key);
    if(!data[dataMod].valid) //if base address is empty
    {
        data[dataMod].key=key;
        data[dataMod].plink=-1; //setting link to -1
        data[dataMod].valid=true;
    }
    else
    {
        bool isEmpty=false;
        for(int i=0;i<data.size();i++) //loop for checking hash has an empty address
        {
            if(!data[i].valid)
            {
                isEmpty=true;
                break;
            }
        }
        if(isEmpty) //if there is an empty adress since our hash table size is prime we will find that addrs.
        {
            if(h1(data[dataMod].key)==dataMod) //mod of key on currentIndex = mod of coming key
            {
                int currentIndex = dataMod;
                int currentMatch = data[dataMod].key;
                int currentMatchInc = h2(currentMatch);
                int currentPlink = data[currentIndex].plink;
                while(currentPlink!=-1) //find an index with empty plink
                {
                    currentIndex=(currentIndex+(currentMatchInc*currentPlink))%data.size();
                    currentMatch = data[currentIndex].key;
                    currentMatchInc = h2(currentMatch);
                    currentPlink = data[currentIndex].plink;
                }
                int step = 0;
                int moveIndex = currentIndex; //find empty index, not changing current index because we will change it's plink
                while(data[moveIndex].valid) //find empty index
                {
                    moveIndex=(moveIndex+currentMatchInc)%data.size();
                    step++;
                }
                data[moveIndex].key = key;
                data[moveIndex].valid = true;
                data[moveIndex].plink = -1;
                data[currentIndex].plink = step;
            }
            else //mod of key on currentIndex not equal to currentIndex remove that key and linked keys
            {
                static vector<int> insertAgain;
                int currentMod = h1(data[dataMod].key);
                int currentMatch = data[currentMod].key;
                int currentMatchInc = h2(currentMatch);
                int currentPlink = data[currentMod].plink;
                while(data[(currentMod+(currentMatchInc*currentPlink))%data.size()].key!=data[dataMod].key) //find where current key is linked
                {
                    currentMod = (currentMod+(currentMatchInc*currentPlink))%data.size();
                    currentMatch = data[currentMod].key;
                    currentMatchInc = h2(currentMatch);
                    currentPlink = data[currentMod].plink;
                }
                data[currentMod].plink = -1; //erase link
                currentMod = dataMod;
                currentPlink = data[currentMod].plink;
                while(currentMod!=-1) //delete other keys linked to that key and put them in a static vector
                {
                    insertAgain.push_back(data[currentMod].key);
                    currentMod = remove(currentMod);
                }
                data[dataMod].key = key; //put new data into its index
                data[dataMod].valid = true;
                data[dataMod].plink = -1;
                while(!insertAgain.empty()) //insert all keys from static vector and clear vector for other insertions
                {
                    insert(insertAgain[0]);
                    insertAgain.erase(insertAgain.begin());
                }
                
            }
        }
    }


}


int ComputedChaining::remove(int pos) //delete key and return -1 if there is no link else return next position linked to data
{
    int nextPos;
    if(data[pos].plink==-1)
        nextPos = -1;
    else
        nextPos = (pos + data[pos].plink*h2(data[pos].key))%data.size();
    data[pos].key = -1;
    data[pos].plink = -1;
    data[pos].valid = false;
    return nextPos;
}
