#include <iostream>
#include <algorithm>
#include <array>
#include <string_view>
#include <string>

int main()
{
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Capture clauses and capture by value" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    https://www.learncpp.com/cpp-tutorial/lambda-captures/
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "The capture clause" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    The capture clause is used to (indirectly) give a lambda access to variables available in the surrounding scope that 
    it normally would not have access to. All we need to do is list the entities we want to access from within the lambda 
    as part of the capture clause. In this case, we want to give our lambda access to the value of variable search, so we 
    add it to the capture clause:
    */
    std::array<std::string_view, 4> arr{  "apple", "banana", "walnut", "lemon"  };

    std::cout << "search for: ";

    std::string search{};
    std::cin >> search;

    auto found{ std::find_if(arr.begin(), arr.end(), 
                            [search](std::string_view str)
                            {
                                return (str.find(search) != std::string_view::npos);
                            }
                             )};

    if(found == arr.end())
    {
        std::cout << "Not found\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }

    //The user can now search for an element of our array.



    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "So how do captures actually work?" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    While it might look like our lambda in the example above is directly accessing the value of main‘s search variable, 
    this is not the case. Lambdas might look like nested blocks, but they work slightly differently (and the distinction 
    is important).

    When a lambda definition is executed, for each variable that the lambda captures, a clone of that variable is made 
    (with an identical name) inside the lambda. These cloned variables are initialized from the outer scope variables of 
    the same name at this point.

    Thus, in the above example, when the lambda object is created, the lambda gets its own cloned variable named search. 
    This cloned search has the same value as main‘s search, so it behaves like we’re accessing main‘s search, but we’re not.

    While these cloned variable have the same name, they don’t necessarily have the same type as the original variable. 
    We’ll explore this in the upcoming sections of this lesson.

    Key insight

    The captured variables of a lambda are clones of the outer scope variables, not the actual variables.

    For advanced readers

    Although lambdas look like functions, they’re actually objects that can be called like functions (these are called 
    functors -- we’ll discuss how to create your own functors from scratch in a future lesson).

    When the compiler encounters a lambda definition, it creates a custom object definition for the lambda. Each captured 
    variable becomes a data member of the object.

    At runtime, when the lambda definition is encountered, the lambda object is instantiated, and the members of the 
    lambda are initialized at that point.
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Captures default to const value" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    By default, variables are captured by const value. This means when the lambda is created, the lambda captures a 
    constant copy of the outer scope variable, which means that the lambda is not allowed to modify them.
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Mutable capture by value" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    To allow modifications of variables that were captured by value, we can mark the lambda as mutable. 
    The mutable keyword in this context removes the const qualification from all variables captured by value.
    */
    int ammo{ 10 };

    auto shoot{ 
                [ammo] () mutable { 
                
                --ammo;

                std::cout << "Pew! " << ammo << " shot(s) left.\n";
                } 
    };

    shoot();
    shoot();
    shoot();
    shoot();

    std::cout << ammo << " shot(s) left\n";

    /*
    While this now compiles, there’s still a logic error. What happened? When the lambda was called, the lambda captured a 
    copy of ammo. When the lambda decremented ammo from 10 to 9 to 8, it decremented its own copy, not the original value.

    Note that the value of ammo is preserved across calls to the lambda!

    Warning:
    Because captured variables are members of the lambda object, their values are persisted across multiple calls to the lambda!
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Capture by reference" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*

    */

    return 0;
}