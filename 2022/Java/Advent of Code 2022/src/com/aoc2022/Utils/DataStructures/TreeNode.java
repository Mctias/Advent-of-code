package com.aoc2022.Utils.DataStructures;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class TreeNode<T> {
    public T data;
    public TreeNode<T> parent;
    public ArrayList<TreeNode<T>> children;

    public int size = 0;

    public TreeNode(T data) {
        this.data = data;
        this.children = new ArrayList<TreeNode<T>>();

    }

    public void addChild(TreeNode childNode) {
        childNode.parent = this;
        this.children.add(childNode);
    }

    public void printTree(){
        if(this == null)
            return;

        System.out.println(this.data);
        for(int i = 0; i < this.children.size(); i++){
            this.children.get(i).printTree();
        }
    }
}
