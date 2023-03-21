<?php
include __DIR__ . "/../solution.php";

class Day21 extends Solution
{
    private function solve_part_1($data, $root)
    {
        if(is_numeric($data[$root]))
        {
            return $data[$root];
        }
        else
        {
            preg_match_all('![-+*/]!', $data[$root], $operator);
            $operator = $operator[0][0];
            list($left, $right) = explode($operator, $data[$root]);
            $left = trim($left);
            $right = trim($right);

            if($operator == '+')
            { 
                return $this->solve_part_1($data, $left) + $this->solve_part_1($data, $right);
            }
            else if($operator == '-')
            { 
                return $this->solve_part_1($data, $left) - $this->solve_part_1($data, $right);
            }
            else if($operator == '*')
            {
                return $this->solve_part_1($data, $left) * $this->solve_part_1($data, $right);
            }
            else
            {
                return $this->solve_part_1($data, $left) / $this->solve_part_1($data, $right);
            }
        }
    }

    private function solve_part_2($data, $root)
    {
        if($data[$root] == "x")
        {
            return "x";
        }
        if(is_numeric($data[$root]))
        {
            return $data[$root];
        }
        else
        {
            preg_match_all('![-+*/=]!', $data[$root], $operator);
            $operator = $operator[0][0];
            list($left, $right) = explode($operator, $data[$root]);
            $left = trim($left);
            $right = trim($right);

            if($operator == '+')
            { 
                return "(".$this->solve_part_2($data, $left) . "+" . $this->solve_part_2($data, $right).")";
            }
            else if($operator == '-')
            { 
                return "(".$this->solve_part_2($data, $left) . "-" . $this->solve_part_2($data, $right).")";
            }
            else if($operator == '*')
            {
                return "(".$this->solve_part_2($data, $left) . "*" . $this->solve_part_2($data, $right).")";
            }
            else if($operator == '/')
            {
                return "(".$this->solve_part_2($data, $left) . "/" . $this->solve_part_2($data, $right).")";
            }
            else 
            {
                return "(".$this->solve_part_2($data, $left) . "=" . $this->solve_part_2($data, $right).")";
            }
        }
    }
    
    protected function part1()
    {
        $data = $this->data;
        $formatted_data = [];

        foreach($data as $line)
        {
            list($left, $right) = explode(':', $line);
            $right = trim($right);
            $formatted_data[$left] = $right;
        }

        return $this->solve_part_1($formatted_data, "root");
    }

    protected function part2()
    {
        $data = $this->data;
        $formatted_data = [];

        foreach($data as $line)
        {
            list($left, $right) = explode(':', $line);
            $right = trim($right);
            $formatted_data[$left] = $right;
        }

        $formatted_data["root"] = "lccz = pttp";
        $formatted_data["humn"] = "x";

        // Paste this in https://www.mathpapa.com/ :)))
        return  "Paste this to  https://www.mathpapa.com/ :))) ---> " . $this->solve_part_2($formatted_data, "root");
    }
}

new Day21(2022, 21);