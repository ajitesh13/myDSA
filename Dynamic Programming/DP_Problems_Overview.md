# Dynamic Programming Problems Overview

This document provides a comprehensive breakdown of each folder in the Dynamic Programming directory, including problem descriptions and corresponding LeetCode questions.

## Folder Structure Analysis

### 1. 01_KnapSack (0/1 Knapsack and Subset Problems)

**Description:** Classic dynamic programming problems involving the 0/1 knapsack pattern where each item can be either included or excluded. This pattern extends to subset sum problems, partition problems, and counting problems.

**Problems:**

- **Classic Problem** - 0/1 Knapsack (`1_knapsack_iterative.cpp`, `1_knapsack_recursive.cpp`)
- **LeetCode No. 416** - Partition Equal Subset Sum (`2_subset_sum_problem_memoized.cpp`, `2_subset_sum_problem_recursive.cpp`, `2_subset_sum_tabulation.cpp`)
- **LeetCode No. 416** - Partition Equal Subset Sum (`3_equal_sum_partition_iterative.cpp`, `3_equal_sum_partition_recursive.cpp`, `3_equal_sum_partition_recursive_memoised.cpp`)
- **LeetCode No. 494** - Target Sum (Count of Subsets) (`4_count_of_subset_sum_with_given_sum_iterative.cpp`, `4_count_of_subset_sum_with_given_sum_memoised.cpp`, `4_count_of_subset_sum_with_given_sum_recursive.cpp`)
- **LeetCode No. 1049** - Last Stone Weight II (`5_minimum_subset_sum_difference.cpp`)
- **LeetCode No. 494** - Target Sum (`6_count_the_no_of_subset_with_given_diff.cpp`, `7_target_sum.cpp`)

**Key Techniques:**

- **Include/Exclude Pattern**: For each element, decide whether to include it or not
- **Subset Sum Approach**: Build DP table to track possible sums
- **Partition Logic**: Divide array into two subsets with specific properties
- **Counting Variations**: Count number of ways instead of finding optimal solution

---

### 2. LCS (Longest Common Subsequence and String Problems)

**Description:** String-based dynamic programming problems involving finding common patterns, subsequences, and string transformations. Uses 2D DP tables to compare characters between strings.

**Problems:**

- **LeetCode No. 1143** - Longest Common Subsequence (`1_lcs_memoized.cpp`, `1_lcs_recursive.cpp`, `1_lcs_tabulation.cpp`)
- **LeetCode No. 718** - Maximum Length of Repeated Subarray (`2_longest_common_substring_tabulation.cpp`)
- **LeetCode No. 1092** - Shortest Common Supersequence (`3_shortest_common_supersequence.cpp`)
- **LeetCode No. 72** - Edit Distance (`4_min_insertion_deletion_needed_to_convert_a_string_into_another.cpp`)
- **LeetCode No. 516** - Longest Palindromic Subsequence (`5_longest_palindromic_subsequence.cpp`)
- **LeetCode No. 1312** - Minimum Insertion Steps to Make a String Palindrome (`6_min_del_to_make_palindrome.cpp`, `8_min_insertion_to_make_a_palindrome.cpp`)
- **LeetCode No. 1062** - Longest Repeating Substring (`7_longest_repeating_subsequence.cpp`)

**Key Techniques:**

- **Character Matching**: Compare characters from two strings
- **Subsequence vs Substring**: Maintain continuity for substring problems
- **String Transformation**: Calculate minimum operations needed
- **Palindrome Properties**: Use string reversal to find palindromic patterns

---

### 3. MCM (Matrix Chain Multiplication and Interval DP)

**Description:** Interval dynamic programming problems where the solution involves finding optimal ways to partition or split intervals. These problems typically use a gap-based approach and involve trying all possible split points.

**Problems:**

- **Classic Problem** - Matrix Chain Multiplication (`1_mcm_memoized.cpp`, `1_mcm_recursive.cpp`)
- **LeetCode No. 132** - Palindrome Partitioning II (`2_palidrome_partition.cpp`, `2_palidrome_partition_memoized.cpp`, `2_palindrome_partition_memoized_optimized.cpp`)
- **LeetCode No. 1547** - Minimum Cost to Cut a Stick (`3_boolean_parenthesisation_recursive.cpp`, `3_boolean_parenthesisation_memoized_3darray.cpp`, `3_boolean_parenthesisation_memoized_map.cpp`)
- **LeetCode No. 87** - Scramble String (`4_scramble_string_recursive.cpp`, `4_scramble_string_memoized.cpp`, `4_scramble_string_leetcode_solution.cpp`)
- **LeetCode No. 887** - Super Egg Drop (`5_egg_dropping_recursive.cpp`, `5_egg_dropping_memoized.cpp`, `5_egg_dropping_iterative.cpp`)

**Key Techniques:**

- **Interval Partitioning**: Try all possible ways to split an interval
- **Gap-based Iteration**: Build solutions for increasing interval sizes
- **Optimal Substructure**: Combine solutions of smaller intervals
- **Multiple Parameters**: Track additional state information (like boolean values)

---

### 4. Unbounded_KnapSack (Unbounded Knapsack and Coin Problems)

**Description:** Dynamic programming problems where items can be used unlimited times. This includes coin change problems, rod cutting, and other optimization problems with unlimited resource usage.

**Problems:**

- **Classic Problem** - Rod Cutting Problem (`8_rod_cutting_problem_recursive.cpp`)
- **LeetCode No. 518** - Coin Change 2 (`9_coin_change_maximum_no_of_ways_recursive.cpp`, `9_coin_change_maximum_no_of_ways_recursive_memoise.cpp`)
- **LeetCode No. 322** - Coin Change (`10_coin_change_min_number_coin_recursive.cpp`)

