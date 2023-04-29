/**@file */
#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
/** Funkcja rozdziela kazda linijke pliku wejsciowego na osobne elementy, tak by mozna z nich korzystac w dalszej czesci programu.

@param str pojedyncza linia pliku wejsciowego
@param ch znak spacji ' ' (w ASCII = 32)
@return Zwraca linijke pliku wejsciowego jako wektor, w ktorym kazdy element linii jest osobnym elementem trojelementowego wektora
*/
vector<string> explode(const string& str, const char& ch);

/** Funkja rekurencyjna wywolywana w funckji GetAllPossiblePaths. Poprzez kolejne wywolania samej siebie znajduje ona polacznia, ktore nie sa bezposrednie pomiedzy szukanymi miastami.

@param cities wektor polaczen miedzy miastami, ktorego zadnym elementem nie jest miasto startowe (wprowadzone przez uzytkownika)
@param currentlySearchedCity miasto, ktore ma polaczenie z miastem startowym. Od tego miasta bedzie dalej szukac polaczenia az do miasta docelowego.
@param destinationCity miasto docelowe
@param firstConnection pierwsze polaczenie pomiedzy miastem startowym, a currentlySearchedCity
@return Funkcja zwraca wszystkie mozliwe polaczenia pomiedzy dwoma miastami, ktore nie sa polaczeniami bezposrednimi
*/

vector<vector<vector<string>>> Recurssion(vector<vector<string>> cities, string currentlySearchedCity, string destinationCity, vector<vector<string>> firstConnection);

/** Funkcja ktora wyszukuje wszystkie polaczenia pomiedzy dwoma podanymi miastami, z ktorych jednym jest miasto startowe wprowadzone przez uzytkownika

@param paths wektor zawierajacy wszystkie polacznie miedzy miastami wraz z dystansem
@param startingCity wprowadzone przez uzytkownika miasto startowe
@param endCity miasto docelowe, dla ktorego sprawdzamy polaczenia
@see Recurssion
@return Funkcja zwraca wszystkie mozliwe polaczenia pomiedzy dwoma miastami
*/
vector<vector<vector<string>>> GetAllPossiblePaths(vector<vector<string>> paths, string startingCity, string endCity);

/** Funkcja zapsisuje wszystkie wczesniej znalezione trasy w odpowiednim dla tresci zadania formacie, a nastepnie wyszukuje, ktora z nich jest najkrotsza.

@param paths wszystkie polaczenia znalezione pomiedzy miastem startowym, a koncowym
@param startingCity miasto wprowadzone przez uzytkownika
@param endCity obecnie sprawdzane miasto, dla ktorego szukamy najkrotszego polaczenia z miastem startowym
@return zwraca najkrotsze polaczenie miedzy dwoma miastami w formacie miasto -> miasto: dystans
*/
string DisplayShortestPath(vector<vector<vector<string>>> paths, string startingCity, string endCity);




#endif