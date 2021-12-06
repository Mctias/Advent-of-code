import {read_from_file} from '../lib/read_from_file.js';

let accumulator = 0;

const find_repetition = (commands, numbers) =>{
    let index_array= [];

    for(let i = 0; i < commands.length; i++){
       console.log(commands[i] + " " + numbers[i]);

       if(commands[i] + " " + numbers[i] == 'jmp -31') 
            commands[i] = 'nop';

       if(i > commands.length)
            return;

        if(index_array.includes(i)){
            console.log('Aborted')
            return;
        }
            

        index_array.push(i);
        
        if(commands[i] === 'nop')
            continue;
        
        else if(commands[i] === 'acc')
            accumulator += numbers[i];
        
        else if(commands[i] === 'jmp')
            i = i + numbers[i] - 1;

    }
}

let test_data = [0,1,4,3,-3,-99,1,-4,6];
let test_commands = ['nop', 'acc', 'jmp', 'acc', 'jmp', 'acc', 'acc', 'jmp', 'acc'];

let data = read_from_file('../input/input_day8.txt');

let commands = [];
let steps = [];

for(let i = 0; i < data.length; i++){
    steps.push(parseInt(data[i].match(/[+\-0-9]+/g)));
    commands.push(data[i].match(/\D/g).join('').replace(/[^a-zA-Z ]/g, "").trim());
    
}


find_repetition(commands, steps);

console.log(accumulator)