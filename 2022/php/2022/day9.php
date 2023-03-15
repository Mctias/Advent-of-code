<?php
include __DIR__ . "/../solution.php";

class Day9 extends Solution
{
    private function sign($n)
    {
        return ($n > 0) - ($n < 0);
    }

    protected function part1()
    {
        $data = $this->data;
        $tailPosistions = [];
        $knots = array_fill(0, 2, [0, 0]);

        foreach ($data as $line)
        {
            list($direction, $magnitude) = explode(" ", $line);
            for ($i = 1; $i <= $magnitude; $i++)
            {
                switch ($direction)
                {
                    case 'R':
                        $knots[0][0]++;
                        break;
                    case 'D':
                        $knots[0][1]--;
                        break;
                    case 'L':
                        $knots[0][0]--;
                        break;
                    case 'U':
                        $knots[0][1]++;
                        break;
                    default:
                        echo "Something went wrong" . PHP_EOL;
                }
                for ($j = 1; $j < count($knots); $j++)
                {
                    $distanceX = $knots[$j - 1][0] - $knots[$j][0];
                    $distanceY = $knots[$j - 1][1] - $knots[$j][1];

                    if (abs($distanceX) > 1 || abs($distanceY) > 1)
                    {
                        $knots[$j][0] += $this->sign($distanceX);
                        $knots[$j][1] += $this->sign($distanceY);
                    }
                    $tx = $knots[count($knots) - 1][0];
                    $ty = $knots[count($knots) - 1][1];
                    array_push($tailPosistions, "[" . $tx . "," . $ty . "]");
                }
            }
        }

        return count(array_unique($tailPosistions));
    }

    protected function part2()
    {
        $data = $this->data;
        $tailPosistions = [];
        $knots = array_fill(0, 10, [0, 0]);

        foreach ($data as $line)
        {
            list($direction, $magnitude) = explode(" ", $line);
            for ($i = 1; $i <= $magnitude; $i++)
            {
                switch ($direction)
                {
                    case 'R':
                        $knots[0][0]++;
                        break;
                    case 'D':
                        $knots[0][1]--;
                        break;
                    case 'L':
                        $knots[0][0]--;
                        break;
                    case 'U':
                        $knots[0][1]++;
                        break;
                    default:
                        echo "Something went wrong" . PHP_EOL;
                }
                for ($j = 1; $j < count($knots); $j++)
                {
                    $distanceX = $knots[$j - 1][0] - $knots[$j][0];
                    $distanceY = $knots[$j - 1][1] - $knots[$j][1];

                    if (abs($distanceX) > 1 || abs($distanceY) > 1)
                    {
                        $knots[$j][0] += $this->sign($distanceX);
                        $knots[$j][1] += $this->sign($distanceY);
                    }
                    $tx = $knots[count($knots) - 1][0];
                    $ty = $knots[count($knots) - 1][1];
                    array_push($tailPosistions, "[" . $tx . "," . $ty . "]");
                }
            }
        }

        return count(array_unique($tailPosistions));
    }
}

new Day9(2022, 9);
