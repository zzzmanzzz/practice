/*

尋找數列中是否存在 a + b = c + d 關係的元素

Reference Book 1, 2.10 
*/


#include<map>
#include<vector>
#include<iostream>


int main() {
    int vals[] = {3, 4, 7, 10, 20, 9, 8};
    int size = 7;
    std::map<int, std::vector<int>> sums;

    for(int i = 0 ; i < size ; i++ ) {
        for(int j = i + 1 ; j < size ; j++) {
            int tmp = vals[i] + vals[j];
            std::vector<int> idx;

            if(sums.find(tmp) == sums.end()) {
                idx.push_back(i);
                idx.push_back(j);
                sums[tmp] = idx;
            }
            
             else {
                if(sums[tmp][0] != i && sums[tmp][1] != j) {
                    std::cout << vals[sums[tmp][0]] << " + " << vals[sums[tmp][1]] << " = " << vals[i] << " + " << vals[j] << std::endl;
                    return 0;
                }               
            }
            
        }
    }

    return 0;

}