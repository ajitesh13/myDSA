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
    this.commands = [];
  }
}

class Group {
  constructor(groupName) {
    this.last = -1;
    this.groupName = groupName;
    this.machines = [];
  }
}

class Network {
  constructor() {
    this.groupName = {};
  }
}

function main() {
  let n = inputString[currentLine++];
  let machines = {};
  let machineInput = inputString[currentLine++].split(" ");
  for (let i = 0; i < n; i++) {
    machines[machineInput[i]] = new Machine();
  }
  let g = inputString[currentLine++];
  let network = new Network();
  for (let i = 0; i < g; i++) {
    let groupName = inputString[currentLine++];
    let newGroup = new Group(groupName);
    let groupLength = inputString[currentLine++];
    let groupMachineInput = inputString[currentLine++].split(" ");
    for (let j = 0; j < groupLength; j++) {
      let groupmachine = groupMachineInput[j];
      newGroup.machines.push(machines[groupmachine]);
    }
    network[groupName] = newGroup;
  }
  let q = inputString[currentLine++];
  for (let i = 0; i < q; i++) {
    let query = inputString[currentLine++];
    let querySplit = query.split("/", 2);
    let groupName = querySplit[0];
    let remainingQuery = querySplit[1];
    executeQuery(machines, groupName, remainingQuery, network);
  }
}

function executeQuery(machines, groupName, remainingQuery, network) {
  let querySplit = remainingQuery.split("=", 2);
  let machine = querySplit[1];
  if (remainingQuery.includes("machine_down")) {
    machines[machine].isUp = false;
  } else if (remainingQuery.includes("machine_up")) {
    machines[machine].isUp = true;
  } else {
    console.log(network);
  }
}
