import {read_from_file} from '../lib/read_from_file.js';

const find_faulty_number = (input, preamble, start_index) => {

   for(let i = start_index; i < preamble - 1; i++){
       for(let j = (i+1); j < preamble; j++){
           if(input[i] + input[j] === input[preamble]){
               return true;
           }

       }
   }
   return false;
    
}

const find_cont_range = (input, target, start_index) =>{
    let sum = 0;

    for(let i = start_index; i < input.length ; i++){
        
        sum += input[i];
        if(sum === target)
            return i;
        else if(sum > target)
            return false;
    }
  
    
}



const test_input = [35,20,15,25,47,40,62,55,65,95,102,117,150,182,127,219,299,277,309,576];
const input = read_from_file('../input/input_day9.txt');

for(let i = 0; i < input.length; i++){
    input[i] = parseInt(input[i]);
}

let start_index = 0;
let end_index;
let target = 133015568;
for(let i = 0; i < input.length; i++){
    let status = find_cont_range(input, target, start_index);
   if(!status){
        start_index++
   }
   else{
       console.log(start_index + " " + status)
       end_index = status + 1;
       break;
   }
  
    

}
let result_array = [];
let control = 0;
for(let i = start_index; i < end_index; i++){  
    result_array.push(input[i]);
    control += input[i];

}
console.log(Math.max(...result_array) + Math.min(...result_array));