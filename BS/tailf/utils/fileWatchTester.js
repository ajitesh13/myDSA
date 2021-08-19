const path = require('path')
const getLastLine = require('./fileBuffer.js').getLastLine
const fileName = path.join(__dirname, '../log.txt')
const minLineLength = 1
getLastLine(fileName, 10)
    .then((lastLine)=> {
        for(i = 0; i < 10; i++){
        console.log(lastLine[i])
        }
    })
    .catch((err)=> {
        console.error(err)
    })