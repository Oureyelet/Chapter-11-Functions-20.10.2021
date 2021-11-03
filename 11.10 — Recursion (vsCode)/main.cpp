#include <iostream>

void countDown(int count)
{
    std::cout << "push " << count << '\n';
    countDown(count-1); // countDown() calls itself recursively
}

void countDown_plus(int count)
{   
    std::cout << "push " << count << '\n';

    if( count > 1 )// termination condition
        countDown_plus(count-1);
    
    std::cout << "pop " << count << '\n';
}

// return the sum of all the integers between 1 (inclusive) and sumto (inclusive)
// returns 0 for negative numbers
int sumTo(int sumto)
{
    if(sumto <= 0)
        return 0;// base case (termination condition) when user passed in an unexpected parameter (0 or negative)
    else if(sumto == 1)
        return 1;// normal base case (termination condition)
    else
        return sumTo(sumto-1) + sumto;// recursive function call
}

int main()
{
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Recursion" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    A recursive function in C++ is a function that calls itself. Here is an example of a poorly-written recursive function:
    */

    //countDown(77);

    /*
    When countDown(5) is called, “push 5” is printed, and countDown(4) is called. countDown(4) prints “push 4” and calls 
    countDown(3). countDown(3) prints “push 3” and calls countDown(2). The sequence of countDown(n) calling countDown(n-1) 
    is repeated indefinitely, effectively forming the recursive equivalent of an infinite loop.

    In lesson 11.8 -- The stack and the heap, you learned that every function call causes data to be placed on the call stack. 
    Because the countDown() function never returns (it just calls countDown() again), this information is never being popped off 
    the stack! Consequently, at some point, the computer will run out of stack memory, stack overflow will result, and the 
    program will crash or terminate. On the author’s machine, this program counted down to -11732 before terminating!
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Recursive termination conditions" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Recursive function calls generally work just like normal function calls. However, the program above illustrates the 
    most important difference with recursive functions: you must include a recursive termination condition, or they will 
    run “forever” (actually, until the call stack runs out of memory). A recursive termination is a condition that, when met, 
    will cause the recursive function to stop calling itself.

    Recursive termination generally involves using an if statement. Here is our function redesigned with a termination 
    condition (and some extra output):
    */
    countDown_plus(5);

    /*
    Now when we run our program, countDown() will start by outputting the following:

    push 5
    push 4
    push 3
    push 2
    push 1

    If you were to look at the call stack at this point, you would see the following:

    countDown(1)
    countDown(2)
    countDown(3)
    countDown(4)
    countDown(5)
    main()

    Because of the termination condition, countDown(1) does not call countDown(0) -- instead, the “if statement” does 
    not execute, so it prints “pop 1” and then terminates. At this point, countDown(1) is popped off the stack, 
    and control returns to countDown(2). countDown(2) resumes execution at the point after countDown(1) was called, 
    so it prints “pop 2” and then terminates. The recursive function calls get subsequently popped off the stack until 
    all instances of countDown have been removed.

    Thus, this program in total outputs:

    push 5
    push 4
    push 3
    push 2
    push 1
    pop 1
    pop 2
    pop 3
    pop 4
    pop 5

    It’s worth noting that the “push” outputs happen in forward order since they occur before the recursive function call. 
    The “pop” outputs occur in reverse order because they occur after the recursive function call, as the functions are 
    being popped off the stack (which happens in the reverse order that they were put on).
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "A more useful example" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Now that we’ve discussed the basic mechanics of recursive function calls, let’s take a look at another recursive 
    function that is slightly more typical:
    */
    std::cout << sumTo(5) << '\n';

    /*
    Recursive programs are often hard to figure out just by looking at them. It’s often instructive to see what 
    happens when we call a recursive function with a particular value. So let’s see what happens when we call this 
    function with parameter sumto = 5.

    sumTo(5) called, 5 <= 1 is false, so we return sumTo(4) + 5.
    sumTo(4) called, 4 <= 1 is false, so we return sumTo(3) + 4.
    sumTo(3) called, 3 <= 1 is false, so we return sumTo(2) + 3.
    sumTo(2) called, 2 <= 1 is false, so we return sumTo(1) + 2.
    sumTo(1) called, 1 <= 1 is true, so we return 1.  This is the termination condition.

    Now we unwind the call stack (popping each function off the call stack as it returns):

    sumTo(1) returns 1.
    sumTo(2) returns sumTo(1) + 2, which is 1 + 2 = 3.
    sumTo(3) returns sumTo(2) + 3, which is 3 + 3 = 6.
    sumTo(4) returns sumTo(3) + 4, which is 6 + 4 = 10.
    sumTo(5) returns sumTo(4) + 5, which is 10 + 5 = 15.

    At this point, it’s easier to see that we’re adding numbers between 1 and the value passed in (both inclusive).

    Because recursive functions can be hard to understand by looking at them, good comments are particularly important.

    Note that in the above code, we recurse with value sumto - 1 rather than --sumto. We do this because operator- has a 
    side effect, and using a variable that has a side effect applied more than once in a given expression will result in 
    undefined behavior. Using sumto - 1 avoids side effects, making sumto safe to use more than once in the expression.
        */











    return 0;
}