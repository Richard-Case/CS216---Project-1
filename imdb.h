#ifndef IMDB_H
#define IMDB_H

#include "Strings.h"
#include <iostream>
#include <map>
#include <set>

class IMDB
{
    public:
		IMDB();		// default constructor

		void ClearTerminal();

		// Insert an actor into the map of actors.
		void InsertActor(std::string actorName, std::set<std::string> movieTitles);

        // Return a string that partially matches the string input by the user.
        std::string MatchExistingMovie(std::string& movieTitle) const;

        // Check whether or not the movie title exists in the map of movies.
        bool MovieExists(std::string& movieTitle) const;

		// Return a string that EXACTLY matches the string input by the user.
		std::string MatchExistingActor(std::string& movieTitle) const;

        // Check whether or not the actor name exists in the map of actors.
        bool ActorExists(std::string& actorName) const;

        // Return a set of movie titles in which the actor name exists.
        std::set<std::string> FindMoviesForActor(std::string& actorName) const;

        // Return a set of actor names which are all in the set under the movie title.
        std::set<std::string> FindActorsInMovie(std::string& movieTitle) const;

    private:
        std::map<std::string, std::set<std::string> > movieMap;		//A map of sets of actor names, headed by movie titles.
        std::map<std::string, std::set<std::string> > actorMap;		//A map of sets of movie titles, headed by actor names.
};

#endif
