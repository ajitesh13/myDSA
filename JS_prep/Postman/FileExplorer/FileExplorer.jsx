import { useState } from "react";
import { ArrowLeft, ArrowRight, Folder, File } from "lucide-react";
import "./Finder.scss";

/**
 * @typedef {Object} FileSystemNode
 * @property {string} name - Name of the file or folder
 * @property {FileSystemNode[]} [files] - Array of child files/folders (only present for folders)
 */

/**
 * Sample directory structure representing a file system
 * @type {FileSystemNode}
 */
const directoryStructure = {
  name: "root",
  files: [
    {
      name: "src",
      files: [
        { name: "index.js" },
        { name: "App.js" },
        {
          name: "components",
          files: [
            { name: "Header.js" },
            { name: "Footer.js" },
            {
              name: "buttons",
              files: [{ name: "Button.js" }, { name: "IconButton.js" }],
            },
          ],
        },
        {
          name: "utils",
          files: [{ name: "helpers.js" }, { name: "constants.js" }],
        },
      ],
    },
    {
      name: "public",
      files: [
        { name: "index.html" },
        {
          name: "assets",
          files: [
            {
              name: "images",
              files: [{ name: "logo.png" }, { name: "background.jpg" }],
            },
          ],
        },
      ],
    },
    {
      name: "docs",
      files: [{ name: "README.md" }, { name: "CONTRIBUTING.md" }],
    },
  ],
};

/**
 * FileExplorer Component
 * Implements a file system explorer with navigation capabilities
 *
 * Features:
 * - Forward/backward navigation
 * - Folder traversal
 * - Path display
 * - Visual distinction between files and folders
 *
 * @returns {JSX.Element} Rendered FileExplorer component
 */
const Finder = () => {
  // Track navigation history (folders visited)
  const [history, setHistory] = useState([]); // Initially empty to show only root
  // Track current path for display
  const [currentPath, setCurrentPath] = useState("root");
  // Stack for forward navigation after going back
  const [forwardStack, setForwardStack] = useState([]);

  /**
   * Navigate to a selected folder
   * @param {FileSystemNode} folder - The folder to navigate to
   */
  const navigateTo = (folder) => {
    setHistory((prev) => [...prev, folder]);
    setCurrentPath(folder.name);
    setForwardStack([]); // Clear forward history when navigating to new folder
  };

  /**
   * Navigate to the previous folder in history
   * Handles two scenarios:
   * 1. When there's more than one item in history
   * 2. When we're at the first level (root)
   */
  const goBack = () => {
    if (history.length > 1) {
      // Add current folder to forward stack for future forward navigation
      setForwardStack((prev) => [history[history.length - 1], ...prev]);

      // Remove the last item from history
      const newHistory = history.slice(0, -1);
      setHistory(newHistory);

      // Update current path to show the previous folder name
      setCurrentPath(newHistory[newHistory.length - 1].name);
    } else {
      // Reset to root when at first level
      setHistory([]);
      setCurrentPath("root");
    }
  };

  /**
   * Navigate forward in history (if available)
   * Takes the first item from forwardStack and:
   * 1. Adds it to history
   * 2. Updates current path
   * 3. Removes it from forward stack
   */
  const goForward = () => {
    if (forwardStack.length > 0) {
      // Get the next folder to navigate to
      const nextFolder = forwardStack[0];

      // Add the folder to navigation history
      setHistory((prev) => [...prev, nextFolder]);

      // Update the current path display
      setCurrentPath(nextFolder.name);

      // Remove the used folder from forward stack
      setForwardStack((prev) => prev.slice(1));
    }
  };

  // Get the current folder to display
  const currentFolder =
    history.length === 0 ? directoryStructure : history[history.length - 1];

  return (
    <div className="finder">
      <div className="finder-controls">
        <button onClick={goBack} disabled={history.length === 0}>
          <ArrowLeft size={16} />
        </button>
        <button onClick={goForward} disabled={forwardStack.length === 0}>
          <ArrowRight size={16} />
        </button>
      </div>
      <div className="finder-content">
        <h2 className="finder-path">{currentPath}</h2>
        <div className="finder-items">
          {history.length === 0 ? (
            // Only show root initially
            <div
              className="finder-item folder"
              onClick={() => navigateTo(directoryStructure)}
            >
              <Folder size={16} />
              <span>{directoryStructure.name}</span>
            </div>
          ) : (
            // Show folder contents after clicking root
            currentFolder.files?.map((item, index) => (
              <div
                key={index}
                className={`finder-item ${item.files ? "folder" : "file"}`}
                onClick={() => (item.files ? navigateTo(item) : null)}
              >
                {item.files ? <Folder size={16} /> : <File size={16} />}
                <span>{item.name}</span>
              </div>
            ))
          )}
        </div>
      </div>
    </div>
  );
};

export default Finder;
