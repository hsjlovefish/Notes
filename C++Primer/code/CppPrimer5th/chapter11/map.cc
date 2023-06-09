#include <algorithm>
#include <iostream>
#include <istream>
#include <map>
#include <unordered_map>
#include <utility>
#include <set>
#include <string>

using namespace std;

// map<string, string> buildMap(ifstream &map_file) {
//     map<string, string> trans_map;
//     string key, value;
//     while (map_file >> key && getline(map_file, value)) {
//         if (value.size() > 1) {
//             trans_map[key] = value.substr(1);
//         } else {
//             throw runtime_error("no rule for " + key);
//         }
//     }
//     return trans_map;
// }

// const string&
// transform(const string &s, const map<string, string> &m) {
//     auto map_it = m.find(s);
//     if (map_it != m.cend()) {
//         return map_it->second;
//     } else {
//         return s;
//     }
// }

// void word_transform(ifstream &map_file, ifstream &input) {
//     auto trans_map = buildMap(map_file);
//     string text;
//     while (getline(input, text)) {
//         istringstream stream(text);
//         string word;
//         bool firstword = true;
//         while (stream >> word) {
//             if (firstword) {
//                 firstword = false;
//             } else {
//                 cout << " ";
//             }
//             cout << transform(word, trans_map);
//         }
//         cout << endl;
//     }
// }

int main(int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    {
        // // map
        // map<string, size_t> word_count;
        // string word;

        // while (cin >> word) {
        //     ++word_count[word];
        // }

        // for (const auto &w : word_count) {
        //     cout << w.first << " occurs " << w.second
        //         << ((w.second > 1) ? " times" : " time") << endl;
        // }
        // /*   input: b a c d
        //  *   output:
        //  *   a occurs 1 time
        //  *   b occurs 1 time
        //  *   c occurs 1 time
        //  *   d occurs 1 time
        // */
    }

    {
        // set
        set<int> iset;
        iset.insert(1);
        for (auto i : iset) {
            cout << i;
        }
    }

    {
        // multimap
        multimap<string, string> authors;
        auto it = authors.insert({"a", "b"});
        cout << it->second << " ";
        auto it2 = authors.insert({"a", "c"});
        cout << (*it2).second << endl;
        for (auto i : authors) {
            cout << i.first << " " << i.second << endl;
        }
    }

    {
        // find + count 组合拳
        multimap<string, string> authors;
        authors.insert({"Alain de Botton", "b"});
        string search_item("Alain de Botton");
        auto entries = authors.count(search_item);
        auto iter = authors.find(search_item);
        while (entries) {
            cout << iter->second << endl;
            ++iter;
            --entries;
        }
    }

    {
        // unordered_map
        unordered_map<string, string> hash_map;
        // 288230376151711743
        cout << "hash map's max bucket count: " << hash_map.max_bucket_count() << endl;
    }
    
    return 0;
}