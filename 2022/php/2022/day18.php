<?php
include __DIR__ . "/../solution.php";

class Day18 extends Solution
{
    protected function part1()
    {
        $count = 0;
        $data = $this->data;
        foreach ($data as $row)
        {
            list($x, $y, $z) = explode(",", $row);
            if (!in_array(($x + 1) . "," . $y . "," . $z, $data))  $count++;
            if (!in_array(($x - 1) . "," . $y . "," . $z, $data))  $count++;
            if (!in_array($x . "," . ($y + 1) . "," . $z, $data))  $count++;
            if (!in_array($x . "," . ($y - 1) . "," . $z, $data))  $count++;
            if (!in_array($x . "," . $y . "," . ($z + 1), $data))  $count++;
            if (!in_array($x . "," . $y . "," . ($z - 1), $data))  $count++;
        }

        return $count;
    }

    protected function part2()
    {
    }
}

new Day18(2022, 18);
