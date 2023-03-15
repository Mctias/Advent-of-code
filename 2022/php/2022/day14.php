<?php
function read_data($input)
{
    $filename = __DIR__ . "\\data\\" . $input . ".txt";
    $file = fopen($filename, "r") or die("Unable to open file");

    $data = [];

    while (!feof($file))
    {
        $line = trim(fgets(($file)));
        array_push($data, $line);
    }

    fclose($file);
    return $data;
}

$grid = [];
$max_x;
$min_x;
$max_y;
$min_y;

$part1;
$part2;

function solve()
{
    global $grid, $max_x, $min_x, $max_y, $min_y, $part2;
    $data = read_data("day14");

    $lines = [];
    foreach ($data as $row)
    {
        array_push($lines, explode("-> ", $row));
    }
    $coords = [];

    foreach ($lines as $line)
    {
        foreach ($line as $coord)
        {
            list($x, $y) = explode(",", $coord);
            array_push($coords, [$x, $y]);
        }
    }

    $max_x =  max(array_column($coords, '0'));
    $max_y =  max(array_column($coords, '1'));
    $min_x =  min(array_column($coords, '0'));
    $min_y =  min(array_column($coords, '1'));

    //From -max * 2 to max * 2 should be close enough to infinity
    for ($i = -$max_x * 2; $i < $max_x  * 2; $i++)
    {
        for ($j = 0; $j <  $max_y + 1; $j++)
        {
            $grid[$i][$j] = ".";
        }

        //Final two rows of air and floor
        $grid[$i][$max_y + 1] = ".";
        $grid[$i][$max_y + 2] = "#";
    }

    foreach ($lines as $line)
    {
        for ($i = 0; $i < count($line) - 1; $i++)
        {
            list($x1, $y1) = explode(",", $line[$i]);
            list($x2, $y2) = explode(",", $line[$i + 1]);

            //Get weird spaces sometimes
            $x1 = trim($x1);
            $x2 = trim($x2);
            $y1 = trim($y1);
            $y2 = trim($y2);

            if ($x1 == $x2)
            {
                foreach (range($y1, $y2) as $y)
                {
                    $grid[$x1][$y] = "#";
                }
            }
            if ($y1 == $y2)
            {
                foreach (range($x1, $x2) as $x)
                {
                    $grid[$x][$y1] = "#";
                }
            }
        }
    }

    $part2 =  sand(500, 0);
}

function sand($px, $py, &$sand_units = 0)
{
    global $grid, $max_x, $min_x, $max_y, $part1;

    if (($py >= $max_y || $px <= $min_x || $px >= $max_x) && !$part1)
    {
        $part1 = $sand_units;
    }

    if ($grid[$px][$py + 1] == ".")
    {
        sand($px, $py + 1, $sand_units);
    }

    if ($grid[$px - 1][$py + 1] == ".")
    {
        sand($px - 1, $py  + 1, $sand_units);
    }

    if ($grid[$px + 1][$py + 1] == ".")
    {
        sand($px + 1, $py + 1, $sand_units);
    }

    $grid[$px][$py] = "o";
    return ++$sand_units;
}

solve();

echo "Part 1: " . $part1 . PHP_EOL;
echo "Part 2: " . $part2 . PHP_EOL;
