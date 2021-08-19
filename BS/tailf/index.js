const express = require("express");
const app = express();
const server = require("http").createServer(app);
const io = require("socket.io")(server);
const path = require("path");
const os = require("os");
const fs = require("fs");

const chokidar = require("chokidar");
const { getLastLine } = require("./utils/fileBuffer");
const { Queue } = require("./utils/Queue");

require("dotenv").config();
var logFile = path.join(__dirname, process.env.FILE);
var port = process.env.PORT || "8080";
var host = process.env.HOST || "localhost";
var page = path.join(__dirname, "/pages/index.html");
var working = false;

const q = new Queue();
q.populateLastTen(logFile);

app.get("/log", (req, res) => {
  res.sendFile(page);
});

io.on("connection", (socket) => {
  console.log("Someone connected");
  socket.emit("device", `${os.hostname()} : ${os.platform()}`);
  // fs.readFile(logFile, 'utf-8', (err, data) => {
  //     var lines = data.trim().split('\n').slice(-10)
  //     for(i = 0; i < lines.length; i++){
  //         socket.emit('logs', lines[i])
  //     }
  // })
  // var lastTen = getLastLine(logFile, 1).then((las))
  // getLastLine(logFile, 10)
  //     .then((lastLine)=> {
  //         var len = 10
  //         if(lastLine.length < 10){
  //             len = lastLine.length
  //         }
  //         for(i = 0; i < len; i++){
  //             // console.log(lastLine[i])
  //             socket.emit('logs', lastLine[i])
  //         }
  //     })
  //     .catch((err)=> {
  //         console.error(err)
  //     })
  let lastTen = q.getLastTen();
  for (i = 0; i < lastTen.length; i++) {
    socket.emit("logs", lastTen[i]);
  }

  fs.watch(logFile, (event, filename) => {
    if (filename && !working) {
      working = true;
      // fs.readFile(logFile, 'utf-8', (err, data) => {
      //     var lines = data.trim().split('\n').slice(-1)
      //     for(i = 0; i < lines.length; i++){
      //         io.emit('logs', lines[0])
      //     }
      // })
      //   getLastLine(logFile, 10)
      //       .then((lastLine)=> {
      //           console.log(lastLine)
      //           io.emit('logs', lastLine[lastLine.length-1])
      //       })
      //       .catch((err)=> {
      //           console.error(err)
      //       })
      q.ioEvent(logFile, io);
      // .then((lastLines) => {
      //   for (i = 0; i < lastLines; i++) {
      //     io.emit("logs", lastLine[i]);
      //   }
      // })
      // .catch((err) => {
      //   console.error(err);
      // });
      setTimeout(() => (working = false), 1000);
    }
  });

  // const watcher = chokidar.watch(logFile, {
  //     ignored: /(^|[\/\\])\../, // ignore dotfiles
  //     persistent: false
  // });

  // watcher.on('change', (path) => {
  //     // console.log(`Change detected`)
  //     if(!working){
  //         working = true
  //         // fs.readFile(logFile, 'utf-8', (err, data) => {
  //         //     var lines = data.trim().split('\n').slice(-1)
  //         //     for(i = 0; i < lines.length; i++){
  //         //         io.emit('logs', lines[0])
  //         //     }
  //         // })
  //         getLastLine(logFile, 10)
  //             .then((lastLine)=> {
  //                 io.emit('logs', lastLine[lastLine.length-1])
  //             })
  //             .catch((err)=> {
  //                 console.error(err)
  //             })
  //         setTimeout(() => working = false, 200)
  //     }
  // })

  socket.on("disconnect", () => {
    console.log("Someone disconnected");
  });
});

server.listen(port, host, () => {
  console.log(`Listening at ${host}:${port}`);
});
