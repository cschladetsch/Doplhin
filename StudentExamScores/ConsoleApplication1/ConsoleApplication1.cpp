#include <algorithm>
#include <iomanip>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

using namespace std;

struct Student {
  string name;
  vector<int> scores;
};

// TODO: generate code for the writeStatistics function
void writeStatistics(const vector<Student>& students) {
  // Check for empty students vector
  if (students.empty()) {
    throw runtime_error("Error: Empty student vector provided.");
  }

  // Calculate overall average score
  double overallAverage = 0.0;
  int totalScores = 0;
  for (const auto& student : students) {
    totalScores += student.scores.size();
    for (const auto& score : student.scores) {
      overallAverage += score;
    }
  }
  overallAverage /= totalScores;

  // Iterate through students and output statistics
  for (const auto& student : students) {
    // Calculate student average
    double studentAverage = 0.0;
    for (const auto& score : student.scores) {
      studentAverage += score;
    }
    studentAverage /= student.scores.size();

    // Find highest and lowest scores
    auto minMax = minmax_element(student.scores.begin(), student.scores.end());

    cout << "Student: " << student.name << endl;
    cout << "Average Score: " << setprecision(2) << fixed << studentAverage << endl;
    cout << "Highest Score: " << *minMax.second << endl;
    cout << "Lowest Score: " << *minMax.first << endl;
    cout << endl;
  }

  // Display overall average score
  cout << "Overall Average Score: " << setprecision(2) << fixed << overallAverage << endl;

  // Find students with highest and lowest averages
  optional<double> highestAverage, lowestAverage;
  vector<string> highestScoringStudents, lowestScoringStudents;

  for (const auto& student : students) {
    double studentAverage = 0.0;
    for (const auto& score : student.scores) {
      studentAverage += score;
    }
    studentAverage /= student.scores.size();

    if (!highestAverage || studentAverage > *highestAverage) {
      highestAverage = studentAverage;
      highestScoringStudents.clear();
      highestScoringStudents.push_back(student.name);
    } else if (studentAverage == *highestAverage) {
      highestScoringStudents.push_back(student.name);
    }

    if (!lowestAverage || studentAverage < *lowestAverage) {
      lowestAverage = studentAverage;
      lowestScoringStudents.clear();
      lowestScoringStudents.push_back(student.name);
    } else if (studentAverage == *lowestAverage) {
      lowestScoringStudents.push_back(student.name);
    }
  }

  // Display students with highest and lowest averages
  cout << "Student(s) with Highest Average Score: ";
  for (const auto& student : highestScoringStudents) {
    cout << student << " ";
  }
  cout << endl;

  cout << "Student(s) with Lowest Average Score: ";
  for (const auto& student : lowestScoringStudents) {
    cout << student << " ";
  }
  cout << endl;
}

int main() {
  vector<Student> students = {
    {"Alice", {80,85,90}},
    {"Bob", {75,70,65}},
    {"Charlie", {90,95,85}}
  };

  try {
    writeStatistics(students);
  } catch (const exception& e) {
    cerr << "Error occurred: " << e.what() << endl;
    return 1;
  }

  return 0;
}