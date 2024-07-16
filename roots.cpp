#include <iostream>
#include <vector>
#include <cmath>

#define ITERATION_COUNT 20

float f(float x) {
    return 4*pow(x, 2) - 4*x;
} // Your function. For f(x) = 4x^2 - 4, your root on [0.5, 2] should be x = 1.

bool f_sign_positive(float f_value) {
    return f_value >= 0;
}

float get_middle_value(float first, float last) {
    return (first + last) / 2.0;
}

float root(std::vector<float> interval) {
    float x_value;
    bool positive_f_on_first_boundary = f_sign_positive(f(interval.front()));

    for (int i = 0; i < ITERATION_COUNT; ++i) {
        x_value = get_middle_value(interval.front(), interval.back());
        bool positive_f_on_middle_point = f_sign_positive(f(x_value));

        if (positive_f_on_first_boundary == positive_f_on_middle_point) {
            interval.front() = x_value;
        } else {
            interval.back() = x_value;
        }
    }
    return x_value;
}

int main() {
    std::vector<float> interval = {0.5, 2};
    std::cout << root(interval);
    
    return 0;
}
