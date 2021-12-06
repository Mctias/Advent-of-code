import {createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require("fs");


  export const read_from_file = (path) => {
    try {
      const data = fs.readFileSync(path, "utf8").toString().replace(/\r\n/g,'\n').split('\n');
      
      //console.log("File content:", data);
      return data;
    } catch (err) {
      console.error(err);
    }
  }
