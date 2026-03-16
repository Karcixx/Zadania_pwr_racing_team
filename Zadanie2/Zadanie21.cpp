#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>

struct point {
	float x;
	float y;
};

//funkcja dodajaca dane z pliku
void open_file(std::ifstream& file, std::vector<point>& points) {
	int number_of_points;
	if (file >> number_of_points);

	for (int i = 0; i < number_of_points; i++) {
		point point;
		if (file >> point.x >> point.y) {
			points.push_back(point);
		}
	}

	/*for (int i = 0; i < points.size(); i++) {
		std::cout << points[i].x << " " << points[i].y << std::endl;
	}*/
}

//funkcja przeszukujaca tablice z punktami i szukajaca skrajnych punktow, dodajac je do nowej tablicy
void extreme_points(std::vector<point>& old_tab, std::vector<point>& new_tab) {
	point min_x = old_tab[0];
	point max_x = old_tab[0];
	point max_y = old_tab[0];
	point min_y = old_tab[0];

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

	//dodanie dodatkowych punktow, ktore nie zostaly wziete wczesniej
	for (int i = 0; i < old_tab.size(); i++) {
		if ((old_tab[i].x == min_x.x && old_tab[i].y != min_x.y) ||
			(old_tab[i].x == max_x.x && old_tab[i].y != max_x.y) ||
			(old_tab[i].y == min_y.y && old_tab[i].x != min_y.x) ||
			(old_tab[i].y == max_y.y && old_tab[i].x != max_y.x)) new_tab.push_back(old_tab[i]);
	}

	for (int i = 0; i < new_tab.size(); i++) {
		std::cout << "(" << new_tab[i].x << ", " << new_tab[i].y << ") ";
	}
}

void straight_parallel(std::vector<point>& extremes, std::vector<point>& all_points) {
	float min_width = 1000;

	//przechodzimy pokolei po elementach tablicy biorac dwa skrajne punkty
	//szukamy trzeciego ze skrajnych najblizszego do naszej prostej
	//tak aby odleglosc byla jak najmniejsza
	//robiac druga petle robimy ja o jeden dalej od poprzedniego
	//aby nie powtarzac par punktow co juz byly

	for (int i = 0; i < extremes.size(); i++) {
		for (int j = i + 1; j < extremes.size(); j++) {
			point p1 = extremes[i];
			point p2 = extremes[j];

			float A = p1.y - p2.y;
			float B = p2.x - p1.x;
			float C = p1.x * p2.y - p2.x * p1.y;

			float denominator = std::sqrt(A * A + B * B);
			if (denominator == 0) continue;

			//nie uzywamy abs, bo nie wiemy po ktorej stronie jest punkt
			//robimy to bo nie mamy posortowanej tablicy ze skrajnymi punktami
			//co nie pozwoli nam brac tylko sasiadow, wiec obchodzimy wyjatek
			//w ktorym punkty sa naprzeciwko

			float d_min = 1000;
			float d_max = -1000; 

			for (const auto& p : all_points) {
				float distance = (A * p.x + B * p.y + C) / denominator;
				if (distance < d_min) d_min = distance;
				if (distance > d_max) d_max = distance;
			}

			float current_width = d_max - d_min;
			if (current_width < min_width) {
				min_width = current_width;
			}
		}
	}

	std::cout << "d= " << min_width;
}

int main() {
	std::string file_name;
	std::cout << "Podaj nazwe pliku: ";
	std::cin >> file_name;

	std::ifstream file(file_name);

	//sprawdzamy, czy plik otworzono poprawnie
	if (!file.is_open()) {
		std::cerr << "Nie udalo sie otworzyc pliku " << file_name;
		return 1;
	}

	//tworzymy tablice naszych punktow do pobrania z pliku tekstowego i dodajemy je do vectora
	std::vector<point> points;

	open_file(file, points);

	std::vector<point> extreme_points_tab;

	//znalezienie wszystkich skarajnych punktow i dodanie do wspolnego vectora
	extreme_points(points, extreme_points_tab);

	straight_parallel(extreme_points_tab, points);

}