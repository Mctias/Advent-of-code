import {read_from_file} from '../lib/read_from_file.js';
let east = 0;
let north = 0;
let south = 0;
let west = 0;

const calculate_travel = (input) =>{

    let latitude = ['E', 'S', 'W', 'N'];

    for(let i = 0; i < input.length; i++){
        let number = input[i].replace(/\D/g, "");
        number = parseInt(number);
        let command = input[i].match(/\D/g).join('');
        

        
        if(command === 'L'){
            latitude = determine_latitude(latitude, 'L', number);
        }
        else if(command === 'R'){
            latitude = determine_latitude(latitude, 'R', number);
        }
        else if(command === 'F'){
            stear(latitude[0], number);
        }
        else{
            stear(command, number);
        }


    }

}

const stear = (latitude, number) =>{
    console.log(number)
    if(latitude === 'N'){
        north += number;
    }
    else if(latitude === 'E'){
        east += number;
    }
    else if(latitude === 'W'){
        west += number;
    }
    else if(latitude === 'S'){
        south += number;
    }
}

const determine_latitude = (input, dir, deg) =>{
    let mag;
    let pos = 0;

    if(dir === 'L'){
        mag = -deg/90;
    }
    else if(dir === 'R'){
        mag = deg/90;
    }

    if(mag < 0)
        pos = input.length + mag;
    else
        pos += mag;

    for(let i = 0; i <= pos-1; i++){
        input.push(input[i]);
    }
    input.splice(0, pos);
    return input;

}

const test_latitude = ['E', 'S', 'W', 'N'];
const test_data = ['F10', 'N3', 'F7', 'R90', 'F11'];
const input = read_from_file('../input/input_day12.txt');

calculate_travel(input);

let hori_result = Math.max(east, west) - Math.min(east,west);
let vert_result = Math.max(north, south) - Math.min(north,south);

console.log(Math.abs(hori_result)  + Math.abs(vert_result));