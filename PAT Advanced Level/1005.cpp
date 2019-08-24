#include<iostream>
#include<string>
#include<vector>

using namespace std;

string num_to_word[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int get_digit(long long a) {
    return a % 10;
}

int main() {
    string n;
    cin>>n;

    long long result = 0;
    for(long long i = 0; i < n.length(); i++){
        result += n[i] - '0';
    }

    vector<string> output;
    if(result == 0){
        cout<<num_to_word[result];
        return 0;
    }
    while(result) {
        int digit = get_digit(result);
        output.push_back(num_to_word[digit]);
        result /= 10;
    }

    for(int i = output.size()-1; i >= 0; i--) {
        cout<<output[i]<<(i ? " " : "\0");
    }

    return 0;
}
