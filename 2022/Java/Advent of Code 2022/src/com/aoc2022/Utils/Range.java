package com.aoc2022.Utils;

public class Range
{
    public int low;
    public int high;

    public Range(int low, int high){
        this.low = low;
        this.high = high;
    }

    public boolean contains(int number){
        return (number >= low && number <= high);
    }
}