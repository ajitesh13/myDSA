/**
 * @param {Array<any>} iterable
 * @param {Function} callbackFn
 * @param {number} size
 *
 * @return {Promise}
 */
export default function mapAsyncLimit(iterable, callbackFn, size) {
  return new Promise(function (resolve, reject) {
    let compiledArr = [];
    for (let i = 0; i < iterable.length; i += size) {
      compiledArr.push(iterable.splice(i, i + size));
    }

    let resultArr = [];

    for (let i = 0; i < compiledArr.length; i++) {
      let newArr = new Array(compiledArr[i].length);
      newArr.forEach(function (item, index) {
        newArr[index] = callbackFn(item);
      });
      resultArr.concat(newArr);
      if (resultArr.length == iterable.length) {
        resolve(resultArr);
      }
    }
  });
}
