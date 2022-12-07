package com.aoc2022.Days;

import com.aoc2022.Utils.Reader;

import java.util.ArrayList;
import java.util.Collections;

public class Day2 {
    Reader fileReader = new Reader();
    ArrayList<String> input = fileReader.lineByLineString("day2");

    public void printResults(){
        System.out.println("Day 2a: " + part1());
        System.out.println("Day 2b: " + part2());
    }

    public Object part1(){
        int totalPoints = 0;
        int rock = 1;
        int paper = 2;
        int scissors = 3;

        for(String round : input){
            char opponent = round.charAt(0);
            char player = round.charAt(1);

            if(opponent == 'A'){
                if(player == 'X'){
                    totalPoints += rock + 3;
                }
                else if(player == 'Y'){
                    totalPoints += paper + 6;
                }
                else if(player == 'Z'){
                    totalPoints += scissors;
                }
            }
            else if(opponent == 'B'){
                if(player == 'X'){
                    totalPoints += rock;
                }
                else if(player == 'Y'){
                    totalPoints += paper + 3;
                }
                else if(player == 'Z'){
                    totalPoints += scissors + 6;
                }
            }
            else if(opponent == 'C'){
                if(player == 'X'){
                    totalPoints += rock + 6;
                }
                else if(player == 'Y'){
                    totalPoints += paper;
                }
                else if(player == 'Z'){
                    totalPoints += scissors + 3;
                }
            }
        }
        return totalPoints;
    }

    public Object part2(){
        int totalPoints = 0;
        int rock = 1;
        int paper = 2;
        int scissors = 3;

        for(String round : input){
            char opponent = round.charAt(0);
            char player = round.charAt(1);

            if(opponent == 'A'){
                if(player == 'X'){
                    totalPoints += scissors;
                }
                else if(player == 'Y'){
                    totalPoints += rock + 3;
                }
                else if(player == 'Z'){
                    totalPoints += paper + 6;
                }
            }
            else if(opponent == 'B'){
                if(player == 'X'){
                    totalPoints += rock;
                }
                else if(player == 'Y'){
                    totalPoints += paper + 3;
                }
                else if(player == 'Z'){
                    totalPoints += scissors + 6;
                }
            }
            else if(opponent == 'C'){
                if(player == 'X'){
                    totalPoints += paper;
                }
                else if(player == 'Y'){
                    totalPoints += scissors + 3;
                }
                else if(player == 'Z'){
                    totalPoints += rock + 6;
                }
            }
        }
        return totalPoints;
    }
}
