#ifndef LOG_H
#define LOG_H

#include <string>

using namespace std;

/**
 * @brief Allows programs to log relevant information
 *
 * This class is a functor. Every class should have a private Log object and use it to optionally output as much information as possible, but turn of the unimportant parts by default.
 * Each type of log information can be output to the console, to a log file, both or neither.
 * There are several different output types:
 * * __general__: general output format. when in doubt, use this type
 * * __warning__: if something strange has happened that can be recovered from, such as receiving a null parameter, use this type to complain about it
 * * __error__: use this if something has gone seriously wrong. should never be disabled. exceptions should complain by logging an error
 * * __success__: if some test or check was passed, this would be the format to use
 * * __state__: useful for outputting the value of variables for debugging purposes
 * * __location__: useful for outputting the current location of program flow for debugging purposes
 */
class Log {
	public:
		/**
		 * @brief used to set where log information of type general should be output to
		 *
		 * general is the general output format. when in doubt, use this type
		 */
		enum outputGeneral {
			putGeneralToConsole,
			putGeneralToFile,
			putGeneralToConsoleAndFile,
			putGeneralToNowhere
		};
		/**
		 * @brief used to set where log information of type warning should be output to
		 *
		 * if something strange has happened that can be recovered from, such as receiving a null parameter, use a warning to complain about it
		 */
		enum outputWarning {
			putWarningToConsole,
			putWarningToFile,
			putWarningToConsoleAndFile,
			putWarningToNowhere
		};
		/**
		 * @brief used to set where log information of type error should be output to
		 *
		 * use an error log if something has gone seriously wrong. should never be disabled. exceptions should complain by logging an error
		 */
		enum outputError {
			putErrorToConsole,
			putErrorToFile,
			putErrorToConsoleAndFile,
			putErrorToNowhere
		};
		/**
		 * @brief used to set where log information of type success should be output to
		 *
		 * a success should be logged if some test or check was passed
		 */
		enum outputSuccess {
			putSuccessToConsole,
			putSuccessToFile,
			putSuccessToConsoleAndFile,
			putSuccessToNowhere
		};
		/**
		 * @brief used to set where log information of type state should be output to
		 *
		 * the state output format is useful for outputting the value of variables for debugging purposes
		 */
		enum outputState {
			putStateToConsole,
			putStateToFile,
			putStateToConsoleAndFile,
			putStateToNowhere
		};
		/**
		 * @brief used to set where log information of type location should be output to
		 *
		 * the location output type is useful for outputting the current location of program flow for debugging purposes
		 */
		enum outputLocation {
			putLocationToConsole,
			putLocationToFile,
			putLocationToConsoleAndFile,
			putLocationToNowhere
		};

		/**
		 * @brief creates a new Log object
		 *
		 * every class should have exactly one Log object to output to so that logging can be set on a per class basis.
		 *
		 * @param[in] tempOutputGeneral where a general message will be logged to
		 * @param[in] tempOutputWarning where a warning message will be logged to
		 * @param[in] tempOutputError where a error message will be logged to
		 * @param[in] tempOutputSuccess where a success message will be logged to
		 * @param[in] tempOutputState where a state message will be logged to
		 * @param[in] tempOutputLocation where a location message will be logged to
		 */
		Log(outputGeneral tempOutputGeneral, outputWarning tempOutputWarning, outputError tempOutputError, outputSuccess tempOutputSuccess, outputState tempOutputState, outputLocation tempOutputLocation);

		/**
		 * @brief the different log formats
		 *
		 * * __general__: general output format. when in doubt, use this type
		 * * __warning__: if something strange has happened that can be recovered from, such as receiving a null parameter, use this type to complain about it
		 * * __error__: use this if something has gone seriously wrong. should never be disabled. exceptions should complain by logging an error
		 * * __success__: if some test or check was passed, this would be the format to use
		 * * __state__: useful for outputting the value of variables for debugging purposes
		 * * __location__: useful for outputting the current location of program flow for debugging purposes
		 */
		enum outputTypes {
			general,
			warning,
			error,
			success,
			state,
			location
		};

		/**
		 * @brief log something
		 *
		 * this function allows a status of a certain type to be logged.
		 *
		 * @param[in] whatType the type of message is to be logged
		 * @param[in] message the message to be logged
		 */
		void operator()(outputTypes whatType, string message);

		/**
		 * @brief log a general message
		 *
		 * this overloaded version always logs a general message.
		 * this convenience function exists since that is the most common message type.
		 *
		 * @param[in] message the message to be logged
		 */
		void operator()(string message);

		~Log();

	private:
		enum output {
			toConsole,
			toFile,
			toConsoleAndFile,
			toNowhere
		};

		output outputToWhere[6];
	};

#endif