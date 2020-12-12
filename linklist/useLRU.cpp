#include"LRU.hpp"
#include<iostream>

int main() {
    LRU cache(3);

    cache.set("A", 9);
    cache.set("B", 1000);
    cache.set("C", 1984);
    cache.dump();

    std::cout << std::endl << cache.access("A") << std::endl;
    cache.dump();

    cache.set("D", 888);

    cache.dump();
}