#include <iostream>
#include <algorithm>
#include <array>
#include <string_view>
#include <string>
#include <vector>

struct Car
{
    std::string make{};
    std::string model{};
};

struct CEnemy
{

};

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
    Much like functions can change the value of arguments passed by reference, we can also capture variables by reference 
    to allow our lambda to affect the value of the argument.

    To capture a variable by reference, we prepend an ampersand (&) to the variable name in the capture. Unlike variables 
    that are captured by value, variables that are captured by reference are non-const, unless the variable they’re capturing 
    is const. Capture by reference should be preferred over capture by value whenever you would normally prefer passing an 
    argument to a function by reference (e.g. for non-fundamental types).

    Here’s the above code with ammo captured by reference:
    */
    /*
    auto shoot{
    // We don't need mutable anymore
    [&ammo]() { // &ammo means ammo is captured by reference
      // Changes to ammo will affect main's ammo
      --ammo;
    */

    //Now, let’s use a reference capture to count how many comparisons std::sort makes when it sorts an array:

    std::array<Car, 3> arr_car{ { { "Volkswagen", "Golf" },
                                  { "Toyota", "Corolla" },
                                  { "Honda", "Civic" } } };

    int comparisons{ 0 };

    std::sort(arr_car.begin(), arr_car.end(),
                [&comparisons](const Car& a, const Car& b){
                    ++comparisons;
                    return (a.make < b.make);
                });

    std::cout << "Comparisons " << comparisons << '\n';

    for(const auto& car : arr_car )
    {
        std::cout << car.make << ' ' << car.model << '\n';
    }


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Capturing multiple variables" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Multiple variables can be captured by separating them with a comma. 
    This can include a mix of variables captured by value or by reference:
    */
    int health{ 33 };
    int armor{ 100 };

    std::vector<CEnemy> enemies{};

    [health, armor, &enemies](){};


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Default captures" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Having to explicitly list the variables you want to capture can be burdensome. If you modify your lambda, 
    you may forget to add or remove captured variables. Fortunately, we can enlist the compiler’s help to auto-generate a 
    list of variables we need to capture.

    A default capture (also called a capture-default) captures all variables that are mentioned in the lambda. 
    Variables not mentioned in the lambda are not captured if a default capture is used.

    To capture all used variables by value, use a capture value of =.
    To capture all used variables by reference, use a capture value of &.

    Here’s an example of using a default capture by value:
    */
    std::array areas{ 100, 25, 121, 40, 56 };

    int width{};
    int lenght{};

    std::cout << "Enter width and height: ";
    std::cin >> width >> lenght;

    auto found_area{ std::find_if(areas.begin(), areas.end(), 
                            [=] (int knownArea) { // will default capture width and height by value
                                return (width * lenght == knownArea); // because they're mentioned here
                            }) };

    if(found_area == areas.end())
    {
        std::cout << "I don't know this area :(\n";
    }
    else
    {
        std::cout << "Area found :)\n";
    }

    /*
    Default captures can be mixed with normal captures. We can capture some variables by value and others by 
    reference, but each variable can only be captured once.

    int health{ 33 };
    int armor{ 100 };
    std::vector<CEnemy> enemies{};

    // Capture health and armor by value, and enemies by reference.
    [health, armor, &enemies](){};

    // Capture enemies by reference and everything else by value.
    [=, &enemies](){};

    // Capture armor by value and everything else by reference.
    [&, armor](){};

    // Illegal, we already said we want to capture everything by reference.
    [&, &armor](){};

    // Illegal, we already said we want to capture everything by value.
    [=, armor](){};

    // Illegal, armor appears twice.
    [armor, &health, &armor](){};

    // Illegal, the default capture has to be the first element in the capture group.
    [armor, &](){};
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Defining new variables in the lambda-capture" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Sometimes we want to capture a variable with a slight modification or declare a new variable that is only 
    visible in the scope of the lambda. We can do so by defining a variable in the lambda-capture without specifying its type.
    */
    std::array areas_007{ 100, 25, 121, 40, 56 };

    int width_007{};
    int lenght_007{};

    std::cout << "Enter width and height: ";
    std::cin >> width_007 >> lenght_007;

    // We store areas, but the user entered width and height.
    // We need to calculate the area before we can search for it.
    auto found_area_007{ std::find_if(areas_007.begin(), areas_007.end(), 
                            // Declare a new variable that's visible only to the lambda.
                           // The type of userArea is automatically deduced to int.
                            [userArea(width_007 * lenght_007)] (int knownArea_007) { 
                                return (userArea == knownArea_007);
                            }) };

    if(found_area_007 == areas_007.end())
    {
        std::cout << "I don't know this area :(\n";
    }
    else
    {
        std::cout << "Area found :)\n";
    }


    /*
    userArea will only be calculated once when the lambda is defined. The calculated area is stored in the lambda object 
    and is the same for every call. If a lambda is mutable and modifies a variable that was defined in the capture, the 
    original value will be overridden.

    Best practice

    Only initialize variables in the capture if their value is short and their type is obvious. Otherwise it’s best to 
    define the variable outside of the lambda and capture it.
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Dangling captured variables" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    https://www.learncpp.com/cpp-tutorial/lambda-captures/
    */

    
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Unintended copies of mutable lambdas" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Because lambdas are objects, they can be copied. In some cases, this can cause problems. Consider the following code:
    */  
    int i{ 0 };

    // Create a new lambda named count
    auto count{ [i]() mutable {
        std::cout << ++i << '\n';
    } };

    count();// invoke count

    auto otherCount{ count };// create a copy of count

    // invoke both count and the copy
    count();
    otherCount();

    /*
    Rather than printing 1, 2, 3, the code prints 2 twice. When we created otherCount as a copy of count, we 
    created a copy of count in its current state. count‘s i was 1, so otherCount‘s i is 1 as well. Since otherCount 
    is a copy of count, they each have their own i.

    If we want to keep our incremenntation we need to change for references captures:

     auto count{ [&i]() {
        std::cout << ++i << '\n';
    } };
    */

    return 0;
}