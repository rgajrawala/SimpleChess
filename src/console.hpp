/*
 *  console.hpp
 *  SimpleChess
 *
 *  Created by Ronak Gajrawala on 12/01/13.
 *  Copyright (c) 2013 Ronak Gajrawala. All rights reserved.
 */

#ifndef SimpleChess_console_hpp
#define SimpleChess_console_hpp

namespace SimpleChess {
	/**
	 * The Console class.
	 * This is the class for anything to do with the console.
	 */
	namespace Console {
		/**
		 * Returns the file name from the path.
		 * @param file The full file path.
		 * @return Returns the file name from the path.
		 */
		std::string ParseFileName(const std::string);

		/**
		 * Simple log function.
		 * @see printf
		 * @param format Format to be printed.
		 * @param ... Variables to be formatted.
		 */
		void Log(const char*, ...);

		/**
		 * Complex log function that formats the line like: file:line [function] format\n.
		 * @see printf
		 * @param line The line number you are calling the function from (__LINE__).
		 * @param file The file you are calling the function from (__FILE__).
		 * @param function The function you are calling the function from (__func__).
		 * @param format Format to be printed.
		 * @param ... Variables to be formatted.
		 */
		void Log(const unsigned short, const char*, const char*, const char*, ...);
		#define FLog(format, ...) SimpleChess::Console::Log(__LINE__, __FILE__, __func__, format, ##__VA_ARGS__)

		/**
		 * Waits for the user to press the ENTER (RETURN) key.
		 * @see getchar
		 */
		void Pause(void);

		/**
		 * Complex error function that formats the line like: file:line [function] format\n.
		 * @see Log
		 * @see printf
		 * @param line The line number you are calling the function from (__LINE__).
		 * @param file The file you are calling the function from (__FILE__).
		 * @param function The function you are calling the function from (__func__).
		 * @param leave If true, calls exit also.
		 * @param format Format to be printed.
		 * @param ... Variables to be formatted.
		 */
		void Error(const unsigned short, const char*, const char*, const bool, const char*, ...);
		#define FError(leave, format, ...) SimpleChess::Console::Error(__LINE__, __FILE__, __func__, leave, format, ##__VA_ARGS__)
	};
};

////////// SOURCE //////////

std::string SimpleChess::Console::ParseFileName(const std::string file) {
	unsigned long found = file.find_last_of("\\/");
	return file.substr(found + 1);
}

void SimpleChess::Console::Log(const char* format, ...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

void SimpleChess::Console::Log(const unsigned short line, const char* file, const char* function, const char* format, ...) {
	va_list args;
	va_start(args, format);
	Log("%11s:%-4d [%s] ", ParseFileName(file).c_str(), line, function);
	vprintf(format, args);
	if (format[strlen(format) - 1] != '\n') {
		putchar('\n');
	}
	va_end(args);
}

void SimpleChess::Console::Pause(void) {
	Log("Press the \'RETURN\' key to continue . . . ");
	getchar();
	fflush(stdin);
}

void SimpleChess::Console::Error(const unsigned short line, const char* file, const char* function, const bool leave, const char* format, ...) {
	va_list args;
	va_start(args, format);
	Log("%11s:%-4d [%s] ", ParseFileName(file).c_str(), line, function);
	vfprintf(stderr, format, args);
	if (format[strlen(format) - 1] != '\n') {
		fputc('\n', stderr);
	}

	va_end(args);
	if (leave) {
		exit(1);
	}
}

#endif
