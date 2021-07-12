// what is closure 

function outer() {
    var i = 10;
    function inner() {
        function inner_again() {
            console.log(i);
        }
        inner_again();
    }
    inner();
}

outer();