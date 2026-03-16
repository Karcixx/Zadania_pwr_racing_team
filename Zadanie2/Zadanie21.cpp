#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>

/*
	Struktura reprezentuj¹ca punkt w przestrzeni 2D
*/
struct point {
	float x;
	float y;
};

/*
	Odczyt - odczytuje dane z pliku i zapisuje punkty do wektora.
	Parametry - file(referencja do otwartego strumienia pliku), 
	points(referencja do vectora, do którego bêd¹ dodawane punkty).
	Zwraca - vector points, do którego zostan¹ dopisane odczytane punkty.
*/
void open_file(std::ifstream& file, std::vector<point>& points) {
	int number_of_points;
	if (file >> number_of_points);

	for (int i = 0; i < number_of_points; i++) {
		point point;
		if (file >> point.x >> point.y) {
			points.push_back(point);
		}
	}
}

/*
	Funkcja wyznacza punkty skrajne (min/max X oraz Y) ze zbioru danych.
	Funkcja przechodzi przez wszystkie punkty, aby znaleŸæ ekstrema,
	a nastêpnie dopisuje brakuj¹ce punkty le¿¹ce na tych samych liniach brzegowych.
*/
void extreme_points(std::vector<point>& old_tab, std::vector<point>& new_tab) {
	point min_x = old_tab[0];
	point max_x = old_tab[0];
	point max_y = old_tab[0];
	point min_y = old_tab[0];

	//Znalezienie g³ównych ekstremów
	for (int i = 0; i < old_tab.size(); i++) {
		if (old_tab[i].x <= min_x.x) min_x = old_tab[i];
		if (old_tab[i].x >= max_x.x) max_x = old_tab[i];
		if (old_tab[i].y <= min_y.y) min_y = old_tab[i];
		if (old_tab[i].y >= max_y.y) max_y = old_tab[i];
	}
	new_tab.push_back(min_x);
	new_tab.push_back(min_y);
	new_tab.push_back(max_x);
	new_tab.push_back(max_y);

	//Dodanie dodatkowych punktów, które równie¿ le¿¹ na krawêdziach, ale
	//nie zosta³y dodane w pierwszym kroku
	for (int i = 0; i < old_tab.size(); i++) {
		if ((old_tab[i].x == min_x.x && old_tab[i].y != min_x.y) ||
			(old_tab[i].x == max_x.x && old_tab[i].y != max_x.y) ||
			(old_tab[i].y == min_y.y && old_tab[i].x != min_y.x) ||
			(old_tab[i].y == max_y.y && old_tab[i].x != max_y.x)) new_tab.push_back(old_tab[i]);
	}

	//Wyœwietlenie punktów skrajnych
	for (int i = 0; i < new_tab.size(); i++) {
		std::cout << "(" << new_tab[i].x << ", " << new_tab[i].y << ") ";
	}
}

/*
	Oblicza najmniejsz¹ szerokoœæ (odleg³oœæ miêdzy prostymi równoleg³ymi) ze zbioru punktów.
	Algorytm generuje proste przechodz¹ce przez pary punktów skrajnych
	i mierzy rozpiêtoœæ (d_max - d_min) ca³ego zbioru wzglêdem tych prostych.
*/
void straight_parallel(std::vector<point>& extremes, std::vector<point>& all_points) {
	float min_width = 1000; //wartoœæ do porównañ

	//Iteracja po parach punktów skrajnych
	for (int i = 0; i < extremes.size(); i++) {
		for (int j = i + 1; j < extremes.size(); j++) {
			point p1 = extremes[i];
			point p2 = extremes[j];

			//Wyznaczanie wspó³czynników prostej Ax + By + C = 0
			float A = p1.y - p2.y;
			float B = p2.x - p1.x;
			float C = p1.x * p2.y - p2.x * p1.y;

			float denominator = std::sqrt(A * A + B * B);
			if (denominator == 0) continue;

			/*
				Wyznaczenie rozpiêtoœci rzutu punktów na kierunek prostopad³y do prostej.
				Szukamy d_min i d_max, aby obs³u¿yæ brak posortowych punktów.
			*/
			 
			float d_min = 1000; //Du¿a wartoœæ pocz¹tkowa do porównañ
			float d_max = -1000; //Ma³a wartoœæ pocz¹tkowa do porównañ

			for (const auto& p : all_points) {
				float distance = (A * p.x + B * p.y + C) / denominator;
				if (distance < d_min) d_min = distance;
				if (distance > d_max) d_max = distance;
			}

			//Porównywanie aktualnie uzyskanego wyniku z poprzednim
			float current_width = d_max - d_min;
			if (current_width < min_width) {
				min_width = current_width;
			}
		}
	}

	//Wyœwietlenie wyniku, po znalezieniu najmniejszej odleg³oœci
	std::cout << "d= " << min_width;
}

int main() {
	std::string file_name;
	std::cout << "Podaj nazwe pliku: ";
	std::cin >> file_name;

	std::ifstream file(file_name);

	//Sprawdzamy, czy plik zosta³ poprawnie otwarty
	if (!file.is_open()) {
		std::cerr << "Nie udalo sie otworzyc pliku " << file_name;
		return 1;
	}

	//Vector wszystkich punktów
	std::vector<point> points;

	open_file(file, points);

	//Vector tylko skrajnych punktów
	std::vector<point> extreme_points_tab;

	//G³ówna logika
	extreme_points(points, extreme_points_tab);
	straight_parallel(extreme_points_tab, points);

}