import { read_from_file } from "../lib/read_from_file.js";

const getParent = (s) =>{
    const words = s.split(' ');
    let parent = words[0] + ' ' + words[1];
    return parent;
}

const getChildren = (s) =>{
    let chunks = s.split('contain');
    chunks = chunks[1].split(',');
    for(let i in chunks)
    {
        chunks[i] = chunks[i].replace(' ', '');
        chunks[i] = chunks[i].replace('bags', '');
        chunks[i] = chunks[i].replace('bag', '');
        chunks[i] = chunks[i].replace('.', '');
    }
    
    return chunks;
}

const buildMap = (p, c)=>{
    let bagRules = {};

    bagRules[p] = c;

    return bagRules;
}

const countGold = (rules, child) => {
    let contents;
    let confirmed = new Set();
    for(let i in rules){
        contents = rules[i];

        if(contents.includes(child))
        {
            countGold(i);
            confirmed.push(i);
        }
    }
    return confirmed;
}

//Reads the input
const input = read_from_file("../input/input_day7.txt");

let p;
let c;
let rules = [];

for(let i in input){
    p = getParent(input[i]);
    c = getChildren(input[i]);
    rules.push(buildMap(p, c));
}

let target = "shiny golden";

console.log(countGold(rules, target));