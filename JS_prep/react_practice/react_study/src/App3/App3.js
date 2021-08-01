import React from "react";
import SearchBar from "./SearchBar";
import axios from "axios";
import ImageList from "./ImageList";

class App3 extends React.Component {
  state = { images: [] };
  onSearchSubmit = async (term) => {
    const response = await axios.get("https://api.unsplash.com/search/photos", {
      params: { query: term },
      headers: {
        Authorization: "Client-ID MaxyOMolouGckheb0pJ-X2_sLU2CrYMaVlSfhDwar4M",
      },
    });
    this.setState({ images: response.data });
  };
  render() {
    return (
      <div className="ui container" style={{ marginTop: "10px" }}>
        <SearchBar onSubmit={this.onSearchSubmit} />
        <ImageList images={this.state.images} />
      </div>
    );
  }
}

export default App3;
