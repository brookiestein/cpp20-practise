Modify the Integer class in the previous exercise so that an Integer object
can be created without an argument. The member value should then be initialized to zero.
Can you think of two ways to do this?
Also, implement a copy constructor that prints a message when called.
Next, add a member function that compares the current object with an Integer object passed
as an argument. The function should return –1 if the current object is less than the argument,
0 if the objects are equal, and +1 if the current object is greater than the argument. Try two
versions of the Integer class, one where the compare() function argument is passed by value
and the other where it is passed by reference. What do you see output from the constructors
when the function is called? Make sure you understand why this is so. You can’t have both
functions present in the class as overloaded functions. Why not?
