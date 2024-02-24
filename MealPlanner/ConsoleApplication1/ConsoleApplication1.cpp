#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <charconv>

using namespace std;

int stringToInt(string_view str) {
    int value;
    auto [p, ec] = from_chars(str.data(), str.data() + str.size(), value);
    if (ec != errc()) {
        throw invalid_argument("Invalid integer " + string(str));
    }
    return value;
}

class MealPlanner {
public:
    enum class MealTime { Breakfast, Lunch, Dinner, Dessert };

    struct FoodItem {
        string name;
        int calories;
        MealTime mealTime;
    };

    void parseData(const string & fileName) {
        ifstream file(fileName);
        if (!file) {
            throw runtime_error("Couldn't open data file: " + fileName);
        }
        string line;
        int lineNumber = 0;
        while (getline(file, line)) {
            ++lineNumber;
            parseLine(line, lineNumber);
        }
    }

    void writeMealPlan(int targetCalories) {
        int totalCalories = calculateTotalCalories();

        if (totalCalories < targetCalories) {
            distributeRemainingCalories(targetCalories - totalCalories);
        }

        writePlan();
    }

private:
    void distributeRemainingCalories(int remainingCalories) {
        auto numDays = _meals.size();
        auto additionalCaloriesPerDay = ceil(remainingCalories / numDays);
        for (auto& [mealTime, items] : _meals) {
            while (remainingCalories > 0) {
                int toAdd = min((int)additionalCaloriesPerDay, (int)remainingCalories);
                items.push_back(FoodItem{ "Additional Item",toAdd, mealTime });
                remainingCalories -= toAdd;
            }
        }
    }

    void writePlan() const {
        for (const auto& [mealTime, items] : _meals) {
            cout << "Meal Time: " << mealNames.at(mealTime) << endl;
            for (const auto& item : items) {
                cout << "- " << item.name << "(" << item.calories << " calories)" << endl;
            }
        }
    }

    void parseLine(const std::string& line, int lineNumber) {
        istringstream iss(line);
        string token;
        vector<string> tokens;
        while (getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 3) {
            throw invalid_argument("Invalid data at " + std::to_string(lineNumber));
        }

        string name = tokens[0];
        int calories = stringToInt(tokens[1]);
        for (auto time : tokens[2]) {
            MealTime mealTime = getMealTime(tokens[2]);
            _meals[mealTime].push_back(FoodItem{ name, calories, mealTime });
        }
    }

    static MealTime getMealTime(const std::string &mealName) {
        static std::map<string, MealTime> mealMap = {
            {"breakfast", MealTime::Breakfast},
            {"lunch", MealTime::Breakfast},
            {"dinner", MealTime::Breakfast},
            {"dessert", MealTime::Dessert},
        };

        auto found = mealMap.find(mealName);
        if (found == mealMap.end()) {
            throw invalid_argument("Invalid meal type " + mealName);
        }

        return found->second;
    }
    
    int calculateTotalCalories() const {
        int total = 0;
        for (const auto& [mealtTime, items] : _meals) {
            for (const auto& item : items) {
                total += item.calories;
            }
        }
        return total;
    }

    map<MealTime, vector<FoodItem>> _meals;
    map<MealTime, string> mealNames = {
        { MealTime::Breakfast, "Breakfast"},
        { MealTime::Lunch, "Lunch"},
        { MealTime::Dinner, "Dinner"},
        { MealTime::Dessert, "Dessert"},
    };
};

pair<string, int> ParseArguments(int argc, char** argv) {
    if (argc < 3) {
        stringstream ss;
        ss << "Usage: " << argv[0] << "<fooditemlist.csv> <daily_calory_target" << endl;
        throw invalid_argument(ss.str());
    }
    return make_pair(argv[1], stringToInt(argv[2]));
}

int main(int argc, char** argv) {
    try {
        auto [fileName, calories] = ParseArguments(argc, argv);

        MealPlanner mealPlanner;
        mealPlanner.parseData(fileName);
        mealPlanner.writeMealPlan(calories);
    }
    catch (const exception& e) {
        std::cerr << "Error: " << e.what() << endl;
    }
    return 0;
}