import React, { useState } from "react";
import "./index.css";

export default function InstructionBoard() {
  const [instructions, setInstructions] = useState([]);
  const [newInstruction, setNewInstruction] = useState("");
  const [errorMessage, setErrorMessage] = useState("");

  const handleInputChange = (e) => {
    setNewInstruction(e.target.value);
    setErrorMessage("");
  };

  const handleAddInstruction = (e) => {
    e.preventDefault();

    if (!newInstruction.trim()) {
      setErrorMessage("Please enter an instruction.");
      return;
    }

    setInstructions([...instructions, newInstruction]);
    setNewInstruction("");
    setErrorMessage("");
  };

  const moveInstructionUp = (index) => {
    if (index === 0) return;

    const updatedInstructions = [...instructions];
    [updatedInstructions[index - 1], updatedInstructions[index]] = [
      updatedInstructions[index],
      updatedInstructions[index - 1],
    ];

    setInstructions(updatedInstructions);
  };

  const moveInstructionDown = (index) => {
    if (index === instructions.length - 1) return;

    const updatedInstructions = [...instructions];
    [updatedInstructions[index + 1], updatedInstructions[index]] = [
      updatedInstructions[index],
      updatedInstructions[index + 1],
    ];

    setInstructions(updatedInstructions);
  };

  return (
    <div className="mt-50 layout-column justify-content-center align-items-center">
      <div>
        <form onSubmit={handleAddInstruction}>
          <section className="my-30 layout-row align-items-center justify-content-center width-1000">
            <input
              id="instruction-input"
              type="text"
              placeholder="New Instruction"
              data-testid="instruction-input"
              className="width-80"
              value={newInstruction}
              onChange={handleInputChange}
            />
            <button
              type="submit"
              className="ml-30 width-20"
              data-testid="add-instruction-button"
            >
              Add Instruction
            </button>
          </section>
        </form>
        <span
          data-testid="error-message"
          className={`error ${!errorMessage ? "hidden-span" : ""}`}
        >
          {errorMessage}
        </span>
      </div>
      <div className="card outlined mt-0 width-800">
        <div className="card-text">
          <h4>Instructions</h4>
          <ul className="styled mt-50" data-testid="instructions">
            {instructions.map((instruction, index) => (
              <li key={index} data-testid="instruction">
                <div className="li-content layout-row justify-content-between align-items-center">
                  <span>{index + 1}</span>
                  <span>{instruction}</span>
                  <div className="icons">
                    <button
                      className="icon-only x-medium mx-2"
                      data-testid="swap-down"
                      disabled={index === instructions.length - 1}
                      onClick={() => moveInstructionDown(index)}
                    >
                      <i className="material-icons">arrow_drop_down_icon</i>
                    </button>
                    <button
                      className="icon-only x-medium mx-2"
                      data-testid="swap-up"
                      disabled={index === 0}
                      onClick={() => moveInstructionUp(index)}
                    >
                      <i className="material-icons">arrow_drop_up_icon</i>
                    </button>
                  </div>
                </div>
              </li>
            ))}
          </ul>
        </div>
      </div>
    </div>
  );
}
