const fs = require("fs");
const readline = require("readline");
const Stream = require("stream");

class Queue {
  constructor() {
    this.items = [];
    this.readSize = 0;
  }

  async populateLastTen(fileName) {
    var newSize = fs.statSync(fileName).getSize;

    if (newSize != this.readSize) {
      let temp = [];
      await this.readFileStream(fileName, this.readSize, newSize).then(
        (arr) => {
          Array.prototype.push.apply(temp, arr);
        }
      );
      Array.prototype.push.apply(this.items, temp);
      this.readSize = newSize;
    }
  }

  readFileStream(fileName, startByte, endByte) {
    let inStream = fs.createReadStream(fileName, {
      start: startByte,
      end: endByte,
    });
    let outStream = new Stream();
    return new Promise((resolve, reject) => {
      let rl = readline.createInterface(inStream, outStream);

      var arr = [];
      rl.on("line", function (line) {
        if (arr.length > 10) {
          arr.shift();
        }
        arr.push(line);
      });

      rl.on("error", reject);

      rl.on("close", function () {
        resolve(arr);
      });
    });
  }

  enqueue(element) {
    this.items.push(element);
  }

  deque() {
    if (this.items.length == 0) console.log("Underflow");
    else this.items.shift();
  }

  async ioEvent(fileName, io) {
    var newSize = fs.statSync(fileName).getSize;

    if (newSize != this.readSize) {
      let inStream = fs.createReadStream(fileName, {
        start: this.readSize,
        end: newSize,
      });

      this.readSize = newSize;
      let outStream = new Stream();

      return new Promise((resolve, reject) => {
        let rl = readline.createInterface(inStream, outStream);

        sendLine = [];
        rl.on("line", function (line) {
          console.log(line);
          io.emit("logs", line);
          // sendLine.push(line);
          // this.items.shift();
        });

        // rl.on("error", reject);

        rl.on("close", function () {
          console.log("Closed readign");
          resolve(sendLine);
        });
      });

      //   let temp = [];
      //   await this.readFileStream(fileName, this.readSize, newSize).then(
      //     (arr) => {
      //       Array.prototype.push.apply(temp, arr);
      //     }
      //   );
      //   Array.prototype.push.apply(this.items, temp);
      //   this.readSize = newSize;
      //   return temp;
    }
  }

  getLastTen() {
    return this.items.slice(-10);
  }

  reduce() {
    this.items = this.items.slice(-10);
  }
  getSize() {
    return this.items.length;
  }
}

module.exports = {
  Queue,
};
