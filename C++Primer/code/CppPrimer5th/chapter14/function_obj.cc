#include <iostream>

using namespace std;

struct absInt {
    int operator()(int val) const {
        return val < 0 ? -val : val;
    }
};

int main(int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    int i = -42;
    absInt abs;
    int ui = abs(i);
    cout << ui << endl;

    return 0;
}