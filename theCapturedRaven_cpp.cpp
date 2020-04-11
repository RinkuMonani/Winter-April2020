#include<bits/stdc++.h>
#include<string>
typedef long long int ll;

using namespace std;

string decompress(string s){
    string result;
    for(int i=0;i<s.size();i++){
        if(isalpha(s[i])){
            result+=s[i];
        }
        else if((int)s[i]>48 && (int)s[i] <58){
            int numstart = i;
            string temp="";
            while(s[i]!='[') i++;
            int repeats = stoi(s.substr(numstart,i));
            i++;
            int openleft=1;
            while(true){
                if(s[i]==']'){
                    openleft--;
                    if(openleft==0)
                        break;
                    else
                        temp+=s[i];
                }
                else if(s[i]=='['){
                    openleft++;
                    temp+=s[i];
                }else{
                    temp+=s[i];
                }
                i++;
        }
        string sub = decompress(temp);
        for(int k=0;k<repeats;k++){
            result += sub;
        }
    }
    }
    return result;
}

int main(){
    string str;
    cin>>str;
    cout<<decompress(str);
}

