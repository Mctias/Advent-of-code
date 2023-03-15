<?php
include __DIR__ . "/../solution.php";

class Day8_A extends Solution
{
    private function go_left($grid, $row, $col)
    {
        $currentValue = $grid[$row][$col];
        $tempCol = $col;
        $currentIsVisible = false;

        while ($tempCol > 0 && $currentIsVisible == false)
        {
            $tempCol--;
            if ($grid[$row][$tempCol] >= $currentValue)
            {
                break;
            }
            if ($tempCol == 0)
            {
                $currentIsVisible = true;
            }
        }
        return $currentIsVisible;
    }

    private function go_up($grid, $row, $col)
    {
        $currentValue = $grid[$row][$col];
        $currentIsVisible = false;
        $tempRow = $row;

        while ($tempRow > 0 && $currentIsVisible == false)
        {
            $tempRow--;
            if ($grid[$tempRow][$col] >= $currentValue)
            {
                break;
            }
            if ($tempRow == 0)
            {
                $currentIsVisible = true;
            }
        }
        return $currentIsVisible;
    }

    private function go_right($grid, $row, $col)
    {
        $currentValue = $grid[$row][$col];
        $currentIsVisible = false;
        $tempCol = $col;

        while ($tempCol < count($grid[0]) - 1 && $currentIsVisible == false)
        {
            $tempCol++;
            if ($grid[$row][$tempCol] >= $currentValue)
            {
                break;
            }
            if ($tempCol == count($grid[0])  - 1)
            {
                $currentIsVisible = true;
            }
        }
        return $currentIsVisible;
    }

    private function go_down($grid, $row, $col, $numberOfRows)
    {
        $currentValue = $grid[$row][$col];
        $currentIsVisible = false;
        $tempRow = $row;

        while ($tempRow < $numberOfRows - 1 && $currentIsVisible == false)
        {
            $tempRow++;
            if ($grid[$tempRow][$col] >= $currentValue)
            {
                break;
            }
            if ($tempRow ==  $numberOfRows - 1)
            {
                $currentIsVisible = true;
            }
        }
        return $currentIsVisible;
    }

    private function format_data($input)
    {
        $data = [];
        foreach ($input as $row)
        {
            $split_text = str_split($row);
            array_push($data, $split_text);
        }
        return $data;
    }

    protected function part1()
    {
        $data = $this->format_data($this->data);

        $numberOfRows = count($data);
        $numberOfCols = count($data[0]);

        $edge = $numberOfRows * 2 + $numberOfCols * 2 - 4;

        $visibleTrees = 0;

        for ($row = 1; $row < $numberOfRows - 1; $row++)
        {
            for ($col = 1; $col < count($data[0]) - 1; $col++)
            {
                if (
                    $this->go_left($data, $row, $col) ||
                    $this->go_up($data, $row, $col) ||
                    $this->go_right($data, $row, $col) ||
                    $this->go_down($data, $row, $col, $numberOfRows)
                ) $visibleTrees++;
            }
        }
        return $visibleTrees + $edge;
    }

    protected function part2()
    {
    }
}

class Day8_B extends Solution
{
    function go_left($grid, $row, $col)
    {
        $currentValue = $grid[$row][$col];
        $tempCol = $col;
        $view = 0;

        while ($tempCol > 0)
        {
            $tempCol--;
            $view++;
            if ($grid[$row][$tempCol] >= $currentValue)
            {
                break;
            }
        }
        return $view;
    }
    function go_up($grid, $row, $col)
    {
        $currentValue = $grid[$row][$col];
        $tempRow = $row;
        $view = 0;

        while ($tempRow > 0)
        {
            $tempRow--;
            $view++;
            if ($grid[$tempRow][$col] >= $currentValue)
            {
                break;
            }
        }
        return $view;
    }
    function go_right($grid, $row, $col)
    {
        $currentValue = $grid[$row][$col];
        $tempCol = $col;
        $view = 0;

        while ($tempCol < count($grid[0]) - 1)
        {
            $tempCol++;
            $view++;
            if ($grid[$row][$tempCol] >= $currentValue)
            {
                break;
            }
        }
        return $view;
    }
    function go_down($grid, $row, $col, $numberOfRows)
    {
        $currentValue = $grid[$row][$col];
        $tempRow = $row;
        $view = 0;

        while ($tempRow < $numberOfRows - 1)
        {
            $tempRow++;
            $view++;
            if ($grid[$tempRow][$col] >= $currentValue)
            {
                break;
            }
        }
        return $view;
    }

    private function format_data($input)
    {
        $data = [];
        foreach ($input as $row)
        {
            $split_text = str_split($row);
            array_push($data, $split_text);
        }
        return $data;
    }

    protected function part2()
    {
        $data = $this->format_data($this->data);

        $numberOfRows = count($data);
        $numberOfCols = count($data[0]);
        $scores = [];
    
        for ($row = 1; $row < $numberOfRows - 1; $row++)
        {
            for ($col = 1; $col < $numberOfCols - 1; $col++)
            {
                $score = $this->go_left($data, $row, $col) * 
                    $this->go_up($data, $row, $col) * 
                    $this->go_right($data, $row, $col) * 
                    $this->go_down($data, $row, $col, $numberOfRows);
                array_push($scores, $score);
            }
        }
        return max($scores);
    }

    protected function part1()
    {
    }
}
new Day8_A(2022, 8);
new Day8_B(2022, 8);
