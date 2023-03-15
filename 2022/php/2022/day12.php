<?php
include __DIR__ . "/../solution.php";
class Day12 extends Solution
{
    private $part1_res;
    private function format_data()
    {
        $data = $this->data;
        $grid = [];
        $row = [];

        foreach ($data as $line)
        {
            $chars = str_split($line);
            foreach ($chars as $char)
            {
                if ($char === 'S')
                    array_push($row, ord('a') - 96);
                else if ($char === 'E')
                    array_push($row, ord('z') - 96);
                else
                    array_push($row, ord($char) - 96);
            }
            array_push($grid, $row);
            $row = [];
        }
        return $grid;
    }

    private function bfs($graph, $end)
    {
        $queue = new SplQueue();

        $queue->enqueue($end);

        $points[$end[0] . "," . $end[1]] = 0;

        $visited = [];
        array_push($visited, $end);

        while ($queue->count() > 0)
        {
            $current = $queue->dequeue();

            $neighbours = $this->get_neighbours($graph, $current[0], $current[1]);

            foreach ($neighbours as $neighbour)
            {
                if (!in_array($neighbour, $visited))
                {
                    array_push($visited, $neighbour);
                    $points[$neighbour[0] . "," . $neighbour[1]] = $points[$current[0] . "," . $current[1]] + 1;
                    $queue->enqueue($neighbour);
                }
            }
        }

        return $points;
    }

    private function get_neighbours($graph, $x, $y)
    {
        $n = [];

        $node_height = $graph[$x][$y] - 2;
        //left
        if ($y != 0 && $node_height <  $graph[$x][$y - 1])
            array_push($n, [$x, $y - 1]);

        //top
        if ($x != 0 && $node_height < $graph[$x - 1][$y])
            array_push($n, [$x - 1, $y]);

        //right
        if ($y != count($graph[0]) - 1 && $node_height < $graph[$x][$y + 1])
            array_push($n, [$x, $y + 1]);

        //bot
        if ($x != count($graph) - 1 && $node_height < $graph[$x + 1][$y])
            array_push($n, [$x + 1, $y]);

        return $n;
    }

    protected function part1()
    {
        $data = $this->format_data();
        $end = [20, 43];
        $start = "20,0";

        $part1_res = $this->bfs($data, $end);

        $this->part1_res = $part1_res;
        return $part1_res[$start];
    }

    protected function part2()
    {
        $data = $this->format_data();
        $part2_res = [];
        foreach ($this->part1_res as $key => $value)
        {
            list($x, $y) = explode(",", $key);

            $x = (int)$x;
            $y = (int)$y;

            if ($data[$x][$y] === 1)
            {
                array_push($part2_res, $value);
            }
        }
        return $part2_res[0];
    }
}
new Day12(2022, 12);