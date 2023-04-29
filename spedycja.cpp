#include "funkcje.h"

using namespace std;

int main(int argc, char* argv[])
{
	string inputFileName, outputFileName, userInputCity;

	//used in makefile
	/*for (int i = 0; i < argc; ++i)
	{
		string a = argv[i];

		if (a == "-i")
		{
			inputFileName = argv[i + 1];
			i++;
		}
		else if (a == "-o")
		{
			outputFileName = argv[i + 1];
			i++;
		}
		else if (a == "-s")
		{
			userInputCity = argv[i + 1];
			i++;
		}
	}*/

	//console solution ;)
	inputFileName = "inputFile.txt";
	outputFileName = "results.txt";
	cout << "Podaj miasto startowe: ";
	cin >> userInputCity;

	ifstream miastaFile(inputFileName);

	vector<string> CitiesNames;
	vector<vector<string>> Paths;

	for (string line; getline(miastaFile, line);)
	{
		vector<string> lineElements = explode(line, ' ');
		Paths.push_back(lineElements);

		if (find(CitiesNames.begin(), CitiesNames.end(), lineElements[0]) == CitiesNames.end()) {
			CitiesNames.push_back(lineElements[0]);
		}

		if (find(CitiesNames.begin(), CitiesNames.end(), lineElements[1]) == CitiesNames.end()) {
			CitiesNames.push_back(lineElements[1]);
		}
	}

	miastaFile.close();

	auto index = find(CitiesNames.begin(), CitiesNames.end(), userInputCity);

	if (index != CitiesNames.end())
	{
		CitiesNames.erase(index);
	}

	ofstream outfile(outputFileName);

	int pathIndex = 1;
	for (const string& city : CitiesNames)
	{
		vector<vector<vector<string>>> paths = GetAllPossiblePaths(Paths, userInputCity, city);
		string displayResult = to_string(pathIndex) + ". " + DisplayShortestPath(paths, userInputCity, city);
		cout << displayResult + "\n";
		outfile << displayResult << endl;
		pathIndex++;
	}

	outfile.close();
}
