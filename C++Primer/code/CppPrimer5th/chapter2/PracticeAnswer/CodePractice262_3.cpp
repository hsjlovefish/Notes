#include <iostream>
#include <string>
using namespace std;

struct Sales_data {
    string bookNo;
    int unit_sold = 0;
    double revenue = 0.0;
};

int main() {
    Sales_data datas, dataTemp;
    double price = 0;
    if (cin >> datas.bookNo) {
        cin >> datas.unit_sold >> price;
        int cnt = datas.unit_sold;
        while (cin >> dataTemp.bookNo) {
            cin >> dataTemp.unit_sold >> price;
            if (dataTemp.bookNo == datas.bookNo) {
                cnt += dataTemp.unit_sold;   
            } else {
                cout << datas.bookNo << " " << cnt << endl;
                datas.bookNo = dataTemp.bookNo;
                cnt = dataTemp.unit_sold;
            }        
        }     
        cout << datas.bookNo << " " << cnt << endl;
    }
    return 0;
}