#include <regex>
#include "imdb.h"

IMDB::IMDB() { /* Empty */ }		// default constructor

// Insert an actor into the map of actors.
void IMDB::InsertActor(std::string actorName, std::set<std::string> movieTitles)
{
    // Upgrade actorMap
	if (!ActorExists(actorName)) { actorMap[actorName] = movieTitles; }
    else { actorMap[actorName].insert(movieTitles.begin(), movieTitles.end()); }

    // Upgrade movieMap
	for (auto index = movieTitles.begin(); index != movieTitles.end(); index++) { movieMap[*index].insert(actorName); }
}

// Return a string that partially matches the string input by the user.
std::string IMDB::MatchExistingMovie(std::string& movieTitle) const
{
    // Generate the expression to match, which contains the movie's title as a substring
    std::regex reg(movieTitle, std::regex_constants::icase);

    for (auto index = movieMap.begin(); index != movieMap.end(); index++)
    {
        if (regex_search(index->first, reg)) { return index->first; }
    }

    return "";
}

// Check whether or not the movie title exists in the map of movies.
bool IMDB::MovieExists(std::string& movieTitle) const
{
	if(movieMap.find(movieTitle) != movieMap.end()) { return true; }
	else { return false; }
}

// Return a string that EXACTLY matches the string input by the user.
std::string IMDB::MatchExistingActor(std::string& actorName) const
{
    // Generate the expression to match, which contains the actor's name as a substring
    std::regex reg(actorName, std::regex_constants::nosubs);

    for (auto index = actorMap.begin(); index != actorMap.end(); index++)
    {
        if (regex_search(index->first, reg)) { return index->first; }
    }

    return "";
}

// Check whether or not the actor name exists in the map of actors.
bool IMDB::ActorExists(std::string& actorName) const
{
	if(actorMap.find(actorName) != actorMap.end()) { return true; }
	else { return false; }
}

// Return a set of movie titles in which the actor name exists.
std::set<std::string> IMDB::FindMoviesForActor(std::string& actorName) const
{
	if(ActorExists(actorName)) { return actorMap.at(actorName); }
	else
	{
		std::cout << clearTerminal
			<< alertError << actorName << alertMissingMovie << std::endl;
		std::set <std::string> emptySet;
		return emptySet;
	}
}

// Return a set of actor names which are all in the set under the movie title.
std::set<std::string> IMDB::FindActorsInMovie(std::string& movieTitle) const
{
	if(MovieExists(movieTitle)) { return movieMap.at(movieTitle); }
	else
	{
		std::cout << clearTerminal
		 	<< alertError << movieTitle << alertMissingMovie << std::endl;
		std::set <std::string> emptySet;
		return emptySet;
	}
}
