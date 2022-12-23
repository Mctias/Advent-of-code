package com.aoc2022.Days;

import com.aoc2022.Utils.DataStructures.TreeNode;
import com.aoc2022.Utils.Reader;
import com.aoc2022.Utils.Printer;
import com.sun.source.tree.Tree;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

public class Day7 {
    Reader fileReader = new Reader();
    Printer printer = new Printer();


    ArrayList<ArrayList<String>> input = fileReader.listOfListStrings("day7");
    ArrayList<Integer> folderSizes = new ArrayList<>();


    public void printResults(){
        System.out.println("Day 7a: " + part1());
        System.out.println("Day 7b: " + part2());
    }

    private static boolean isNumeric(String strNum) {
        if (strNum == null) {
            return false;
        }
        try {
            double d = Double.parseDouble(strNum);
        } catch (NumberFormatException nfe) {
            return false;
        }
        return true;
    }

    private int calculateFolderSizes(TreeNode currentNode ){
        if(currentNode.children.isEmpty()){
            return Integer.parseInt(currentNode.data.toString());
        }
        int sizeSum = 0;
        for(var child : currentNode.children){
            sizeSum += calculateFolderSizes((TreeNode) child);
        }
        currentNode.size += sizeSum;
        return currentNode.size;
    }

    private int foldersBelowThreshold(TreeNode currentNode){
        int total = 0;
        if(currentNode.size < 100000)
            total += currentNode.size;

        for(var child : currentNode.children){
            total += foldersBelowThreshold((TreeNode) child);
        }
        return total;
    }

    private void findSmallestSizeAboveThreshold(TreeNode currentNode){

        if(currentNode.size > 2805968)
            folderSizes.add(currentNode.size);

        for(var child : currentNode.children){
            findSmallestSizeAboveThreshold((TreeNode) child);
        }
    }

    public Object part1(){
        TreeNode currentNode = null;
        TreeNode head = null;

        for(int i = 0; i < input.size(); i++){
            if(input.get(i).size() == 3){
                var dir = input.get(i).get(2);
                if(dir.equals("..")){
                    currentNode = currentNode.parent;
                }
                else if(dir.equals("/")){
                    head = new TreeNode(dir);
                    currentNode = head;
                }
                else{
                    for(var child : currentNode.children){
                        TreeNode nodeChild = (TreeNode) child;
                        if(nodeChild.data.equals(dir)){
                            currentNode = nodeChild;
                            break;
                        }
                    }
                }
            }
            if(input.get(i).get(1).equals("ls")){
                continue;
            }
            if(input.get(i).get(0).equals("dir")){
                var dir = input.get(i).get(1);
                TreeNode node = new TreeNode<>(dir);
                currentNode.addChild(node);
            }
            if(isNumeric(input.get(i).get(0))){
                var dir = input.get(i).get(0);
                TreeNode node = new TreeNode<>(dir);
                currentNode.addChild(node);
            }
        }

        calculateFolderSizes(head);

        int result = foldersBelowThreshold(head);


        findSmallestSizeAboveThreshold(head);

        Collections.sort(folderSizes);
        System.out.println(folderSizes.get(0));

        return result;
    }

    public Object part2(){
        return null;
    }
}
