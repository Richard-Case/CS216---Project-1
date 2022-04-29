#include "Analyze.h"

void Analyze::Movies(const IMDB& imdb)
{
    std::string movie1, movie2, userInput;
	bool moveForward = false;

	// Ensure that the user doesn't have to restart the app if their input fails.
	do
	{
		// Get the first movie's title from the user.
	    do
	    {
			std::cout << clearTerminal
				<< "Please enter the first movie title: ";
		    getline(std::cin, movie1);

			std::cout << std::endl
			 	<< "You entered \"" << movie1 << "\". Is that correct?" << std::endl
				<< promptInput;
			getline(std::cin, userInput);

			if (userInput[0] == 'Y' || userInput[0] == 'y') { moveForward = true; }
			else { moveForward = false; }

	    } while (!moveForward);


		// Get the second movie's title from the user.
		do
		{
			std::cout << clearTerminal
				<< "Please enter the second movie title: ";
		    getline(std::cin, movie2);

			std::cout << std::endl
			 	<< "You entered \"" << movie2 << "\". Is that correct?" << std::endl
				<< promptInput;
			getline(std::cin, userInput);

			if (userInput[0] == 'Y' || userInput[0] == 'y') { moveForward = true; }
			else { moveForward = false; }

		} while (!moveForward);

		std::string matchedMovie1, matchedMovie2;
		matchedMovie1 = imdb.MatchExistingMovie(movie1);
		matchedMovie2 = imdb.MatchExistingMovie(movie2);

		// If both movie names entered by the user have a match...
		if (matchedMovie1.length() > 0 && matchedMovie2.length() > 0)
		{
			std::cout << clearTerminal
				<< "Your input matches the following two movies: " << std::endl
				<< "1: " << matchedMovie1 << std::endl
				<< "2: " << matchedMovie2 << std::endl << std::endl
				<< "Both movies exist within the database."
				<< std::endl
				<< promptContinue;
			getline(std::cin, userInput);
			if (userInput.length() != 0) { userInput = ""; }

	        do
	        {
				std::cout << clearTerminal
					<< "Please make a selection from the following menu..." << std::endl
					<< "A: All actors whom are in EITHER movie" << std::endl
					<< "B: All actors whom are in EACH movie" << std::endl
					<< "C: All actors whom are in BOTH movies" << std::endl
					<< "O: All actors whom are in only ONE of the two movies" << std::endl
					<< "Q: Quit to main menu" << std::endl
					<< std::endl
					<< promptInput;
				getline(std::cin, userInput);


				int actorCount = 0;
				if(userInput[0] == 'A' || userInput[0] == 'a')
				{
					std::cout << clearTerminal
						<< "Searching for every actor in either movie." << std::endl
						<< promptContinue;
					getline(std::cin, userInput);
					if (userInput.length() != 0) { userInput = ""; }

					std::cout << clearTerminal;
					std::set<std::string> allActors = imdb.FindActorsInMovie(matchedMovie1);
					std::set<std::string> actorsInMovie2 = imdb.FindActorsInMovie(matchedMovie2);

			        for (auto index = actorsInMovie2.begin(); index != actorsInMovie2.end(); index++) { allActors.insert(*index); }

					actorCount = 1;
			        for (auto index = allActors.begin(); index != allActors.end(); index++)
					{
						std::cout << actorCount++ << ": " << *index << std::endl;
					}

					std::cout << std::endl << promptContinue;
					getline(std::cin, userInput);
					if (userInput.length() != 0) { userInput = ""; }

					moveForward = false;

				}
				else if (userInput[0] == 'B' || userInput[0] == 'b')
				{
					std::cout << clearTerminal
						<< "Searching for every actor in each movie." << std::endl
						<< promptContinue;
					getline(std::cin, userInput);
					if (userInput.length() != 0) { userInput = ""; }

					std::cout << clearTerminal;
					std::set<std::string> actorsInMovie1 = imdb.FindActorsInMovie(matchedMovie1);
					std::set<std::string> actorsInMovie2 = imdb.FindActorsInMovie(matchedMovie2);

					actorCount = 1;
					std::cout << matchedMovie1 << ":" << std::endl;
			        for (auto index = actorsInMovie1.begin(); index != actorsInMovie1.end(); index++)
					{
						std::cout << actorCount++ << ": " << *index << std::endl;
					}

					actorCount = 1;
					std::cout << std::endl << matchedMovie2 << ":" << std::endl;
			        for (auto index = actorsInMovie2.begin(); index != actorsInMovie2.end(); index++)
					{
						std::cout << actorCount++ << ": " << *index << std::endl;
					}

					std::cout << std::endl << promptContinue;
					getline(std::cin, userInput);
					if (userInput.length() != 0) { userInput = ""; }

					moveForward = false;

				}
				else if (userInput[0] == 'C' || userInput[0] == 'c')
				{
					std::cout << clearTerminal
						<< "Searching for every actor in both movies." << std::endl
						<< promptContinue;
					getline(std::cin, userInput);
					if (userInput.length() != 0) { userInput = ""; }

					std::cout << clearTerminal;
					std::set<std::string> actorsInMovie1 = imdb.FindActorsInMovie(matchedMovie1);
					std::set<std::string> actorsInMovie2 = imdb.FindActorsInMovie(matchedMovie2);
					std::set<std::string> actorsInBoth;

					for (auto index = actorsInMovie1.begin(); index != actorsInMovie1.end(); index++)
					{
						if (actorsInMovie2.find(*index) != actorsInMovie2.end())
						{
							actorsInBoth.insert(*index);
						}
					}

					if(actorsInBoth.size() != 0)
					{
						actorCount = 1;
						for (auto index = actorsInBoth.begin(); index != actorsInBoth.end(); index++)
						{
							std::cout << actorCount++ << ": " << *index << std::endl;
						}
					}
					else
					{
						std::cout << "None." << std::endl;
					}

					std::cout << std::endl << promptContinue;
					getline(std::cin, userInput);
					if (userInput.length() != 0) { userInput = ""; }

					moveForward = false;

				}
				else if (userInput[0] == 'O' || userInput[0] == 'o')
				{
					std::cout << clearTerminal
						<< "Searching for actors whom are only in one movie." << std::endl
						<< promptContinue;
					getline(std::cin, userInput);
					if (userInput.length() != 0) { userInput = ""; }

					std::cout << clearTerminal;
					std::set<std::string> actorsInMovie1 = imdb.FindActorsInMovie(matchedMovie1);
					std::set<std::string> actorsInMovie2 = imdb.FindActorsInMovie(matchedMovie2);
					std::set<std::string> actorsOnlyInMovie1 = actorsInMovie1;
					std::set<std::string> actorsOnlyInMovie2 = actorsInMovie2;

					for (auto index = actorsInMovie1.begin(); index != actorsInMovie1.end(); index++)
					{
						if (actorsInMovie2.find(*index) != actorsInMovie2.end())
						{
							actorsOnlyInMovie1.erase(*index);
							actorsOnlyInMovie2.erase(*index);
						}
					}

					std::cout << matchedMovie1 << ":" << std::endl;
					if (actorsOnlyInMovie1.size() !=0)
					{
						actorCount = 1;
				        for (auto index = actorsOnlyInMovie1.begin(); index != actorsOnlyInMovie1.end(); index++)
						{
							std::cout << actorCount++ << ": " << *index << std::endl;
						}
					}
					else { std::cout << "No actors whom are only in " << matchedMovie1 << std::endl; }

					std::cout << std::endl << matchedMovie2 << ":" << std::endl;
					if (actorsOnlyInMovie2.size() != 0)
					{
						actorCount = 1;
				        for (auto index = actorsOnlyInMovie2.begin(); index != actorsOnlyInMovie2.end(); index++)
						{
							std::cout << actorCount++ << ": " << *index << std::endl;
						}
					}
					else { std::cout << "No actors whom are only in " << matchedMovie1 << std::endl; }

					std::cout << std::endl << promptContinue;
					getline(std::cin, userInput);
					if (userInput.length() != 0) { userInput = ""; }

					moveForward = false;

				}
				else if (userInput[0] == 'Q' || userInput[0] == 'q')
				{
		            moveForward = true;
				}
				else
				{
					std::cout << clearTerminal
						<< alertInvalidInput << std::endl
						<< promptContinue;
					getline(std::cin, userInput);
					if (userInput.length() != 0) { userInput = ""; }

					moveForward = false;
				}
	        } while (!moveForward);

			if(userInput[0] == 'Y' || userInput[0] == 'y') { moveForward = false; }
			else { moveForward = true; }
	    }
	    else	// If either movie name entered by the user does not have a match...
	    {
			if (matchedMovie1.length() == 0 && matchedMovie2.length() == 0)
			{
				std::cout << clearTerminal
					<< movie1 << " & " << movie2 << alert2InvalidMovies << std::endl;
			}
			else if (matchedMovie1.length() == 0)
			{
				std::cout << clearTerminal
					<< movie1 << alert1InvalidMovie << std::endl;
			}
			else
			{
				std::cout << clearTerminal
					<< movie2 << alert1InvalidMovie << std::endl;
			}

			std::cout << promptInput;
			getline(std::cin, userInput);

			if(userInput[0] == 'Y' || userInput[0] == 'y') { moveForward = false; }
			else { moveForward = true; }
	    }
	} while (!moveForward);
}

