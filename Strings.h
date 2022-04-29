#ifndef STRINGS_H
#define STRINGS_H
#include <string>

// STANDARD ALERTS
const std::string alert1InvalidMovie = " is INVALID. Would you like to try again?";
const std::string alert2InvalidMovies = " are both INVALID. Would you like to try again?";
const std::string alertError = "ERROR: ";
const std::string alertInvalidInput = "INVALID INPUT \nPlease Try Again...";
const std::string alertMissingActor = " not in database! \nPlease ensure that you typed the actor's name exactly.";
const std::string alertMissingMovie = " not in database! \nPlease ensure that you typed the movie's title exactly.";
const std::string alertWarning = "WARNING: ";

// STANDARD PROMPTS...
const std::string promptContinue = "Press ENTER to continue...";
const std::string promptInput = "INPUT: ";

// IOStream Utilities...
const std::string clearTerminal = "\033[2J\033[1;1H";	// Clears the LINUX terminal.

#endif
