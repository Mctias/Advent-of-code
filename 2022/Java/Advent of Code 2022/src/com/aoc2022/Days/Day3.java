package com.aoc2022.Days;

import com.aoc2022.Utils.Reader;

import java.util.ArrayList;
import java.util.Collections;
import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class Day3 {
    Reader fileReader = new Reader();
    ArrayList<String> input = fileReader.lineByLineString("day3");

    public void printResults(){
        System.out.println("Day 3a: " + part1());
        System.out.println("Day 3b: " + part2());
    }

    public Object part1(){
        Map<Character, Integer> hm = new HashMap<Character, Integer>();

        int priority = 1;
        for(char letter  = 'a'; letter <= 'z'; letter++, priority++){
            hm.put(letter, priority);
        }
        for(char letter  = 'A'; letter <= 'Z'; letter++, priority++){
            hm.put(letter, priority);
        }

        ArrayList<Character> overlaps = new ArrayList<>();
        for(String s : input){
            ArrayList<Character> firstHalf = new ArrayList<>();
            ArrayList<Character> secondsHalf = new ArrayList<>();
            for(int i  = 0; i < s.length(); i++){
                if(i < s.length() / 2){
                    firstHalf.add(s.charAt(i));
                }
                else{
                    secondsHalf.add(s.charAt(i));
                }
            }
            firstHalf.retainAll(secondsHalf);
            overlaps.addAll(firstHalf.stream().distinct().collect(Collectors.toList()));
        }

        int result = 0;
        for(Character a : overlaps){
            result += hm.get(a);
        }

        return result;
    }

    public Object part2(){
        Map<Character, Integer> hm = new HashMap<Character, Integer>();

        int priority = 1;
        for(char letter  = 'a'; letter <= 'z'; letter++, priority++){
            hm.put(letter, priority);
        }
        for(char letter  = 'A'; letter <= 'Z'; letter++, priority++){
            hm.put(letter, priority);
        }

        ArrayList<Character> overlaps = new ArrayList<>();
        for(int i = 0; i < input.size(); i+=3){
            List<Character> first = input.get(i).chars().mapToObj(e -> (char)e).collect(Collectors.toList());
            List<Character> second = input.get(i + 1).chars().mapToObj(e -> (char)e).collect(Collectors.toList());
            List<Character> third = input.get(i + 2).chars().mapToObj(e -> (char)e).collect(Collectors.toList());

            first.retainAll(second);
            first.retainAll(third);

            overlaps.addAll(first.stream().distinct().collect(Collectors.toList()));
        }

        int result = 0;
        for(Character a : overlaps){
            result += hm.get(a);
        }

        return result;
    }
}
