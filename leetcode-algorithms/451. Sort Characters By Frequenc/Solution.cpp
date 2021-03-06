// Given a string, sort it in decreasing order based on the frequency of characters.
//
// Example 1:
//
// Input:
// "tree"
//
// Output:
// "eert"
//
// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:
//
// Input:
// "cccaaa"
//
// Output:
// "cccaaa"
//
// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:
//
// Input:
// "Aabb"
//
// Output:
// "bbAa"
//
// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

class Solution {
public:
    string frequencySort(string s) {
        map<int, set<char>> times_to_value;

        map<char, int> times;

        for (auto c : s) {
            if (times.count(c) == 0) {
                times[c]++;
                times_to_value[times[c]].insert(c);
            } else {
                times_to_value[times[c]++].erase(c);
                times_to_value[times[c]].insert(c);
            }
        }

        string rslt = "";
        map<int, set<char>>::reverse_iterator iter = times_to_value.rbegin();
        for (; iter != times_to_value.rend(); iter++) {
            set<char>::iterator citer = iter->second.begin();
            for (; citer != iter->second.end(); citer++) {
                for (int i = 0; i < iter->first; i++) {
                    rslt += *citer;
                }
            }
        }

        return rslt;
    }
};

// solution 2
struct item {
    item(char val_, int count_) { val = val_; count = count_; }
    char val;
    int count;
};

class cmp {
public:
    bool operator()(item& a, item& b) { return a.count > b.count; }
};

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> count;
        for (auto c : s) count[c]++;

        vector<item> vec;
        for (auto v : count) {
            vec.push_back(item(v.first, v.second));
        }

        string rslt = "";
        sort(vec.begin(), vec.end(), cmp());
        for (auto v : vec) {
            while (v.count--) {
                rslt += v.val;
            }
        }

        return rslt;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> vmap;
        map<int, vector<int>, greater<int>> countmap;

        for (auto c : s) {
            vmap[c]++;
        }

        for (auto item : vmap) {
            countmap[item.second].push_back(item.first);
        }

        string rslt = "";
        for (auto item : countmap) {
            for (auto c : item.second) {
                for (int i = 0; i < item.first; i++) {
                    rslt += c;
                }
            }
        }

        return rslt;
    }
};
