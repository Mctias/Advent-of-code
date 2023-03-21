<?php
abstract class Solution
{
    protected $data;
    protected $test_data;
    protected $year;
    protected $day;

    public function __construct($year, $day)
    {
        $this->year = $year;
        $this->day = $day;
        $this->data = $this->read_data($day);
        $this->test_data = $this->read_test_data($day);
        $this->print_results();
    }

    private function read_data($day)
    {

        $filename = __DIR__ . "\\" . $this->year . "\\data\\" . "day" . $day . ".txt";
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

    private function read_test_data($day)
    {

        $filename = __DIR__ . "\\" . $this->year . "\\data\\" . "test" . $day . ".txt";
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

    abstract protected function part1();

    abstract protected function part2();

    private function print_results()
    { 
        echo "===== Day " . $this->day . " =====\n"; 
        if(!$this->part1() == null)
        {
            echo "Part 1: ";
            print_r($this->part1());
            echo PHP_EOL;
        }

        if(!$this->part2() == null)
        {
            echo "Part 2: ";
            print_r($this->part2());
        }
    }
}
