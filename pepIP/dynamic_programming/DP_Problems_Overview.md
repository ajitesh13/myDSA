# Dynamic Programming Problems Overview

This document provides a comprehensive breakdown of each folder in the dynamic programming directory, including problem descriptions and corresponding LeetCode questions.

## Folder Structure Analysis

### 1. DP-1 LIS (Longest Increasing Subsequence)

**Description:** Problems related to finding the longest subsequence where elements are in increasing order. Uses dynamic programming to track the length of LIS ending at each position.

**Problems:**

- **LeetCode No. 300** - Longest Increasing Subsequence (`1_lis.cpp`, `1_lis_print.cpp`)
- **LeetCode No. 300** - Longest Increasing Subsequence O(n log n) (`2_lis_nlogn.cpp`)
- **LeetCode No. 1024** - Building Bridges (`3_building_bridge.cpp`)
- **LeetCode No. 354** - Russian Doll Envelopes (`4_russian_envelop.cpp`)
- **LeetCode No. 1691** - Maximum Height by Stacking Cuboids (`5_box_stack.cpp`)
- **LeetCode No. 674** - Longest Continuous Increasing Subsequence (`6_min_inc_subsequence.cpp`)
- **LeetCode No. 978** - Longest Turbulent Subarray (`7_max_sum_alternating_subsequence.cpp`)
- **LeetCode No. 1235** - Maximum Profit in Job Scheduling (`8_weighted_job_scheduling.cpp`)

---

### 2. DP-2 Buy and Sell (Stock Trading Problems)

**Description:** State machine DP problems involving buying and selling stocks with various constraints. Uses state transitions to track holding/not holding stock states.

**Problems:**

- **LeetCode No. 121** - Best Time to Buy and Sell Stock (`9_buyandsell1.cpp`)
- **LeetCode No. 122** - Best Time to Buy and Sell Stock II (`10_buyandsell2.cpp`)
- **LeetCode No. 123** - Best Time to Buy and Sell Stock III (`11_buyandsell3.cpp`)
- **LeetCode No. 188** - Best Time to Buy and Sell Stock IV (`12_buyandsell4.cpp`)
- **LeetCode No. 309** - Best Time to Buy and Sell Stock with Cooldown (`13_buyandsell5.cpp`)
- **LeetCode No. 714** - Best Time to Buy and Sell Stock with Transaction Fee (`14_buyandsell6.cpp`)

---

### 3. DP-3 Include-Exclude (House Coloring & Jump Games)

**Description:** Problems involving include/exclude decisions with constraints. Uses DP to track valid states while respecting adjacency or consecutive constraints.

**Problems:**

- **LeetCode No. 276** - Paint Fence (`15_paint_fence.class`)
- **LeetCode No. 256** - Paint House (`16_paint_house.class`)
- **LeetCode No. 265** - Paint House II (`16_paint_house2.class`)
- **Custom Problem** - No Consecutive Zeros (`17_no_consecutive_zero.cpp`)
- **Custom Problem** - Number of Ways to Construct Buildings (`18_number_of_ways_to_construct_building.cpp`)
- **LeetCode No. 45** - Jump Game II (`19_jump_game_II_linear_complexity_imp.class`, `19_jump_game_II_quadratic_complexity.class`)

---

### 4. DP-4 Catalan Number (Catalan Number Applications)

**Description:** Problems that follow Catalan number patterns, involving balanced structures and binary tree counting. Uses recursive formula C(n) = Σ C(i) \* C(n-1-i).

**Problems:**

- **LeetCode No. 22** - Generate Parentheses (`20_valid_parenthesis.cpp`)
- **LeetCode No. 96** - Unique Binary Search Trees (`21_count_number_of_bst.cpp`)
- **LeetCode No. 894** - All Possible Full Binary Trees (`extra_mountain_construction.cpp`)

---

### 5. DP-5 Miscellaneous (Various DP Problems)

**Description:** Collection of diverse DP problems including keyboard operations, ugly numbers, and combinatorics. Each uses specific DP approaches tailored to the problem constraints.

**Problems:**

- **LeetCode No. 650** - 2 Keys Keyboard (`22_two_key_keyboard.cpp`)
- **LeetCode No. 264** - Ugly Number II (`28_ugly_number.cpp`)
- **LeetCode No. 313** - Super Ugly Number (`29_super_ugly_number.cpp`)
- **LeetCode No. 1569** - Number of Ways to Reorder Array to Get Same BST (`30_binomial_coefficient.cpp`)
- **Custom Problem** - Friends Pairing Problem (`31_friends_pairing.cpp`)

---

