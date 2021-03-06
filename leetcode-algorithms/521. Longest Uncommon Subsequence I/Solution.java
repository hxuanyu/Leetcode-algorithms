class Solution {
    public int findLUSlength(String a, String b) {
        if (a.length() != b.length()) return Math.max(a.length(), b.length());

        if (!a.contentEquals(b)) return a.length();

        return -1;
    }
}
