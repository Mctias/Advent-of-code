<?php
include __DIR__ . "/../solution.php";

class Day25 extends Solution
{
    private function snafu_to_dec($snafu)
    {
        $result = 0;
        $mult = 5 ** (strlen($snafu) - 1);

        $numbers = str_split($snafu);
        foreach ($numbers as $number)
        {
            if ($number === "=") $number = -2;
            if ($number === "-") $number = -1;

            $result += (int)$number * $mult;

            //echo $mult . PHP_EOL;
            $mult /= 5;
        }

        return $result;
    }

    private function dec_to_snafu($dec)
    {
        $snafu = "";

        while ($dec > 0)
        {
            $sn = (int)$dec % 5;
            $dec = (int)($dec / 5);
            switch ($sn)
            {
                case 0:
                    $snafu =  "0" . $snafu;
                    break;
                case 1:
                    $snafu = "1" . $snafu;
                    break;
                case 2:
                    $snafu = "2" . $snafu;
                    break;
                case 3:
                    $snafu = "=" . $snafu;
                    $dec++;
                    break;
                case 4:
                    $snafu = "-" . $snafu;
                    $dec++;
                    break;
            }
        }
        return $snafu;
    }
    protected function part1()
    {
        $data = $this->data;
        $decimals = [];

        foreach ($data as $row)
        {
            $decimal = $this->snafu_to_dec($row);
            array_push($decimals, $decimal);
        }


        $sum = array_sum($decimals);
        $snafu = $this->dec_to_snafu($sum);

        return $snafu;
    }

    protected function part2()
    {
        return "Merry Christmas";
    }
}

new Day25(2022, 25);
