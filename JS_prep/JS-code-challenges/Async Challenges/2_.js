// Create a function which receives a function as argument and executes it after 2 seconds

function recEx(func) {
  setTimeout(() => {
    func();
  }, 2000);
}

function func() {
  console.log("This is func");
}

recEx(func);
