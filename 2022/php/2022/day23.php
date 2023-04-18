<?php
include __DIR__ . "/../solution.php";
//error_reporting(E_ERROR | E_PARSE);
class Day23 extends Solution
{
    private $directions = ["N", "S", "W", "E"];

    private function format_data()
    {
        $data = $this->data;
        $new_data = [];
        $sub = [];

        foreach ($data as $value)
        {
            $chars = str_split($value);
            foreach ($chars as $char)
            {
                array_push($sub, $char);
            }
            array_push($new_data, $sub);
            $sub = [];
        }

        return $new_data;
    }

    private function pad(&$data)
    {
        $y_pad = [];

        $l = count($data[0]);

        foreach (range(1, $l) as $_)
        {
            array_push($y_pad, ".");
        }

        array_unshift($data, $y_pad);
        array_push($data, $y_pad);

        foreach ($data as &$row)
        {
            array_unshift($row, ".");
            array_push($row, ".");
        }
    }

    private function check_and_pad(&$data)
    {
        
        for ($r = 0; $r < count($data); $r++)
        {
            for ($c = 0; $c < count($data); $c++)
            {
                if ($data[0][$c] == "#" || $data[$r][0] == "#")
                {
                    $this->pad($data);
                }
                if ($data[count($data[$r]) - 1][$c] == "#" || $data[$r][count($data) - 1] == "#")
                {
                    $this->pad($data);
                }
            }
        }
    }

    private function check_adj($data, $r, $c)
    {

        if (
            $this->check_north($data, $r, $c) && $this->check_south($data, $r, $c) &&
            $this->check_west($data, $r, $c) && $this->check_east($data, $r, $c)
        )
        {
            return false;
        }
        return true;
    }

    private function check_north($data, $r, $c)
    {
        // \
        //  x
        if ($data[$r - 1][$c - 1] == "#") return false;

        // |
        // x
        if ($data[$r - 1][$c] == "#") return false;

        //  /
        // x
        if ($data[$r - 1][$c + 1] == "#") return false;

        return true;
    }

    private function check_south($data, $r, $c)
    {
        // x
        //  \
        if ($data[$r + 1][$c + 1] == "#") return false;

        // x
        // |
        if ($data[$r + 1][$c] == "#") return false;

        //  x
        // /
        if ($data[$r + 1][$c - 1] == "#") return false;

        return true;
    }

    private function check_west($data, $r, $c)
    {
        //  x
        // /
        if ($data[$r + 1][$c - 1] == "#") return false;

        // --x
        if ($data[$r][$c - 1] == "#") return false;

        // \
        //  x
        if ($data[$r - 1][$c - 1] == "#") return false;

        return true;
    }

    private function check_east($data, $r, $c)
    {
        //  /
        // x
        if ($data[$r - 1][$c + 1] == "#") return false;

        // x--
        if ($data[$r][$c + 1] == "#") return false;

        // x
        //  \
        if ($data[$r + 1][$c + 1] == "#") return false;

        return true;
    }

    private function build_string($data)
    {
        $str = "";
        foreach ($data as $row)
        {
            foreach ($row as $val)
            {
                $str = $str . $val;
            }
            $str = $str . "\n";
        }
        return $str;
    }

