package isomorphicstrings;

import java.util.HashMap;
import java.util.Map;

class Solution {
    public static boolean isIsomorphic(String s, String t) {
        Map<Character, Character> charMapping = new HashMap<Character, Character>();

        for (int i = 0; i < s.length(); i++) {
            if (charMapping.containsKey(t.charAt(i))) {
                if (charMapping.get(t.charAt(i)) != s.charAt(i))
                    return false;
            } else {
                if (charMapping.values().contains(s.charAt(i)))
                    return false;
                charMapping.put(t.charAt(i), s.charAt(i));
            }
        }

        return true;
    }

    public static void main(String[] args) {
        String s;
        String t;

        s = "egg";
        t = "add";
        assert (isIsomorphic(s, t));

        s = "foo";
        t = "bar";
        assert (!isIsomorphic(s, t));

        s = "paper";
        t = "title";
        assert (isIsomorphic(s, t));
    }
}