#include <iostream>
#include <cmath> // for std::pow(a, b);
#include <random> // for std::mt19937
#include <ctime> // for std::time
#include <vector>
#include <algorithm> // for std::find // std::min_elements

void printStack(const std::vector<double>& stack)
{
	for (auto element : stack)
		std::cout << element << ' ';
	std::cout << "(cap " << stack.capacity() << " length " << stack.size() << ")\n";
}

int main()
{
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Question #3" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    We’re going to write a little game with square numbers (numbers which can be created by multiplying an integer 
    with itself (1, 4, 9, 16, 25, …)).

    Ask the user to input 2 numbers, the first is the square root of the number to start at, the second is the amount 
    of numbers to generate. Generate a random integer from 2 to 4, and square numbers in the range that was chosen by 
    the user. Multiply each square number by the random number. You can assume that the user enters valid numbers.

    The user has to calculate which numbers have been generated. The program checks if the user guessed correctly 
    and removes the guessed number from the list. If the user guessed wrong, the game is over and the program prints 
    the number that was closest to the user’s final guess, but only if the final guess was not off by more than 4.

    Here are a couple of sample sessions to give you a better understanding of how the game works:

    Start where? 4
    How many? 8
    I generated 8 square numbers. Do you know what each number is after multiplying it by 2?
    > 32
    Nice! 7 number(s) left.
    > 72
    Nice! 6 number(s) left.
    > 50
    Nice! 5 number(s) left.
    > 126
    126 is wrong! Try 128 next time.

        The user chose to start at 4 and wants to play with 8 numbers.
        Each square number will be multiplied by 2. 2 was randomly chosen by the program.
        The program generates 8 square numbers, starting with 4 as a base:
        16 25 36 49 64 81 100 121
        But each number is multiplied by 2, so we get:
        32 50 72 98 128 162 200 242
        Now the user starts to guess. The order in which in guesses are entered doesn’t matter.
        32 is in the list.
        72 is in the list.
        126 is not in the list, the user loses. There is a number in the list (128) that is not more then 4 away 
        from the user’s guess, so that number is printed.

    Start where? 1
    How many? 3
    I generated 3 square numbers. Do you know what each number is after multiplying it by 4?
    > 4
    Nice! 2 numbers left.
    > 16
    Nice! 1 numbers left.
    > 36
    Nice! You found all numbers, good job!

        The user chose to start at 1 and wants to play with 3 numbers.
        Each square number will be multiplied by 4.
        The program generates these square numbers:
        1 4 9
        Multiplied by 4
        4 16 36
        The user guesses all numbers correctly and wins the game.

    Start where? 2
    How many? 2
    I generated 2 square numbers. Do you know what each number is after multiplying it by 4?
    > 21
    21 is wrong!

        The user chose to start at 2 and wants to play with 2 numbers.
        Each square number will be multiplied by 4.
        The program generates these numbers:
        16 36
        The user guesses 21 and loses. 21 is not close enough to any of the remaining numbers, so no number is printed.

    Use std::find (10.25 -- Introduction to standard library algorithms) to search for a number in the list.
    Use std::vector::erase to remove an element, e.g.

    auto found{ std::find( ... ) };

    // Make sure the element was found

    myVector.erase(found);

    Use std::min_element and a lambda to find the number closest to the user’s guess. std::min_element works 
    analogous to std::max_element from the previous quiz.
    */

    std::cout << "Start where? ";
    int first_int{};
    std::cin >> first_int;
    
    std::cout << "How many? ";
    int second_int{};
    std::cin >> second_int;

    // Initialize our mersenne twister with a random seed based on the clock
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    // Create a reusable random number generator that generates uniform numbers between 2 and 4
	std::uniform_int_distribution die{ 2, 4 };
	// If your compiler doesn't support C++17, use this instead
	// std::uniform_int_distribution<> die{ 2, 4 };

    int our_random{ die(mersenne) };

    std::cout << "I generated " << second_int << " square numbers. Do you know what each number is after multiplying it by " <<
                our_random << "?\n";

    std::vector<double> stack{};
    stack.reserve(second_int);

    for(int i{ 0 }; i < second_int; ++i)
    {
        double x{ (static_cast<double>(first_int) + i) * (static_cast<double>(first_int) + i) };
        double y{ x * our_random };
        stack.push_back(y);
    }

    printStack(stack);

    double choice{};

    for(int i{ second_int }; i != 0; --i)
    {
        std::cout << '>';
        std::cin >> choice;
        auto found{ std::find(stack.begin(), stack.end(), choice) };

        if(i < 2)
        {
            std::cout << "Nice! You found all numbers, good job!\n";
            break;
        }

        if(found != stack.end())
        { 
            stack.erase(found);
            std::cout << "Nice! " << i - 1 << " numbers left.\n";
        }
        else
        {
            std::cout << choice << " is wrong!\n";
        }
    }
        
    return 0;
}