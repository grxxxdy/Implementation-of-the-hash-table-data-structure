# Implementation-of-the-hash-table-data-structure
1 year of computer science. Algorithms and data structures, Lab 6

# Task (translated using ChatGPT):

1. Implement the function generateRandLong():  
    1.1 The function should generate and return a random large number,
to be used as a unique key identifier in the hash table. The function signature: long long generateRandLong().

2. Implement a static hash table using the chaining method:  
2.1 Create a structure Data to store various data types according to the variant; it will be used as values for the hash table. Implement the generation of random data for the structure fields in the empty constructor Data().  
2.2 Create a structure HashNode to store the key and value.  
2.3 Create a structure LinkedList with support for adding elements; separate it into header and cpp files.  
2.4 Create a structure HashTable that will contain an array of linked lists bucketsArray of static size M = 10000.
   
3. Add dynamic resizing of the hash table:  
3.1 Calculate the load factor (current table load) at each step and change the size of the bucketsArray depending on maxLoadFactor (the maximum possible table load).  
3.2 Set the initial size of bucketsArray to a small value; dynamically increase the size when maxLoadFactor is exceeded.  
3.3 When reallocating memory for all elements of the hash table, compute new positions according to the change in the hash function.  

4. Perform testing of the hash table:  
4.1 Use several different values of maxLoadFactor (e.g., 9, 4, and 0.5) and different hash functions.  
4.2 Conduct testing with time measurements using the provided function testHashTable(), and choose optimal hash function and maxLoadFactor values.  
4.3 Explore the use of the ready-made library solution STL unordered_map, compare the obtained results with your solution.  
