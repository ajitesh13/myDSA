/* Interview Question: Print 1, 2, 3...5 after corresponding interval of time, 
1 after 1 sec
2 after 2 sec and so on  */


// solution using let
function x() {
   for (let i = 1; i <= 5; i++) {
        setTimeout(() => {
            console.log(i);
        }, i*1000);
   }
   console.log("A");
}
x();

// solution using var 
function x() {
    for (var i = 1; i<=5; i++) {
        function close(i) {
            setTimeout(() => {
                console.log(i);
            }, i*1000);
        }
        close(i);
    }
}
x();

