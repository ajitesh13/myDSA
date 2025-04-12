import React, { useState } from "react";
import FileList from "./FileList";
import initialData from "./initialdata";

function File() {
  const [data, setData] = useState(initialData);
  const [inputValue, setInputValue] = useState("");

  const handleInputChange = (e) => {
    setInputValue(e.target.value);
  };

  const handleAddFile = () => {
    if (inputValue.trim() === "") {
      alert("Please enter a file name in the input box");
      return;
    }

    const newFile = { name: inputValue };
    setData([...data, newFile]);
    setInputValue("");
  };

  const handleToggleFolder = (
    index,
    isSubFolder = false,
    parentIndex = null,
    subIndex = null
  ) => {
    const newData = [...data];

    if (isSubFolder) {
      newData[parentIndex].files[subIndex].isOpen =
        !newData[parentIndex].files[subIndex].isOpen;
    } else {
      newData[index].isOpen = !newData[index].isOpen;
    }

    setData(newData);
  };

  const handleDoubleClick = (index) => {
    const newData = [...data];
    if (!newData[index].files) {
      newData[index].files = [];
      newData[index].isOpen = false;
    }
    setData(newData);
  };

  return (
    <div className="layout-row justify-content-between">
      <ul data-testid="files">
        <FileList
          data={data}
          onToggleFolder={handleToggleFolder}
          onDoubleClick={handleDoubleClick}
          onAddFile={handleAddFile}
        />
      </ul>
      <input
        data-testid="input-box"
        className="mt-15 mr-35 w-15"
        style={{ borderColor: "black" }}
        type="text"
        placeholder="Enter an item"
        value={inputValue}
        onChange={handleInputChange}
      />
    </div>
  );
}

export default File;
