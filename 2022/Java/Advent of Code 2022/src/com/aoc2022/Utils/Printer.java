package com.aoc2022.Utils;

import java.util.ArrayList;

public class Printer {
    public void PrintListOfList(ArrayList<ArrayList<String>> input){
        for(int i = 0; i < input.size(); i++){
            for(int j = 0; j < input.get(i).size(); j++){
                System.out.println(input.get(i).get(j));
            }
        }

    }
}
