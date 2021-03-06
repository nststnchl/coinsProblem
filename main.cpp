#include <iostream>
#include <map>
#include <set>

using namespace std;

int check(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < '0' || s[i] > '9') {
            return -1;
        }
    }
    return atoi(s.c_str());
}

uint get_number() {
    int n = -1;
    string s;
    while (n < 0) {
        cin >> s;
        n = check(s);
        if (n < 0) {
            cerr << "You should enter positive number!" << endl;
            cout << "Try again:" << endl;
        }
    }
    return (uint) n;
}

set<uint> values;
map<int, multiset<uint>> min_num;

int solution(uint goal) {
    if (min_num.count(goal) == 1) {
        return (int) min_num.at(goal).size();
    } else {
        bool f = false;
        int result = INT32_MAX;
        multiset<uint> cur_set;
        int prev_sol;
        for (auto i = values.begin(); i != values.end(); i++) {
            if (goal - *i > goal) {
                continue;
            }
            prev_sol = solution(goal - *i);
            if (prev_sol == -1) {
                continue;
            }
            if (result > 1 + prev_sol) {
                f = true;
                result = 1 + prev_sol;
                cur_set = min_num.at(goal - *i);
                cur_set.insert(*i);
            }
        }
        min_num[goal] = cur_set;
        if (f) {
            return result;
        } else {
            return -1;
        }
    }
}

int main() {
    cout << "Enter number of coins:" << endl;
    uint n = get_number();

    cout << "Enter coin's values: " << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": ";
        values.insert(get_number());
    }

    cout << "Enter a value we should get from coins: " << endl;

    uint goal = get_number();

    for (auto i = values.begin(); i != values.end(); i++) {
        min_num[*i] = {*i};
    }

    int ans = solution(goal);
    if (ans < 0) {
        cout << "You can't present " << goal << " with this set of coins";
        return 0;
    }

    cout << "Minimal number of coins is " << ans << "." << endl;
    if (ans > 1) {
        cout << "Required coins are: ";
    } else {
        cout << "Required coin is: ";
    }
    for (auto i = min_num.at(goal).begin(); i != min_num.at(goal).end(); i++) {
        cout << *i << ' ';
    }

    return 0;
}