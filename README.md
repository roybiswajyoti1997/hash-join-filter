# Hash-Based Join on Filtered Random Arrays

This C++ program generates two arrays of random integers and performs a hash-based join on values that fall within a specific range. The join operation outputs matched index-value pairs between the two arrays.

---

## How It Works

### 1. Data Generation
Two integer arrays are generated:
- Each contains 200 random values.
- The generator allows specifying both range and size.

### 2. Range Filtering
Each array is filtered to retain only values within a specified inclusive range (120 to 140). The filtered output includes the index and value of matching entries.

### 3. Hash Table Construction
A hash table is created for the filtered values of the second array:
- Keys are the values.
- Values are vectors of corresponding indices.

### 4. Hash Join
The program checks for matching values from the first array in the hash table:
- For every match, the pair of indices from both arrays and the shared value are stored.


## Algorithmic Highlights

- **Random generation** with uniform distribution.
- **Filtering** using simple value comparison with index tracking.
- **Hash join** implemented using `unordered_map` for fast lookup.
- Efficient **O(n)** average complexity for the join step due to hashing.

---

## Build & Run

```bash
g++ -o join_program main.cpp
./join_program
```

## Sample output

```
Matching and combining indices and values:-
A[21] == B[34] <Value:: 132>
A[21] == B[52] <Value:: 132>

A[26] == B[134] <Value:: 135>
A[36] == B[41] <Value:: 140>

```
