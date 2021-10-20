#include <iostream>
#include <cmath> // for std::sin() and std::cos()

//To pass a variable by reference, we simply declare the function parameters as references rather than as normal variables:
void addOne(int& ref)// ref is a reference variable
{
    ref += 1;
    // same as ref = ref + 1;
}

void getSinCos(double degrees, double& sinOut, double& cosOut)
{
    // sin() and cos() take radians, not degrees, so we need to convert
    constexpr double pi { 3.14159265358979323846 };// the value of pi
    double radians{ degrees * pi / 180.0 };
    sinOut = std::sin(radians);
    cosOut = std::cos(radians);

}



int main()
{

    std::cout << "Hello Nifty!\n";

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Passing arguments by reference" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    While pass by value is suitable in many cases, it has a couple of limitations. First, when passing a large struct or 
    class to a function, pass by value will make a copy of the argument into the function parameter. In many cases, this is a 
    needless performance hit, as the original argument would have sufficed. Second, when passing arguments by value, the only 
    way to return a value back to the caller is via the function’s return value. While this is often suitable, there are cases 
    where it would be more clear and efficient to have the function modify the argument passed in. Pass by reference 
    solves both of these issues.
    */

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Pass by reference" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    To pass a variable by reference, we simply declare the function parameters as references rather than as normal variables:
   
    When the function is called, ref will become a reference to the argument. Since a reference to a variable is treated 
    exactly the same as the variable itself, any changes made to the reference are passed through to the argument!

    The following example shows this in action:
    */
    int x{ 7 };
    std::cout << x << '\n';

    addOne(x);

    std::cout << x << '\n';

    /*
    This program is the same as the one we used for the pass by value example, except addOne’s parameter is now a reference 
    instead of a normal variable. When we call addOne(value), ref becomes a reference to main’s value variable.
    As you can see, the function changed the value of the argument from 5 to 6!
    */

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Returning multiple values via out parameters" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Sometimes we need a function to return multiple values. However, functions can only have one return value. 
    One way to return multiple values is using reference parameters:
    */
    double sin{ 0.0 };
    double cos{ 0.0 };

    // getSinCos will return the sin and cos in variables sin and cos
    getSinCos(30.0, sin, cos);

    std::cout << "The sin is " << sin << '\n';
    std::cout << "The cos is " << cos << '\n';

    /*
    This function takes one parameter (by value) as input, and “returns” two parameters (by reference) as output. Parameters that 
    are only used for returning values back to the caller are called out parameters. We’ve named these out parameters with the 
    suffix “out” to denote that they’re out parameters. This helps remind the caller that the initial value passed to these 
    parameters doesn’t matter, and that we should expect them to be rewritten. By convention, output parameters are typically 
    the rightmost parameters.

    Let’s explore how this works in more detail. First, the main function creates local variables sin and cos. Those are passed 
    into function getSinCos() by reference (rather than by value). This means function getSinCos() has access to the actual sin 
    and cos variables, not just copies. getSinCos() accordingly assigns new values to sin and cos (through references sinOut and 
    cosOut respectively), which overwrites the old values in sin and cos. Main then prints these updated values.

    If sin and cos had been passed by value instead of reference, getSinCos() would have changed copies of sin and cos, leading 
    to any changes being discarded at the end of the function. But because sin and cos were passed by reference, any changes 
    made to sin or cos (through the references) are persisted beyond the function. We can therefore use this mechanism to 
    return values back to the caller.

    This method, while functional, has a few minor downsides. First, the caller must pass in arguments to hold the updated 
    outputs even if it doesn’t intend to use them. More importantly, the syntax is a bit unnatural, with both the input and 
    output parameters being put together in the function call. It’s not obvious from the caller’s end that sin and cos are out 
    parameters and will be changed. This is probably the most dangerous part of this method (as it can lead to mistakes 
    being made). Some programmers and companies feel this is a big enough problem to advise avoiding output parameters altogether, 
    or using pass by address for out parameters instead (which has a clearer syntax indicating whether a parameter is modifiable 
    or not).

    Personally, we recommend avoiding out parameters altogether if possible. If you do use them, naming out parameters 
    (and output arguments) with an “out” suffix (or prefix) can help make it clear that the value might be modified.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Limitations of pass by reference" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    Non-const references can only reference non-const l-values (e.g. non-const variables), so a reference parameter cannot 
    accept an argument that is a const l-value or an r-value (e.g. literals and the results of expressions).
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Pass by const reference" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    
    */




    return 0;
}