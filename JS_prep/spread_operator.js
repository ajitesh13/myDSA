/**
 * spread operator as rest Parameter
 */
function func(a, b, ...args) {
  console.log(args);
}

func(1, 2, 3, 4, 5, 6);

/**
 * Spread operator use cases
 * 1. combining array
 */

const odd = [1, 3, 5];
const combined = [...odd, 8, 9];

console.log(combined);

/**
 * 2. In place of apply
 */
function compare(a, b) {
  return a - b;
}

var result = compare.apply(null, [4, 2]);
var result = compare(...[5, 2]);
console.log(result);

/**
 * 3. Spread operator with string
 */

let ar = ["a", "bc", ..."bc", "d"];
console.log(ar);

/**
 * Spread Operator with objects
 * 1. Copying properties of an object into another
 */

const circle = {
  prop1: "a",
  prop2: "b",
  prop3: "c",
  s: {
    gt: "fr",
  },
};

console.log(circle);

const circle1 = {
  ...circle,
  prop5: "d",
  prop6: "e",
};

console.log(circle1);

/**
 * 2. Cloning an object
 */

const circle2 = {
  prop1: "a",
  prop2: "b",
  prop3: "c",
  s: {
    gt: "fr",
  },
};

console.log(circle2);

const circle3 = { ...circle2 };
console.log(circle3);

/**
 * 3. forming copy (very very important)
 */

const c4 = {
  prop1: "a",
  prop2: "b",
  prop3: "d",
  prop4: {
    prop41: "e",
  },
};

const c5 = { ...c4 };

c4.prop3 = "z"; // will not affect the c5 object
c4.prop4.prop41 = "x"; // will affect the c5 object

console.log(c5);
