package com.mohamadamin.techdev.foundational;

import java.util.Arrays;
import java.util.Comparator;

/**
 * Created by Mohamad Amin Mohamadi (mohammadi.mohamadamin@gmail.com) on 9/16/17.
 * <a href="https://techdevguide.withgoogle.com/paths/foundational/sequence-2/find-longest-word-in-dictionary-that-subsequence-of-given-string/#code-challenge">Problem link</a>
 */
public class SubsequencesInDictionary {

    private int indexOf[][];
    private int last[];

    public static void main(String[] args) {
        String longest = new SubsequencesInDictionary().findLongestSubsequent(
                "abppplee",
                new String[]{"able", "ale", "apple", "bale", "kangaroo"}
        );
        System.out.println(longest);
    }

    private void preprocess(String word) {
        indexOf = new int['z'-'a'][word.length()];
        last = new int['z'-'a'];
        for (int i = 0; i < indexOf.length; i++) {
            for (int j = 0; j < word.length(); j++) {
                indexOf[i][j] = -1;
            }
        }
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            indexOf[c-'a'][last[c-'a']++] = i;
        }
    }

    private boolean isSubsequent(String suspect) {
        int currentIndex = -1;
        for (int i = 0; i < suspect.length(); i++) {
            boolean found = false;
            int indexes[] = indexOf[suspect.charAt(i) - 'a'];
            for (int j = 0; j < last[suspect.charAt(i) - 'a']; j++) {
                if (indexes[j] > currentIndex) {
                    currentIndex = indexes[j];
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }

    public String findLongestSubsequent(String word, String[] suspects) {

        Arrays.sort(suspects, new Comparator<String>() {
            public int compare(String o1, String o2) {
                return o2.length() - o1.length();
            }
        });
        preprocess(word);

        for (String suspect : suspects) {
            if (isSubsequent(suspect)) {
                return suspect;
            }
        }

        return null;

    }

}
