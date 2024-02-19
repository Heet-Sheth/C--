#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> boyer_moore(const string &text, const string &pattern)
{
    int i, j, h; // Declare variables i, j, and h

    vector<int> occurrences;

    // Preprocess the bad character heuristic
    unordered_map<char, int> bad_character_shifts;
    for (int i = 0; i < pattern.length(); ++i)
    {
        bad_character_shifts[pattern[i]] = pattern.length() - 1 - i;
    }

    // Preprocess the good suffix heuristic
    vector<int> good_suffix_shifts(pattern.length(), pattern.length());
    i = pattern.length() - 1;
    j = pattern.length() - 1;
    h = pattern.length();

    while (i > 0)
    {
        while (j >= 0 && pattern[j] == pattern[i - 1])
        {
            j--;
        }

        if (j < 0)
        {
            good_suffix_shifts[i - 1] = h;
            h = i;
        }
        else
        {
            h = min(h, j + 1);
        }

        i--;
    }

    // Search for the pattern in the text
    i = pattern.length() - 1;
    j = pattern.length() - 1;

    while (i < text.length())
    {
        while (j >= 0 && pattern[j] == text[i + j])
        {
            j--;
        }

        if (j < 0)
        {
            occurrences.push_back(i);

            i += pattern.length();
            j = pattern.length() - 1;
        }
        else
        {
            int skip = bad_character_shifts[text[i + j]];
            skip = max(skip, good_suffix_shifts[pattern[j]]);
            i += skip;
            j = pattern.length() - 1;
        }
    }

    return occurrences;
}

int main()
{
    string text = "haystack needle in a haystack";
    string pattern = "needle";

    vector<int> occurrences = boyer_moore(text, pattern);

    for (int i = 0; i < occurrences.size(); ++i)
    {
        cout << occurrences[i] << endl;
    }

    return 0;
}
