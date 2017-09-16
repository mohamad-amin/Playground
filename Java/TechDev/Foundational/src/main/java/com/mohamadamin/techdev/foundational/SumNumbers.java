package com.mohamadamin.techdev.foundational;

/**
 * Created by Mohamad Amin Mohamadi (mohammadi.mohamadamin@gmail.com) on 9/17/17.
 */
public class SumNumbers {

    public static void main(String[] args) {
        System.out.println(new SumNumbers().sumNumbers("aa11b33"));
    }

    public int sumNumbers(String str) {
        int result = 0;
        for (int i = 0; i < str.length(); i++) {
            if (Character.isDigit(str.charAt(i)))  {
                String number = buildNumber(str.substring(i));
                i += number.length() - 1;
                result += Integer.valueOf(number);
            }
        }
        return result;
    }

    private String buildNumber(String str) {
        String result = "";
        for (char c : str.toCharArray()) {
            if (Character.isDigit(c)) {
                result += c;
            } else {
                return result;
            }
        }
        return result;
    }

}
