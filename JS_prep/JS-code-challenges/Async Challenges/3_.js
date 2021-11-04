// Print numbers from 1 to 10 with delay of 1 second between each value being printed

let num1 = 1;
let num2 = 10;
for (let i = num1; i <= num2; i++) {
  setTimeout(() => {
    console.log(i);
  }, i * 1000);
}
