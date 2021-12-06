import {read_from_file} from '../lib/read_from_file.js';

let x = 0;
let y = 0;
let wx = 10;
let wy = 1; 


const calculate_travel = (input) =>{

    for(let i = 0; i < input.length; i++){
        let number = input[i].replace(/\D/g, "");
        number = parseInt(number);
        let command = input[i].match(/\D/g).join('');
        
        if(command === 'L'){
            for(let i = 0; i < number; i+=90){
                [wx, wy] = [-wy, wx]
            }
        }
        else if(command === 'R'){
            for(let i = 0; i < number; i+=90){
                [wx, wy] = [wy, -wx]
            }
        }
        else if(command === 'F'){
            forward(number);
        }
        else{
            stear_wp(command, number);
        }


    }

    return Math.abs(x) + Math.abs(y);

}

const stear_wp = (latitude, number) =>{
    
    if(latitude === 'N'){
        wy += number ;
    }
    else if(latitude === 'E'){
        wx += number ;
    }
    else if(latitude === 'W'){
        wx -= number ;
    }
    else if(latitude === 'S'){
        wy -= number;
    }
}

const forward = (value) =>{

    x += wx * value;
    y += wy * value;

}

const test_data = ['F10', 'N3', 'F7', 'R90', 'F11'];
const input = read_from_file('../input/input_day12.txt');

let result = calculate_travel(input);

console.log(result);

