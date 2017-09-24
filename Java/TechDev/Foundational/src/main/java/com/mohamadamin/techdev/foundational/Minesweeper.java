package com.mohamadamin.techdev.foundational;

import java.util.Arrays;

/**
 * Created by Mohamad Amin Mohamadi (mohammadi.mohamadamin@gmail.com) on 9/17/17.
 */
public class Minesweeper {

    public static void main(String[] args) {
        int matrix[][] = new Minesweeper().createMap();
        for (int i = 0; i < matrix.length; i++) {
            System.out.println(Arrays.toString(matrix[i]));
        }
    }

    public int[][] createMap() {
        return null;
    }

}
