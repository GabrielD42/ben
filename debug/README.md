# C++ Debug Utilities

these are a few simple C++ classes that I find useful for squashing bugs.

## Log

`Log` is useful for outputting information to both a log file as well as to the terminal. It has a very simple interface, with only a constructor and an overloaded `operator()`. It is extremely configurable because it defines a handful of different message types, and allows where they output to be set individually. 

### Message Types

At the moment, there are 6 output types:

* __general__: general output format. when in doubt, use this type

* __warning__: if something strange has happened that can be recovered from, such as receiving a null parameter, use this type to complain about it

* __error__: use this if something has gone seriously wrong. should never be disabled. exceptions should complain by logging an error

* __success__: if some test or check was passed, this would be the format to use

* __state__: useful for outputting the value of variables for debugging purposes

* __location__: useful for outputting the current location of program flow for debugging purposes

### Usage

Here is a simple usage example:

```
#include "log.h"

using namespace std;

int main() {
	Log log(Log::putGeneralToConsole, Log::putWarningToFile,
		Log::putErrorToConsoleAndFile, Log::putSuccessToConsole,
		Log::putStateToNone, Log::putLocationToNone);
	log(Log::error, "this is an error!");
	log("this is a general message");
}
``` 