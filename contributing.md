Note: this file uses Github Flavored Markdown, so please view on Github.

#What You Need to Know About this Project
Note: this file (and all documentation, including the comments, are written using [Markdown](https://help.github.com/articles/markdown-basics))

##Formating
With more than one person working on this now and stuff, I figured I should establish a coding standard. Feel free to make suggestions.

```C++
if(!(3 == 5)) {
	int theAnswer = 42; // the answer to life, the universe and everything
	}
```

This sample code demonstrates most of the guidelines:
* No spaces around parentheses
* Space around binary operators (such as ==, +, -, etc.)
* No spaces around unary operators (such as !, *, &, etc.)
* Opening braces ({) come 1 space after last part of declaration
* Closing braces ({) go on their own line at the same indentation level as the block they are closing
* all names of objects, classes, functions and variables should be in camel-case (first letter of every word capitalized), no underscores or dashes
	* for variables and functions, the first letter is lowercase
	* for objects and classes, the first letter is capitalized
* Macros (`#define`) and constants (`const`) are declared in all caps.
* comments come 1 space after the relevant line
* Use the tab character, not spaces

##Naming Conventions
For the most part, simply name stuff what makes the most sense. A few restrictions:
* include guards must be named in all caps `FILE_NAME_H`, with underscores to seperate words
* arguments being passed to methods simply to be used to set a corisponding variable in the class should be named `tempVariableName`, where `variableName` is the name of the variable in the class that will be set.
* functions used to change data in a class should be called `setSomething`, where `Something` describes what is to be set
* functions used to access data in a class should be called `getSomething`, where `Something` describes what is to be returned

##Comments
The majority of comments should be of the `//` variety, as specified in the formatting section. place them after any confusing line, or to clarify an unclear name.

Document all functions and classes! No need to document variables. We are using a documentation program called Doxygen, which generates documentation using comments as specified in doxygenConfig and as used in deploy.sh. Doxygen requires a specific style of comments, as follows:

```C++
/**
 * this is a description about what this class/function does. this description supports Markdown
 *
 * @param parameterName this is a description about what a parameter (argument) is for
 * @param another describe all parameters
 *
 * @return what this function returns (exclude this line if it returns nothing)
 */
 ```

All documentation should be placed in the .h file whenever possible.

The documentation can be viewed by opening a browser to file:///path/to/ben/docs/index.html


##Coding Style
Each class should be divided into 2 files, a .h and .cpp, with a proper [include guard](http://faculty.cs.niu.edu/~mcmahon/CS241/c241man/node90.html) in the .h file. File names should follow the format classNameWithFirstCharacterLowercase.extension, and include guard macro names should be `CLASS_NAME_WITH_UNDERSCORES_IN_ALL_CAPS_H` (always include the `_H`). The one exception to this rule are template classes, in which case put what would normally be in .cpp below the contents of the .h, with the include guard around the whole file.

Do not make unnecessary classes, but if it is likely that a more generalized version of the class will be useful, it is easier to make them both then later do the separation between generalization and specification.

In most cases, memory is more expensive then time, so it is encouraged to recalculate some numbers in order to save space.

##Git and Github
We are using Git and Github to manage this project. Git is a command line versioning tool to keep track of changes, and Github is a hosted server to store these files on. For the most part, the deploy script should take care of the messy details, but I suggest going through [this](https://try.github.io/levels/1/challenges/1) introduction to git.
To learn more about git read [this](http://git-scm.com/book). The only thing it is mandatory to to know to use this project is how to resolve conflicts. So after going through the basic [tutorial](https://try.github.io/levels/1/challenges/1), read at least [this](http://git-scm.com/book/en/Git-Branching-Basic-Branching-and-Merging) page.

##Deploying
The deployment script (deploy.sh) takes two options:
the first is a flag, indicating which Raspberry Pi the script should attempt to download code onto. The current options are
* `-g` for Gabriel's pi
* `-k` for Keane's
* `-n` for no Pi

The second option is the commit message for git. It should be enclosed in quotes.

The script does the following (in order)
* generates updated documentation
* commits changes to Github
* if specified, ssh's into a Raspberry Pi, and commands it to pull down new changes from Github using the pullChanges.sh script, then compiles the new code using the Makefile (see the next section for more on that)

##Linking and Compiling Code
I have chosen to use Makefiles to compile code. A Makefile describes how an executable depends on different files, and how each of those files in turn how made. One executable file is made from a number of object files being combined. Each object file in turn is made of one .cpp file and any other files it includes (the accompanying .h file at a minimum). You will need to modify the Makefile whenever you add or remove files. You should be able to do that simply by copying and pasting what is already there. To learn more about how they work read through the [manual](https://www.gnu.org/software/make/manual/html_node/index.html).

##What You Need to Contribute to this Project
Besides the obvious (computer, intelligence), you need:
* the linux operating system
* git (`sudo apt-get install git`)
* make (`sudo apt-get install make`)
* g++ (`sudo apt-get install g++`)
* a decent text editor (I suggest [Sublime Text](http://www.sublimetext.com/))
	* if you get Sublime, some useful packages are:
		* [Package Control](https://sublime.wbond.net/) is absolutely necessary. Installing it will allow you to install all other packages from inside Sublime.
		* Diff for git comparisons
		* DoxyDoc for documenting C++
		* Git for running git command from inside sublime
		* GitGutter for viewing changes this commit
		* My favorite theme is Minimal, but that's a personal preference

a Raspberry Pi is needed to test code, because that's the only place where the C++ hardware library will compile. Your pi will need:
* an Internet connection
* git (`sudo apt-get install git`)
* make (`sudo apt-get install make`)
* g++ (`sudo apt-get install g++`)
* [wiringPi](http://wiringpi.com/)
for convenience, give it a static IP address then add a flag to the deployment script.

Good luck!