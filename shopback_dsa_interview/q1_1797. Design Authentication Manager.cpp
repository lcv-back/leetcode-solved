#include<iostream>
#include<unordered_map>
#include <vector>
using namespace std;

class Token {
public:
	int expirationTime;
	Token(int expiration) : expirationTime(expiration) {}
};

class AuthenticationManager {
private:
	int timeToLive;
	unordered_map<string, Token*> tokens; // set tokenId is key

public:
    AuthenticationManager(int timeToLive) {      
    	this->timeToLive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = new Token(currentTime + timeToLive);
    }
    
    void renew(string tokenId, int currentTime) {
        if(tokens.find(tokenId) != tokens.end()){
        	Token* token = tokens[tokenId];
        	if(token->expirationTime > currentTime){
        		token->expirationTime = currentTime + timeToLive;
        	}
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for(auto& entry : tokens){
        	Token* token = entry.second;
        	if(token->expirationTime > currentTime){
        		count++;
        	}
        }
        return count;
    }
};

int main(){
	AuthenticationManager authManager(5); // time to live is 5
    
    // generate token
    authManager.generate("token1", 1);
    authManager.generate("token2", 2);
    
    // renew token1
    authManager.renew("token1", 3);
    
    // counting unexpired tokens at time t = 6
    cout << "Unexpired Tokens at time 6: " << authManager.countUnexpiredTokens(6) << endl; // 2

    // counting unexpired tokens at time t = 7
    cout << "Unexpired Tokens at time 7: " << authManager.countUnexpiredTokens(7) << endl; // 1
    
    return 0;
}