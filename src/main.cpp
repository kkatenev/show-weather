#include <iostream>
#include "weather.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Error, use it like this: " << argv[0] << " Tokyo London ... CityN" << std::endl;
        return 1;
    }

    std::string apiKey = "11609216badd4399a9653802242706";
    Weather weather(apiKey);
    for (int i = 1; i < argc; ++i) {
        std::string city = argv[i];
        std::string weatherInfo = weather.getWeather(city);
        std::cout << weatherInfo << std::endl;
    }
    return 0;
}
