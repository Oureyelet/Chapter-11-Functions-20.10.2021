#include <iostream>
#include <array>

int doubleValue(int x)
{
    int value{ x * 2 };

    return value;// A copy of value will be returned here
}// value goes out of scope here

int* allotaceArray(int size)
{
    return new int[size];
}

// Returns a reference to the index element of array
int& getElement(std::array<int, 25>& array, int index)
{
    /*
    We know that array[index] will not be destroyed when we return to the caller (since the caller 
    passed in the array in the first place!)so it's okay to return it by reference
    */
    return array[index];
}

int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Returning values by value, reference, and address" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    n the three previous lessons, you learned about passing arguments to functions by value, reference, and address. 
    In this section, we’ll consider the issue of returning values back to the caller via all three methods.

    As it turns out, returning values from a function to its caller by value, address, or reference works almost exactly the 
    same way as passing arguments to a function does. All of the same upsides and downsides for each method are present. The 
    primary difference between the two is simply that the direction of data flow is reversed. However, there is one more added 
    bit of complexity -- because local variables in a function go out of scope and are destroyed when the function returns, we 
    need to consider the effect of this on each return type.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Return by value" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Return by value is the simplest and safest return type to use. When a value is returned by value, a copy of that value is 
    returned to the caller. As with pass by value, you can return by value literals (e.g. 5), variables (e.g. x), or expressions 
    (e.g. x+1), which makes return by value very flexible.

    Another advantage of return by value is that you can return variables (or expressions) that involve local variables declared 
    within the function without having to worry about scoping issues. Because the variables are evaluated before the function 
    returns, and a copy of the value is returned to the caller, there are no problems when the function’s variable goes out of 
    scope at the end of the function.
    */
    std::cout << doubleValue(12345) << '\n';

    /*
    Return by value is the most appropriate when returning variables that were declared inside the function, or 
    for returning function arguments that were passed by value. However, like pass by value, return by value is slow for 
    structs and large classes.

    When to use return by value:

        When returning variables that were declared inside the function
        When returning function arguments that were passed by value

    When not to use return by value:

        When returning a built-in array or pointer (use return by address)
        When returning a large struct or class (use return by reference)
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Return by address" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Returning by address involves returning the address of a variable to the caller. Similar to pass by address, return by 
    address can only return the address of a variable, not a literal or an expression (which don’t have addresses). Because 
    return by address just copies an address from the function to the caller, return by address is fast.

    However, return by address has one additional downside that return by value doesn’t -- if you try to return the address 
    of a variable local to the function, your program will exhibit undefined behavior. Consider the following example:

    int* doubleValue(int x)
    {
        int value{ x * 2 };
        return &value; // return value by address here
    } // value destroyed here

    As you can see here, value is destroyed just after its address is returned to the caller. The end result is that the 
    caller ends up with the address of non-allocated memory (a dangling pointer), which will cause problems if used. This is a 
    common mistake that new programmers make. Many newer compilers will give a warning (not an error) if the programmer tries to 
    return a local variable by address -- however, there are quite a few ways to trick the compiler into letting you do something 
    illegal without generating a warning, so the burden is on the programmer to ensure the pointer they are returning will 
    point to a valid variable after the function returns.

    Return by address was often used to return dynamically allocated memory to the caller:
    */
    int* array{ allotaceArray(12) };

    // do stuff here

    delete[] array;

    /*
    This works because dynamically allocated memory is not destroyed at the end of the block in which it is allocated, so that 
    memory will still exist when the address is returned back to the caller. Keeping track of manual allocations can be difficult. 
    Separating the allocation and deletion into different functions makes it even harder to understand who’s responsible for 
    deleting the resource or if the resource needs to be deleted at all. Smart pointers (covered later) and types that clean 
    up after themselves should be used instead of manual allocations.

    When to use return by address:

        When returning dynamically allocated memory and you can’t use a type that handles allocations for you
        When returning function arguments that were passed by address

    When not to use return by address:

        When returning variables that were declared inside the function or parameters that were 
            passed by value (use return by value)
        When returning a large struct or class that was passed by reference (use return by reference)
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Return by reference" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Similar to return by address, values returned by reference must be variables (you should not return a reference to a 
    literal or an expression that resolves to a temporary value, as those will go out of scope at the end of the function 
    and you’ll end up returning a dangling reference). When a variable is returned by reference, a reference to the variable 
    is passed back to the caller. The caller can then use this reference to continue modifying the variable, which can be 
    useful at times. Return by reference is also fast, which can be useful when returning structs and classes.

    However, just like return by address, you should not return local variables by reference. Consider the following example:
    
    int& doubleValue(int x)
    {
        int value{ x * 2 };
        return value; // return a reference to value here
    } // value is destroyed here
        
    In the above program, the program is returning a reference to a value that will be destroyed when the function returns. 
    This would mean the caller receives a reference to garbage. Fortunately, your compiler will probably give you a warning 
    or error if you try to do this.

    Return by reference is typically used to return arguments passed by reference to the function back to the caller. In the 
    following example, we return (by reference) an element of an array that was passed to our function by reference:    
    */
    std::array<int, 25> std_array;

    // Set the element of array with index 10 to the value 5
    getElement(std_array, 10) = 5;
 
    std::cout << "our array index 10: " << std_array[10] << '\n';

    /*
    When we call getElement(array, 10), getElement() returns a reference to the array element with index 10. 
    main() then uses this reference to assign that element the value 5.

    Although this is somewhat of a contrived example (because you can access array[10] directly), once you learn about 
    classes you will find a lot more uses for returning values by reference.

    When to use return by reference:

        When returning a reference parameter
        When returning a member of an object that was passed into the function by reference or address
        When returning a large struct or class that will not be destroyed at the end of the function (e.g. one that was 
        passed in by reference)

    When not to use return by reference:

        When returning variables that were declared inside the function or parameters that were passed by value (use return 
        by value)
        When returning a built-in array or pointer value (use return by address)
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Mixing return references and values" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    
    */





    return 0;
}