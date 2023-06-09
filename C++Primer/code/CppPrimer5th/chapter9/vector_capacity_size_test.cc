#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> ivec;

    cout << "initial: " << ivec.size() 
        << " " << ivec.capacity() << endl;
    for (vector<int>::size_type idx = 0; idx != 24; ++idx) {
        ivec.push_back(idx);
    }
    cout << "after insert 24 times: "
         << ivec.size() << " " << ivec.capacity() << endl;
    
    ivec.reserve(50);
    cout << "reserve 50: " << ivec.size() << " " << ivec.capacity() << endl;

    while (ivec.size() != ivec.capacity()) {
        ivec.push_back(0);
    }
    cout << "Running out of space in the container: " 
        << ivec.size() << " " << ivec.capacity() << endl;

    ivec.push_back(0);
    cout << "then push once: " 
        << ivec.size() << " " << ivec.capacity() << endl;

    ivec.shrink_to_fit();
    cout << "Request to return memory: " 
        << ivec.size() << " " << ivec.capacity() << endl;

    return 0;
}