package com.aoc2022.Utils;

import java.io.*;
import java.util.ArrayList;

public class Reader {
    static final String DATA_PATH = "C:\\Users\\Mattias Persson\\Documents\\Jobb\\AoC\\2022\\Java\\Advent of Code 2022\\data\\";
    /*
       1
       2
       3
     */
    public ArrayList<Integer> lineByLineInt(String day) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        try{
            String filePath = DATA_PATH + day + ".txt";
            File file = new File(filePath);
            BufferedReader br = new BufferedReader(new FileReader(file));
            String st;

            while((st = br.readLine()) != null){
                result.add(Integer.parseInt(st));
            }
            br.close();
        }
        catch (FileNotFoundException e){
            System.out.println("File not found\n" + e);
        }
        catch(NumberFormatException e){
            System.out.println("Failed to format string to number\n" + e);
        }
        catch (Exception e) {
            System.out.println("Something broke :)\n" + e);
        }
        return result;
    }
    /*
      Removes whitespace
      A B
      C D
      D E
    */
    public ArrayList<String> lineByLineString(String day) {
        ArrayList<String> result = new ArrayList<String>();
        try{
            String filePath = DATA_PATH + day + ".txt";
            File file = new File(filePath);
            BufferedReader br = new BufferedReader(new FileReader(file));
            String st;

            while((st = br.readLine()) != null){
                result.add(st.replaceAll("\\s+",""));
            }
            br.close();
        }
        catch (FileNotFoundException e){
            System.out.println("File not found\n" + e);
        }
        catch(NumberFormatException e){
            System.out.println("Failed to format string to number\n" + e);
        }
        catch (Exception e) {
            System.out.println("Something broke :)\n" + e);
        }
        return result;
    }

    /*
      1,2,3
     */
    public ArrayList<Integer> commaSeparated(String day) {
        ArrayList<Integer> result = new ArrayList<>();
        try{
            String filePath = DATA_PATH + day + ".txt";
            File file = new File(filePath);
            BufferedReader br = new BufferedReader(new FileReader(file));
            String st;

            while((st = br.readLine()) != null){
                String[] tokens = st.split(",");
                for (String s : tokens){
                    result.add(Integer.parseInt(s));
                }
            }

            br.close();
        }
        catch (FileNotFoundException e){
            System.out.println("File not found\n" + e);
        }
        catch(NumberFormatException e){
            System.out.println("Failed to format string to number\n" + e);
        }
        catch (Exception e) {
            System.out.println("Something broke :)\n" + e);
        }
        return result;
    }
    /*
      1,2,3
     */
    public ArrayList<ArrayList<Integer>> commaSeparatedListOfList(String day) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        try{
            String filePath = DATA_PATH + day + ".txt";
            File file = new File(filePath);
            BufferedReader br = new BufferedReader(new FileReader(file));
            String st;

            while((st = br.readLine()) != null){
                ArrayList<Integer> seq = new ArrayList<>();
                String[] tokens = st.split(",");
                for (String s : tokens){
                    seq.add(Integer.parseInt(s));
                }
                result.add(seq);
            }

            br.close();
        }
        catch (FileNotFoundException e){
            System.out.println("File not found\n" + e);
        }
        catch(NumberFormatException e){
            System.out.println("Failed to format string to number\n" + e);
        }
        catch (Exception e) {
            System.out.println("Something broke :)\n" + e);
        }
        return result;
    }
    /*
       Returns list which seperates the segments with -1
       1
       2
       3

       4
       5
       6
    */
    public ArrayList<Integer> emptyLines(String day) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        try{
            String filePath = DATA_PATH + day + ".txt";
            File file = new File(filePath);
            BufferedReader br = new BufferedReader(new FileReader(file));
            String st;

            while((st = br.readLine()) != null){
                if (st.isEmpty()){
                    result.add(-1);
                    continue;
                }
                result.add(Integer.parseInt(st));
            }
            br.close();
        }
        catch (FileNotFoundException e){
            System.out.println("File not found\n" + e);
        }
        catch(NumberFormatException e){
            System.out.println("Failed to format string to number\n" + e);
        }
        catch (Exception e) {
            System.out.println("Something broke :)\n" + e);
        }
        return result;
    }

    /*
       A list of lists with each sublist containing segments
       1
       2
       3

       4
       5
       6
    */
    public ArrayList<ArrayList<Integer>> listOfLists(String day) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        try{
            String filePath = DATA_PATH + day + ".txt";
            File file = new File(filePath);
            BufferedReader br = new BufferedReader(new FileReader(file));
            String st;

            ArrayList<Integer> segment = new ArrayList<Integer>();

            while((st = br.readLine()) != null){
                if (st.isEmpty()){
                    result.add(new ArrayList<>(segment));
                    segment.clear();
                    continue;
                }
                segment.add(Integer.parseInt(st));
            }
            // Need to add the last one as well
            result.add(segment);
            br.close();
        }
        catch (FileNotFoundException e){
            System.out.println("File not found\n" + e);
        }
        catch(NumberFormatException e){
            System.out.println("Failed to format string to number\n" + e);
        }
        catch (Exception e) {
            System.out.println("Something broke :)\n" + e);
        }
        return result;
    }
    public ArrayList<ArrayList<String>> listOfListStrings(String day) {
        ArrayList<ArrayList<String>> result = new ArrayList<ArrayList<String>>();
        try{
            String filePath = DATA_PATH + day + ".txt";
            File file = new File(filePath);
            BufferedReader br = new BufferedReader(new FileReader(file));
            String st;

            ArrayList<String> segment = new ArrayList<String>();

            while((st = br.readLine()) != null){
                String[] arrOfStr = st.split(" ", -1);
                for(int i = 0; i < arrOfStr.length; i++){
                    segment.add(arrOfStr[i]);
                }
                result.add(new ArrayList<>(segment));
                segment.clear();
            }
            // Need to add the last one as well

            br.close();
        }
        catch (FileNotFoundException e){
            System.out.println("File not found\n" + e);
        }
        catch(NumberFormatException e){
            System.out.println("Failed to format string to number\n" + e);
        }
        catch (Exception e) {
            System.out.println("Something broke :)\n" + e);
        }
        return result;
    }

    /*
        1-4, 5-6
        5-7, 9-9
        0-4, 5-6
    */
    public ArrayList<Range> ranges(String day){
        ArrayList<Range> result = new ArrayList<Range>();
        try{
            String filePath = DATA_PATH + day + ".txt";
            File file = new File(filePath);
            BufferedReader br = new BufferedReader(new FileReader(file));
            String st;

            while((st = br.readLine()) != null){
                st = st.replaceAll(",","-");
                String[] numbers = st.split("-");

                Range r1 = new Range(Integer.parseInt(numbers[0]), Integer.parseInt(numbers[1]));
                Range r2 = new Range(Integer.parseInt(numbers[2]), Integer.parseInt(numbers[3]));
                result.add(r1);
                result.add(r2);
            }
            br.close();
        }
        catch (FileNotFoundException e){
            System.out.println("File not found\n" + e);
        }
        catch(NumberFormatException e){
            System.out.println("Failed to format string to number\n" + e);
        }
        catch (Exception e) {
            System.out.println("Something broke :)\n" + e);
        }
        return result;
    }

}
