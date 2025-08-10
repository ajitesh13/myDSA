class AsyncQueue {
  constructor() {
    this.task_queue = [];
    this.task_status_obj = {};
    this.execution_in_progress = false;
    this.taskId = 0;
    this.task_result_obj = {};
  }

  add_task(payload) {
    this.taskId += 1;
    const taskId = this.taskId;
    this.task_queue.push({ ...payload, taskId, status: "queued" });
    this.task_status_obj[taskId] = "queued";

    if (!this.execution_in_progress && this.task_queue.length > 0) {
      this.execution_in_progress = true;
      this.start_execution();
    }

    return taskId;
  }

  async start_execution() {
    if (this.task_queue.length === 0) {
      this.execution_in_progress = false;
      return;
    }

    const topTask = this.task_queue.shift();
    const id = topTask.taskId;
    try {
      this.task_status_obj[id] = "inprogress";
      const result = await topTask.body();
      this.task_status_obj[id] = "done";
      this.task_result_obj[id] = result;
    } catch (error) {
      this.task_status_obj[id] = `Error: ${error.message || error.toString()}`;
    }

    await this.start_execution();
  }

  check_task_status(taskId) {
    return {
      status: this.task_status_obj[taskId],
      result: this.task_result_obj[taskId],
    };
  }
}

module.exports = AsyncQueue;
