<?php
include __DIR__ . "/../solution.php";
class Day13 extends Solution
{
    private function format_data_1()
    {
        $raw_data = $this->data;
        $data = [];
        $pairs = [];
        foreach ($raw_data as $line)
        {
            if ($line === "")
            {
                array_push($data, $pairs);
                $pairs = [];
            }
            else
            {
                array_push($pairs, json_decode($line));
            }
        }
        return $data;
    }
    private function format_data_2()
    {
        $raw_data = $this->data;
        $data = [];
        foreach ($raw_data as $line)
        {
            if ($line === "")
            {
                continue;
            }
            else
            {
                array_push($data, json_decode($line));
            }
        }
        return $data;
    }

    private function compare($left, $right)
    {
        if (is_int($left) && is_int($right))
        {
            return $left <=> $right;
        }

        if (is_int($left))
        {
            $left = [$left];
        }

        if (is_int($right))
        {
            $right = [$right];
        }

        for ($i = 0; $i < min(count($left), count($right)); $i++)
        {
            $c = $this->compare($left[$i], $right[$i]);
            if ($c !== 0)
            {
                return $c;
            }
        }

        return count($left) <=> count($right);
    }

    protected function part1()
    {
        $data = $this->format_data_1();
        $result = [];
    
        foreach ($data as $index => [$left, $right])
        {
            if ($this->compare($left, $right) !== 1)
            {
                array_push($result, $index + 1);
            }
        }
    
        return array_sum($result);
    }

    protected function part2()
    {
        $data = $this->format_data_2("day13");
        array_push($data, [[2]], [[6]]);
    
        usort($data, [$this, "compare"]);
    
        $result = (array_search([[2]], $data) + 1) * (array_search([[6]], $data) + 1);
        return $result;
    }
}
new Day13(2022, 13);