Note: this file uses Github Flavored Markdown, so please view on Github.

#Style Guide and Other Relevant Information
With more than one person working on this now and stuff, I figured I should establish a coding standard. Feel free to make suggestions.

Note: this file (and all documentation, including the comments, are written using [Markdown](https://help.github.com/articles/markdown-basics))

##Formating
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
Each class should be divided into 2 files, a .h and .cpp, with a proper [include guard](http://faculty.cs.niu.edu/~mcmahon/CS241/c241man/node90.html) in the .h file. File names should follow the format classNameWithFirstCharacterLowercase.extension, and include guard macro names should be CLASS_NAME_WITH_UNDERSCORES_IN_ALL_CAPS_H (always include the _H). The one exception to this rule are template classes, in which case put what would normally be in .cpp below the contents of the .h, with the include guard around the whole file.

Do not make unnecessary classes, but if it is likely that a more generalized version of the class will be useful, it is easier to make them both then later do the separation between generalization and specification.

In most cases, memory is more expensive then time, so it is encouraged to recalculate some numbers in order to save space.

##Git and Github
We are using Git and Github to manage this project. Git is a command line versioning tool to keep track of changes, and Github is a hosted server to store these files on. For the most part, the deploy script should take care of the messy details, but here are a few basic concepts and commands.

The actual version of the code is stored on the server. To begin, type `git clone https://github.com/GabrielD42/ben.git' to copy the code from the server onto the machine. When you want to start working, you run `git pull` to pull down all changes anyone else has made. Once you have made some changes if you run `git status` you can see what you have changed. Moving code back up to the server is a multi-step process. The first part is to add files to a staging area. The staging area is the place to put files that you want to upload. This is a useful feature in larger projects but redundant in our case. To do that, run `git add fileName`, or better yet, `git add --all`. The next step is to "commit" the changes. This marks a change on your local machine, but not on the remote server. To do this type `git commit", and a text editor will pop up to allow you to enter a commit message, which describes what you have changed since the last commit. The last step is to push the changes to the server by typing `git push`.

At some point during this process you may try to make changes only to find that someone else has changed the exact same part of the same file. In that case, git will give you a list of files where there are conflicts. You can view that list again by typing `git status`. Open those files and look for weird looking symbols such as "<<<<<<< HEAD (code) ======= (conflicting code) >>>>>>> something". In this case you must choose which is better, (code) or (conflicting code), delete everything else then run those command again.

To learn more about git read [this](http://git-scm.com/book).

Luckily for you, the deployment script does all this and more...

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
I have chosen to use Makefiles to compile code. A Makefile describes how an executable depends on different files, and how each of those files in turn how made. One executable file is made from a number of object files being combined. Each object file in turn is made of one .cpp file and any other files it includes (the accompanying .h file at a minimum).

Here is the current Makefile, with comments. As long as you understand enough to make changes when adding or removing files, its fine. `#` start comments
```
#declaring variables here. notice lists are space separated
#objects stores a list of all compiled files (all the .cpp's should be here with a .o extension)
objects = base.o main.o ping.o utils.o square.o
#templates stores a list of all header files containing template classes (they can't be compiled)
templates = node.h list.h

#this line says that the executable file "ping" depends on all the files listed in the objects and templates variables
ping: $(objects) $(templates)
	#this line states that to create the "ping" executable, you must run this command (these lines must be indented)
	g++ -o ping $(objects) $(templates) -lwiringPi
	rm $(objects)

#if it is noticed that ping has changed, the make command will then try to recompile all dependencies
base.o: base.cpp base.h
	g++ -c -o base.o base.cpp -lwiringPi

main.o: main.cpp main.h
	g++ -c -o main.o main.cpp -lwiringPi

ping.o: ping.cpp ping.h
	g++ -c -o ping.o ping.cpp -lwiringPi

utils.o: utils.cpp utils.h
	g++ -c -o utils.o utils.cpp -lwiringPi

square.o: square.cpp square.h
	g++ -c -o square.o square.cpp
```

the g++ command is the c++ compiler on linux. the `-c` option means only compile, don't link. The `-o` file says: output to the filename after this option. all files listed after that are used to compile. the `-lwiringPi` tells the compiler to use the special hardware library for the raspberry pi.

To use a Makefile simply type `make`.

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
for convenience, give it a static IP address then add a flag to the deployment script. Good luck!