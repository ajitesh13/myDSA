import React from "react";

function FileList({ data, onToggleFolder, onDoubleClick, onAddFile }) {
  const renderFiles = (files, parentIndex) => {
    if (!files) return null;

    return (
      <ul>
        {files.map((file, index) => (
          <li key={file.name + index}>
            <button
              onClick={() =>
                file.files && onToggleFolder(index, true, parentIndex, index)
              }
              onDoubleClick={() => onDoubleClick(parentIndex)}
            >
              {file.name}
              {file.files && <span>[{file.isOpen ? "-" : "+"}]</span>}
            </button>
            {file.files && file.isOpen && renderFiles(file.files, index)}
          </li>
        ))}
        <li>
          <button onClick={() => onAddFile()}>+</button>
        </li>
      </ul>
    );
  };

  return (
    <ul>
      {data.map((item, index) => (
        <li key={item.name + index}>
          <button
            onClick={() => item.files && onToggleFolder(index)}
            onDoubleClick={() => onDoubleClick(index)}
          >
            {item.name}
            {item.files && <span>[{item.isOpen ? "-" : "+"}]</span>}
          </button>
          {item.files && item.isOpen && renderFiles(item.files, index)}
        </li>
      ))}
      <li>
        <button onClick={() => onAddFile()}>+</button>
      </li>
    </ul>
  );
}

export default FileList;
