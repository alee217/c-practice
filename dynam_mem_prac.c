#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct complex_st {
    double real; // real component
    double imag; // imaginary component
} Complex;

typedef struct complex_set_st {
    double num_points_in_set;
    Complex* points; // an array of Complex
} ComplexSet;

ComplexSet* AllocSet(Complex c_arr[], int size);
void FreeSet(ComplexSet* set);

int main(int argc, char** argv) {
    Complex c_arr[] = {{1.0, 2.0}, {2.0, 3.0}};
    assert(c_arr[0].real == 1.0 && c_arr[0].imag == 2.0);
    assert(c_arr[1].real == 2.0 && c_arr[1].imag == 3.0);
    ComplexSet* set = AllocSet(c_arr, 2);
    assert(set != NULL);
    FreeSet(set);
    printf("success");
    return 0;
}

ComplexSet* AllocSet(Complex c_arr[], int size) {
    ComplexSet* res = (ComplexSet*) malloc(sizeof(ComplexSet));
    if (res == NULL) {
        return NULL;
    }
    Complex* ps = (Complex*) malloc(size * sizeof(Complex));
    if (ps == NULL) {
        free(res);
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        ps[i] = c_arr[i];
    }
    res->num_points_in_set = size;
    res->points = ps;
    return res;
}

void FreeSet(ComplexSet* set) {
    free(set->points);
    free(set);
}