const AsyncQueue = require("./async-queue");

// Create two separate queues
const queue1 = new AsyncQueue();
const queue2 = new AsyncQueue();

// Add tasks to queue1
const id1_q1 = queue1.add_task({
  taskName: "queue1_task1",
  body: async () => {
    console.log("Executing Queue 1 - Task 1");
    return "Queue1_Task1_Result";
  },
});

const id2_q1 = queue1.add_task({
  taskName: "queue1_task2",
  body: () =>
    new Promise((resolve) => {
      setTimeout(() => {
        console.log("Executing Queue 1 - Task 2 (delayed)");
        resolve("Queue1_Task2_Result");
      }, 1000);
    }),
});

// Add tasks to queue2
const id1_q2 = queue2.add_task({
  taskName: "queue2_task1",
  body: async () => {
    console.log("Executing Queue 2 - Task 1");
    return "Queue2_Task1_Result";
  },
});

const id2_q2 = queue2.add_task({
  taskName: "queue2_task2",
  body: () =>
    new Promise((resolve) => {
      setTimeout(() => {
        console.log("Executing Queue 2 - Task 2 (delayed)");
        resolve("Queue2_Task2_Result");
      }, 500);
    }),
});

// After 3 seconds, check task statuses
setTimeout(() => {
  console.log("Queue 1 - Task 1 Status:", queue1.check_task_status(id1_q1));
  console.log("Queue 1 - Task 2 Status:", queue1.check_task_status(id2_q1));

  console.log("Queue 2 - Task 1 Status:", queue2.check_task_status(id1_q2));
  console.log("Queue 2 - Task 2 Status:", queue2.check_task_status(id2_q2));
}, 3000);
