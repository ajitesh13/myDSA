// Expected Output: getMatrics(2, 4): { sum: 6, nested: { mul: 8 }, sub: -2 }

function process(specObj, args) {
  let newObj = {};
  let keys = Object.keys(specObj);
  keys.forEach((key) => {
    if (typeof specObj[key] === "function") {
      newObj[key] = specObj[key](...args);
    } else if (typeof specObj[key] === "object") {
      let newSpecObj = specObj[key];
      newObj[key] = process(newSpecObj, args);
    }
  });
  return newObj;
}

function applySpec(specObj) {
  return function (...args) {
    console.log("HOC => ", args);
    return process(specObj, args);
  };
}

const getMatrics = applySpec({
  sum: (a, b) => a + b, // sum is called with (2, 4)
  nested: {
    mul: (a, b) => a * b, // mul is called with (2, 4)
  },
  sub: (a, b) => a - b,
});

console.log(getMatrics(2, 4));
