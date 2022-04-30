#include <fstream>
#include <cctype>
#include <sstream>
#include "Analyze.h"

void WaitForUserContinue();
void WaitForUserExit();

int main(int numArgs, char* argPointers[])
{
	const int REQ_NUM_ARGS = 2;
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

    if (numArgs != REQ_NUM_ARGS)
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

			if(toupper(fileName[0]) == checkQuit[0])
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

		if(userInput[0] == checkMainMenu1[0])
		{
			analyze->Movies(imdb);
            exit = false;
		}
		else if (userInput[0] == checkMainMenu2[0])
		{
			analyze->Actors(imdb);
            exit = false;
		}
		else if (toupper(userInput[0]) == checkQuit[0])
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
