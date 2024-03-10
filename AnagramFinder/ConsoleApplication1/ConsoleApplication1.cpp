#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>
#include <map>

// Remove punctuation and convert to lowercase
std::string normalize(std::string_view input) {
    std::string result;
    std::ranges::for_each(input | std::views::transform(tolower) | std::views::filter([](char c) { return isalpha(c); }),
                          [&result](char c) { result.push_back(c); });
    return result;
}

// Find anagrams within a vector of words
std::vector<std::vector<std::string>> find_anagrams(const std::vector<std::string>& words) {
    // Create a map to store anagrams grouped by their sorted form
    std::map<std::string, std::vector<std::string>> anagram_map;

    // Iterate through words and add them to the map
    for (const auto& word : words) {
        std::string normalized_word = normalize(word);
        std::sort(normalized_word.begin(), normalized_word.end());
        anagram_map[normalized_word].push_back(word);
    }

    // Create a vector of anagram groups
    std::vector<std::vector<std::string>> anagram_groups;

    // Iterate through the map and extract groups with more than one anagram
    for (const auto& [_, anagrams] : anagram_map) {
        if (anagrams.size() > 1) {
            anagram_groups.push_back(anagrams);
        }
    }

    return anagram_groups;
}

int main() {
    try {
        // Read words from standard input
        std::vector<std::string> words;
        std::string word;
        while (std::cin >> word) {
            words.push_back(word);
        }

        // Find anagrams
        std::vector<std::vector<std::string>> anagram_groups = find_anagrams(words);

        // Print anagram groups
        int group_number = 1;
        for (const auto& anagrams : anagram_groups) {
            std::cout << "Group " << group_number++ << std::endl;
            for (const auto& anagram : anagrams) {
                std::cout << "- " << anagram << std::endl;
            }
        }

    } catch (const std::exception& e) {
        // Handle exceptions and provide additional context
        std::cerr << "Error: " << e.what() << " (main())" << std::endl;
        return 1;
    }

    return 0;
}


/*
```

## Example Usage

```bash
$ cat ./another_input.txt
eat tea apple leap pale car care arc
$ cat ./another_input.txt | ./find_anagrams
Group 1
- eat
- tea
Group 2
- leap
- pale
Group 3
- car
- care
- arc
```
*/