**Key Techniques:**

- **Unlimited Usage**: Each item can be selected multiple times
- **Coin Change Variations**: Count ways vs minimum coins needed
- **Rod Cutting Logic**: Maximize profit by cutting rod optimally
- **Bottom-up Building**: Build solutions for increasing capacities

---

## Key Dynamic Programming Patterns

### 1. **0/1 Knapsack Pattern**

- **When to Use**: Each item can be taken at most once
- **Examples**: Subset sum, partition problems, target sum
- **Approach**: For each item, decide include or exclude

### 2. **Unbounded Knapsack Pattern**

- **When to Use**: Items can be used unlimited times
- **Examples**: Coin change, rod cutting
- **Approach**: For each capacity, try all items that fit

### 3. **Longest Common Subsequence Pattern**

- **When to Use**: Comparing two sequences
- **Examples**: Edit distance, palindrome problems
- **Approach**: Build 2D table comparing characters

### 4. **Matrix Chain Multiplication Pattern**

- **When to Use**: Optimal way to split intervals
- **Examples**: Palindrome partitioning, boolean parenthesization
- **Approach**: Try all possible split points in interval

## Problem Difficulty Progression

### **Beginner Level:**

- Basic Knapsack (0/1 and Unbounded)
- Simple LCS problems
- Basic subset sum

### **Intermediate Level:**

- Partition problems with constraints
- String transformation problems
- Matrix chain multiplication

### **Advanced Level:**

- Boolean parenthesization with multiple states
- Scramble string with complex recursion
- Egg dropping with optimization

## Summary

This directory contains a comprehensive collection of fundamental dynamic programming problems organized by core patterns. The progression moves from basic knapsack problems to advanced interval DP techniques. Each folder demonstrates specific DP approaches:

- **Pattern Recognition**: 0/1 Knapsack, Unbounded Knapsack, LCS, MCM
- **State Management**: 1D, 2D, and 3D DP arrays
- **Optimization Techniques**: Memoization, tabulation, space optimization
- **Problem Variations**: Counting, minimization, maximization, existence

The problems range from fundamental algorithmic concepts to complex competitive programming challenges, providing a solid foundation for understanding various dynamic programming paradigms and their real-world applications.

---

## Additional Practice Problems by Pattern

### **0/1 Knapsack Pattern - More Practice:**

- **LeetCode No. 698** - Partition to K Equal Sum Subsets
- **LeetCode No. 473** - Matchsticks to Square
- **LeetCode No. 1049** - Last Stone Weight II
- **LeetCode No. 1863** - Sum of All Subset XOR Totals
- **LeetCode No. 2035** - Partition Array Into Two Arrays to Minimize Sum Difference
- **LeetCode No. 1981** - Minimize the Difference Between Target and Chosen Elements
- **LeetCode No. 2172** - Maximum AND Sum of Array

### **LCS Pattern - More Practice:**

- **LeetCode No. 583** - Delete Operation for Two Strings
- **LeetCode No. 712** - Minimum ASCII Delete Sum for Two Strings
- **LeetCode No. 115** - Distinct Subsequences
- **LeetCode No. 97** - Interleaving String
- **LeetCode No. 1458** - Max Dot Product of Two Subsequences
- **LeetCode No. 1035** - Uncrossed Lines
- **LeetCode No. 1312** - Minimum Insertion Steps to Make a String Palindrome
- **LeetCode No. 647** - Palindromic Substrings
- **LeetCode No. 5** - Longest Palindromic Substring

### **MCM Pattern - More Practice:**

- **LeetCode No. 1130** - Minimum Cost Tree From Leaf Values
- **LeetCode No. 1039** - Minimum Score Triangulation of Polygon
- **LeetCode No. 375** - Guess Number Higher or Lower II
- **LeetCode No. 1547** - Minimum Cost to Cut a Stick
- **LeetCode No. 1000** - Minimum Cost to Merge Stones
- **LeetCode No. 1278** - Palindrome Partitioning III
- **LeetCode No. 1312** - Minimum Insertion Steps to Make a String Palindrome

### **Unbounded Knapsack Pattern - More Practice:**

- **LeetCode No. 377** - Combination Sum IV
- **LeetCode No. 279** - Perfect Squares
- **LeetCode No. 139** - Word Break
- **LeetCode No. 140** - Word Break II
- **LeetCode No. 983** - Minimum Cost For Tickets
- **LeetCode No. 1449** - Form Largest Integer With Digits That Add up to Target
- **LeetCode No. 1155** - Number of Dice Rolls With Target Sum
- **LeetCode No. 2222** - Number of Ways to Select Buildings

### **Linear DP - Additional Problems:**

- **LeetCode No. 70** - Climbing Stairs
- **LeetCode No. 746** - Min Cost Climbing Stairs
- **LeetCode No. 198** - House Robber
- **LeetCode No. 213** - House Robber II
- **LeetCode No. 740** - Delete and Earn
- **LeetCode No. 91** - Decode Ways
- **LeetCode No. 62** - Unique Paths
- **LeetCode No. 63** - Unique Paths II
- **LeetCode No. 64** - Minimum Path Sum
- **LeetCode No. 120** - Triangle

### **Advanced DP - Challenge Problems:**

- **LeetCode No. 10** - Regular Expression Matching
- **LeetCode No. 44** - Wildcard Matching
- **LeetCode No. 32** - Longest Valid Parentheses
- **LeetCode No. 85** - Maximal Rectangle
- **LeetCode No. 221** - Maximal Square
- **LeetCode No. 1277** - Count Square Submatrices with All Ones
- **LeetCode No. 1139** - Largest 1-Bordered Square
- **LeetCode No. 1143** - Longest Common Subsequence
- **LeetCode No. 1473** - Paint House III
