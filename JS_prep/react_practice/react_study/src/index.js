import React from "react";
import ReactDOM from "react-dom";
// import App1 from "./App1/App1";
// import App2 from "./App2/App2";
// import Time from "./Time";
// import App3 from "./App3/App3";
// import List from "./List";
import App4 from "./App4/App4";

const App = () => {
  return (
    <div>
      <App4 />
      {/* <List /> */}
      {/* <App3 /> */}
      {/* <App2 /> */}
      {/* <Time /> */}
      {/* <App1 /> */}
    </div>
  );
};

ReactDOM.render(<App />, document.querySelector("#root"));
