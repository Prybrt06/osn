#include <iostream>
#include <vector>

using namespace std;

// Function to segment an array into two parts based on an index
pair<vector<int>, vector<int> > segmentArray(const vector<int> &inputArray, size_t index)
{
    if (index >= inputArray.size())
    {
        cerr << "Invalid index for array segmentation." << endl;
        // Returning empty vectors as an indication of an error or invalid input
        return make_pair(vector<int>(), vector<int>());
    }

    // Create two segments based on the specified index
    vector<int> segment1(inputArray.begin(), inputArray.begin() + index);
    vector<int> segment2(inputArray.begin() + index, inputArray.end());

    return make_pair(segment1, segment2);
}

int main()
{
    // Example usage
    vector<int> inputArray;

    for (int i = 1; i <= 10; i++)
    {
        inputArray.push_back(i);
    }
    size_t segmentIndex = 4;

    // Segment the array
    auto segments = segmentArray(inputArray, segmentIndex);

    // Display the segmented arrays
    cout << "Segment 1: ";
    for (int value : segments.first)
    {
        cout << value << " ";
    }
    cout << endl;

    cout << "Segment 2: ";
    for (int value : segments.second)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
