import java.util.ArrayList;

public class Day1 {
    Reader fileReader = new Reader();
    ArrayList<Integer> input = fileReader.lineByLine("day1");

    public void printResults(){
        System.out.println("Day 1a: " + part1());
        System.out.println("Day 1b: " + part2());
    }

    public Object part1(){
        int numberOfIncreases = 0;
        int lastNumber = Integer.MAX_VALUE;
        for(int i = 0; i < input.size(); i++){
            if(input.get(i) > lastNumber){
                numberOfIncreases++;
            }
            lastNumber = input.get(i);
        }
        return numberOfIncreases;
    }

    public Object part2(){
        int numberOfIncreases = 0;
        ArrayList<Integer> sums = new ArrayList<Integer>();
        for(int i = 0; i < input.size() - 2; i++){
            int tot = input.get(i) + input.get(i + 1) + input.get(i + 2);
            sums.add(tot);
        }

        int lastNumber = Integer.MAX_VALUE;
        for(int i = 0; i < sums.size(); i++){
            if(sums.get(i) > lastNumber){
                numberOfIncreases++;
            }
            lastNumber = sums.get(i);
        }
        return numberOfIncreases;
    }
}
