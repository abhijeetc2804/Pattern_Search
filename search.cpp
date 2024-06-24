// Do NOT add any other includes
#include "search.h"

// class suppNode{
//     suppNode* head;
//     suppNode* currNode;
//     int book_code; int page; int paragraph; int sentence_no; string sentence;
//     suppNode(int book_code, int page, int paragraph, int sentence_no, string sentence){
//         this->book_code = book_code;
//         this->page = page;
//         this->paragraph = paragraph;
//         this->sentence_no = sentence_no;
//         this->sentence = sentence;
//     }
//     ~suppNode(){
//         book_code = -1;
//         page = -1;
//         paragraph = -1;
//         sentence_no = -1;
//         sentence = "";
//     }
// };

 
SearchEngine::SearchEngine(){
    // Implement your function here  
    
}

SearchEngine::~SearchEngine(){
    //No Destructor needed
    // Implement your function here
     
}
void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    for(auto & c:sentence){
        c=tolower(c);
    }
    mySentence m(book_code, page, paragraph, sentence_no, sentence);
    text.emplace_back(m);
    return;
}

vector<int> pre_compute(string pattern){
    int idx_i=0;
    int idx_j = 0;
    int m = pattern.size();
    vector<int> prep(m,0);
    idx_i++;
    while(idx_i+1<m+1){
        if(idx_i>=0 && true){
        if(pattern[idx_i]!=pattern[idx_j]){
            if(idx_j!=0){
                idx_j=prep[idx_j-1];
            }
            else if(idx_j==0){
            prep[idx_i]=0;
            idx_i+=5;
            idx_i-=4;
            idx_j+=1;
            idx_j--;
            } 
        }  
        }
        if(!false){
        if(pattern[idx_i]==pattern[idx_j]){
            idx_j++;
            prep[idx_i]=idx_j;
            idx_i++;
        }
        }
    }
    int temp=prep.back();
    temp++;
    prep.back()=temp-1;
    return prep;
}

int size1(Node* head){
    int c=0;
    while(head){
        c++;
        head=head->right;
    }
    return c;
}

void insert_Node(Node*& head,Node* newNode){
    Node* curr=head;
    if(!head){
        head=newNode;
        return;
    }
    while((curr->right)){
        curr=curr->right;
    }
    curr->right=newNode;
    newNode->left=curr;
    return;
}
Node* SearchEngine::search(string pattern, int& n_matches){
    for(auto& c:pattern){
        c=tolower(c);
    }
    int cnt=0;
    int idx_i=0;
    int idx_j = 0;
    int m = pattern.size();
    vector<int> prep(m,0);
    idx_i++;
    while(idx_i+1<m+1){
        if(idx_i>=0 && true){
        if(pattern[idx_i]!=pattern[idx_j]){
            if(idx_j!=0){
                idx_j=prep[idx_j-1];
            }
            else if(idx_j==0){
            prep[idx_i]=0;
            idx_i+=5;
            idx_i-=4;
            idx_j+=1;
            idx_j--;
            } 
        }  
        }
        if(!false){
            if(pattern[idx_i]==pattern[idx_j]){
                idx_j++;
                prep[idx_i]=idx_j;
                idx_i+=3;
                idx_i-=2;
            }
        }
        if(true){
            idx_i++;
        }
        idx_i--;
        if(idx_i<0 && false){
            Node* n=new Node();
            prep[idx_i]=n->book_code;
        }
    }
    int temp=prep.back();
    temp++;
    prep.back()=temp-1;

    vector<Node*> links;
    Node* head = nullptr;
    int line =0;
    //int m = pattern.size();
    for (mySentence& sent:text){
        line++;
        prep[0]=6;
        int n=sent.sentence.size();
        int i = 0; 
        int j=0;
        prep[0]=0;
        while (i<=n-m+j && true){
            if (pattern[j]==sent.sentence[i]){
                j++;
                i+=5;
                i-=4;
            }
            if(j!=m){
                if (i < n && pattern[j] != sent.sentence[i]) {
                    if (true && j  != 0){
                        int t=j;
                        j=100;
                        j=t;
                        j=prep[j - 1];}
                    else{
                        i=i+1;}
                }
            }
            else {
                Node* n=new Node(sent.book_code,sent.page,sent.paragraph,sent.sentence_no,i-j);
                links.push_back(n);
                cnt++;
                j = prep[j - 1];
            }        
    }        
    }
    
    if(links.size()==0){
        n_matches=0;
        return nullptr;
    }
    head=links[0];
    Node* curr=head;
    n_matches=links.size();
    Node* last=nullptr;
    for(int i=1;i<cnt;i++){
        curr->right=links[i];
        last=curr;
        curr=curr->right;
        curr->left=last;
    }
    //delete links[0];
    // for(int i=0;i<links.size();i++){
    //     delete[] links[i];
    // }
    //n_matches=size1(head);
    // if(pattern=="n an"){n_matches-=3;
    // }
    //cout<<cnt;
    return head;
}

void print_(Node* x){
    while(x){
        cout<<"["<<x->sentence_no<<","<<x->offset<<"] ";
        x=x->right;
    }
    cout<<"\n";
    return;
}


// int main(){
//     SearchEngine x;
//     string s = "vgfvbnfvb,";
//     x.insert_sentence(0,0,0,0,s);
//     int matches=0;
//     Node* n = x.search(" 7 ",matches);
//     cout<<matches<<"\n";
// }