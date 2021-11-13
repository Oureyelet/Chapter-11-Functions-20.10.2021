#include <iostream>
#include <string_view>
#include <algorithm>
#include <array>
#include <functional>

//functions prototypes:
static bool containsNut(std::string_view str);

int main()
{
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Introduction to lambdas" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Consider this snippet of code that we introduced in lesson 10.25 -- Introduction to standard library algorithms:
    */
    constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    // std::find_if takes a pointer to a function
    const auto found{ std::find_if(arr.begin(), arr.end(), containsNut) };

    if(found == arr.end())
    {
        std::cout << "No nuts\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }

    /*
    This code searches through an array of strings looking for the first element that contains the substring “nut”. 
    Thus, it produces the result:

    Found walnut

    And while it works, it could be improved.

    The root of the issue here is that std::find_if requires that we pass it a function pointer. Because of that, 
    we are forced to define a function that’s only going to be used once, that must be given a name, and that must 
    be put in the global scope (because functions can’t be nested!). The function is also so short, it’s almost easier 
    to discern what it does from the one line of code than from the name and comments.
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Lambdas to the rescue" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    A lambda expression (also called a lambda or closure) allows us to define an anonymous function inside another function. 
    The nesting is important, as it allows us both to avoid namespace naming pollution, and to define the function as 
    close to where it is used as possible (providing additional context).

    The syntax for lambdas is one of the weirder things in C++, and takes a bit of getting used to. Lambdas take the form:

    [ captureClause ] ( parameters ) -> returnType
    {
        statements;
    }

    The capture clause and parameters can both be empty if they are not needed.

    The return type is optional, and if omitted, auto will be assumed (thus using type inference used to determine 
    the return type). While we previously noted that type inference for function return types should be avoided, 
    in this context, it’s fine to use (because these functions are typically so trivial).

    Also note that lambdas have no name, so we don’t need to provide one.
    */

    []() {};// defines a lambda with no captures, no parameters, and no return type

    //Let’s rewrite the above example using a lambda:

    constexpr std::array<std::string_view, 4> arr2{  "apple", "banana", "walnut", "lemon"  };

    // Define the function right where we use it.
    const auto found2{ std::find_if(arr2.begin(), arr2.end(),
                                [](std::string_view str) // here's our lambda, no capture clause
                                {
                                    return (str.find("nut") != std::string_view::npos);
                                }) };
    
    if(found2 == arr2.end())
    {
        std::cout << "No nuts\n";
    }
    else
    {
        std::cout << "Found " << *found2 << '\n';
    }

    /*
    This works just like the function pointer case, and produces an identical result:

    Found walnut

    Note how similar our lambda is to our containsNut function. They both have identical parameters and function bodies. 
    The lambda has no capture clause (we’ll explain what a capture clause is in the next lesson) because it doesn’t need 
    one. And we’ve omitted the trailing return type in the lambda (for conciseness), but since operator!= returns a bool, 
    our lambda will return a bool too.
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Type of a lambda" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In the above example, we defined a lambda right where it was needed. This use of a lambda is sometimes called a 
    function literal.

    However, writing a lambda in the same line as it’s used can sometimes make code harder to read. Much like we can 
    initialize a variable with a literal value (or a function pointer) for use later, we can also initialize a lambda 
    variable with a lambda definition and then use it later. A named lambda along with a good function name can make 
    code easier to read.

    For example, in the following snippet, we’re using std::all_of to check if all elements of an array are even:
    
    // Bad: We have to read the lambda to understand what's happening.
    return std::all_of(array.begin(), array.end(), [](int i){ return ((i % 2) == 0); });
    
    We can improve the readability of this as follows:
    */
    std::array<int, 10> array{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    auto isEven{
        [](int i)
        {
            return (i % 2 == 0);
        }
    };
    //return std::all_of(array.begin(), array.end(), isEven);

    /*
    Note how well the last line reads: “return whether all of the elements in the array are even”

    But what is the type of lambda isEven?

    As it turns out, lambdas don’t have a type that we can explicitly use. When we write a lambda, the compiler 
    generates a unique type just for the lambda that is not exposed to us.
    */

    /*
    For advanced readers:

    In actuality, lambdas aren’t functions (which is part of how they avoid the limitation of C++ not 
    supporting nested functions). They’re a special kind of object called a functor. Functors are objects 
    that contain an overloaded operator() that make them callable like a function.
    */

    /*
    Although we don’t know the type of a lambda, there are several ways of storing a lambda for use 
    post-definition. If the lambda has an empty capture clause, we can use a regular function pointer. 
    In the next lesson, we introduce lambda captures, a function pointer won’t work anymore at that point. 
    However, std::function can be used for lambdas even if they are capturing something.
    */

    // A regular function pointer. Only works with an empty capture clause.
    double (*addNumbers1)(double, double){
        [](double a, double b){
            return (a + b);
        }
    };
    std::cout << addNumbers1(7.7, 77.7) << '\n';

    // Using std::function. The lambda could have a non-empty capture clause (Next lesson).
    std::function addNumbers2 { // note: pre-C++17, use std::function<double(double, double)> instead
        [](double a, double b){
            return (a + b);
        }
    };
    std::cout << addNumbers2(777, 777) << '\n';

    auto addNumbers3{
        [](double a, double b){
            return (a + b);
        }
    };
    std::cout << addNumbers3(1234, 4321) << '\n';

    /*
    The only way of using the lambda’s actual type is by means of auto. auto also has the benefit of having no 
    overhead compared to std::function.

    Unfortunately, we can’t always use auto. In cases where the actual lambda is unknown (e.g. because we’re passing a 
    lambda to a function as a parameter and the caller determines what lambda will be passed in), we can’t use auto 
    without compromises. In such cases, std::function can be used.
    */
    



    return 0;
}

static bool containsNut(std::string_view str) // static means internal linkage in this context
{
  // std::string_view::find returns std::string_view::npos, which is a very large number,
  // if it doesn't find the substring.
  // Otherwise it returns the index where the substring occurs in str.
  return (str.find("nut") != std::string_view::npos);
}