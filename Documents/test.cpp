#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

enum class RootCount { kZero, kOne, kTwo, kInf };

struct Roots {
    RootCount count;
    double first;
    double second;
};

Roots SolveQuadratic(int a, int b, int c) {
    Roots answer;
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                answer.count = RootCount::kInf;
            } else {
                answer.count = RootCount::kZero;
            }
        } else {
            answer.count = RootCount::kOne;
            answer.first = -static_cast<double>(c) / b;
        }

    } else {
        int discr = (b * b - 4 * a * c);
        std::cout << discr << "\n";
        if (discr < 0) {
            answer.count = RootCount::kZero;
        } else if (discr == 0) {
            answer.count = RootCount::kOne;
            answer.first = -static_cast<double>(b) / (2 * a);
        } else {
            double halfdiff =
                abs(std::sqrt(static_cast<double>(discr)) / (2 * a));
            std::cout << halfdiff << " "
                      << std::sqrt(static_cast<double>(discr)) / (2 * a)
                      << "\n";
            double avg = -static_cast<double>(b) / (2 * a);
            answer.count = RootCount::kTwo;
            answer.first = avg - halfdiff;
            answer.second = avg + halfdiff;
        }
    }
    return answer;
}
int main() {
    Roots ans;
    int a;
    int b;
    int c;
    std::cin >> a >> b >> c;
    ans = SolveQuadratic(a, b, c);
    std::cout << ans.first << " " << ans.second << " "
              << static_cast<int>(ans.count);
}