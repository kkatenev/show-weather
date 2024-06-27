#include <string>
#include <curl/curl.h>
#include "../include/json.hpp"

class Weather {
  public:
      Weather(const std::string& apiKey);
      std::string getWeather(const std::string& city);

  private:
      std::string apiKey;
      static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
};
