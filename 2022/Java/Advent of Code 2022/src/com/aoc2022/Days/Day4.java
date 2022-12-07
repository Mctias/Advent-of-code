package com.aoc2022.Days;

import com.aoc2022.Utils.Range;
import com.aoc2022.Utils.Reader;
import java.util.Collections;
import java.util.ArrayList;

public class Day4 {
    Reader fileReader = new Reader();
    ArrayList<Range> input = fileReader.ranges("day4");

    public void printResults(){
        System.out.println("Day 4a: " + part1());
        System.out.println("Day 4b: " + part2());
    }

    public Object part1(){
        int result = 0;
        for(int i = 0; i < input.size() - 1; i+=2){
            Range r1 = input.get(i);
            Range r2 = input.get(i + 1);

            if(r2.low >= r1.low && r2.high <= r1.high ){
                result++;
            }
            else if(r1.low >= r2.low && r1.high <= r2.high ){
                result++;
            }
        }

        return result;
    }

    public Object part2(){
        int result = 0;
        for(int i = 0; i < input.size() - 1; i+=2){
            Range r1 = input.get(i);
            Range r2 = input.get(i + 1);

            if(r1.contains(r2.low) || r1.contains(r2.high)){
                result++;
            }
            else if(r2.contains(r1.low) || r2.contains(r1.high)){
                result++;
            }
        }

        return result;
    }
}
