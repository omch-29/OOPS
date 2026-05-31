#include <bits/stdc++.h>
using namespace std;

class URLShortener {
private:
    unordered_map<string, string> longToShort;
    unordered_map<string, string> shortToLong;
    long long counter = 1;
    const string base62 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    // Encode counter to Base62
    string encode(long long num) {
        string shortUrl = "";
        while (num > 0) {
            shortUrl += base62[num % 62];
            num /= 62;
        }
        reverse(shortUrl.begin(), shortUrl.end());
        return shortUrl;
    }

public:
    string shortenURL(const string& longURL) {
        string domain = "https://tiny.ly/";
        // If already exists
        if (longToShort.find(longURL) != longToShort.end()) {
            return domain+longToShort[longURL];
        }

        // Generate new short URL
        
        string shortURL = encode(counter++);

        longToShort[longURL] = shortURL;
        shortToLong[shortURL] = longURL;

        return domain+shortURL;
    }

    string getOriginalURL(const string& shortURL) {
        string key = shortURL;
        string domain = "https://tiny.ly/";
        if (shortURL.find(domain) == 0) {
        key = shortURL.substr(domain.length());
    }
        if (shortToLong.find(key) != shortToLong.end()) {
            return shortToLong[key];
        }
        return "URL not found";
    }
};

// Driver code
int main() {
    URLShortener obj;

    string longURL1 = "https://example.com/very/long/url/1";
    string longURL2 = "https://example.com/very/long/url/2";

    string short1 = obj.shortenURL(longURL1);
    string short2 = obj.shortenURL(longURL2);

    cout << "Short URL 1: " << short1 << endl;
    cout << "Short URL 2: " << short2 << endl;

    cout << "Original URL 1: " << obj.getOriginalURL(short1) << endl;
    cout << "Original URL 2: " << obj.getOriginalURL(short2) << endl;

    return 0;
}