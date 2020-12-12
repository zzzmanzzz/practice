/*

給定一條路線上相鄰兩站對應的票
A-D B-G C-A G-F D-B

求這些票的路線
C-A-D-B-G-F

Reference Book 1, 
*/


#include<map>
#include<set>
#include<string>
#include<iostream>




int main() {
    const int size = 5;
    std::string start[] = {"A", "B", "C", "G", "D"};
    std::string end[] = {"D", "G", "A", "F", "B"};
    // init
    std::map<std::string, std::string> tickets;
    std::set<std::string> endStation;

    for(int i = 0 ; i < size ; i++ ) {
        tickets[start[i]] = end[i];
        endStation.insert(end[i]);
    }

    //find first station

    std::string s;
    for(int i = 0 ; i < size ; i++ ) {
        if(endStation.find(start[i]) == endStation.end()) {
            s = start[i];
            break;
        }
    }

    //get route
    std::cout<< s << " ";
    for(int i = 0 ; i < size ; i++ ) {
        s = tickets[s];
        std::cout << s << " ";
    } 
    return 0;
}