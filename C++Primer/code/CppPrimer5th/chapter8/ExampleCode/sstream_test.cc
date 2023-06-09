#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main(int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    // in shell
    // g++ sstream_test.cc -std=c++11 
    // type ./a.out <infile >outfile

    {
        string line, word;
        vector<PersonInfo> people;
        while (getline(cin, line)) {
            PersonInfo info;
            istringstream record(line);
            record >> info.name;
            while (record >> word) {
                info.phones.push_back(word);
            }
            people.push_back(info);
        }

        for (const auto &p : people) {
            cout << p.name << " ";
            for (const auto &num : p.phones) {
                cout << num << " ";
            }
            cout << std::endl;
        }
    }

    {
        vector<string> people{"jack", "tony", "steve", "mars"};
        ostringstream formatted;
        for (const string &entry : people) {
            formatted << " " << entry;
        }
        cout << formatted.str() << endl;
    }

    return 0;
}