### 6. DP-6 Merging-Intervals (Matrix Chain Multiplication Variants)

**Description:** Interval DP problems where optimal solutions are found by trying all possible ways to split intervals. Uses gap-based iteration to build solutions bottom-up.

**Problems:**

- **LeetCode No. 312** - Burst Balloons (`23_burst_balloons_iterative_dp.cpp`, `23_burst_balloons_recursive_dp.cpp`, `23_burst_balloons_recursive.cpp`)
- **LeetCode No. 1547** - Minimum Cost to Cut a Stick (`24_boolean_parenthesis.cpp`)
- **Custom Problem** - Maximum/Minimum Value of Expression (`25_max_min_value_of_expression_with_*_+.cpp`)
- **LeetCode No. 1039** - Minimum Score Triangulation of Polygon (`26_min_score_trangulations_of_polygon.cpp`)
- **Classic Problem** - Matrix Chain Multiplication (`27_mcm.cpp`)

---

### 7. DP-7 Eggdrop (Egg Dropping Problem)

**Description:** Classic optimization problem involving finding the minimum number of trials needed to determine the critical floor. Uses 2D DP with floor and egg constraints.

**Problems:**

- **LeetCode No. 887** - Super Egg Drop (`32_egg_drop.cpp`)

---

### 8. DP-8 (Advanced DP Problems)

**Description:** Complex DP problems involving multiple constraints and optimization techniques including LIS variants and sequence problems.

**Problems:**

- **Custom Problem** - Highway Billboard Placement (`33_highway_billboard_include_exclude.cpp`, `33_highway_billboard_lis_n2.cpp`)
- **Custom Problem** - Sequence of ai bj ck (`34_sequence_of_ai_bj_ck_On.cpp`, `34_sequence_of_ai_bj_ck_On2.cpp`)
- **LeetCode No. 403** - Frog Jump (`35_frog_jump.cpp`)

---

### 9. DP-9 3D-DP (Three-Dimensional Dynamic Programming)

**Description:** Problems requiring 3D state space, typically involving path problems with additional constraints or cherry pickup scenarios with multiple agents.

**Problems:**

- **LeetCode No. 64** - Minimum Path Sum (`36_min_path_sum.cpp`, `36_min_path_sum2.cpp`)
- **LeetCode No. 741** - Cherry Pickup (`37_cherry_pickup_psuedocode_iterative_3D_dp.cpp`, `37_cherry_pickup_psuedocode_recursive_3d_dp.cpp`, `37_cherry_pickup_psuedocode_recursive_4d_dp.cpp`, `37_cherry_pickup_recursive.cpp`)

---

### 10. DP-10 Strings (String-based Dynamic Programming)

**Description:** DP problems involving string manipulation, pattern matching, and subsequence problems. Uses 2D tables to compare characters and build optimal solutions.

**Problems:**

- **LeetCode No. 1143** - Longest Common Subsequence (`38_longest_common_subsequence_1D.cpp`, `38_longest_common_subsequence_2D.cpp`)
- **Custom Problem** - LCS for 3 Strings (`39_LCS_for_3_string.cpp`)
- **LeetCode No. 516** - Longest Palindromic Subsequence (`40_longest_palindromic_subsequence.cpp`)
- **LeetCode No. 730** - Count Different Palindromic Subsequences (`41_count_number_of_palindromic_subsequence.cpp`)
- **LeetCode No. 87** - Scramble String (`42_scramble_string.cpp`)
- **Custom Problem** - Distinct Palindromic Subsequences (`43_distinct_palindromic_subsequence.cpp`)
- **LeetCode No. 1092** - Shortest Common Supersequence (`44_shortest_common_supersequence.cpp`)
- **LeetCode No. 44** - Wildcard Matching (`45_wild_card_queries.cpp`)

---

## Summary

This directory contains a comprehensive collection of dynamic programming problems organized by pattern and complexity. The progression moves from basic concepts like Longest Increasing Subsequence to advanced topics like 3D DP and complex string algorithms. Each folder demonstrates specific DP techniques:

- **Pattern Recognition**: LIS, LCS, Catalan Numbers
- **State Machine**: Stock trading problems
- **Interval DP**: Matrix chain multiplication variants
- **Multi-dimensional DP**: 3D state spaces
- **String DP**: Pattern matching and subsequence problems

The problems range from fundamental LeetCode questions to custom implementations, providing a solid foundation for understanding various dynamic programming approaches and their applications in competitive programming and technical interviews.

---

## Additional Practice Problems by Category

### **DP-1 LIS Pattern - More Practice:**

