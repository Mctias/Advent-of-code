<?php
include __DIR__ . "/../solution.php";

class Day20 extends Solution
{
    private function mix($data, $iterations = 1)
    {
        $new_data = [];
        foreach ($data as $key => $value)
        {
            array_push($new_data, [$key, $value]);
        }

        $mod = count($data) - 1;

        foreach (range(1, $iterations) as $_)
        {
            foreach ($data as $key => $value)
            {
                $from_key = array_search([$key, $value], $new_data);

                $d = $new_data[$from_key];
                $val = $d[1];

                $to_key = ($from_key + (int)$val) % $mod;

                if ($to_key <= 0)
                {
                    $to_key += $mod;
                }

                unset($new_data[$from_key]);
                array_splice($new_data, $to_key, 0, [$d]);
            }
        }

        $result_data = [];
        foreach ($new_data as $value)
        {
            array_push($result_data, $value[1]);
        }

        return $result_data;
    }

    private function calculate_coordinates($data)
    {
        $zero_key = array_search(0, $data);

        return $data[($zero_key + 1000) % count($data)] +
            $data[($zero_key + 2000) % count($data)] +
            $data[($zero_key + 3000) % count($data)];
    }

    protected function part1()
    {
        $data = $this->data;
        return $this->calculate_coordinates($this->mix($data));
    }

    protected function part2()
    {
        $data = [];

        foreach ($this->data as $value)
        {
            array_push($data, $value * 811589153);
        }
        
        return $this->calculate_coordinates($this->mix($data, 10));
    }
}

new Day20(2022, 20);
