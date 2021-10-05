const getMatrics = applySpec({
  sum: (a, b) => a + b, // sum is called with (2, 4)
  nested: {
    mul: (a, b) => a * b, // mul is called with (2, 4)
  },
  sub: (a, b) => a - b,
});

function applySpec(obj) {
  let obj1 = {};
  obj1["sum"] = obj.sum;
  obj1["nested"["mul"]] = obj.nested.mul;
  obj1["sub"] = obj.sub;
}

console.log(getMatrics(2, 4));
