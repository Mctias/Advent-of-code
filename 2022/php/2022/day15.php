<?php
ini_set('memory_limit', '3000M');
include __DIR__ . "/../solution.php";

class Day15 extends Solution
{
    private function format_data($input)
    {
        $data = [];

        foreach ($input as $line)
        {
            list($first_half, $second_half) = explode(":", $line);
            preg_match_all('/-?[0-9]+/', $first_half, $sensor_coords);
            preg_match_all('/-?[0-9]+/', $second_half, $beacon_coords);
            $sensor_coords = array_merge(...$sensor_coords);
            $beacon_coords = array_merge(...$beacon_coords);

            array_push($data, [$sensor_coords, $beacon_coords]);
        }

        return $data;
    }
    protected function part1()
    {
        $data = $this->format_data($this->data);
        $b = [];
        $n_b = [];
        $line = 2000000;

        foreach ($data as $row)
        {
            $b_x = $row[1][0];
            $b_y = $row[1][1];

            array_push($b, [$b_x, $b_y]);
        }

        foreach ($data as $row)
        {
            $s_x = $row[0][0];
            $s_y = $row[0][1];

            $b_x = $row[1][0];
            $b_y = $row[1][1];

            $radius = abs($b_x - $s_x) + abs($b_y - $s_y);
            $distance = abs($s_y -  $line);

            if ($distance <= $radius)
            {
                for ($x = $s_x - ($radius - $distance); $x <= $s_x + ($radius - $distance); $x++)
                {
                    if (!in_array([$x, $line], $b) && !isset($n_b[$x][$line])) $n_b[$x][$line] = 1;
                }
            }
        }
        return count($n_b);
    }

    protected function part2()
    {
        $data = $this->format_data($this->data);
        $b = [];
        $n_b = [];
        $line = 4000000;

        foreach ($data as $row)
        {
            $b_x = $row[1][0];
            $b_y = $row[1][1];

            array_push($b, [$b_x, $b_y]);
        }

        foreach ($data as $row)
        {
            $s_x = $row[0][0];
            $s_y = $row[0][1];

            $b_x = $row[1][0];
            $b_y = $row[1][1];

            $radius = abs($b_x - $s_x) + abs($b_y - $s_y);
            $distance = abs($s_y -  $line);

            if ($distance <= $radius)
            {
                $min_x = max(0, $s_x - ($radius - $distance));
                $max_x = min(4000000,  $s_x + ($radius - $distance));

                for ($x = $min_x; $x <= $max_x; $x++)
                {
                    if (!in_array([$x, $line], $b) && !isset($n_b[$x][$line])) $n_b[$x][$line] = 1;
                }
            }
        }
    }
}
new Day15(2022, 15);