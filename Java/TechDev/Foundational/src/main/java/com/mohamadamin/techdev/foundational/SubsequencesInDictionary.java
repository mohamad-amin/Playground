package com.mohamadamin.techdev.foundational;

/**
 * Created by Mohamad Amin Mohamadi (mohammadi.mohamadamin@gmail.com) on 9/16/17.
 * <a href="https://techdevguide.withgoogle.com/paths/foundational/sequence-2/find-longest-word-in-dictionary-that-subsequence-of-given-string/#code-challenge">Problem link</a>
 */
public class SubsequencesInDictionary {

    public static void main(String[] args) {
        String longest = new SubsequencesInDictionary().findLongestSubsequent(
                "abppplee",
                new String[]{"able", "ale", "apple", "bale", "kangaroo"}
        );
        System.out.println(longest);
    }

    private boolean isSubsequent(String suspect, String word) {
        int i = 0, j = 0;
        while (i < suspect.length() && j < word.length()) {
            if (suspect.charAt(i) == word.charAt(j)) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i == suspect.length();
    }

    public String findLongestSubsequent(String word, String[] suspects) {
        String longest = "";
        for (String suspect : suspects) {
            if (isSubsequent(suspect, word) && suspect.length() > longest.length()) {
                longest = suspect;
            }
        }
        return longest;
    }

}
