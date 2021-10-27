#include <iostream>
#include <utility> // for std::swap

int foo()// code for foo starts at memory address 0x002717f0
{
    return 5;
}

int goo()
{
    return 7;
}

int foo2(int x)
{
    return x;
}

void SelectionSort(int *array, int size)
{
    // Step through each element of the array
    for(int startIndex{ 0 }; startIndex < (size-1); ++startIndex)
    {
        // smallestIndex is the index of the smallest element we've encountered so far.
        int smallestIndex{ startIndex };
        
        // Look for smallest element remaining in the array (starting at startIndex+1)
        for(int currentIndex{ startIndex+1 }; currentIndex < size; ++currentIndex)
        {
            // If the current element is smaller than our previously found smallest
            if(array[smallestIndex] > array[currentIndex])// COMPARISON DONE HERE
            {
                // This is the new smallest number for this iteration
                smallestIndex = currentIndex;
            }

        }

        // Swap our start element with our smallest element
        std::swap(array[startIndex], array[smallestIndex]);
    }
}

bool ascending(int x, int y)
{
    return (x > y);// swap if the first element is greater than the second
}

void SelectionSort_plus_our_comparison(int *array, int size)
{
    // Step through each element of the array
    for(int startIndex{ 0 }; startIndex < (size-1); ++startIndex)
    {
        // smallestIndex is the index of the smallest element we've encountered so far.
        int smallestIndex{ startIndex };
        
        // Look for smallest element remaining in the array (starting at startIndex+1)
        for(int currentIndex{ startIndex+1 }; currentIndex < size; ++currentIndex)
        {
            // If the current element is smaller than our previously found smallest
            if(ascending(array[smallestIndex], array[currentIndex]))// COMPARISON DONE HERE
            {
                // This is the new smallest number for this iteration
                smallestIndex = currentIndex;
            }

        }

        // Swap our start element with our smallest element
        std::swap(array[startIndex], array[smallestIndex]);
    }
}

void SelectionSort_plus_our_function_pointer_parameter(int *array, int size, bool (*comparisonFcn)(int, int))
{
    // Step through each element of the array
    for(int startIndex{ 0 }; startIndex < (size-1); ++startIndex)
    {
        // smallestIndex is the index of the smallest element we've encountered so far.
        int smallestIndex{ startIndex };
        
        // Look for smallest element remaining in the array (starting at startIndex+1)
        for(int currentIndex{ startIndex+1 }; currentIndex < size; ++currentIndex)
        {
            // If the current element is smaller than our previously found smallest
            if(ascending(array[smallestIndex], array[currentIndex]))// COMPARISON DONE HERE
            {
                // This is the new smallest number for this iteration
                smallestIndex = currentIndex;
            }

        }

        // Swap our start element with our smallest element
        std::swap(array[startIndex], array[smallestIndex]);
    }
}

