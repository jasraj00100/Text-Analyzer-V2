// Terxt Analyzer Advanced

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int count_letters = 0;
int count_digits = 0;
int count_spaces = 0;

// this funtion is created measure the frequency of letters
void letters(const string& text){
    // hashing of charcters are used 
    int hash[26] = {0};
    for(int i = 0;i < text.size();i++){
        if(text[i] >= 'a' && text[i] <= 'z'){
            hash[text[i]-'a']++;
            count_letters++;
        }
    }

    int i = 0;
    int n = 26;
    string letters = "abcdefghijklmnopqrstuvwxyz";
    while (n--){ 
        // this will only display the letters that are present in the text
        if(hash[i] != 0){
            cout << letters[i] << " -> ";
            cout << hash[letters[i]-'a'] << endl;
        }
        i++;
    }
    cout << "\n";
}

// this funtion is created to count numbers
void digits(const string& text){
    int hash2[10] = {0};
    for(int i = 0;i < text.size();i++){
        if(text[i] >= '0' && text[i] <= '9'){
            hash2[text[i] - '0']++;
            count_digits++;
        }
    }

    int j = 0;
    int m = 10;
    string numbers = "0123456789";
    while (m--){
        if(hash2[j] != 0){
            cout << numbers[j] << " -> ";
            cout << hash2[numbers[j] - '0'] << endl;
        }
        j++;
    }
    cout << "\n";
}

// this funtion is created to count spaces
void spaces(const string& text){
    int count = 0;
    for (int i = 0; i < text.size(); i++){
        if(text[i] == ' '){
            count++;
            count_spaces++;
        }
    }
    cout << "spaces -> " << count << endl;
    cout << "\n";
}

// this function counts total number of words in the text
void words_counter(const string& text){
    int counter = 0;
    // first of all imagine you are counting the word
    // first word you count as 1 and then space is between it so you ignore it 
    // then next word comes in then you count it as 2 and then you are inside the word until space comes
    bool insideword = false;
    for(int i = 0;i<text.size();i++){
        if(text[i] == ' '){
            insideword = false;
        }
        else{
            if(insideword == false){
                counter++;
                insideword = true;
            }
        }
    }
    cout << "Words -> " << counter << endl;
    cout << "\n";
}

void special_characters(const string& text){
    cout << "Special Characters -> " << text.size() - (count_letters + count_digits + count_spaces );
    cout << endl;
}

int main(){
    string text = "";
    string line;
    // taking input(sentences) from the user
    cout << "Enter your text (press Enter twice to finish):\n";
    // getline() - Read everything until Enter is pressed.
    while (true){
        getline(cin,line);
        
        if(line.empty()){
            break;
        }
        if(!text.empty()){
            text += ' ';
        }
        text += line;
    }

    // this will change any upper case letter to lower case
    transform(text.begin(), text.end(), text.begin(), ::tolower);

    letters(text);
    digits(text);
    spaces(text);
    words_counter(text);
    cout << "Total Characters -> " << text.size() << endl;
    special_characters(text);
    
    return 0;
}
