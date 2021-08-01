import React from "react";

const users = [
  { id: 1, name: "Leanne Graham" },
  { id: 2, name: "Ervin Howell" },
  { id: 3, name: "Clementine Bauch" },
  { id: 4, name: "Patricia Lebsack" },
];

class List extends React.Component {
  render() {
    return (
      <ul>
        {users.map((elem) => (
          <li>{elem.name}</li>
        ))}
      </ul>
    );
  }
}

export default List;
