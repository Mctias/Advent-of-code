<?php
include __DIR__ . "/../solution.php";
class Day10 extends Solution
{
    protected function part1()
    {
        $data = $this->data;
        $cycles = 0;
        $signal_str = 0;
        $x = 1;

        foreach ($data as $line)
        {
            if (str_contains($line, " "))
                list($command, $value) = explode(" ", $line);
            else
                $command = $line;

            if ($command == "addx")
            {
                $cycles++;
                if ($cycles == 20 || $cycles == 60 || $cycles == 100 || $cycles == 140 || $cycles == 180 || $cycles == 220)
                {
                    $signal_str +=  $cycles * $x;
                }

                $cycles++;
                if ($cycles == 20 || $cycles == 60 || $cycles == 100 || $cycles == 140 || $cycles == 180 || $cycles == 220)
                {
                    $signal_str +=  $cycles * $x;
                }
                $x += $value;
            }
            else
            {
                $cycles++;
                if ($cycles == 20 || $cycles == 60 || $cycles == 100 || $cycles == 140 || $cycles == 180 || $cycles == 220)
                {
                    $signal_str +=  $cycles * $x;
                }
            }
        }

        return $signal_str;
    }


    protected function part2()
    {
        $data = $this->data;
        $cycles = 0;
        $x = 1;
        $row = 0;
        $crt = array_fill(0, 5, "");

        foreach ($data as $line)
        {
            if (str_contains($line, " "))
                list($command, $value) = explode(" ", $line);
            else
                $command = $line;

            if ($command == "addx")
            {
                if ((int)abs($x - ($cycles % 40)) <= 1)
                {
                    $crt[$row] = $crt[$row] . "#";
                }
                else
                {
                    $crt[$row] = $crt[$row] . " ";
                }

                $cycles++;

                if ($cycles % 40 == 0 && $cycles != 0) $row++;

                if ((int)abs($x - ($cycles % 40)) <= 1)
                {
                    $crt[$row] = $crt[$row] . "#";
                }
                else
                {
                    $crt[$row] = $crt[$row] . " ";
                }

                $cycles++;

                if ($cycles % 40 == 0 && $cycles != 0) $row++;
                $x += $value;
            }
            else
            {
                if ((int)abs($x - ($cycles % 40)) <= 1)
                {
                    $crt[$row] = $crt[$row] . "#";
                }
                else
                {
                    $crt[$row] = $crt[$row] . " ";
                }
                $cycles++;

                if ($cycles % 40 == 0 && $cycles != 0) $row++;
            }
        }

        return $crt;
    }
}

new Day10(2022, 10);
