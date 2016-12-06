Flat  profile:


Each sample counts as 0.01 seconds.

   time | cumulative seconds | self seconds | calls | self us/call | total us/call | name 
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

