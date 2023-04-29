#include "funkcje.h"

using namespace std;

vector<string> explode(const string& str, const char& ch) {
	string next;
	vector<string> result;


	for (string::const_iterator it = str.begin(); it != str.end(); it++) {

		if (*it == ch) {

			if (!next.empty()) {

				result.push_back(next);
				next.clear();
			}
		}
		else {

			next += *it;
		}
	}
	if (!next.empty())
		result.push_back(next);
	return result;
}

vector<vector<vector<string>>> Recurssion(vector<vector<string>> cities, string currentlySearchedCity, string destinationCity, vector<vector<string>> firstConnection)
{
	vector<vector<string>> temp(firstConnection);
	vector<vector<vector<string>>> completePaths;

	for (const vector<string>& element : cities)
	{
		if ((element[0] == currentlySearchedCity && element[1] == destinationCity) || (element[1] == currentlySearchedCity && element[0] == destinationCity))
		{
			temp.push_back(element);
			completePaths.push_back(temp);
		}

		if (element[0] == currentlySearchedCity)
		{
			temp.push_back(element);
			vector<vector<string>> newCities(cities);

			int counter = 0;
			vector<int> indexesToRemove;
			for (const vector<string>& x : cities)
			{
				for (const string& y : x)
				{
					if (y == currentlySearchedCity)
					{
						indexesToRemove.push_back(counter);
					}
				}

				counter++;
			}

			int removeIndex = 0;
			for (const int& toRemove : indexesToRemove)
			{
				newCities.erase(newCities.begin() + toRemove + removeIndex);
				removeIndex--;
			}

			vector<vector<vector<string>>> result = Recurssion(newCities, element[1], destinationCity, temp);

			if (result.size() > 0)
			{
				for (const std::vector<vector<string>>& resultItem : result)
				{
					completePaths.push_back(resultItem);
				}
			}
			else
			{
				if (temp.size() > 1)
				{
					temp.pop_back();
				}
			}
		}

		if (element[1] == currentlySearchedCity)
		{
			temp.push_back(element);
			vector<vector<string>> newCities(cities);

			int counter = 0;
			vector<int> indexesToRemove;
			for (const vector<string>& x : cities)
			{
				for (const string& y : x)
				{
					if (y == currentlySearchedCity)
					{
						indexesToRemove.push_back(counter);
					}
				}

				counter++;
			}

			int removeIndex = 0;
			for (const int& toRemove : indexesToRemove)
			{
				newCities.erase(newCities.begin() + toRemove + removeIndex);
				removeIndex--;
			}

			vector<vector<vector<string>>> result = Recurssion(newCities, element[0], destinationCity, temp);

			if (result.size() > 0)
			{
				for (const vector<vector<string>>& resultItem : result)
				{
					completePaths.push_back(resultItem);
				}
			}
			else
			{
				if (temp.size() > 1)
				{
					temp.pop_back();
				}
			}
		}
	}

	return completePaths;
}


vector<vector<vector<string>>> GetAllPossiblePaths(vector<vector<string>> paths, string startingCity, string endCity)
{
	vector<vector<vector<string>>> savedPaths;
	vector<vector<string>> allCitiesTemp(paths);

	int counter = 0;
	vector<int> toRemoveIndexes;
	for (const vector<string>& element : allCitiesTemp)
	{
		if ((element[0] == startingCity && element[1] == endCity) || (element[0] == endCity && element[1] == startingCity))
		{
			savedPaths.push_back(vector<vector<string>>{ element });
			toRemoveIndexes.push_back(counter);
		}

		counter++;
	}

	int removeIndex = 0;
	for (const int& element : toRemoveIndexes)
	{
		allCitiesTemp.erase(allCitiesTemp.begin() + element + removeIndex);
		removeIndex--;
	}

	vector<vector<string>> citiesToCheck;
	for (const vector<string>& element : allCitiesTemp)
	{
		if (element[0] == startingCity || element[1] == startingCity)
		{
			citiesToCheck.push_back(element);
		}
	}

	for (const vector<string>& element : citiesToCheck)
	{
		vector<vector<string>> temp(allCitiesTemp);

		string cityToSearch = element[0];

		if (cityToSearch == startingCity)
		{
			cityToSearch = element[1];
		}

		counter = 0;
		vector<int> toRemoveIndexes2;

		for (const vector<string>& element : temp)
		{
			if (element[0] == startingCity || element[1] == startingCity)
			{
				toRemoveIndexes2.push_back(counter);
			}

			counter++;
		}

		removeIndex = 0;
		for (const int& element : toRemoveIndexes2)
		{
			temp.erase(temp.begin() + element + removeIndex);
			removeIndex--;
		}

		vector<vector<vector<string>>> allPathsForGivenCity = Recurssion({ temp }, cityToSearch, endCity, { element });

		for (const vector<vector<string>>& element : allPathsForGivenCity)
		{
			savedPaths.push_back(element);
		}
	}

	return savedPaths;
}

string DisplayShortestPath(vector<vector<vector<string>>> paths, string startingCity, string endCity)
{
	int counter = 1;
	vector<string> pathsDisplay;
	vector<int> distancesDisplay;

	for (const vector<vector<string>>& path : paths)
	{
		string result = "";
		string currentConnectionCity = "";
		int currentPathDistance = 0;

		for (const vector<string>& distance : path)
		{
			currentPathDistance += stoi(distance[2]); //stoi == string -> integer

			if (path.size() > 1) //dla polaczen niebezposrednich
			{
				if (distance[0] == startingCity)
				{
					result = distance[0] + " -> " + distance[1];
					currentConnectionCity = distance[1];
				}
				else if (distance[1] == startingCity)
				{
					result = distance[1] + " -> " + distance[0];
					currentConnectionCity = distance[0];
				}
				else if (distance[0] == endCity)
				{
					result += " -> " + endCity;
				}
				else if (distance[1] == endCity)
				{
					result += " -> " + endCity;
				}
				else
				{
					if (distance[0] == currentConnectionCity)
					{
						result += " -> " + distance[1];
						currentConnectionCity = distance[1];
					}
					else if (distance[1] == currentConnectionCity)
					{
						result += " -> " + distance[0];
						currentConnectionCity = distance[0];
					}
				}
			}
			else
			{
				if (distance[0] == startingCity)
				{
					result = distance[0] + " -> " + distance[1];
				}
				else
				{
					result = distance[1] + " -> " + distance[0];
				}
			}
		}

		pathsDisplay.push_back(to_string(counter) + " " + result);
		distancesDisplay.push_back(currentPathDistance);

		counter++;
	}

	auto shortestDistance = min_element(distancesDisplay.begin(), distancesDisplay.end());
	string shortestDistancePath = pathsDisplay[distance(distancesDisplay.begin(), shortestDistance)]; //szuka ile elementow jest miedzy poczatkiem, a najkrotszym wynikiem i ta liczba elementow to counter dla najkrotszej sciezki

	shortestDistancePath.erase(0, 2); //wyrzuca elementy od pozycji 0 do 2

	return shortestDistancePath + ": " + to_string(shortestDistance[0]);
}
