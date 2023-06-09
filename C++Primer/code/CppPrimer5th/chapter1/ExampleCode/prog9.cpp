#include <iostream>
#include "Sales_item.h"
#include <vector>
#include <memory>
#include <string>
#include <unordered_map>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
using namespace std;

int main() {

    Sales_item total;
   
    if (cin >> total) {
        Sales_item trans;
        while (cin >> trans) {
            if (total.isbn() == trans.isbn()) {
                total += trans;
            } else {   
                cout << total << endl;
                total = trans;
            }
        }
        cout << total << endl;
    } else {
        cerr << "No data?!" << endl;
        return -1;
    }

    return 0;
} 
