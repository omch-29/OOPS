#include<bits/stdc++.h>
using namespace std;

class urlShortener{
private:
    unordered_map<string,string>shortToLong;
    unordered_map<string,string>longToShort;
    long long counter=1;
    const string domain="https://tiny.ly/";
    const string base="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string encode(long long cnt){
        string shortUrl;
        while(cnt>0){
            shortUrl+=base[cnt%62];
            cnt/=62;
        }
        reverse(shortUrl.begin(), shortUrl.end());
        return shortUrl;
    }
public:
    string getShortUrl(string longUrl){
        if(longToShort.find(longUrl)!=longToShort.end()){
            return longToShort[longUrl];
        }
        string shortUrl=encode(counter++);
        longToShort[longUrl]=shortUrl;
        shortToLong[shortUrl]=longUrl;
        return domain+shortUrl;
    }
    string getOriginalUrl(string shortUrl){
        string key=shortUrl;
        if(key.find(domain)==0){
            key=key.substr(domain.length());
        }
        if(shortToLong.find(key)!=shortToLong.end()){
            return shortToLong[key];
        }
        return "Url not Shortened";
    }
};
int main(){
    urlShortener obj;
    string longURL1 = "https://example.com/very/long/url/1";
    string longURL2 = "https://example.com/very/long/url/2";

    string short1 = obj.getShortUrl(longURL1);
    string short2 = obj.getShortUrl(longURL2);

    cout << "Short URL 1: " << short1 << endl;
    cout << "Short URL 2: " << short2 << endl;

    cout << "Original URL 1: " << obj.getOriginalUrl(short1) << endl;
    cout << "Original URL 2: " << obj.getOriginalUrl(short2) << endl;

    return 0;
}