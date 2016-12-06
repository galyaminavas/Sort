GProf's output for Quick Sort on >100 000 strings test

Flat  profile:



Each sample counts as 0.01 seconds.

   time | cumulative seconds | self seconds | calls | self us/call | total us/call | name 
------ | ------ | ------ | ------ | ------ | ------ | ------ 
 99.54 |  3.58 |  3.58 |  178252 |  20.10 |  20.10 |  partition 
 0.84 |  3.61 |  0.03 |  |  |  |  count_strings 


Call graph





granularity: each sample hit covers 2 byte(s) for 0.28% of 3.61 seconds


 index | % time | self | children | called | name 3.58 
------ | ------ | ------ | ------ | ------ | ------ 
 |  | 3.58 |  0.00 |  178252/178252 |  sort_quick  [2]
 [1] |  99.2 |  3.58 |  0.00 |  178252 |  partition  [1]
 |  |  |  |  178252 |  sort_quick  [2]
 [2] |  99.2 |  0.00 |  3.58 |  0+178252 |  sort_quick  [2]
 |  |  3.58 |  0.00 |  178252/178252 |  partition  [1]
 |  |  |  |  178252 |  sort_quick  [2]
 [3] |  0.8 |  0.03 |  0.00 | | count_strings  [3]
