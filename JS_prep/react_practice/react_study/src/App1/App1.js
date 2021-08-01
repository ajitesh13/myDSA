import React from "react";
import CommentDetail from "./CommentDetail";
import ApprovalCard from "./ApprovalCard";

const App = () => {
  let arname = ["Sam", "Alex"]; // implement ComponentDetails using a for loop
  return (
    <div>
      <ApprovalCard>
        <CommentDetail author="Sam" timeAgo="Today at 4:45 PM" />
        {/* Passing CommentDetail as children componeent to Approval Card */}
      </ApprovalCard>
      <ApprovalCard>
        <CommentDetail author="Alex" timeAgo="Today at 5:00 PM" />
      </ApprovalCard>
      <ApprovalCard>Are you Sure you want to do this ?</ApprovalCard>
    </div>
  );
};

export default App;
