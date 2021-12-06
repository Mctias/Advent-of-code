import { read_from_file } from "../lib/read_from_file.js";

//Creates a range
const range = (start, end) => {
    var ans = [];
    for (let i = start; i <= end; i++) {
        ans.push(i);
    }
    return ans;
}

//Findes the seat from the boardingpass
const find_seat = (boardingPass) =>{
    let rows = range(0, 127);
    let columns = range(0, 7);

    for(let i = 0; i < boardingPass.length; i++){

        if(boardingPass[i] === 'R'){
            columns = upper_half(columns);
        }
        else if(boardingPass[i] === 'L'){
            columns = lower_half(columns);
        }
        else if(boardingPass[i] === 'B'){
            rows = upper_half(rows);
        }
        else if(boardingPass[i] === 'F'){
            rows = lower_half(rows);
        }
    }
    return [rows,columns]
}

//Returns the upper half of the array
const upper_half = (input) =>{
    const half = Math.ceil(input.length / 2);

    const secondHalf = input.slice(-half);
    

    return secondHalf;
}

//Returns the lower half of the array
const lower_half = (input) =>{
    const half = Math.ceil(input.length / 2);

    const firstHalf = input.slice(0, half);

    return firstHalf;
}

//Calculates the id given the row and column
const calculate_id = (row, column) =>{
    return row[0] * 8 + column[0];
}

//Reads the boarding pass from a file
const boardingPass = read_from_file("../input/input.txt");

let ids = [];

//Gets the results and pushed the ids to an array
for(let i = 0; i < boardingPass.length; i++){
    let result = find_seat(boardingPass[i]);
    console.log(result, calculate_id(result[0], result[1]));
    ids.push(calculate_id(result[0], result[1]));
}

console.log(Math.max(...ids));
ids = ids.sort();
console.log(ids)

//Finds the missing id
for(let i = 0; i < ids.length - 1; i++){
    let next = ids[i] + 1;

    if(ids[i + 1] != next)
        console.log(ids[i] + " " + ids[i + 1]);

}