package com.aoc2022.Days;

import com.aoc2022.Utils.Reader;
import java.util.Collections;
import java.util.ArrayList;

public class Day1 {
    Reader fileReader = new Reader();
    ArrayList<Integer> input = fileReader.emptyLines("day1");

    public void printResults(){
        System.out.println("Day 1a: " + part1());
        System.out.println("Day 1b: " + part2());
    }

    public Object part1(){
        ArrayList<Integer> totalCalories = new ArrayList<Integer>();
        int temp = 0;
        for(int i : input){
            if(i == -1){
                totalCalories.add(temp);
                temp = 0;
                continue;
            }
            temp += i;
        }
        int result = Collections.max(totalCalories);
        return result;
    }

    public Object part2(){
        ArrayList<Integer> totalCalories = new ArrayList<Integer>();
        int temp = 0;
        for(int i : input){
            if(i == -1){
                totalCalories.add(temp);
                temp = 0;
                continue;
            }
            temp += i;
        }
        Collections.sort(totalCalories, Collections.reverseOrder());
        int result = totalCalories.get(0) + totalCalories.get(1) + totalCalories.get(2);
        return result;
    }
}