    protected function part1()
    {
        $data = $this->format_data();

        foreach(range(1, 10) as $_)
        {
            $this->check_and_pad($data);

            $prop = [];
            $test = [];
            // First part
            for ($r = 0; $r < count($data); $r++)
            {
                for ($c = 0; $c < count($data[$r]); $c++)
                {
                    if ($data[$r][$c] != "#")
                    {
                        continue;
                    }
                    if ($this->check_adj($data, $r, $c))
                    {
                        foreach ($this->directions as $direction)
                        {
                            switch ($direction)
                            {
                                case 'N':
                                    if ($this->check_north($data, $r, $c))
                                    {
                                        array_push($prop, [$r - 1, $c, "N"]);
                                        array_push($test, $r - 1 . "," . $c);
                                        break 2;
                                    }
                                    break;

                                case 'S':
                                    if ($this->check_south($data, $r, $c))
                                    {
                                        array_push($prop, [$r + 1, $c, "S"]);
                                        array_push($test, $r + 1 . "," . $c);
                                        break 2;
                                    }
                                    break;

                                case 'W':
                                    if ($this->check_west($data, $r, $c))
                                    {
                                        array_push($prop, [$r, $c - 1, "W"]);
                                        array_push($test, $r . "," . $c - 1);
                                        break 2;
                                    }
                                    break;

                                case 'E':
                                    if ($this->check_east($data, $r, $c))
                                    {
                                        array_push($prop, [$r, $c + 1, "E"]);
                                        array_push($test, $r . "," . $c + 1);
                                        break 2;
                                    }
                                    break;

                                default:
                                    echo "Error: Unknown\n";
                                    break;
                            }
                        }
                    }
                }
            }

            // Second part
            $dupes = array_diff_assoc($test, array_unique($test));

            foreach ($prop as $key => $value)
            {
                $r = $value[0];
                $c = $value[1];

                if (in_array($r . "," . $c, $dupes))
                {
                    unset($prop[$key]);
                }
            }

            foreach ($prop as $value)
            {
                $r = $value[0];
                $c = $value[1];
                $d = $value[2];

                if ($d == "N")
                {
                    $data[$r][$c] = "#";
                    $data[$r + 1][$c] = ".";
                }
                else if ($d == "S")
                {
                    $data[$r][$c] = "#";
                    $data[$r - 1][$c] = ".";
                }
                else if ($d == "W")
                {
                    $data[$r][$c] = "#";
                    $data[$r][$c + 1] = ".";
                }
                else if ($d == "E")
                {
                    $data[$r][$c] = "#";
                    $data[$r][$c - 1] = ".";
                }
            }


            $dir = array_shift($this->directions);
            array_push($this->directions, $dir);
        }
        $sum = count($data) * count(array_column($data, 0));

        return null;

    }

    protected function part2()
    {
        $data = $this->format_data();

        $stop = false;
        $old_str = "";
        $rounds = 0;

        while($stop == false)
        {
            $this->check_and_pad($data);
            $rounds++;

            $prop = [];
            $test = [];
            // First part
            for ($r = 0; $r < count($data); $r++)
            {
                for ($c = 0; $c < count($data[$r]); $c++)
                {
                    if ($data[$r][$c] != "#")
                    {
                        continue;
                    }

                    if ($this->check_adj($data, $r, $c))
                    {
                        foreach ($this->directions as $direction)
                        {
                            switch ($direction)
                            {
                                case 'N':
                                    if ($this->check_north($data, $r, $c))
                                    {
                                        array_push($prop, [$r - 1, $c, "N"]);
                                        array_push($test, $r - 1 . "," . $c);
                                        break 2;
                                    }
                                    break;

                                case 'S':
                                    if ($this->check_south($data, $r, $c))
                                    {
                                        array_push($prop, [$r + 1, $c, "S"]);
                                        array_push($test, $r + 1 . "," . $c);
                                        break 2;
                                    }
                                    break;

                                case 'W':
                                    if ($this->check_west($data, $r, $c))
                                    {
                                        array_push($prop, [$r, $c - 1, "W"]);
                                        array_push($test, $r . "," . $c - 1);
                                        break 2;
                                    }
                                    break;

                                case 'E':
                                    if ($this->check_east($data, $r, $c))
                                    {
                                        array_push($prop, [$r, $c + 1, "E"]);
                                        array_push($test, $r . "," . $c + 1);
                                        break 2;
                                    }
                                    break;

                                default:
                                    echo "Error: Unknown\n";
                                    break;
                            }
                        }
                    }
                }
            }
            // Second part

            $dupes = array_diff_assoc($test, array_unique($test));

            foreach ($prop as $key => $value)
            {
                $r = $value[0];
                $c = $value[1];

                if (in_array($r . "," . $c, $dupes))
                {
                    unset($prop[$key]);
                }
            }

            foreach ($prop as $value)
            {
                $r = $value[0];
                $c = $value[1];
                $d = $value[2];

                if ($d == "N")
                {
                    $data[$r][$c] = "#";
                    $data[$r + 1][$c] = ".";
                }
                else if ($d == "S")
                {
                    $data[$r][$c] = "#";
                    $data[$r - 1][$c] = ".";
                }
                else if ($d == "W")
                {
                    $data[$r][$c] = "#";
                    $data[$r][$c + 1] = ".";
                }
                else if ($d == "E")
                {
                    $data[$r][$c] = "#";
                    $data[$r][$c - 1] = ".";
                }
            }


            $dir = array_shift($this->directions);
            array_push($this->directions, $dir);

            $grid = $this->build_string($data);
            if ($grid == $old_str)
            {
                $stop = true;
            }
            $old_str = $grid;
        }
        
        return $rounds;
    }
}
new Day23(2022, 23);
