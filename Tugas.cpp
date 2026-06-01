#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>

using namespace std;

//enkapsulasi
class TokoElektronik {
private:
    array<string, 3> etalase;

public:
    // Constructor
    TokoElektronik() {
        etalase[0] = "Laptop";
        etalase[1] = "Smartphone";
        etalase[2] = "Printer";
    }

};