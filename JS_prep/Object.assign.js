class Circle {
  constructor(radius) {
    this.radius = radius;
  }
  set diameter(value) {
    this.radius = value / 2;
    console.log("SET ", value + 1);
  }

  get diameter() {
    return this.radius * 2;
  }
}

let circle = new Circle(100);

// Object.assign triggers the setter
let cloneCircle1 = Object.assign(circle, {
  diameter: 200,
});

let cloneCircle2 = {
  ...circle,
};
