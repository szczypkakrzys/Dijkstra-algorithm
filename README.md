# Spedycja
Program dla firmy spedycyjnej, określający najkrótszą drogę pomiędzy miastem, w którym znajduje się siedziba firmy, a każdym z możliwych miast docelowych. Zadaniem algorytmu jest znalezienie najkrótszej ścieżki z pojedynczego źródła w grafie - wykorzystany został algorytm Dijkstry.

## Treść zadania: 
Napisać program, który wyszukuje najkrótsze połączenie pomiędzy dwoma miastami.
Użytkownik ma podać plik z miastami w formacie: <miasto> <miasto> <odległość>, gdzie
każda trasa musi być w osobnej linii oraz wybrać miasto startowe, z którego wszystkie trasy
będą się rozpoczynały. Program uruchamiany jest z linii poleceń z wykorzystaniem
następujących przełączników:
-i plik wejściowy z drogami
-o plik wyjściowy z trasami spedycyjnymi
-s nazwa miasta startowego, gdzie znajduje się centrala

## Działanie programu 
W folderze znajduje się przykładowy plik z miastami _inputFile.txt_. Podane są w nim połączenia między miastami (wierzchołkami grafu) w odpowiednim dla treści zadania formacie. Uruchamiajac program należy podać miasto startowe, czyli siedzibę naszej firmy transportowej, a następnie wygenerowane zostaną najkrótsze możliwe połączenia z miasta startowego do każdego innego z podanych w pliku miast.

### Wyniki dla podanego przykładu
Podaj miasto startowe: Krakow
1. Krakow -> Warszawa -> Gdansk: 580
2. Krakow -> Warszawa: 300
3. Krakow -> Warszawa -> Gdansk -> Szczecin: 780