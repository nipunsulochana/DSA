#include <iostream>
#include <vector>

std::vector<int> computeLPS(const std::string& pattern) {
    int len = 0; // Length of the previous longest prefix suffix
    std::vector<int> lps(pattern.size(), 0);

    for (int i = 1; i < pattern.size(); ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMP(const std::string& text, const std::string& pattern) {
    std::vector<int> lps = computeLPS(pattern);
    int i = 0; // Index for text[]
    int j = 0; // Index for pattern[]

    while (i < text.size()) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == pattern.size()) {
            std::cout << "Pattern found at index " << i - j << std::endl;
            j = lps[j - 1];
        } else if (i < text.size() && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABCABAB";
    KMP(text, pattern);
    return 0;
}
