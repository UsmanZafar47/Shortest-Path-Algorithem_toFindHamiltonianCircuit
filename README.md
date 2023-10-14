<br>**#PROBLEM:** 
<br>Suppose you are designing a delivery robot that must visit a number of locations in a warehouse. The robot
starts at a designated "home" location and must visit every other location exactly once before returning to the home location. Additionally, the robot has a limited battery life and must return home before its battery runs out. More formally, you are given an undirected graph G = (V, E) representing the warehouse layout, where each vertex v ∈ V represents a location and each edge (u, v) ∈ E represents a direct path between locations u and v that the robot can traverse. The home location is a designated vertex h ∈ V, and each vertex v ∈ V (other than h) has a delivery time t(v) representing the amount of time it takes the robot to deliver a package at location v. Your goal is to find a Hamiltonian circuit in G that starts and ends at h and visits every other vertex exactly once, subject to the constraint that the total time taken by the robot (including delivery times and travel times) does not exceed a given time limit T. Design an algorithm to solve this problem. If a feasible Hamiltonian circuit exists, your algorithm should output the sequence of vertices visited in the circuit. If no feasible circuit exists, your algorithm should output "NO FEASIBLE CIRCUIT". You may assume that the input graph is connected, and that the battery life of the robot is sufficient to travel between any two locations in the warehouse.  

<br>**# Shortest-Path-Algorithm to Find Hamiltonian Circuit**  
<br>#**Solved** This Problem Using a Backtracking Algorithm to Find Hamiltonian Circuit  
<br>**##Explanation:**
<br>is_valid function of bool type checks whether a candidate vertex can be added to the current path by checking whether the path weight exceeds the minimum weight found so far whether there is an edge between the last and candidate vertex or whether the candidate vertex in path is already included or the path is complete.
**backtrack_algo** function generates all possible permutations of vertices to find a **Hamiltonian circuit**. It uses the is_valid function to determine whether a given permutation is a valid extension for the current path or not. If Hamilton Circuits is found it prints its circuit and weights (in this function it prints vertices indexes for the circuit).  

<br>**#Time Complexity:**
the time complexity of this algorithm is O(n!) where n is the number of vertices in a graph. This is because the function tries all possible permutations of the vertices to find the Hamiltonian circuit  

<br>**#Space Complexity:**
The space complexity of this algorithm is O(n), where n is the number of vertices in the graph. This is because the algorithm uses an array of size n to store the current path being explored, and a constant amount of additional space to store variables like the current weight of the path and circuit, and the minimum weight found so far.
