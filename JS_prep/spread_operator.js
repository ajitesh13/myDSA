// rest parameter
// function func(a, b, ...args) {
//     console.log(args);
// }

// func(1, 2, 3, 4, 5, 6);

// spread operator 
// const odd = [1, 3, 5]
// const combined = [...odd, 8, 9]

// console.log(combined);

function compare(a, b) {
    return a - b;
}

var result = compare.apply(null, [4, 2]);
var result = compare(...[5, 2]);
console.log(result);

let ar = ["a", "bc", ..."bc", "d"];
console.log(ar);
