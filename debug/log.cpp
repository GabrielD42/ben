#include "log.h"
#include <iostream>

Log::Log(outputGeneral tempOutputGeneral, outputWarning tempOutputWarning, outputError tempOutputError, outputSuccess tempOutputSuccess, outputState tempOutputState, outputLocation tempOutputLocation) {
	outputToWhere[general] = static_cast<output>(tempOutputGeneral);
	outputToWhere[warning] = static_cast<output>(tempOutputWarning);
	outputToWhere[error] = static_cast<output>(tempOutputError);
	outputToWhere[success] = static_cast<output>(tempOutputSuccess);
	outputToWhere[state] = static_cast<output>(tempOutputState);
	outputToWhere[location] = static_cast<output>(tempOutputLocation);
}

void Log::operator()(outputTypes whatType, string message) {
	if(outputToWhere[whatType] == toConsole || outputToWhere[whatType] == toConsoleAndFile) {
		cout << message << endl;
	}
}

void Log::operator()(string message) {
	operator()(general, message);
}

Log::~Log() {
	// nothing to see here, move along
}