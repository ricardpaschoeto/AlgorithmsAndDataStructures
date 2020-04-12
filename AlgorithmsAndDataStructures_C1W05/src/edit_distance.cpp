#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;

int edit_distance(const string &str1, const string &str2) {
    int insertion = 0, deletion = 0, match = 0, mismatch = 0;
    int minimum = 0;
    std::vector<std::vector<int> > D(str1.length()+1, std::vector<int>(str2.length()+1, 0));
    std::vector<char> nstr1(str1.length() + 1,' ');
    std::vector<char> nstr2(str2.length() + 1,' ');
    for (size_t i = 0; i <= str1.length(); i++)
    {
        D[i][0] = i;
        if(i < str1.length())
            nstr1[i + 1] = str1[i];
    }

    for (size_t j = 0; j <= str2.length(); j++)
    {
        D[0][j] = j;
        if (j < str2.length())
            nstr2[j + 1] = str2[j];
    }

    for (size_t j = 1; j <= str2.length(); j++)
    {
        for (size_t i = 1; i <= str1.length(); i++)
        {
            insertion = D[i][j - 1] + 1;
            deletion = D[i - 1][j] + 1;
            match = D[i-1][j-1];
            mismatch = D[i - 1][j - 1] + 1;
            minimum = std::min(insertion, deletion);
            if (nstr1[i] == nstr2[j])
                D[i][j] = std::min(minimum,match);
            else
                D[i][j] = std::min(minimum, mismatch);
        }
    }

  return D[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
