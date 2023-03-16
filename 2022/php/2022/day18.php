<?php
include __DIR__ . "/../solution.php";

class Day18 extends Solution
{
    private function get_neighbours($cube)
    {
        [$x, $y, $z] = $cube;
        $n = [];

        array_push($n, [$x - 1, $y, $z]);
        array_push($n, [$x + 1, $y, $z]);
        array_push($n, [$x, $y - 1, $z]);
        array_push($n, [$x, $y + 1, $z]);
        array_push($n, [$x, $y, $z - 1]);
        array_push($n, [$x, $y, $z + 1]);

        return $n;
    }

    private function get_surfaces($cubes)
    {
        $count = 0;
        foreach ($cubes as $cube)
        {   
            $neighbours = $this->get_neighbours($cube);
            foreach($neighbours as $n)
            {
                if(!in_array($n, $cubes))
                {
                    $count++;
                }
            }
        }
        return $count;
    }

    private function format_data()
    {
        $data = $this->data;
        $formatted_data = [];

        foreach($data as $row)
        {
            list($x, $y, $z) = explode(",", $row);
            array_push($formatted_data, [$x, $y, $z]);
        }

        return $formatted_data;
    }

    protected function part1()
    {
        $data = $this->format_data();
        return $this->get_surfaces($data);
    }

    protected function part2()
    {
        $data = $this->format_data();

        $min_x = 0;
        $max_x = 0;
        $min_y = 0;
        $max_y = 0;
        $min_z = 0;
        $max_z = 0;

        foreach ($data as $row)
        {
            [$x, $y, $z] = $row;
            $min_x = min($min_x, $x);
            $max_x = max($max_x, $x);
            $min_y = min($min_y, $y);
            $max_y = max($max_y, $y);
            $min_z = min($min_z, $z);
            $max_z = max($max_z, $z);
        }

        $min_x -= 1;
        $max_x += 1;
        $min_y -= 1;
        $max_y += 1;
        $min_z -= 1;
        $max_z += 1;

        $water_points = [];

        $q = new SplQueue();
        $q->enqueue([$min_x, $min_y, $min_z]);

        while ($q->count())
        {
            [$x, $y, $z] = $q->dequeue();

            if (in_array([$x, $y, $z], $water_points))
            {
                continue;
            }

            array_push($water_points, [$x, $y, $z]);

            $neighbours = $this->get_neighbours([$x, $y, $z]);

            foreach ($neighbours as [$nx, $ny, $nz])
            {
                if (
                    $min_x <= $nx && $nx <= $max_x
                    && $min_y <= $ny && $ny <= $max_y
                    && $min_z <= $z && $z <= $max_z)
                {
                    if (!in_array([$nx, $ny, $nz], $data))
                    {
                        $q->enqueue([$nx, $ny, $nz]);
                    }
                }
            }
        }

        $lava_points = [];
        foreach (range($min_x, $max_x ) as $nx)
        {
            foreach (range($min_y, $max_y ) as $ny)
            {
                foreach (range($min_z, $max_z ) as $nz)
                {
                    
                    if (!in_array([$nx, $ny, $nz], $water_points))
                    {
                        array_push($lava_points, [$nx, $ny, $nz]);
                    }
                }
            }
        }

        return $this->get_surfaces($lava_points);
    }
}

new Day18(2022, 18);
