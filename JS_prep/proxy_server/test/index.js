process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => {
	inputString += inputStdin;
});

process.stdin.on("end", (_) => {
	inputString = inputString
		.trim()
		.split("\n")
		.map((string) => {
			return string.trim();
		});
	main();
});

class Server {
	constructor(ip, endPoint, next = null, prev = null) {
		this.ip = ip;
		this.next = next;
		this.prev = prev;
		this.endPoint = endPoint;
		this.commands = [];
	}
}

class EndPoint {
	constructor(endPointName, start = null, end = null, curr = null) {
		this.endPointName = endPointName;
		this.start = start;
		this.end = end;
		this.curr = curr;
	}

	addNode(node) {
		if (this.start === null) {
			node.next = node;
			node.prev = node;
			this.start = node;
			this.end = node;
		} else {
			this.end.next = node;
			node.prev = this.end;
			node.next = this.start;
			this.start.prev = node;
			this.end = node;
		}
	}

	removeNode(node) {
		if (this.curr.ip === node.ip) {
			node.prev.next = node.next;
			node.next.prev = node.prev;
			this.curr = this.curr.prev;
		} else if (this.start.ip === node.ip) {
			this.end.next = this.start.next;
			this.start.next.prev = this.end;
			this.start = this.start.next;
		} else if (this.end.ip === node.ip) {
			this.end.prev.next = this.start;
			this.start.prev = this.end.prev;
			this.end = this.end.prev;
		} else {
			node.prev.next = node.next;
			node.next.prev = node.prev;
		}
		node.next = null;
		node.prev = null;
	}
}

class Network {
	constructor() {
		this.endpoints = {};
	}
}

function main() {
	let N = parseInt(inputString[currentLine++]);
	let serverList = {};
	let serverIpInput = inputString[currentLine++].split(" ");
	// console.log(serverIpInput);
	for (let i = 0; i < N; i++) {
		serverList[serverIpInput[i]] = new Server(serverIpInput[i]);
	}
	let M = parseInt(inputString[currentLine++]);
	let network = new Network();
	for (let i = 0; i < M; i++) {
		let endPointName = inputString[currentLine++];
		network.endpoints[endPointName] = new EndPoint(endPointName);
		let numberOfServers = parseInt(inputString[currentLine++]);
		let endpointServerList = inputString[currentLine++].split(" ");
		for (let j = 0; j < numberOfServers; j++) {
			network.endpoints[endPointName].addNode(
				serverList[endpointServerList[j]]
			);
			serverList[endpointServerList[j]].endPoint = endPointName;
			// console.log(serverList[endpointServerList[j]]);
		}
	}
	// console.log(network.endpoints["sahu"]);
	let numberOfQuery = inputString[currentLine++];
	for (let i = 0; i < numberOfQuery; i++) {
		let query = inputString[currentLine++];
		executeQuery(query, serverList, network);
	}
	console.log(serverList);
}

function executeQuery(query, serverList, network) {
	let querySplit = query.split("/", 2);
	let endPointName = querySplit[0];
	let remainingQuery = querySplit[1];
	let targetEndpoint = network.endpoints[endPointName];
	// take out the endPointName from the Server.endPoint property not from query
	if (remainingQuery.includes("machine_up")) {
		let remainingQuerysplit = remainingQuery.split("=");
		let serverIp = remainingQuerysplit[1];
		targetEndpoint.addNode(serverList[serverIp]);
	} else if (remainingQuery.includes("machine_down")) {
		let remainingQuerysplit = remainingQuery.split("=");
		let serverIp = remainingQuerysplit[1];
		targetEndpoint.removeNode(serverList[serverIp]);
	} else {
		// console.log(targetEndpoint);
		if (targetEndpoint.curr === null) {
			targetEndpoint.curr = targetEndpoint.start;
			targetEndpoint.curr.commands.push(remainingQuery);
		} else {
			targetEndpoint.curr = targetEndpoint.curr.next;
			targetEndpoint.curr.commands.push(remainingQuery);
		}
	}
}
