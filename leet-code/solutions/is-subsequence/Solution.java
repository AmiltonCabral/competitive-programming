package issubsequence;

class Solution {
    public static boolean isSubsequence(String s, String t) {
        if (s.length() == 0)
            return true;

        int sIndex = 0;
        for (int i = 0; i < t.length(); i++) {
            if (t.charAt(i) == s.charAt(sIndex))
                sIndex++;
            if (sIndex == s.length())
                return true;
        }

        return false;
    }

    public static boolean isSubsequenceV2(String s, String t) {
        int i = 0;
        int j = 0;

        while (i < s.length() && j < t.length()) {
            if (s.charAt(i) == t.charAt(j)) {
                i++;
            }
            j++;
        }

        return i == s.length();
    }

    public static void main(String[] args) {
        String s;
        String t;

        s = "abc";
        t = "ahbgdc";
        assert (isSubsequence(s, t));

        s = "axc";
        t = "ahbgdc";
        assert (!isSubsequence(s, t));
    }
}
