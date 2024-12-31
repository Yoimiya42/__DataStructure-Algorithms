# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/*
Hash Collision: multiple inputs(keys) correspond to the same output(value)

The larger the capacity of hashTable, 
the lower the probability that multiple keys being assigned to the same bucket, resulting in fewer collisions
Hence, we can reduce the hashTable collision by expanding capacity of hashTable.

Load Factor = ( n(pairs) / Total buckets ) 
It used to measure the severity of hash collision and often serves as a trigger for resizing the hashTable.

e.g. In Java, the default load factor is 0.75, 
which means that once exist pairs reach 75% of the total buckets,
the system will resize the hashTable to twice its original size.

Unfortunately, the resizing operation is also time-consuming, and 
a hash function's input space is typically far greater than its output space.
    - Separate Chaining
    - Open Addressing
these two methods are used to improve the structure of hash table.
*/





int main()
{
    return 0;
}