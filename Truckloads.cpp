#include "Truckloads.h"
#include <iostream>
#include <cmath>

int Truckloads::numTrucks(int numCrates, int loadSize, int stat){
    if(numCrates<=loadSize){
        return stat;
    }
    else{
        numCrates=numCrates/2;
        if(numCrates%1!=0) numCrates=static_cast<int>(std::ceil(numCrates));
        return numTrucks(numCrates,loadSize,stat*2);
    }
}//第一个是一共多少捆 第二个一辆车最多装几捆

int Truckloads::numTrucks(int numCrates, int loadSize){
    return numTrucks(numCrates,loadSize,1);
}