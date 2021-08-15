process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => {
  inputString += inputStdin;
});

process.stdin.on("end", (_) => {
  // console.log(inputString);
  inputString = inputString
    .trim()
    .split("\n")
    .map((string) => {
      return string.trim();
    });
  main();
});

class Machine {
  constructor() {
    this.isUp = true;
    this.commands = new Array();
  }
}

class Group {
  constructor() {
    this.last = -1;
    this.map = {};
    this.machines = new Array();
  }
}

class Network {
  constructor() {
    this.groups = {};
  }
}

function main() {
  let network = new Network();

  let N = parseInt(inputString[currentLine++]);
  let machines = {};
  let m_arr = inputString[currentLine++].split(" ");
  // console.log(m_arr)
  for (let m in m_arr) {
    machines[m_arr[m]] = new Machine();
  }
  // console.log(machines);

  let g = parseInt(inputString[currentLine++]);
  // console.log(m)
  for (let i = 0; i < g; i++) {
    let proxyName = inputString[currentLine++];

    let m = parseInt(inputString[currentLine++]);
    // console.log(proxyName, m)
    let newGroup = new Group();
    let mx = inputString[currentLine++].split(" ");
    for (let k in mx) {
      let mc = machines[mx[k]];
      newGroup.machines.push(mc);
    }
    network.groups[proxyName] = newGroup;
    console.log(newGroup);
  }

  let q = parseInt(inputString[currentLine++]);
  // console.log(q, " Q")
  // console.log(network)
  for (let i = 0; i < q; i++) {
    let query = inputString[currentLine++];
    // console.log(query)
    executeQuery(network, machines, query);
  }

  console.log(machines);
}

function executeQuery(network, machines, query) {
  let strings = query.split("/", 2);
  if (strings.length < 1) return;

  let proxyName = strings[0];
  let remainingQuery = strings[1];

  // console.log(proxyName, remainingQuery);

  let target = network.groups[proxyName];
  // console.log(target)
  if (remainingQuery.includes("machine_down")) {
    let split = remainingQuery.split("=");
    let machineName = split[1];
    machines[machineName].isUp = false;
  } else if (remainingQuery.includes("machine_up")) {
    let split = remainingQuery.split("=");
    let machineName = split[1];
    machines[machineName].isUp = true;
  } else {
    let toProcess =
      (target.last != -1 ? target.last : 0) % target.machines.length;
    // console.log(toProcess)
    for (let i = toProcess; i < target.machines.length; i++) {
      if (target.machines[i].isUp) {
        target.machines[i].commands.push(query);
        target.last = i + 1;
        return;
      }
    }
    for (let i = 0; i < target.last; i++) {
      if (target.machines[i].isUp) {
        target.machines[i].commands.push(query);
        target.last = i + 1;
        return;
      }
    }
  }
}
