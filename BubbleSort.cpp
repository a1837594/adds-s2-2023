#include "BubbleSort.h"

std::vector<int> BubbleSort::sort(std::vector<int> list) {
    int n = list.size();
    for(int i=n-1;i>1;i--){
        for(int j=0;j<i;j++){
            if(list.at(j)>list.at(j+1)){
                int save=list.at(j+1);
                list.at(j)=list.at(j+1);
                list.at(j+1)=save;
            }
        }
    }
    return list;
}
