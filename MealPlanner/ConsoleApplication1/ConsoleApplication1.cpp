#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>
#include <charconv>

using namespace std;

enum class MealType {
    Breakfast,
    Lunch,
    Dinner,
    Dessert
};

class MealPlanner {

};


struct ArgumentParser {

    ArgumentParser();
    
    static pair<string, int> parse(int argc, char** argv) {
        return {"foo", 200};
    }
};

int main(int argc, char** argv) {
    ArgumentParser parser;
    auto [fileName, calories] = parser.parse(argc, argv);
    return 0;
}

