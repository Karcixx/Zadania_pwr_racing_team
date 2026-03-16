# **Zadania PWR Racing Team**

## **Zadanie 1 (Brak wykonania zadania)**
Wyjaśnienie: Ze względu na brak wcześniejszej styczności z wymaganym oprogramowaniem oraz ograniczony czas, nie byłam w stanie zrealizować tego zadania.


## **Zadanie 2**
Dla ułatwienia zadania, dodałam strukture "Point", która jest potrzebna dla zdefiniowania punktów i łatwego iterowania po vectorach. Funkcja "open_file" odczytuje dane z pliku i zapisuje je do vectora "points".
* Zadanie 2.1  
    **Sposób działania:** stworzenie 4 zmiennych, aby przypisać tylko skrajne punkty wykorzytując pętlę for, dzięki której łatwo iterujemy po każdym elemencie vectora "points". Po znalezieniu skrajnych punktów, szukamy
    dodatkowych, ktore zostały pominięte we wczesniej iteracji.  
    **Napotkane problemy:** dwa razy przechodzenie po tej samej pętli. Nie wymyśliłam innego sposobu, na ugryzienie tego zadania. Niestety miałam tylko jeden wolny dzień, aby przysiaść do tych zadań, więc
    nie myślałam o potencjalnych zmianach. Doddatkowo brak posortowanych elementów w vectorze "points", tak aby były jak w kierunku wskazówek zegara. To ma swoje konsekwencje w zadaniu 2.2.
  
* Zadanie 2.2  
    **Sposób działania:** używając pętli w pętli przechodzimy przez każdą parę elementów vectora "extreme_points". Każdej z par punktów liczymy jej prostą, a potem przyrównujemy z innym skrajnym punktem, aby sprawdzić odległość.  
    **Napotkane problemy:** słaba wydajność kodu, przez dużą ilość pętli. Przypisanie do zmiennej d_min, d_max i min_width konkretnych wartości. Powoduje to brak obsługi błędu, dla przypadku bardziej odległych punktów.
    Każdy z problemów starałam się obejść, ale to zadanie drugie zajęło mi najwięcej czasu i szukania pomysłu. Nie wiedziałam jaki algorytm sortowania wykorzystać i w jaki sposób sprawdzać te punkty. Starałam się
    wykonać to zadanie jak najlepiej.

* Zadanie 2.3  
     **Sposób działania:** znów porównywanie punktów każdy z każdym, aby liczyć odległości między nimi. Przy każdym przejściu pętli porównujemy wynik z poprzednim.  
     **Napotkane błędy:** Słaba złożoność obliczeniowa, którą próbowałam obejść. Dodałam plik "Dodatek.cpp", w którym są moje nieudolne próby poprawienia jakości kodu. Zamysł polegał na zrobieniu Drzewa KD, dzięki któremu szybciej można przechodzić między punktami. Problem pojawił się w momencie, gdy chciałam już przeszukiwać drzewo, aby porównywać odległości. Niestety na początku, jak zaczęłam pisać kod, źle założyłam, że wystarczy sprawdzić tylko sąsiadujące punkty w drzewie, czyli od każdego węzła sprawić jego odległość do jego lewego i prawego dziecka. Ten trop okazał się błędny, przez co zaczęłam wątpić, czy ma to szanse mieć lepszą złożoność obliczeniową. Nie miałam czasu dokończyć kodu, więc przesyłam jedynie próbę rozwiązania przeze mnie problemu.

    
