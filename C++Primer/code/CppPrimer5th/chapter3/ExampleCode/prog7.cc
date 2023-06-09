#include <vector>
#include <iterator>
using namespace std;

int main() {

    int int_arr[] = {0, 1, 2, 3, 4, 5};
    vector<int> ivec(begin(int_arr), end(int_arr));
    vector<int> subVec(int_arr + 1, int_arr + 4); // int_arr[1]  int_arr[2]  int_arr[4]
    return 0;
}