import React from "react";

class App4 extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      pageList: [],
    };
    this.pageList = [
      {
        name: "Ajitesh1",
        id: "1",
      },
      {
        name: "Ajitesh2",
        id: "2",
      },
      {
        name: "Ajitesh3",
        id: 3,
      },
    ];
  }

  render() {
    return (
      <div>
        <select>
          {this.state.pageList.map((elem) => {
            return <option>{elem.name}</option>;
          })}
        </select>
      </div>
    );
  }
}

export default App4;
