Zadania PWR Racing Team

Zadanie 1 (Brak wykonania zadania)
Wyjaśnienie: Brak znajomości programu, wymaganego do wykonania zadania

Zadanie 2
  Dla ułatwienia zadania, dodałam strukture "point", która jest potrzebna dla zdefiniowania punkty i łatwego iterowania po vectorach. Funkcja "open_file" odczytuje dane z pliku i zapisuje do vectora points.
  2.1 
    Sposób działania: stworzenie 4 zmiennych do przypisania im tylko skrajnych punktów. W pętli for, dzięki której łatwo iterujemy po każdym elemencie vectora "points". Po znalezieniu skrajnych punktow, szukamy
    dodatkowych, ktore zostały pominięte we wczesniej.
    Napotkane problemy: dwa razy przechodzenie po tej samej pętli. Nie wymyśliłam innego sposobu, na ugryzienie tego zadania. Niestety miałam tylko jeden wolny dzień, aby przysiaść do tych zadań, więc
    nie myślałam o potencjalnych zmianach. Doddatkowo brak posortowanych elementów w vectorze "points", tak aby były jak w kierunku wskazówek zegara. To ma swoje konsekwencje w zadaniu 2.2
  2.2
    Sposób działania: używając pętli w pętli przechodzimy przez każdą parę elementów vectora "extreme_points". Z każdej pary liczymy jej prostą, a potem przyrównujemy z innym skrajnym punktem, aby sprawdzić odległość.
    Napotkane problemy: słaba wydajność kodu, przez dużą ilość pętli. Przypisanie do zmiennej d_min, d_max i min_width konkretnych wartości. Powoduje to brak obsługi błędu, dla przypadku bardziej odległych punktów.
    Każdy z problemów starałam się obejść, ale to zadanie drugie zajęło mi najwięcej czasu i szukania pomysłu. Nie wiedziałam jaki algorytm sortowania wykorzystać i w jaki sposób sprawdzać te punkty. Starałam się
    wykonać to zadanie jak najlepiej.
