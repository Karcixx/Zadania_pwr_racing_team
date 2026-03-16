#include <iostream>
#include <vector>

struct Point {
	float x;
	float y;
};

//strucktura wezla
struct Node {
	Point point;
	Node* left = nullptr;
	Node* right = nullptr;
};

//wyszukanie mediany
int partition(std::vector<Point>& points, int start, int end, int axis) {
	float pivot;
	// i - wskazuje gdzie wrzucic element mniejszy od pivota
	int i = start;

	//zaleznosc od tego, czy bierzemy w drzewie podzial po x czy y 
	if (axis == 0) {
		//pivot - ostatni element w vectorze punktow
		pivot = points[end].x;

		//zamiana, jezeli cos jest mniejsze od pivota, idzie na poczatek
		for (int j = start; j < end; j++) {
			if (points[j].x < pivot) {
				std::swap(points[i], points[j]);
				i++;
			}
		}
	}
	//to samo dla y co dla x
	else {
		pivot = points[end].y;

		for (int j = start; j < end; j++) {
			if (points[j].y < pivot) {
				std::swap(points[i], points[j]);
				i++;
			}
		}
	}
	//dajemy naszego pivota na srodek i zwracamy jego index
	std::swap(points[i], points[end]);
	return i;

}

//quickselect
void quickselect(std::vector<Point>& points, int start, int end, int mid, int axis) {
	//sprawdzamy, czy przedzial nie ma jednego elementu
	if (start >= end) return;
	int pivot_index = partition(points, start, end, axis);

	//sprawdzamy czy pivot jest w miejscu ktory chcielismy
	if (pivot_index == mid) return;
	//mediana musi byc po lewej od pivota
	else if (mid < pivot_index) quickselect(points, start, pivot_index - 1, mid, axis);
	//mediana musi byc po prawej od pivota
	else quickselect(points, pivot_index + 1, end, mid, axis);
}

//budowa drzewa 
Node* kd_tree(std::vector<Point>& points, int start, int end, int depth = 0) {
	if (start > end) return nullptr;

	int axis = depth % 2;
	int mid_index = start + (end - start) / 2;

	//ustawiamy mediane uzywajac zrobionych funkcji
	quickselect(points, start, end, mid_index, axis);
	Node* node = new Node;
	node->point = points[mid_index];

	//rekurencja tworzymy drzewo z lewej i prawej strony
	node->left = kd_tree(points, start, mid_index - 1, depth + 1);
	node->right = kd_tree(points, mid_index + 1, end, depth + 1);

	return node;
}


//szukanie pary z drzew, ktore sa najblizej siebie
void nearest_pair(std::vector<Point>& points) {

	Node* root = kd_tree(points, 0, points.size() - 1);

	float distance = (root->left->point.x);

}