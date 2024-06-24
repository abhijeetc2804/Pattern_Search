// Do NOT add any other includes
#include "dict.h"

vector<string> tokenize(string s){
    vector<string> v;
    int n = s.size();
    string s1 = "";
    for(int i = 0; i < n; i++){
    char lowercase_char = std::tolower(s[i]);
    bool check = false;
    if(isalpha(lowercase_char)){
        s1.append(1, lowercase_char);
    }
    else if(lowercase_char==' '){
        v.emplace_back(s1);
        s1.clear();
    }
    else{
    switch (lowercase_char){
        case ' ':{v.emplace_back(s1);
                s1.clear();
                break;}
        case '.':{v.emplace_back(s1);
                s1.clear();
                break;}
        case ',':{v.emplace_back(s1);
                s1.clear();
                break;}
        case '\"':{v.emplace_back(s1);
                s1.clear();
                break;}
        case '-':{v.emplace_back(s1);
                s1.clear();
                break;}
        case ':':{v.emplace_back(s1);
                s1.clear();
                break;}
        case '!':{v.emplace_back(s1);
                s1.clear();
                break;}
        case '\'':{v.emplace_back(s1);
                s1.clear();
                break;}
        case '(':{v.emplace_back(s1);
                s1.clear();
                break;}
        case ')':{v.emplace_back(s1);
                s1.clear();
                break;}
        case '?':{v.emplace_back(s1);
                s1.clear();
                break;}
        // case '—':{v.emplace_back(s1);
        //         s1.clear();
        //         break;}
        case '[':{v.emplace_back(s1);
                s1.clear();
                break;}
        case ']':{v.emplace_back(s1);
                s1.clear();
                break;}
        // case '“':{v.emplace_back(s1);
        //         s1.clear();
        //         break;}
        // case '”':{v.emplace_back(s1);
        //         s1.clear();
        //         break;}
        // case '‘':{v.emplace_back(s1);
        //         s1.clear();
        //         break;}
        // case '’':{v.emplace_back(s1);
        //         s1.clear();
        //         break;}
        // case '˙':{v.emplace_back(s1);
        //         s1.clear();
        //         break;}
        case ';':{v.emplace_back(s1);
                s1.clear();
                break;}
        case '@':{v.emplace_back(s1);
                s1.clear();
                break;}
        default:
            s1.append(1, lowercase_char);
        }
    }
    }
    if (s1 != ""){
        v.emplace_back(s1);
    }
    return v;
}

int hash_func(string id){
    int hash_value=0;
    int prime=67;
    int n=id.size();
    int mod=1000003;
    int pow=1;
    for(int i=0;i<n;i++){
        hash_value+=pow*(id[i]);
        if(hash_value>=mod){
            hash_value %= mod;
        }
        pow *= prime;
        if (pow >= mod){
            pow %= mod;
        }
    }
    return hash_value;
}

Dict::Dict() : hash_table(1000003) {
    // Constructor code (if needed)
}

Dict::~Dict(){ 
}

void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    // Implement your function here
    vector<string> v;
    v=tokenize(sentence);
    for (const string& word : v){
        int hash=hash_func(word);
        bool check=false;
        if(word.size()!=0){
        for(auto& entry : hash_table[hash]) {
            if(entry.first==word){
                entry.second++;
                check=true;
                break;
            }
        }
        if(!check){
            hash_table[hash].emplace_back(word, 1);
        }
        }
    }
    return;
}

int Dict::get_word_count(string word){
    // Implement your function here 
    int hash = hash_func(word);
        for (const auto& entry : hash_table[hash]){
            if (entry.first == word) {
                return entry.second;
            }
        }
    return 0; 
}

void Dict::dump_dictionary(string filename){
    // Implement your function here 
    ofstream of;//(filename,ios::app);
    of.open(filename);
    string buffer;
    int c=0;
    vector<string> v;
    for(int i=0;i<1000003; i++){
        for(const auto& entry : hash_table[i]) {
            buffer += entry.first + ", " + to_string(entry.second) + "\n";
            c++;
        }
        if(c>100){
            of<<buffer;
            buffer.clear();
            c=0;
        }
    }
    of<<buffer;
    of.close();
}

// int main(){
//     Dict x;
//     string s="0 00 000 008 032 aaaaaa";
//     x.insert_sentence(0,0,0,0, s);
//     string s1="hello 1 1/2 1/2lb 2lb 1/2 1/2/3 ";
//     x.insert_sentence(0,0,0,1, s1);    
//     x.dump_dictionary("hello.txt");
// }
