/* var ar = new Array();

for (let i = 0; i<5; i++) {
    ar.push(i);
}

for (let i=0; i<5; i++) {
    console.log(ar[i]);
}

ar.length = 0;

for (let i = 0; i<5; i++) {
    ar.push(i);
}
 */

var arr = [5,7,8,2,3,4];

let index = arr.findIndex(x => x === 8);
arr.splice(index, 1);

console.log(arr);
