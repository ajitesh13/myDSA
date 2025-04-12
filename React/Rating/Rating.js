import React, { useState, useEffect } from "react";
import "./Rating.css";

const Rating = (props) => {
  const emptyIcon = props.emptyIcon || "/icons/stars/empty.svg";
  const filledIcon = props.filledIcon || "/icons/stars/filled.svg";
  const halfFilledIcon = props.halfFilledIcon || "/icons/stars/half.svg";
  const steps = props.steps || 1;
  const totalStars = 5;

  const [hoverValue, setHoverValue] = useState(0);
  const [rating, setRating] = useState(props.value || 0);
  const [isHovering, setIsHovering] = useState(false);

  useEffect(() => {
    if (props.value !== undefined) {
      setRating(props.value);
    }
  }, [props.value]);

  // Utility function to calculate if the mouse event happened on the left side of the target or the right side.
  const isLessThanHalf = (event) => {
    const { target } = event;
    const boundingClientRect = target.getBoundingClientRect();
    let mouseAt = event.clientX - boundingClientRect.left;
    mouseAt = Math.round(Math.abs(mouseAt));
    return mouseAt <= boundingClientRect.width / 2;
  };

  const handleMouseMove = (index, event) => {
    if (steps === 0.5 && isLessThanHalf(event)) {
      setHoverValue(index + 0.5);
    } else {
      setHoverValue(index + 1);
    }
    setIsHovering(true);
  };

  const handleMouseLeave = () => {
    setIsHovering(false);
  };

  const handleClick = (index, event) => {
    let newRating;
    if (steps === 0.5 && isLessThanHalf(event)) {
      newRating = index + 0.5;
    } else {
      newRating = index + 1;
    }

    // Toggle rating if clicking on the same star
    if (newRating === rating) {
      setRating(0);
    } else {
      setRating(newRating);
    }
  };

  const handleKeyDown = (event) => {
    if (event.key === "ArrowRight") {
      setRating((prev) => Math.min(prev + steps, totalStars));
    } else if (event.key === "ArrowLeft") {
      setRating((prev) => Math.max(prev - steps, 0));
    } else if (event.key >= "1" && event.key <= "5") {
      setRating(parseInt(event.key));
    }
  };

  const getIconSrc = (index) => {
    const value = isHovering ? hoverValue : rating;

    if (index < Math.floor(value)) {
      return filledIcon;
    } else if (index === Math.floor(value) && value % 1 !== 0) {
      return halfFilledIcon;
    } else {
      return emptyIcon;
    }
  };

  const renderSymbols = () => {
    return Array(totalStars)
      .fill(0)
      .map((_, index) => (
        <img
          key={index}
          src={getIconSrc(index)}
          className="rating-image"
          data-testid="rating-icon"
          alt="Rate"
          onMouseMove={(e) => handleMouseMove(index, e)}
          onMouseOver={(e) => handleMouseMove(index, e)}
          onMouseEnter={(e) => handleMouseMove(index, e)}
          onMouseOut={handleMouseLeave}
          onMouseLeave={handleMouseLeave}
          onClick={(e) => handleClick(index, e)}
        />
      ));
  };

  return (
    <div
      tabIndex="0"
      className="star-rating"
      data-testid="star-rating-container"
      onKeyDown={handleKeyDown}
    >
      {renderSymbols()}
    </div>
  );
};

export default Rating;
