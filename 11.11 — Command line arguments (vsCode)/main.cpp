#include <iostream>

int main()
{
    std::cout << "Hello World" << '\n';

    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "The need for command line arguments" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    As you learned lesson 0.4 -- introduction to development, when you compile and link your program, the output is an 
    executable file. When a program is run, execution starts at the top of the function called main(). Up to this point, 
    we’ve declared main like this:

    int main()

    Notice that this version of main() takes no parameters. However, many programs need some kind of input to work with. 
    For example, let’s say you were writing a program called Thumbnail that read in an image file, and then produced a 
    thumbnail (a smaller version of the image). How would Thumbnail know which image to read and process? The user has 
    to have some way of telling the program which file to open. To do this, you might take this approach:

    // Program: Thumbnail
    #include <iostream>
    #include <string>

    int main()
    {
        std::cout << "Please enter an image filename to create a thumbnail for: ";
        std::string filename{};
        std::cin >> filename;

        // open image file
        // create thumbnail
        // output thumbnail
    }

    However, there is a potential problem with this approach. Every time the program is run, the program will wait for 
    the user to enter input. This may not be a problem if you’re manually running this program once from the command line. 
    But it is problematic in other cases, such as when you want to run this program on many files, or have this program run 
    by another program.

    Let’s look into these cases further.

    Consider the case where you want to create thumbnails for all the image files in a given directory. How would you do 
    that? You could run this program as many times as there are images in the directory, typing out each filename by hand. 
    However, if there were hundreds of images, this could take all day! A good solution here would be to write a program 
    that loops through each filename in the directory, calling Thumbnail once for each file.

    Now consider the case where you’re running a website, and you want to have your website create a Thumbnail every time a 
    user uploads an image to your website. This program isn’t set up to accept input from the web, so how would the uploader 
    enter a filename in this case? A good solution here would be to have your web server call Thumbnail automatically after 
    upload.

    In both of these cases, we really need a way for an external program to pass in the filename as input to our Thumbnail 
    program when Thumbnail is launched, rather than having Thumbnail wait for the user to enter the filename after it 
    has started.

    Command line arguments are optional string arguments that are passed by the operating system to the program when 
    it is launched. The program can then use them as input (or ignore them). Much like function parameters provide a 
    way for a function to provide inputs to another function, command line arguments provide a way for people or programs 
    to provide inputs to a program.
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Passing command line arguments" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*

    */

    return 0;
}