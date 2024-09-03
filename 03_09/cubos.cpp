#include <iostream>

using namespace std;

int cubos(int n){
    if (n == 0) {
        return 0;
    }
    return (n * n * n) + cubos(n-1);
};

int main() {
    cout << cubos(5) << endl;
    return 0;
}