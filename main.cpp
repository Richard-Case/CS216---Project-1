/*
Richard Case
CS216 - Project 1

Requirements:
	- Utilize a provided text file to check the user's input and return results.
	- Allow partial matches between the user input and movie titles.
		- Not required for actor names, as names can be shared by different people.
		- Allowed to require strcit casing, as well.
	- Must use IMDB class header file, included as part of Lab 5.
	- Must accurately replicate the output from the sample file.
	  (http://www.cs.uky.edu/~yipike/CS216/PA1Sample_imdb.pdf)
*/

// Including...
#include <fstream>
#include <cctype>
#include <sstream>
#include "Analyze.h"

void WaitForUserContinue();
void WaitForUserExit();

int main(int numArgs, char* argPointers[])
{
	const int NECESSARY_NUM_ARGS = 2;
	std::string userInput = "";

	std::cout << clearTerminal
		<< promptApplicationExplanation << std::endl
		<< std::endl
		<< promptBegin;
	getline(std::cin, userInput);
	if (userInput.length() != 0) { userInput = ""; }

	// Ensure that the user provides a text file for input.
	std::string fileName = "";
	bool validFile = false;
	std::ifstream userFile;

    if (numArgs != NECESSARY_NUM_ARGS)
    {
        std::cout << clearTerminal
			<< alertWarning << argPointers[0] << alterTextFile << std::endl
			<< promptTextFile << std::endl
			<< promptInput;
			getline(std::cin, fileName);
    }
	else { fileName = argPointers[1]; }

	do
	{
	    userFile.open(fileName);

	    // Validate that the file provided can be opened.
	    if (!userFile.good())
	    {
	        std::cout << clearTerminal
				<< alertWarning << alertFileName1 << fileName << alertFileName2 << std::endl;
			getline(std::cin, fileName);

			if(toupper(fileName[0]) == 'Q' && toupper(fileName[1]) == 'U' && toupper(fileName[2]) == 'I' && toupper(fileName[3]) == 'T')
			{
				std::cout << clearTerminal;
				WaitForUserExit();
				return 1;
			}

			validFile = false;
	    }
		else { validFile = true; }
	} while (!validFile);

	// Instantiate a class to handle the text from the file.
    IMDB imdb;

    while (!userFile.eof())
    {
        std::string line, actorName, movieTitle;
        getline(userFile, line);

        // If actual text is contained in the line...
        if (line.length() != 0)
        {
            std::istringstream iss(line);
            getline(iss, actorName,';');

            // Extract any extra white space
            iss>>std::ws;

			// Generate a set of MOVIE TITLES associated with the ACTOR.
            std::set<std::string> movieTitles;
            while (getline(iss, movieTitle, ';'))
            {
                movieTitles.insert(movieTitle);

                // Extract any extra white space
                iss>>std::ws;
            }

            imdb.InsertActor(actorName, movieTitles);
        }
    }

	userFile.close();

	Analyze* analyze;
	bool exit = false;

	do
	{
		std::cout << clearTerminal
			<< promptMainMenu << std::endl
			<< promptInput;
		getline(std::cin, userInput);

		if(userInput == "1")
		{
			analyze->Movies(imdb);
            exit = false;
		}
		else if (userInput == "2")
		{
			analyze->Actors(imdb);
            exit = false;
		}
		else if (userInput[0] == 'Q' || userInput[0] == 'q')
		{
			exit = true;
		}
		else
		{
			std::cout << clearTerminal
				<< alertInvalidInput << std::endl;
			WaitForUserContinue();
			if (userInput.length() != 0) { userInput = ""; }
		}

	} while (!exit);

	WaitForUserExit();

    return 0;
}

void WaitForUserContinue()
{
	std::string passThrough = "";
	std::cout << promptContinue;
	getline(std::cin, passThrough);
}

void WaitForUserExit()
{
	std::string passThrough = "";
	std::cout << clearTerminal
		<< promptGoodbye
		<< promptExit;
	getline(std::cin, passThrough);
	std::cout << clearTerminal;
}
