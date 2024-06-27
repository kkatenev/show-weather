#include "weather.h"
#include <iostream>
#include <sstream>

Weather::Weather(const std::string& apiKey) : apiKey(apiKey) {}

size_t Weather::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string Weather::getWeather(const std::string& city) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    std::ostringstream urlStream;
    urlStream << "http://api.weatherapi.com/v1/current.json?key=" << apiKey << "&q=" << city;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, urlStream.str().c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    auto json = nlohmann::json::parse(readBuffer);
    std::ostringstream result;
    result << "Weather in " << city << ": " << json["current"]["condition"]["text"] << ", "
           << json["current"]["temp_c"] << "°C";

    return result.str();
}
