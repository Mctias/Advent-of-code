package com.aoc2022.Days;

import com.aoc2022.Utils.Reader;

import java.util.ArrayList;
import java.util.Stack;

public class Day5 {
    Reader fileReader = new Reader();
    ArrayList<String> stacksInput = fileReader.lineByLineString("stacks5");
    ArrayList<ArrayList<Integer>> moves = fileReader.commaSeperatedListOfList("day5");


    public void printResults(){
        System.out.println("Day 5a: " + part1());
        System.out.println("Day 5b: " + part2());
    }

    public void buildStacks(ArrayList<Stack<Character>> stacks){
        for(int i = 0; i < 9; i++){
            Stack<Character> temp = new Stack<>();
            for(int j = stacksInput.get(i).length() - 1; j >= 0; j--){
                temp.push(stacksInput.get(i).charAt(j));
            }
            stacks.add(temp);
        }
    }
    public Object part1(){
        ArrayList<Stack<Character>> stacks = new ArrayList<>();
        buildStacks(stacks);

        for(var move : moves){
            int numberOfCrates = move.get(0);
            int fromCrate = move.get(1) - 1;
            int toCrate = move.get(2) - 1;

            for(int i = 0; i < numberOfCrates; i++){
                stacks.get(toCrate).push(stacks.get(fromCrate).peek());
                stacks.get(fromCrate).pop();
            }
        }
        String result = "";
        for(int i = 0; i < stacks.size(); i++){
            result += stacks.get(i).peek();
        }

        return result;
    }

    public Object part2(){
        ArrayList<Stack<Character>> stacks = new ArrayList<>();
        buildStacks(stacks);

        for(var move : moves){
            ArrayList<Character> ordered = new ArrayList<>();
            int numberOfCrates = move.get(0);
            int fromCrate = move.get(1) - 1;
            int toCrate = move.get(2) - 1;

            for(int i = 0; i < numberOfCrates; i++){
                ordered.add(stacks.get(fromCrate).peek());
                stacks.get(fromCrate).pop();
            }

            for(int i = ordered.size() - 1; i >= 0; i--){
                stacks.get(toCrate).push(ordered.get(i));
            }
        }
        String result = "";
        for(int i = 0; i < stacks.size(); i++){
            result += stacks.get(i).peek();
        }

        return result;
    }
}
