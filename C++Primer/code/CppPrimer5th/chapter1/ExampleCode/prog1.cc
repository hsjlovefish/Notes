#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	printf("hello world!\n");
    cout << "hello world!\n" << endl;
    for (int i = 0; i < 100; ++i) {
        cout << i << endl;
        if (i == 99) {
            break;
        }
    }
    return -1;
}
