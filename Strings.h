#ifndef STRINGS_H
#define STRINGS_H
#include <string>

// STANDARD ALERTS
const std::string alert1InvalidMovie = " is INVALID. Would you like to try again?";
const std::string alert2InvalidMovies = " are both INVALID. Would you like to try again?";
const std::string alertError = "ERROR: ";
const std::string alertFileName1 = "Cannot open file \"";
const std::string alertFileName2 = "\"!\nPlease provide a text file as input, or enter \"Q\" to exit the application.";
const std::string alertInvalidInput = "INVALID INPUT \nPlease Try Again...";
const std::string alertMissingActor = " not in database! \nPlease ensure that you typed the actor's name exactly.";
const std::string alertMissingMovie = " not in database! \nPlease ensure that you typed the movie's title exactly.";
const std::string alertNoActors = "No actors whom are only in ";
const std::string alterTextFile = " requires a text file to function.";
const std::string alertWarning = "WARNING: ";

// STANDARD PROMPTS...
const std::string promptActorName = "Please enter an Actor's name. \n";
const std::string promptApplicationExplanation = "This application accesses a database of MOVIES and ACTORS, \nthen displays relevant information according to input from the user.";
const std::string promptBegin = "Press ENTER to begin...";
const std::string promptCheck = "\". Is that correct? \n";
const std::string promptCoactorSearch = "Searching for every co-actor for ";
const std::string promptContinue = "Press ENTER to continue...";
const std::string promptEntered = "You entered \" \n";
const std::string promptExit = "Press ENTER to exit...";
const std::string promptFirstMovie = "Please enter the first movie title: ";
const std::string promptGoodbye = "Have a good one! \n";
const std::string promptInDB = "Both movies exist within the database.";
const std::string promptInput = "INPUT: ";
const std::string promptInputMatches = "Your input matches the following two movies: \n";
const std::string promptMainMenuLine01 = "Please make a selection from the following menu... \n";
const std::string promptMainMenuLine02 = "1: Find ACTORS in MOVIES \n";
const std::string promptMainMenuLine03 = "2: FIND ACTORS and CO-ACTORS \n";
const std::string promptMainMenuLine04 = "Q: Exit the application \n";
const std::string promptMainMenu = ( promptMainMenuLine01 + promptMainMenuLine02 + promptMainMenuLine03 + promptMainMenuLine04 );
const std::string promptMenuLine01 = "Please make a selection from the following menu... \n";
const std::string promptMenuLine02 = "A: All actors whom are in EITHER movie \n";
const std::string promptMenuLine03 = "B: All actors whom are in EACH movie \n";
const std::string promptMenuLine04 = "C: All actors whom are in BOTH movies \n";
const std::string promptMenuLine05 = "O: All actors whom are in only ONE of the two movies \n";
const std::string promptMenuLine06 = "Q: Quit to main menu \n";
const std::string promptMenu = (promptMenuLine01 + promptMenuLine02 + promptMenuLine03 +
								promptMenuLine04 + promptMenuLine05 + promptMenuLine06 );
const std::string promptSearchActorInBoth = "Searching for every actor in both movies. \n";
const std::string promptSearchActorInEach = "Searching for every actor in each movie. \n";
const std::string promptSearchActorInEither = "Searching for every actor in either movie. \n";
const std::string promptSearchActorInOne = "Searching for actors whom are only in one movie. \n";
const std::string promptSecondMovie = "Please enter the second movie title: ";
const std::string promptTextFile = "Please provide a text file as input.";

// IOStream Utilities...
const std::string clearTerminal = "\033[2J\033[1;1H";	// Clears the LINUX terminal.

// INPUT CHECKS...
const std::string checkMainOption01 = "1";
const std::string checkMainOption02 = "2";
const std::string checkMenuOption01 = "A";
const std::string checkMenuOption02 = "B";
const std::string checkMenuOption03 = "C";
const std::string checkMenuOption04 = "O";
const std::string checkQuit = "Q";
const std::string checkYes = "Y";

#endif
