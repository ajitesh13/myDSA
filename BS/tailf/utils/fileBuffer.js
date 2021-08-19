const fs = require('fs');
const readline = require('readline');
const Stream = require('stream');
const {Queue} = require('./Queue')

exports.getLastLine = (fileName, minLength) => {
    let inStream = fs.createReadStream(fileName);
    let outStream = new Stream;
    return new Promise((resolve, reject)=> {
        let rl = readline.createInterface(inStream, outStream);
        
        const q = new Queue();
        rl.on('line', function (line) {
            if(q.getSize() <= 10){
                q.enqueue(line)
            }
            else{
                q.deque();
                q.enqueue(line)
            }
        });

        rl.on('error', reject)

        rl.on('close', function () {
            resolve(q.getArray())
        });
    })
}
