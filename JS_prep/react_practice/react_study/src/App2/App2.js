import React from "react";
import SeasonDisplay from "./SeasonDisplay";
import Spinner from "./Spinner";

class App2 extends React.Component {
  state = { lat: null, errmsg: "" };

  componentDidMount() {
    window.navigator.geolocation.getCurrentPosition(
      (position) => this.setState({ lat: position.coords.latitude }),
      (err) => this.setState({ errmsg: err.message })
    );
  }

  render() {
    if (!this.state.errmsg && this.state.lat) {
      return <SeasonDisplay lat={this.state.lat} />;
    }
    if (this.state.errmsg && !this.state.lat) {
      return <div>{this.state.errmsg}</div>;
    }
    return <Spinner />;
  }
}

export default App2;
