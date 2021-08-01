import React from "react";

const ImageList = (props) => {
  console.log("this-->", props.images);
  for (let i = 0; i < props.images.length; i++) {
    console.log(props.images[i]);
  }
  //   const images = props.images.map((image) => {
  //     return <img src={image.urls.regular} alt="" />;
  //   });
  //   return <div>{images}</div>;
  return <div>{props.images}</div>;
};

export default ImageList;
