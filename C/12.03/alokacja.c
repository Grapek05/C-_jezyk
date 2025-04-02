int (main) {
    // tworzy tablice jednowymiarową 
    int * arr_new(size_t n) {
        int * tablica = (int*)malloc(sizeof(int)*(n+1));
        tablica[0]=n;
        return tablica;
    } 
    // zwalnia pamięć tablicy
    void arr_free(int *a) {
        free(a);
    }
    // zwraca długość tablicy
    size_t arr_length(const int *a) {
        return a[0];
    } 
    // wypisuje wartosci tablicy(printf)
    void arr_print(const int *a) {
    for (int i = 1; i <= a[0]; i++)
    printf("%d", a[i])
}
    printf("\n");
    // zeruje wartości tablicy
    void arr_clear(int *a) 
    for (int i = 1; i <= a[0]; i++) {
        a[i] = 0;
    // ustawia wartość w tablicy
    void arr_set(int *a, size_t index, int value)
    if (index <a[0]) {
        a[index+1] = value;
    }
    // pobiera wartość z tablicy
    int arr_get(const int *a, size_t index)
        if(index >=a[0]) {
            return index
        }
        return a[index]
    }
    // wypełnia tablicę losowymi wartościami
    void arr_rand(int *a) {
        rand(time(NULL)); 
        for (int i = 1; i =<a[0]; i++) {
            a[i] = raid()
        }}
    // zwraca iloczyn skalarny (lub 0 jeżeli tablice mają różne długości)
    int arr_dot(const int *a, const int *b) {
        int zm = 0;
        if (a[0] == b[0]) {
            for (int i = 1; i =<a[0]; i++) {
                zm += a[i]*o[i]
            }
            return zm
        }
    } 
    // jeżeli tablice są tej samej długości to modyfikuje tablicę dest przez dodawanie wartości z tablicy arr (zwraca true), w przeciwnym razie false
    // #include <stdbool.h>
    bool arr_add(int *dest, const int *arr) {
        if (dest[0] == arr[0];) {
            for (int i = 1; i <=dest[0]; i++) {
                dest[i] += arr[i];
            }
            return true;
        }
        return false;
    }
    // tworzy nową tablicę i zapisuje w niej kolejne zsumowane wartości z tablic a i b (długość nowej tablicy jest taka jak najdłuższa z nich)
    int* arr_add_new(const int *a, const int *b) {
        int size = i
        if (a[0] > b[0]) {
            size = a[0];
        } else {
            size = b[0];
        }
        int * new_arr = arr_new(size);
        for (int i = 1; i =< size; i++) { // Polegamy na tym ze getter zwraca nam wartosci 0 dla nieistniejacych indeksów
            new_arr[i] = arr_get(a,i)+arr_get(b,i);
        }
        return new_arr;
    
}
}