// Copyright (c) 2019 St. Mother Teressa HS All rights reserved.
//
// Created by: Ben Whitten
// Created on: December 2019
// This is a program which generates 10 numbers and tells you the average.

#include <time.h>
#include <iostream>


template <int rows, int cols>
int sumOfNumbers(int (&list)[rows][cols]) {
    int total = 0;

    for (size_t rowElement = 0; rowElement < rows; ++rowElement) {
        for (size_t columnElement = 0; columnElement < cols; ++columnElement)
            total += list[rowElement][columnElement];
    }

    return total;
}


int main() {
    // this is what runs the program

    int randomNumber = 0;
    int average = 0;
    int sum = 0;
    const int rows = 2;
    const int columns = 5;
    int array[rows][columns];

    unsigned int seed = time(NULL);

    for (int rowElement = 0; rowElement < rows; rowElement++) {
        for (int columnElement = 0; columnElement < columns; columnElement++) {
            randomNumber = (rand_r(&seed) % 50) + 1;
            array[rowElement][columnElement] = randomNumber;
            std::cout << randomNumber << ", ";
        }
        std::cout << std::endl;
    }

    sum = sumOfNumbers(array);
    average = sum/(rows*columns);
    std::cout << "The average is: " << average << std::endl;
}
