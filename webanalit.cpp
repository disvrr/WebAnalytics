#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

unordered_map<string, unordered_set<string>> loadUserProductMap(const string& filename) {
    unordered_map<string, unordered_set<string>> userProducts;
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Can`t open a file: " << filename << endl;
        exit(1);
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string user_id, product_id, timestamp;

        if (!getline(ss, user_id, ',')) continue;
        if (!getline(ss, product_id, ',')) continue;
        getline(ss, timestamp, ',');

        userProducts[user_id].insert(product_id);
    }

    return userProducts;
}

int main() {

    string day1_file = "D:\Diana\dev\progects\webanalit\webanalit\day1.csv.txt";
    string day2_file = "D:\Diana\dev\progects\webanalit\webanalit\day2.csv.txt";


    unordered_map<string, unordered_set<string>> day1 = loadUserProductMap(day1_file);
    unordered_map<string, unordered_set<string>> day2 = loadUserProductMap(day2_file);

    cout << "Users, that On the second day visited the page that hadn’t been visited by this user on the first day:\n";


    for (const auto& entry : day2) {
        const string& user_id = entry.first;
        const auto& products_day2 = entry.second;

        if (day1.count(user_id)) {
            const auto& products_day1 = day1[user_id];
            for (const auto& product : products_day2) {
                if (!products_day1.count(product)) {
                    cout << user_id << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
