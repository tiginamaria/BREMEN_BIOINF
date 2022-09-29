## HW1

Firstly build all files:
```bash
make -f Makefile -C . all
```

### Task #1: 
#### Find the most frequent words k-mers in a string

Function `get_freq_table` calculates number of each k-mers occurrence in input text using hash table.
Time complexity `O(kn)` where `n` is input text length and k is k-mer length.

Then function `get_most_frequent_words` goes through all entities in hash table and collects ones with maximum count.
Time complexity is also `O(kn)` - hash table size.

Run:
```bash
./bin/hw1/task1 ACGTTGCATGTCGCATGATGCATGAGAGCT 4
CATG GCAT
```

### Task #2:
#### Find all occurrences of a Pattern in a string

Function `get_all_occurrences` calculates number of pattern occurrences trying to compare pattern with each substring of corresponding length of the input text.
Time complexity `O(kn)` where `n` is input text length and k is pattern length.\
(Can be a bit improved using char arrays and memcmp and lot using Knuth–Morris–Pratt algorithm)

Run:
```bash
./bin/hw1/task2 ATAT GATATATGCATATACTT
1 3 9 
```

### Task #3:
#### Calculate Hamming distance between two texts of same length

Function `get_hamming_distance` calculate Hamming distance by comparing symbols on same positions.
Time complexity `O(n)` where `n` is input text length.\
(For adds/deletions we can use dynamic programming)

Run:
```bash
./bin/hw1/task3 GGGCCGTTGGT GGACCGTTGAC
3
```

### Task #4:
#### Find the most frequent k-mers with mismatches and reverse complements

Function `get_freq_table` calculates number of each k-mers occurrence (and its neighbours in Hamming distance less than d) 
in input text using hash table.
Time complexity `O(kn^2)` where `n` is input text length and k is k-mer length. It `n` times more than in first task as 
it requires one more iteration through text to count all close neighbours also.

Then function `get_most_frequent_words` goes through all entities in hash table and collects ones with maximum count
taking in account number of reversed complement pattern which is calculated using `get_reversed_complement_pattern` function.  
Time complexity is also `O(kn)` - hash table size.

Run:
```bash
./bin/hw1/task4 ACGTTGCATGTCGCATGATGCATGAGAGCT 4 1
ATGC GATG ATGT
```

### Task #5:
#### Find d-neighborhood set of all k-mers whose Hamming distance from Pattern < d

Function `get_neighbors` runs the recursive process of neighbours finding changing letters on text one by one and 
going deeper in recursion.\

Time complexity can be estimated as `O(4^n)` but for more precise estimation I need t solve this recurrent equation.\
T(n, 0) = 1 \
T(n, d) = 3 * T(n - 1, d - 1) + T(n - 1, d)

Run:
```bash
./bin/hw1/task5 ACG 1
AAG ATG ACA ACT ACC ACG AGG TCG CCG GCG 
```

### Task #6:
#### Find a position in a genome minimizing the skew

Function `get_min_skew` finds all position in text where C-G balance is minimum.
Time complexity `O(n)` where `n` is input text length.

Run:
```bash
./bin/hw1/task6 TAAAGACTGCCGAGAGGCCAACACGAGTGCTAGAACGAGGGGCGTAAACGCGGGTCCGAT
11 24 
```