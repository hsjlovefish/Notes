#include <iostream>
#include <string>
using namespace std;

struct Sales_data {
    string bookNo;
    int unit_sold = 0;
    double revenue = 0.0;
};

int main() {
    Sales_data data1, data2;
    int price = 0;
    cout << "please input data1:" << endl;;
    cin >> data1.bookNo >> data1.unit_sold 
        >> price;
    data1.revenue = data1.unit_sold * price;
    cout << "please input data2:" << endl;;
    cin >> data2.bookNo >> data2.unit_sold 
        >> price;
    data2.revenue = data2.unit_sold * price;
    if (data1.bookNo == data2.bookNo) {
        int sellCnt = data1.unit_sold + data2.unit_sold; 
        double amount = data1.revenue + data2.revenue;
        cout << data1.bookNo << " " 
             << sellCnt << " "
             << amount << " ";
        if (sellCnt != 0) {
            cout << amount / sellCnt << endl;
        }
    } else {
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;      
    }
    return 0;
}