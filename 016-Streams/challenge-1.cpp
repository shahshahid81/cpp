#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City
{
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country
{
    std::string name;
    std::vector<City> cities;
};

struct Tours
{
    std::string title;
    std::vector<Country> countries;
};

void print_tour_data(Tours &tours);

int main()
{
    Tours tours{"Tour Ticket Prices from Miami",
                {
                    {
                        "Colombia",
                        {{"Bogota", 8778000, 400.98},
                         {"Cali", 2401000, 424.12},
                         {"Medellin", 2464000, 350.98},
                         {"Cartagena", 972000, 345.34}},
                    },
                    {
                        "Brazil",
                        {{"Rio De Janiero", 13500000, 567.45},
                         {"Sao Paulo", 11310000, 975.45},
                         {"Salvador", 18234000, 855.99}},
                    },
                    {
                        "Chile",
                        {{"Valdivia", 260000, 569.12},
                         {"Santiago", 7040000, 520.00}},
                    },
                    {"Argentina", {{"Buenos Aires", 3010000, 723.77}}},
                }};

    print_tour_data(tours);

    std::cout << std::endl
              << std::endl;
    return 0;
}

void print_tour_data(Tours &tours)
{
    const short width = 70;
    const short country_width = 20;
    const short city_width = 20;
    const short population_width = 15;
    const short price_width = 15;
    const short space = (width - tours.title.length()) / 2;
    std::cout << std::endl
              << std::setw(space) << "" << tours.title << std::endl
              << std::endl;

    std::cout << std::setw(country_width) << std::left << "Country"
              << std::setw(city_width) << std::left << "City"
              << std::setw(population_width) << std::right << "Population"
              << std::setw(price_width) << std::right << "Price"
              << std::endl;

    std::cout << std::setw(width) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');

    for (auto &country : tours.countries)
    {

        bool first_row = true;
        for (auto &city : country.cities)
        {
            std::cout << std::setw(country_width) << std::left << (first_row ? country.name : "");
            std::cout << std::setw(city_width) << std::left << city.name;
            std::cout << std::setw(population_width) << std::right << city.population;
            std::cout << std::setw(price_width) << std::right << std::setprecision(2) << std::fixed << city.cost;
            std::cout << std::endl;
            first_row = false;
        }
    }
}
