function func(a, b) {
    this.count = a;
    this.count1 = b;
    this.get = function () {
        console.log(count);
    }
}

var A = new func(5, 4);
console.log(A.count);
