#include "log.h"

using namespace std;

int main() {
	Log log(Log::putGeneralToConsoleAndFile, Log::putWarningToConsoleAndFile, Log::putErrorToConsoleAndFile, Log::putSuccessToConsoleAndFile, Log::putStateToConsoleAndFile, Log::putLocationToConsoleAndFile);
	log(Log::general, "testing a general log");
}