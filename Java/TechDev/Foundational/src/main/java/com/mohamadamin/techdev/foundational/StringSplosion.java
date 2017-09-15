package com.mohamadamin.techdev.foundational;

/**
 * Created by Mohamad Amin Mohamadi (mohammadi.mohamadamin@gmail.com) on 9/16/17.
 * <a href="https://techdevguide.withgoogle.com/paths/foundational/sequence-2/stringsplosion-problem-ccocodcode/#!">Problem link</a>
 */

public class StringSplosion {

    public static void main(String[] args) {
        System.out.println(new StringSplosion().stringSplosion("Code"));
    }

    public String stringSplosion(String str) {
        StringBuilder sploded = new StringBuilder();
        for (int i=0; i <= str.length(); i++) {
            sploded.append(str.substring(0, i));
        }
        return sploded.toString();
    }

}
