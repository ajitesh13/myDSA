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
  main()  ;
});

class ListNode {
  /**
   * @param {string} ip
   * @param {Machine} machine
   * @param {ListNode} next
   * @param {ListNode} prev
   */
  constructor(ip, machine, proxyServer = null, next = null, prev = null) {
    this.machine = machine;
    this.ip = ip;
    this.proxyServer = proxyServer;
    this.prev = prev;
    this.next = next;
  }
}

class Group {
  /**
   * @param {string} proxyName
   * @param {ListNode} start
   * @param {ListNode} end
   * @param {ListNode} cur
   */
  constructor(proxyName, start = null, end = null, cur = null) {
    this.proxyName = proxyName;
    this.start = start;
    this.end = end;
    this.cur = cur;
  }

  /**
   * @param {ListNode} node
   */
  addNode(node) {
    if (this.start === null) {
      this.start = this.end = this.cur = node;
      this.start.next = this.start;
      this.start.prev = this.start;
      return;
    }
    node.next = this.start;
    node.prev = this.end;
    this.start.prev = node;
    this.end.next = node;
    this.end = node;
    // console.log(node)
    return;
  }

  /**
   * @param {ListNode} node
   */
  removeNode(node) {
    if (this.start.ip === this.end.ip) {
      this.start = this.end = this.cur = null;
      return;
    }
    if (node.ip === this.cur.ip) {
      this.cur = node.next;
    }
    if (node.ip === this.start.ip) {
      this.start = node.next;
    }
    if (node.ip === this.end.ip) {
      this.end = node.prev;
    }
    node.prev.next = node.next;
    node.next.prev = node.prev;
    node.prev = null;
    node.next = null;
    // console.log(node)
    return;
  }
}

class Machine {
  constructor() {
    this.isUp = true;
    this.commands = new Array();
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
  for (let m in m_arr) {
    let machineNode = new ListNode(m_arr[m], new Machine());
    machines[m_arr[m]] = machineNode;
  }
  let g = parseInt(inputString[currentLine++]);

  for (let i = 0; i < g; i++) {
    let proxyName = inputString[currentLine++];
    let m = parseInt(inputString[currentLine++]);
    let newGroup = new Group(proxyName);
    let mx = inputString[currentLine++].split(" ");
    for (let k in mx) {
      let mc = machines[mx[k]];
      mc.proxyServer = newGroup;
      newGroup.addNode(mc);
    }
    network.groups[proxyName] = newGroup;
    // console.log(newGroup);
  }
  //   console.log(network);
  let q = parseInt(inputString[currentLine++]);
  // console.log(q, " Q")
  // console.log(network)
  for (let i = 0; i < q; i++) {
    let query = inputString[currentLine++];
    // console.log(query)
    executeQuery(network, machines, query);
  }
  // console.log(machines);

  let groups = network.groups["panda"];
  // console.log(groups)

  // let start = groups.start,
  //     itr = groups.start;
  // console.log(start.ip)
  // console.log(itr.next.ip)
  // console.log(itr.next.next.ip)
  // console.log(itr.next.next.next.ip)

  for (let i of Object.values(machines)) {
    console.log(i.ip);
    console.log(i.machine.commands);
  }
}

function executeQuery(network, machines, query) {
  let strings = query.split("/", 2);
  if (strings.length < 1) return;

  let proxyName = strings[0];
  let remainingQuery = strings[1];

  let target = network.groups[proxyName];

  if (remainingQuery.includes("machine_down")) {
    let split = remainingQuery.split("=");
    let machineName = split[1];
    let machineNode = machines[machineName];
    let proxyServer = machineNode.proxyServer;
    console.log(machineName + " goes down");
    proxyServer.removeNode(machineNode);
    return;
  } else if (remainingQuery.includes("machine_up")) {
    let split = remainingQuery.split("=");
    let machineName = split[1];
    let machineNode = machines[machineName];
    let proxyServer = machineNode.proxyServer;
    console.log(machineName + " comes up");
    proxyServer.addNode(machineNode);
    return;
  } else {
    if (target.cur !== null) {
      target.cur.machine.commands.push(query);
      target.cur = target.cur.next;
    }
    return;
  }
}
