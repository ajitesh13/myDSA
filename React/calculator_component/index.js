import React, { useState } from "react";
import "./index.css";

export default function Calculator() {
  const [input1, setInput1] = useState("");
  const [input2, setInput2] = useState("");
  const [operator, setOperator] = useState("+");
  const [result, setResult] = useState(null);
  const [totalOperations, setTotalOperations] = useState(0);

  const handleOperation = (op) => {
    if (input1 === "" || input2 === "") return;

    const num1 = parseFloat(input1);
    const num2 = parseFloat(input2);
    let calculatedResult;

    switch (op) {
      case "+":
        calculatedResult = num1 + num2;
        break;
      case "-":
        calculatedResult = num1 - num2;
        break;
      case "*":
        calculatedResult = num1 * num2;
        break;
      case "/":
        calculatedResult = num1 / num2;
        break;
      default:
        return;
    }

    setOperator(op);
    setResult(calculatedResult);
    setTotalOperations(totalOperations + 1);
  };

  const handleReset = () => {
    setInput1("");
    setInput2("");
    setOperator("+");
    setResult(null);
  };

  return (
    <div className="layout-column align-items-center">
      <div data-testid="total-operations" className="pt-50 total-operations">
        Total operations performed: {totalOperations}
      </div>
      <div className="card">
        <section className="card-text">
          <div className="layout-row justify-content-around align-items-center mt-40">
            <input
              type="number"
              className="ml-3 mr-3"
              data-testid="app-input1"
              autoComplete="off"
              placeholder="Eg: 1"
              name="input1"
              value={input1}
              onChange={(e) => setInput1(e.target.value)}
            />
            <label
              className="ml-2 mr-2 symbol text-center"
              data-testid="selected-operator"
            >
              {operator}
            </label>
            <input
              type="number"
              data-testid="app-input2"
              autoComplete="off"
              className="ml-3 mr-3"
              placeholder="Eg: 2"
              value={input2}
              onChange={(e) => setInput2(e.target.value)}
            />
          </div>

          <div className="layout-row justify-content-around mt-30">
            <button
              className="operationFont"
              type="submit"
              data-testid="addButton"
              onClick={() => handleOperation("+")}
            >
              +
            </button>
            <button
              className="operationFont"
              type="submit"
              data-testid="subtractButton"
              onClick={() => handleOperation("-")}
            >
              -
            </button>
            <button
              className="operationFont"
              type="submit"
              data-testid="multiplyButton"
              onClick={() => handleOperation("*")}
            >
              *
            </button>
            <button
              className="operationFont"
              type="submit"
              data-testid="divideButton"
              onClick={() => handleOperation("/")}
            >
              /
            </button>
          </div>

          <div className="layout-row justify-content-between align-items-center mt-30">
            <button
              type="reset"
              data-testid="resetButton"
              className="outline danger"
              onClick={handleReset}
            >
              Reset
            </button>
            <div className="layout-row justify-content-center align-items-center result-container">
              {result !== null && (
                <div
                  data-testid="result"
                  className="result-value ma-0 slide-up-fade-in"
                >
                  Result: {result}
                </div>
              )}
            </div>
          </div>
        </section>
      </div>
    </div>
  );
}