- **LeetCode No. 368** - Largest Divisible Subset
- **LeetCode No. 646** - Maximum Length of Pair Chain
- **LeetCode No. 673** - Number of Longest Increasing Subsequence
- **LeetCode No. 1048** - Longest String Chain
- **LeetCode No. 1027** - Longest Arithmetic Subsequence
- **LeetCode No. 1218** - Longest Arithmetic Subsequence of Given Difference
- **LeetCode No. 2370** - Longest Ideal Subsequence

### **DP-2 Stock Trading - More Practice:**

- **LeetCode No. 2291** - Maximum Profit From Trading Stocks
- **LeetCode No. 1911** - Maximum Alternating Subsequence Sum
- **LeetCode No. 2008** - Maximum Earnings From Taxi
- **LeetCode No. 1493** - Longest Subarray of 1's After Deleting One Element

### **DP-3 Include-Exclude - More Practice:**

- **LeetCode No. 198** - House Robber
- **LeetCode No. 213** - House Robber II
- **LeetCode No. 337** - House Robber III
- **LeetCode No. 740** - Delete and Earn
- **LeetCode No. 1388** - Pizza With 3n Slices
- **LeetCode No. 1463** - Cherry Pickup II
- **LeetCode No. 1696** - Jump Game VI

### **DP-4 Catalan Numbers - More Practice:**

- **LeetCode No. 95** - Unique Binary Search Trees II
- **LeetCode No. 241** - Different Ways to Add Parentheses
- **LeetCode No. 1259** - Handshakes That Don't Cross
- **LeetCode No. 1569** - Number of Ways to Reorder Array to Get Same BST

### **DP-5 Miscellaneous - More Practice:**

- **LeetCode No. 279** - Perfect Squares
- **LeetCode No. 343** - Integer Break
- **LeetCode No. 357** - Count Numbers with Unique Digits
- **LeetCode No. 1201** - Ugly Number III
- **LeetCode No. 1137** - N-th Tribonacci Number
- **LeetCode No. 1359** - Count All Valid Pickup and Delivery Options

### **DP-6 Merging Intervals - More Practice:**

- **LeetCode No. 1000** - Minimum Cost to Merge Stones
- **LeetCode No. 375** - Guess Number Higher or Lower II
- **LeetCode No. 1278** - Palindrome Partitioning III
- **LeetCode No. 1770** - Maximum Score from Performing Multiplication Operations
- **LeetCode No. 1246** - Palindrome Removal

### **DP-7 Egg Drop - More Practice:**

- **LeetCode No. 1884** - Egg Drop With 2 Eggs and N Floors
- **LeetCode No. 1690** - Stone Game VII
- **LeetCode No. 375** - Guess Number Higher or Lower II

### **DP-8 Advanced DP - More Practice:**

- **LeetCode No. 1425** - Constrained Subsequence Sum
- **LeetCode No. 1504** - Count Submatrices With All Ones
- **LeetCode No. 1531** - String Compression II
- **LeetCode No. 1639** - Number of Ways to Form a Target String Given a Dictionary

### **DP-9 3D DP - More Practice:**

- **LeetCode No. 1473** - Paint House III
- **LeetCode No. 1444** - Number of Ways of Cutting a Pizza
- **LeetCode No. 1420** - Build Array Where You Can Find The Maximum Exactly K Comparisons
- **LeetCode No. 1363** - Largest Multiple of Three

### **DP-10 String DP - More Practice:**

- **LeetCode No. 10** - Regular Expression Matching
- **LeetCode No. 97** - Interleaving String
- **LeetCode No. 115** - Distinct Subsequences
- **LeetCode No. 583** - Delete Operation for Two Strings
- **LeetCode No. 712** - Minimum ASCII Delete Sum for Two Strings
- **LeetCode No. 1035** - Uncrossed Lines
- **LeetCode No. 1458** - Max Dot Product of Two Subsequences
- **LeetCode No. 1639** - Number of Ways to Form a Target String Given a Dictionary

### **Multi-Pattern Problems (Combines Multiple DP Techniques):**

- **LeetCode No. 32** - Longest Valid Parentheses (String + Stack simulation)
- **LeetCode No. 85** - Maximal Rectangle (2D DP + Stack)
- **LeetCode No. 221** - Maximal Square (2D DP)
- **LeetCode No. 1277** - Count Square Submatrices with All Ones
- **LeetCode No. 1092** - Shortest Common Supersequence (LCS variant)
- **LeetCode No. 1186** - Maximum Subarray Sum with One Deletion
- **LeetCode No. 1537** - Get the Maximum Score (Path DP with multiple arrays)
