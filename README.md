more than 100 000 strings test

Quick Sort

Flat  profile:


Each sample counts as 0.01 seconds.

  % time | cumulative seconds | self seconds | calls | self us/call | total us/call | name 
------ | ------ | ------ | ------ | ------ | ------ | ------ 
 98.51 |  3.18 |  3.18 |  178252 |  17.85 |  17.85 |  partition 
 0.93 |  3.21 |  0.03 |  |  |  |  count_strings 
 0.93 |  3.24 |  0.03 |  |  |  |  count_strings_length 


Call graph


granularity: each sample hit covers 2 byte(s) for 0.31% of 3.24 seconds


 index | % time | self | children | called | name 
------ | ------ | ------ | ------ | ------ | ------ 
 |  | 3.18  |  0.00 |  178252/178252 |  sort_quick  [2]
 [1] |  98.1 |  3.18 |  0.00 |  178252 |  partition  [1]
 |  |  |  |  178252 |  sort_quick  [2]
 [2] |  98.1 |  0.00 |  3.18 |  0+178252 |  sort_quick  [2]
 |  |  3.18 |  0.00 |  178252/178252 |  partition  [1]
 |  |  |  |  178252 |  sort_quick  [2]
 |  |  |  |  |  <spontaneous>  
 [3] | 0.9 |  0.03 |  0.00 | | count_strings  [3]
 |  |  |  |  |  <spontaneous>  
 [4] |  0.9 |  0.03 |  0.00 |  |count_strings_length  [4]
 
 
 Insertion Sort
 
 Flat  profile:


Each sample counts as 0.01 seconds.

  % time | cumulative seconds | self seconds | calls | self Ts/call | total Ts/call | name 
------ | ------ | ------ | ------ | ------ | ------ | ------ 
 99.56 |  6.11 |  6.11 |  |  |  |  sort_insertion 
 0.49 |  6.14 |  0.03 |  |  |  |  read_strings 
 0.16 |  6.15 |  0.01 |  |  |  |  count_strings 
 0.16 |  6.16 |  0.01 |  |  |  |  count_strings_length 
 
 
 Merge Sort
 
 Flat  profile:


Each sample counts as 0.01 seconds.

  % time | cumulative seconds | self seconds | calls | self ns/call | total ns/call | name 
------ | ------ | ------ | ------ | ------ | ------ | ------ 
 40.15 |  0.04 |  0.04 |  |  |  |  count_strings_length 
 30.11 |  0.07 |  0.03 |  |  |  |  count_strings 
 20.07 |  0.09 |  0.02 |  |  |  |  read_strings 
 10.04 |  0.10 |  0.01 |  186695 |  53.76 |  53.76 |  merge 


Call graph


granularity: each sample hit covers 2 byte(s) for 9.96% of 0.10 seconds


 index | % time | self | children | called | name <spontaneous> 
------ | ------ | ------ | ------ | ------ | ------ 
 [1] |  |  40.0 |  0.04 |  0.00 |  count_strings_length  [1]
 [2]  |  30.0 |  0.03 |  0.00 | |  count_strings  [2]
 [3]  |  20.0 |  0.02 |  0.00 | | read_strings  [3]
 |  |  0.01 |  0.00 |  186695/186695 |  sort_merge  [5]
 [4] |  10.0 |  0.01 |  0.00 |  186695 |  merge  [4]
 |  |  |  |  373392 |  sort_merge  [5]
 [5] |  10.0 |  0.00 |  0.01 |  0+373392 |  sort_merge  [5]
 |  |  0.01 |  0.00 |  186695/186695 |  merge  [4]
 |  |  |  |  373392 |  sort_merge  [5]



