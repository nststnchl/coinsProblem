## Description ##
####Formulation of the problem: ####
**Input**: *Number of coins*, their *values* and *sum* required to be collected from these coins.

**Output**: Minimal number of coins required to collect *sum* and their values

####Realization: ####
Algorithm:

Solution is recursive.
To find a minimal number of coins required to collect *sum* we need
to check if *sum* equals to value of some coin. If that is true, answer is obviously 1.
Otherwise we need:
1. To find for each value of coins a minimal number of coins required to collect *sum - value of this coin*.
2. To find minimum among values from first clause.
3. To add 1 to result of second clause. That would be our final result.

**Consistency:**

This solution is working, because during execution there is working rule:
we either don't know truly minimal number of coins for each sum we are looking to or we know true value of it.

**Complexity:**

For each value from 1 to max value of coins we may launch number(= number of coins) of request.
Then complexity is *number of coins* * *maximum coin*

####Tests: ####
1. **Input**:   number = 5, values = {1, 5, 10, 20, 25}, sum = 40

   **Output**: minimal number = 2, required values = {20, 20}

2. **Input**:   number = 2, values = {1, 3}, sum = 5

   **Output**: minimal number = 3, required values = {1, 1, 3}

3. **Input**:   number = 2, values = {20, 25}, sum = 21

   **Output**: no solution exists