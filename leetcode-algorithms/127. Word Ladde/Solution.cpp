// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
//
// Only one letter can be changed at a time.
// Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
// Note:
//
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.
// Example 1:
//
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
//
// Output: 5
//
// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
// Example 2:
//
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
//
// Output: 0
//
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> que;
        que.push(beginWord);
        set<string> wlist(wordList.begin(), wordList.end());
        int dis = 1;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                auto top = que.front();
                que.pop();
                vector<string> nei;
                findneigh(top, wlist, nei);
                for (auto n : nei) {
                    if (n == endWord) {
                        dis++;
                        return dis;
                    } else que.push(n);
                }
            }
            dis++;
        }

        return 0;
    }

    void findneigh(string& word, set<string>& wordlist, vector<string>& nei) {
        wordlist.erase(word);
        for (int i = 0; i < word.size(); i++) {
            char oc = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if (wordlist.count(word)) {
                    nei.push_back(word);
                    wordlist.erase(word);
                }
            }

            word[i] = oc;
        }
    }
};
