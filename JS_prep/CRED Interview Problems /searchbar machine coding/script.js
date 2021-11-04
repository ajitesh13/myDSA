var searchField = document.getElementById("search-input");
let suggestionsContainer = document.getElementById("suggestions");

(() => {})();
searchField.addEventListener("input", (e) => {
  let keyword = e.target.value;
  if (keyword) {
    fetchResults(keyword);
  } else {
    removeOldSuggestions();
    suggestionsContainer.style.display = "none";
  }
});

const fetchResults = async (keyword) => {
  const data = await fetch(
    `https://restcountries.eu/rest/v2/name/${keyword}?fields=name`
  );
  const json = await data.json();
  populateSuggestions(json.slice(0, 5));
};

const populateSuggestions = (list) => {
  if (list) {
    // remove the old suggestions
    removeOldSuggestions();
    // append new suggestions
    list.forEach((country) => {
      let elem = document.createElement("li");
      elem.setAttribute("class", "suggestion");
      elem.innerHTML = country.name;
      suggestionsContainer.append(elem);
    });
  }
  suggestionsContainer.style.display = "block";
};

const removeOldSuggestions = () => {
  // remove the old suggestions
  while (suggestionsContainer.lastElementChild) {
    suggestionsContainer.removeChild(suggestionsContainer.lastElementChild);
  }
};
