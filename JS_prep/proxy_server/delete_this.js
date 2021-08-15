let ar = [
  {
    what: true,
    val: "1234",
  },
  {
    what: true,
    val: "6789",
  },
  {
    what: true,
    val: "7890",
  },
];

class group {
  constructor() {
    this.ar = [];
  }
}

let g = new group();
g.ar.push(ar[0]);
g.ar.push(ar[1]);
let g1 = new group();
g1.ar.push(ar[2]);

ar[1].what = false;
ar[2].what = false;
ar[0].what = false;
console.log("ar: ");

for (let i = 0; i < ar.length; i++) {
  console.log(ar[i]);
}
console.log("g: ");

for (let i = 0; i < g.ar.length; i++) {
  console.log(g.ar[i]);
}

console.log("g1: ");

for (let i = 0; i < g1.ar.length; i++) {
  console.log(g1.ar[i]);
}