int main()
{
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Function Pointers" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In lesson 10.8 -- Introduction to pointers, you learned that a pointer is a variable that holds the 
    address of another variable. Function pointers are similar, except that instead of pointing to variables, 
    they point to functions!

    Consider the following function:
    */
    std::cout << foo() << '\n';

    /*
    Identifier foo is the function’s name. But what type is the function? Functions have their own 
    l-value function type -- in this case, a function type that returns an integer and takes no parameters. 
    Much like variables, functions live at an assigned address in memory.

    When a function is called (via the () operator), execution jumps to the address of the function being called:
    */
    foo(); // jump to address 0x002717f0

    /*
    At some point in your programming career (if you haven’t already), you’ll probably make a simple mistake:
    */
    std::cout << foo << '\n'; // we meant to call foo(), but instead we're printing foo itself!

    /*
    Instead of calling function foo() and printing the return value, we’ve unintentionally sent 
    function foo directly to std::cout.

    Print some other value (e.g. 1) on your machine, depending on how your compiler decides to convert the 
    function pointer to another type for printing. If your machine doesn’t print the function’s address, you may be 
    able to force it to do so by converting the function to a void pointer and printing that:
    */
    std::cout << reinterpret_cast<void*>(foo) << '\n';// Tell C++ to interpret function foo as a void 

    /*
    Just like it is possible to declare a non-constant pointer to a normal variable, it’s also 
    possible to declare a non-constant pointer to a function. In the rest of this lesson, we’ll examine 
    these function pointers and their uses. Function pointers are a fairly advanced topic, and the rest of 
    this lesson can be safely skipped or skimmed by those only looking for C++ basics.
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Pointers to functions" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    The syntax for creating a non-const function pointer is one of the ugliest things you will ever see in C++:
    
    // fcnPtr is a pointer to a function that takes no arguments and returns an integer
    int (*fcnPtr)();
    */

    /*
    In the above snippet, fcnPtr is a pointer to a function that has no parameters and returns an integer. 
    fcnPtr can point to any function that matches this type.

    The parenthesis around *fcnPtr are necessary for precedence reasons, as int *fcnPtr() would be interpreted as a 
    forward declaration for a function named fcnPtr that takes no parameters and returns a pointer to an integer.

    To make a const function pointer, the const goes after the asterisk:

    int (*const fcnPtr)();

    If you put the const before the int, then that would indicate the function being pointed to would return a const int.
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Assigning a function to a function pointer" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Function pointers can be initialized with a function (and non-const function pointers can be assigned a function). 
    In the above example, we have used foo directly, and it has been converted to a function pointer. 
    Like with pointers to variables, we can also use &foo to get a function pointer to foo.
    */
    int (*fcnPtr)(){ &foo };// fcnPtr points to function foo    
    fcnPtr = &goo;// fcnPtr now points to function goo

    /*
    Note that the type (parameters and return type) of the function pointer must match the type of the function. 
    Here are some examples of this:
    
    // function prototypes
    int foo();
    double goo();
    int hoo(int x);

    // function pointer assignments
    int (*fcnPtr1)(){ &foo }; // okay
    int (*fcnPtr2)(){ &goo }; // wrong -- return types don't match!
    double (*fcnPtr4)(){ &goo }; // okay
    fcnPtr1 = &hoo; // wrong -- fcnPtr1 has no parameters, but hoo() does
    int (*fcnPtr3)(int){ &hoo }; // okay
    */

    /*
    Unlike fundamental types, C++ will implicitly convert a function into a function pointer if needed 
    (so you don’t need to use the address-of operator (&) to get the function’s address). However, it will not 
    implicitly convert function pointers to void pointers, or vice-versa.

    Function pointers can also be initialized or assigned the value nullptr:
    int (*fcnptr)() { nullptr }; // okay
    */
   

    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Calling a function using a function pointer" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    The other primary thing you can do with a function pointer is use it to actually call the function. 
    There are two ways to do this. The first is via explicit dereference:
    */
    int (*fcn_ptr_foo2)(int){ &foo2 };// Initialize fcnPtr with function foo
    std::cout << (*fcn_ptr_foo2)(777) << '\n'; // call function foo(5) through fcnPtr.

    /*
    The second way is via implicit dereference:
    */
    std::cout << fcn_ptr_foo2(888) << '\n';// call function foo(5) through fcnPtr.

    /*
    As you can see, the implicit dereference method looks just like a normal function call -- which is what you’d expect, 
    since normal function names are pointers to functions anyway! However, some older compilers do not support the implicit 
    dereference method, but all modern compilers should.

    One interesting note: Default parameters won’t work for functions called through function pointers. Default parameters 
    are resolved at compile-time (that is, if you don’t supply an argument for a defaulted parameter, the compiler 
    substitutes one in for you when the code is compiled). However, function pointers are resolved at run-time. Consequently, 
    default parameters can not be resolved when making a function call with a function pointer. You’ll explicitly 
    have to pass in values for any defaulted parameters in this case.

    Also note that because function pointers can be set to nullptr, it’s a good idea to assert or conditionally 
    test whether your function pointer is a null pointer before calling it. Just like with normal pointers, dereferencing 
    a null function pointer lead to undefined behavior.
    */
    int (*fcn_ptr_goo)(){ &goo };// Initialize fcnPtr with function foo
    if(fcn_ptr_goo)// make sure fcnPtr isn't a null pointer
    {
        std::cout << (*fcn_ptr_goo)() << '\n';// otherwise this will lead to undefined behavior
    }


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Passing functions as arguments to other functions" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    One of the most useful things to do with function pointers is pass a function as an argument to another function. 
    Functions used as arguments to another function are sometimes called callback functions.

    Consider a case where you are writing a function to perform a task (such as sorting an array), but you want the 
    user to be able to define how a particular part of that task will be performed (such as whether the array is sorted 
    in ascending or descending order). Let’s take a closer look at this problem as applied specifically to sorting, as 
    an example that can be generalized to other similar problems.

    Many comparison-based sorting algorithms work on a similar concept: the sorting algorithm iterates through a list of 
    numbers, does comparisons on pairs of numbers, and reorders the numbers based on the results of those comparisons. 
    Consequently, by varying the comparison, we can change the way the algorithm sorts without affecting the rest of the 
    sorting code.

    Here is our selection sort routine from a previous lesson:
    */

    //see our function: void SelectionSort(int *array, int size) above...

    /*
    Let’s replace that comparison with a function to do the comparison. Because our comparison function is going 
    to compare two integers and return a boolean value to indicate whether the elements should be swapped, 
    it will look something like this:
    */

    //see our function: bool ascending(int x, int y) above....

    /*
    And here’s our selection sort routine using the ascending() function to do the comparison:
    */

    //see our function: void SelectionSort_plus_our_comparison(int *array, int size) above...

    /*
    Now, in order to let the caller decide how the sorting will be done, instead of using our own hard-coded comparison 
    function, we’ll allow the caller to provide their own sorting function! This is done via a function pointer.

    Because the caller’s comparison function is going to compare two integers and return a boolean value, a pointer to 
    such a function would look something like this:

    bool (*comparisonFcn)(int, int);
    */

    /*
    So, we’ll allow the caller to pass our sort routine a pointer to their desired comparison function as the 
    third parameter, and then we’ll use the caller’s function to do the comparison.

    Here’s a full example of a selection sort that uses a function pointer parameter to do a user-defined comparison, 
    along with an example of how to call it:
    */









    return 0;
}