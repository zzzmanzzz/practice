#include"queue.hpp"
void queue::dump() {
    std::cout << "<rear> ";
    while(this->hasNext()) {
        std::cout << this->dequeue() << " ";
    }
    std::cout << "<front>";
}