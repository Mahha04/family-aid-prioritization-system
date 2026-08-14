# Aid Eligibility and Family Need Prioritization System

## Description
A C++ algorithmic decision-support tool that evaluates and ranks family eligibility for humanitarian aid based on socio-economic vulnerability indicators. It processes multi-factor scoring metrics and implements a custom Merge Sort routine to prioritize top-k recipients efficiently.

## Features
- Socio-economic scoring based on household size, chronic medical conditions, elderly care, and zero-income status.
- Custom-built Merge Sort algorithm to maintain stability and guaranteed logarithmic sorting performance.
- Dynamic filtering to extract the highest-need families within defined capacity constraints.

## Technical Specifications
- Language: C++
- Core Topics: Divide and Conquer, Sorting Algorithms, Time Complexity Analysis, Vectors and STL.
- Time Complexity: O(N log N)
- Space Complexity: O(N)

## Usage

### Build
g++ -O3 main.cpp -o aid_system

### Execute
./aid_system

### Input Format
The first line contains integers k (target capacity) and n (total families).
The subsequent n lines contain family details: name, children count, disease count, elderly count, and income flag (0 for no income, 1 otherwise).

### Sample Execution

Input:
5 10
Ahmad 3 1 1 0
Sara 1 0 1 1
Khaled 4 1 1 0
Lina 2 0 1 0
Omar 1 1 1 1
Noor 5 0 1 0
Yousef 2 1 1 1
Maha 3 0 1 0
Rami 1 0 1 0
Dina 4 1 1 1

Output:
Total Families: 5

Families:
Khaled 720
Ahmad 540
Noor 180
Dina 180
Maha 108