void Analyze::Actors (const IMDB& imdb)
{
	// Prompt the user to input an actor's name.
	std::string actorName, userInput;
	bool moveForward = false;

	do
	{
		std::cout << clearTerminal
			<< "Please enter an Actor's name: ";
		getline(std::cin, actorName);

		std::cout << std::endl
			<< "You entered \"" << actorName << "\". Is that correct?" << std::endl
			<< promptInput;
		getline(std::cin, userInput);

		if (userInput[0] == 'Y' || userInput[0] == 'y') { moveForward = true; }
		else { moveForward = false; }

	} while (!moveForward);

	std::string matchedActor = imdb.MatchExistingActor(actorName);

	// Is the Actor's name valid?
	if (matchedActor.length() > 0)
	{
		std::cout << clearTerminal
			<< "Searching for every co-actor for " << actorName << "." << std::endl
			<< promptContinue;
		getline(std::cin, userInput);
		if (userInput.length() != 0) { userInput = ""; }

		// Print a list of Co-Actors from each movie which the Actor is in.
		std::set<std::string> actorMovies = imdb.FindMoviesForActor(actorName);

		for (auto index = actorMovies.begin(); index != actorMovies.end(); index++)
		{
			std::string movie = *index;
			std::set<std::string> coActorsInMovie = imdb.FindActorsInMovie(movie);
			if (coActorsInMovie.find(actorName) != coActorsInMovie.end())
			{
				coActorsInMovie.erase(actorName);
			}

			if (coActorsInMovie.size() != 0)
			{
				std::cout << std::endl
					<< movie << ":" << std::endl;

				int actorCount = 1;
				for (auto actor = coActorsInMovie.begin(); actor != coActorsInMovie.end(); actor++)
				{
					std::cout << actorCount++ << ": " << *actor << std::endl;
				}
			}
		}

		std::cout << std::endl << promptContinue;
		getline(std::cin, userInput);
		if (userInput.length() != 0) { userInput = ""; }
		// Return to the main menu.
	}
	else
	{
		std::cout << clearTerminal
			<< actorName << alertMissingActor << std::endl
			<< promptContinue;
		getline(std::cin, userInput);
		if (userInput.length() != 0) { userInput = ""; }
	}
}
