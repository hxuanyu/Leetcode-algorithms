// We are playing the Guess Game. The game is as follows:
//
// I pick a number from 1 to n. You have to guess which number I picked.
//
// Every time you guess wrong, I'll tell you whether the number is higher or lower.
//
// You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
//
// -1 : My number is lower
//  1 : My number is higher
//  0 : Congrats! You got it!
// Example:
// n = 10, I pick 6.
//
// Return 6.
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;

        int mid;
        do {
            mid = low + (high - low) / 2;

            int gus = guess(mid);
            if (gus == 0) return mid;
            else if (gus == -1) high = mid - 1;
            else low = mid + 1;
        } while (low <= high);

        return -1;
    }
};
