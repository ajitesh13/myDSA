import React, { useEffect, useState } from "react";
import "./index.css";
const classNames = require("classnames");

export default function FootballMatchesData() {
  let [selectedYear, setSelectedYear] = useState(null);
  let [matches, setMatches] = useState([]);
  let [loading, setLoading] = useState(false);
  let [error, setError] = useState(false);

  useEffect(() => {
    if (selectedYear) {
      setLoading(true);
      fetch(
        `https://jsonmock.hackerrank.com/api/football_competitions?year=${selectedYear}`
      )
        .then((response) => response.json())
        .then((data) => {
          setMatches(data.data);
          setLoading(false);
        })
        .catch((err) => {
          setError(true);
          setLoading(false);
        });
    }
  }, [selectedYear]);

  let onclick = (year) => {
    setSelectedYear(year);
  };

  let years = [2011, 2012, 2013, 2014, 2015, 2016, 2017];

  return (
    <div className="layout-row">
      <div className="section-title">Select Year</div>
      <ul className="sidebar" data-testid="year-list">
        {years.map((year) => {
          return (
            <li
              className={classNames({
                "sidebar-item": true,
                active: selectedYear === year,
              })}
              onClick={() => onclick(year)}
              key={year}
            >
              <a>{year}</a>
            </li>
          );
        })}
      </ul>

      <section className="content">
        <section>
          {matches.length > 0 && (
            <div className="total-matches" data-testid="total-matches">
              Total matches: {matches.length}
            </div>
          )}

          {matches.length > 0 && (
            <ul className="mr-20 matches styled" data-testid="match-list">
              {matches.map((match, index) => (
                <li className="slide-up-fade-in" key={index}>
                  Match {match.name} won by {match.winner}
                </li>
              ))}
            </ul>
          )}
        </section>

        {selectedYear && matches.length === 0 && !loading && (
          <div data-testid="no-result" className="slide-up-fade-in no-result">
            No Matches Found
          </div>
        )}
      </section>
    </div>
  );
}
