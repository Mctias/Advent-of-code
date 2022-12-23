package com.aoc2022.Days;

import com.aoc2022.Utils.Reader;
import java.util.Collections;
import java.util.ArrayList;

public class Day6 {
    Reader fileReader = new Reader();
    ArrayList<String> input = fileReader.lineByLineString("day6");

    public void printResults(){
        System.out.println("Day 6a: " + part1());
        System.out.println("Day 6b: " + part2());
    }
    boolean uniqueCharacters(String str)
    {
        for (int i = 0; i < str.length(); i++)
            for (int j = i + 1; j < str.length(); j++)
                if (str.charAt(i) == str.charAt(j))
                    return false;

        return true;
    }



    public Object part1(){
        String code = input.get(0);
        for(int i = 0; i < code.length(); i++){
            String window = "" + code.charAt(i) + code.charAt(i+1) + code.charAt(i+2) + code.charAt(i+3);
            if(uniqueCharacters(window)){
                return i + 4;
            }
        }
        return 0;
    }

    public Object part2(){
        String code = input.get(0);
        for(int i = 0; i < code.length(); i++){
            String window = "";
            for(int j = i; j < i + 14; j++){
                window += "" + code.charAt(j);
            }
            if(uniqueCharacters(window)){
                return i + 14;
            }
        }
        return 0;
    }
}
