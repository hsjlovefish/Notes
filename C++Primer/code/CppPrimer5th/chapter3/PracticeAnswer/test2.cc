#include <iostream>
using namespace std;

int main() {

    typedef int int_array[4];
    int_array ia[3] = {
      {0, 1, 2, 3},
      {4, 5, 6, 7},
      {8, 9, 10, 11}
    };
    int ia1[3][4] = {
      {0, 1, 2, 3},
      {4, 5, 6, 7},
      {8, 9, 10, 11}
   };
   for (int_array &arr : ia) {
       for (int ival : arr) {
           cout << ival << ' ';
       }
       cout << endl;
   }

   for (int_array *p = ia; p != ia + 3; ++p) {
       for (int *q = *p; q != *p + 4; ++q) {
           cout << *q << ' ';
       }
       cout << endl;
   }

    return 0;

}