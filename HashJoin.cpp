#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

// Generate random numbers in a given range
vector<int> generateRandomNumbers(int max, int min, int size) {
    vector<int> dataElements(size);
    for (int i = 0; i < size; i++) {
        dataElements[i] = min + rand() % (max - min + 1);
    }
    return dataElements;
}

// Filter values within a given range
vector<pair<int, int>> withinRange(int min, int max, vector<int> values) {
    vector<pair<int, int>> filteredRange;
    for (int i = 0; i < values.size(); i++) {
        if (values[i] >= min && values[i] <= max) {
            filteredRange.push_back({i, values[i]});
        }
    }
    return filteredRange;
}

int main() {
    
    // Generate random values for data columns A and B
    vector<int> colA = generateRandomNumbers(200, 0, 200); // For Column A :: Range between 0 to 200, Size 200
    vector<int> colB = generateRandomNumbers(200, 100, 200); // For Column B :: Range between 100 to 200, Size 200

    // Filter values for the range between the range between 120 to 140
    vector<pair<int, int>> filteredRangeA = withinRange(120, 140, colA);
    vector<pair<int, int>> filteredRangeB = withinRange(120, 140, colB);

    // Print filtered values for data columns A and B
    cout << "Filtered Data Column A (Index, Value):-\n";
    for (int i = 0; i < filteredRangeA.size(); i++) {
        cout << "A[" << filteredRangeA[i].first << "] = " << filteredRangeA[i].second << "\n";
    }

    cout << "\nFiltered Data Column B (Index, Value):-\n";
    for (int i = 0; i < filteredRangeB.size(); i++) {
        cout << "B[" << filteredRangeB[i].first << "] = " << filteredRangeB[i].second << "\n";
    }

    // Hash table for filtered Column B to store all indices for each value
    unordered_map<int, vector<int>> hashTableB; // Hash table where key = value, value = list of indices 
    for (int i = 0; i < filteredRangeB.size(); i++) {
        hashTableB[filteredRangeB[i].second].push_back(filteredRangeB[i].first); // Append index to the vector
    }

    // Match values between filtered data columns A and B
    vector<pair<int, pair<int, int>>> result; // To store the matching pairs between data column A and B along with the value
    for (int i = 0; i < filteredRangeA.size(); i++) {
        int valueA = filteredRangeA[i].second; // Value from data column A
        if (hashTableB.find(valueA) != hashTableB.end()) { // Check if value exists in hash table
            // Append all indexes with same value to result
            for (int j = 0; j < hashTableB[valueA].size(); j++) { 
                result.push_back({filteredRangeA[i].first, {hashTableB[valueA][j], valueA}}); // Insert match between A and B
            }
    
        }
    }

    // Final output
    cout << "\nMatching and combining indices and values:-\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "A[" << result[i].first << "] == B[" << result[i].second.first << "] <Value:: " << result[i].second.second << ">\n";
    }

    return 0;
}