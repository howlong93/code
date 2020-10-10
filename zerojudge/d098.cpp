#include <bits/stdc++.h>                                                        
                                                                                
using namespace std;                                                            
bool if_num(string);                                                            
                                                                                
int main() {                                                                    
    string input, keep;                                                         
                                                                                
    while (getline(cin, input)) {                                               
        stringstream ss;                                                        
        long long int isnum, sum = 0;                                           
        ss << input;                                                            
                                                                                
        while (ss >> keep) {                                                    
            if (if_num(keep)) {                                                 
                stringstream ll;                                                
                ll << keep;                                                     
                ll >> isnum;                                                    
                sum += isnum;                                                   
            }                                                                   
        }                                                                       
                                                                                
        cout << sum << "\n";                                                    
    }                                                                           
                                                                                
    return 0;                                                                   
}                                                                               
                                                                                
bool if_num(string seg) {                                                       
    for (auto k : seg)                                                          
        if (!(k >= '0' && k <= '9')) {                                          
            return false;                                                       
        }                                                                       
                                                                                
    return true;                                                                
}
