function F() {
    return this;
}

var z = F();
// console.log(z);

var obj1 = {
    name: "Aji",
    age: 13,
    meth: function F() {
        return this.name;
    }
}

var getName = obj1.meth;
var obj2 = {name: "Aji12", getName}

console.log(obj2.getName())