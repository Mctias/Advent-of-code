import { read_from_file } from "../lib/read_from_file.js";

const number_of_uniques = (answers, rows) => {
    let array = [];
    
    for(let i = 0; i < answers.length; i++){
        array.push(answers[i])
    }
    
    if(!array.includes('\n'))
        return array.length;
    
    let nonUnique = array.filter((item,i) => array.includes(item, i+1))
    const result = new Set(nonUnique);
    
    result.delete('\n');

    let testArray = Array.from(result);



    for(let i = 0; i < rows.length; i++){
        for(let j = 0; j < testArray.length; j++){
            if(!rows[i].includes(testArray[j]))
                result.delete(testArray[j])
        }

    }
    
    return result.size;
}


const answers = read_from_file("../input/input_day6.txt");
//const answers = ['abc', 'a\nb\nc', 'ab\nac', 'a\na\na\na', 'b'];

let result = 0;

for(let i = 0; i < answers.length; i++){
    
    result += number_of_uniques(answers[i], answers[i].split('\n'));
}

console.log(result);

