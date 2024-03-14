#include <algorithm>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

struct Student {
  string name;
  vector<int> scores;
};

// Calculates and writes statistics for each student
// Throws an exception if there are no scores for a student
void writeStatistics(const vector<Student>& students) {
  for (const auto& student : students) {
    if (student.scores.empty()) {
      throw runtime_error("Error: Student " + student.name + " has no scores.");
    }

    // Calculate average score
    const double average = accumulate(student.scores.begin(), student.scores.end(), 0.0) / student.scores.size();

    // Find highest and lowest scores
    const auto [min, max] = minmax_element(student.scores.begin(), student.scores.end());

    // Output statistics
    cout << "\nStudent: " << student.name << endl;
    cout << "Average Score: " << average << endl;
    cout << "Highest Score: " << *max << endl;
    cout << "Lowest Score: " << *min << endl;
  }
}

// Calculates overall average score and finds students with highest and lowest average scores
void calculateOverallStatistics(const vector<Student>& students) {
  // Calculate overall average score
  double totalScore = 0;
  int totalStudents = 0;
  for (const auto& student : students) {
    totalScore += accumulate(student.scores.begin(), student.scores.end(), 0.0);
    totalStudents += student.scores.size();
  }
  const double overallAverage = totalScore / totalStudents;
  cout << "\nOverall Average Score: " << overallAverage << endl;

  // Find students with highest and lowest average scores
  auto highestScoringStudents = students;
  auto lowestScoringStudents = students;
  sort(highestScoringStudents.begin(), highestScoringStudents.end(),
       [](const Student& a, const Student& b) {
         return accumulate(a.scores.begin(), a.scores.end(), 0.0) / a.scores.size()
             > accumulate(b.scores.begin(), b.scores.end(), 0.0) / b.scores.size();
       });
  sort(lowestScoringStudents.begin(), lowestScoringStudents.end(),
       [](const Student& a, const Student& b) {
         return accumulate(a.scores.begin(), a.scores.end(), 0.0) / a.scores.size()
             < accumulate(b.scores.begin(), b.scores.end(), 0.0) / b.scores.size();
       });

  // Output highest and lowest scoring students
  cout << "Student(s) with Highest Average Score: ";
  for (const auto& student : highestScoringStudents) {
    cout << student.name << " ";
  }
  cout << endl;

  cout << "Student(s) with Lowest Average Score: ";
  for (const auto& student : lowestScoringStudents) {
    cout << student.name << " ";
  }
  cout << endl;
}

int main() {
  vector<Student> students = {
    {"Alice", {80, 85, 90}},
    {"Bob", {75, 70, 65}},
    {"Charlie", {90, 95, 85}}
  };

  try {
    writeStatistics(students);
    calculateOverallStatistics(students);
  } catch (const exception& ex) {
    cerr << "Error occurred: " << ex.what() << endl;
    return 1;
  }

  return 0;
}
