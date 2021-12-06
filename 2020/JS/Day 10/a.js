
import {read_from_file} from '../lib/read_from_file.js';

const find_differences = (input) =>{
    let jolt = 0;
    let one_diff = 0;
    //There will always be at least one three
    let three_diff = 1;

    input.sort((a, b) => a - b);
    console.log(input)

    for(let i = 0; i < input.length; i++){
        if(input[i] === jolt + 1){
            one_diff++;
            jolt = input[i];
        }
        else if(input[i] === jolt + 3){
            three_diff++;
            jolt = input[i];
        }
    }
    return [one_diff, three_diff];
}

let test_input = [28,33,18,42,31,14,46,20,48,47,24,23,49,45,19,38,39,11,1,32,25,35,8,17,7,9,4,2,34,10,3];
const input = read_from_file('../input/input_day10.txt');

for(let i = 0; i < input.length; i++){
    input[i] = parseInt(input[i]);
}

console.log(find_differences(input)[0] * find_differences(input)[1]);