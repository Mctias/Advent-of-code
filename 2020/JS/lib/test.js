import { quicksort } from "./quicksort.js";
import {binary_search} from "./binary_search.js"

let seq = [7, -2, 4, 1, 6, 5, 0, -4, 2];
quicksort(seq, 0, seq.length-1);

console.log(seq);

console.log(binary_search(seq, 7 ,0, seq.length-1));