class MyPromise {
  constructor(executor) {
    this.status = "pending";
    this.value = undefined;
    this.successCallbacks = [];
    this.errorCallbacks = [];

    const resolve = (value) => {
      if (this.status === "pending") {
        this.status = "fulfilled";
        this.value = value;
        setTimeout(() => {
          this.successCallbacks.forEach((cb) => cb(value));
        });
      }
    };

    const reject = (reason) => {
      if (this.status === "pending") {
        this.status = "rejected";
        this.value = reason;
        setTimeout(() => {
          this.errorCallbacks.forEach((cb) => cb(reason));
        });
      }
    };

    try {
      executor(resolve, reject);
    } catch (e) {
      reject(e);
    }
  }

  then(onFulfilled, onRejected) {
    return new MyPromise((resolve, reject) => {
      const handleSuccess = (value) => {
        try {
          const result = onFulfilled ? onFulfilled(value) : value;
          resolve(result);
        } catch (e) {
          reject(e);
        }
      };

      const handleError = (reason) => {
        try {
          const result = onRejected ? onRejected(reason) : reason;
          reject(result);
        } catch (e) {
          reject(e);
        }
      };

      if (this.status === "fulfilled") {
        setTimeout(() => handleSuccess(this.value));
      } else if (this.status === "rejected") {
        setTimeout(() => handleError(this.value));
      } else {
        this.successCallbacks.push(handleSuccess);
        this.errorCallbacks.push(handleError);
      }
    });
  }

  catch(onRejected) {
    return this.then(null, onRejected);
  }
}
