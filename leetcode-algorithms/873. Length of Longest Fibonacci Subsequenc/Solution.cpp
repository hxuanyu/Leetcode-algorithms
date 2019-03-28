// A sequence X_1, X_2, ..., X_n is fibonacci-like if:
//
// n >= 3
// X_i + X_{i+1} = X_{i+2} for all i + 2 <= n
// Given a strictly increasing array A of positive integers forming a sequence, find the length of the longest fibonacci-like subsequence of A.  If one does not exist, return 0.
//
// (Recall that a subsequence is derived from another sequence A by deleting any number of elements (including none) from A, without changing the order of the remaining elements.  For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].)
//
//
//
// Example 1:
//
// Input: [1,2,3,4,5,6,7,8]
// Output: 5
// Explanation:
// The longest subsequence that is fibonacci-like: [1,2,3,5,8].
// Example 2:
//
// Input: [1,3,7,11,12,14,18]
// Output: 3
// Explanation:
// The longest subsequence that is fibonacci-like:
// [1,11,12], [3,11,14] or [7,11,18].
//
//
// Note:
//
// 3 <= A.length <= 1000
// 1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9
// (The time limit has been reduced by 50% for submissions in Java, C, and C++.)
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int size = A.size();
        vector<vector<int>> lens(size, vector<int>(size, 0));
        map<int, int> vmap;
        for (int i = 0; i < size; i++) vmap[A[i]] = i;

        int maxlen = 2;


        for (int j = 0; j < size; j++) {
            for (int i = 0; i < j; i++) {
                lens[i][j] = 2;
                if (vmap.count(A[j] - A[i]) == 0) continue;
                if (A[j] - A[i] >= A[i]) continue;

                int idx = vmap[A[j] - A[i]];
                if (lens[idx][i] > 0) lens[i][j] = lens[idx][i] + 1;
                maxlen = max(maxlen, lens[i][j]);
            }
        }

        return maxlen > 2 ? maxlen : 0;
    }
};