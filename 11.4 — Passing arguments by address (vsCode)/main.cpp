#include <iostream>

void foo(int* ptr)
{
    *ptr = 6;
}

void printArray(int* array, int lenght)
{
    for(int i{ 0 }; i < lenght; ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
}

void setToNull(int* tempPtr)
{
    // we're making tempPtr point at something else, not changing the value that tempPtr points to.
    tempPtr = NULL; // use 0 instead if not C++11
}

int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Passing arguments by address" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    There is one more way to pass variables to functions, and that is by address. Passing an argument by address involves 
    passing the address of the argument variable rather than the argument variable itself. Because the argument is an address, 
    the function parameter must be a pointer. The function can then dereference the pointer to access or change the value
    being pointed to.

    Here is an example of a function that takes a parameter passed by address:
    */
    int value{ 7 };

    std::cout << "value is: " << value << '\n';
    foo(&value);
    std::cout << "value is: " << value << '\n';

    /*
    As you can see, the function foo() changed the value of the argument (variable value) through pointer parameter ptr.

    Pass by address is typically used with pointers, which most often are used to point to built-in arrays. For example, 
    the following function will print all the values in an array:
    */
    //see printArray() above.
    /*
    Here is an example program that calls this function:
    */
    int array[]{ 6, 5, 4, 3, 2, 100 };// remember, arrays decay into pointers

    printArray(array, 6);// so array evaluates to a pointer to the first element of the array here, no & needed

    /*
    Remember that fixed arrays decay into pointers when passed to a function, so we have to pass the length as a separate 
    parameter.

    It is always a good idea to ensure parameters passed by address are not null pointers before dereferencing them. 
    Dereferencing a null pointer will typically cause the program to crash.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Passing by const address" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Because printArray() doesn’t modify any of its arguments, it’s good form to make the array parameter const.
    This allows us to tell at a glance that printArray() won’t modify the array argument passed in, 
    and will ensure we don’t do so by accident.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Addresses are actually passed by value" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    When you pass a pointer to a function, the pointer’s value (the address it points to) is copied from the argument to the function’s parameter. In other words, it’s passed by value! If you change the function parameter’s value, you are only changing a copy. Consequently, the original pointer argument will not be changed.

    Here’s a sample program that illustrates this.
    */
    // First we set ptr_y to the address of y, which means *ptr = 5
    int y{ 5 };
    int* ptr_y{ &y };

    // This will print 5
    std::cout << *ptr_y << '\n';

    // tempPtr will receive a copy of ptr
    setToNull(ptr_y);

    // ptr is still set to the address of five!

    //this will print 5
    if(ptr_y)
        std::cout << *ptr_y << '\n';
    else
        std::cout << "ptr is NULL";

    /*
    tempPtr receives a copy of the address that ptr is holding. Even though we change tempPtr to point at something 
    else (nullptr), this does not change the value that ptr points to. Consequently, this program prints: 55
    */

    











    return 0;
}