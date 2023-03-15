<?php
include __DIR__ . "/../solution.php";
class Day11 extends Solution
{
    private function format_data()
    {
        $raw_data = $this->data;
        //print_r($data);
        $data = [];
        $sub_data = [];

        $index = -1;

        foreach ($raw_data as $line)
        {
            if (str_contains($line, "Monkey") && $index != -1)
            {
                list($_, $ind) = explode(" ", $line);
                $ind = trim($ind, ":");
                array_push($sub_data, 0);
                $data[$index] = $sub_data;
                $sub_data = [];
            }
            else if ($line === "") continue;
            else if (str_contains($line, "Starting items:"))
            {
                preg_match_all('!\d+!', $line, $matches);
                foreach ($matches as $number)
                {
                    array_push($sub_data, $number);
                }
            }
            else if (str_contains($line, "Operation:"))
            {
                preg_match_all('!\d+!', $line, $num);
                preg_match_all('![-+*/]!', $line, $operator);

                if ($num == null)
                {
                    array_push($sub_data, $operator);
                }
                else
                {
                    array_push($sub_data, array_merge($operator[0], $num[0]));
                }
            }
            else if (str_contains($line, "Test:"))
            {
                preg_match_all('!\d+!', $line, $matches);
                array_push($sub_data, $matches[0][0]);
            }
            else if (str_contains($line, "If true:"))
            {
                preg_match_all('!\d+!', $line, $matches);
                array_push($sub_data, $matches[0][0]);
            }
            else if (str_contains($line, "If false:"))
            {
                preg_match_all('!\d+!', $line, $matches);
                array_push($sub_data, $matches[0][0]);

                $index++;
            }
        }
        return $data;
    }

    protected function part1()
    {
        $data = $this->format_data();
        for ($k = 0; $k < 20; $k++)
        {
            for ($j = 0; $j < count($data); $j++)
            {
                $data[$j][0] = array_values($data[$j][0]);
                $items = $data[$j][0];

                if (count($items) == 0) continue;

                $operation = $data[$j][1];
                $test = $data[$j][2];
                $test_true = $data[$j][3];
                $test_false = $data[$j][4];

                for ($i = 0; $i < count($items); $i++)
                {
                    $data[$j][5]++;
                    if ($operation[0] == "*")
                    {
                        if (count($operation) == 1)
                        {
                            $items[$i] *= $items[$i];
                        }
                        else
                        {
                            $items[$i] *= (int)$operation[1];
                        }
                    }
                    else if ($operation[0] == "+")
                    {
                        if (count($operation) == 1)
                        {
                            $items[$i] += $items[$i];
                        }
                        else
                        {
                            $items[$i] += (int)$operation[1];
                        }
                    }

                    $items[$i] = (int)($items[$i] / 3);

                    if ($items[$i] % $test == 0)
                    {
                        array_push($data[$test_true][0], $items[$i]);
                    }
                    else
                    {
                        array_push($data[$test_false][0], $items[$i]);
                    }
                    unset($data[$j][0][$i]);
                }
            }
        }

        $results = [];
        foreach ($data as $line)
        {
            array_push($results, $line[5]);
        }

        rsort($results);

        return $results[0] * $results[1];
    }

    protected function part2()
    {
        $data = $this->format_data();

        for ($k = 0; $k < 10000; $k++)
        {
            for ($j = 0; $j < count($data); $j++)
            {
                $data[$j][0] = array_values($data[$j][0]);
                $items = $data[$j][0];
                if (count($items) == 0) continue;
                $operation = $data[$j][1];
                $test = $data[$j][2];
                $test_true = $data[$j][3];
                $test_false = $data[$j][4];

                for ($i = 0; $i < count($items); $i++)
                {
                    $data[$j][5]++;
                    if ($operation[0] == "*")
                    {
                        if (count($operation) == 1)
                        {
                            $items[$i] *= $items[$i];
                        }
                        else
                        {
                            $items[$i] *= (int)$operation[1];
                        }
                    }
                    else if ($operation[0] == "+")
                    {
                        if (count($operation) == 1)
                        {
                            $items[$i] += $items[$i];
                        }
                        else
                        {
                            $items[$i] += (int)$operation[1];
                        }
                    }

                    $items[$i] = (int)($items[$i]) % 9699690;

                    if ($items[$i] % $test == 0)
                    {
                        array_push($data[$test_true][0], $items[$i]);
                    }
                    else
                    {
                        array_push($data[$test_false][0], $items[$i]);
                    }
                    unset($data[$j][0][$i]);
                }
            }
        }

        $results = [];
        foreach ($data as $line)
        {
            array_push($results, $line[5]);
        }

        rsort($results);

        return $results[0] * $results[1];
    }
}

new Day11(2022, 11);
