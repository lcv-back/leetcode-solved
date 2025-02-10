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
	AuthenticationManager authManager(5); // Thời gian sống của mã thông báo là 5 giây
    
    // Tạo một số mã thông báo
    authManager.generate("token1", 1);
    authManager.generate("token2", 2);
    
    // Gia hạn mã thông báo "token1"
    authManager.renew("token1", 3);
    
    // Đếm số lượng mã thông báo chưa hết hạn tại thời gian t = 6
    cout << "Unexpired Tokens at time 6: " << authManager.countUnexpiredTokens(6) << endl; // Kết quả là 2

    // Đếm số lượng mã thông báo chưa hết hạn tại thời gian t = 7
    cout << "Unexpired Tokens at time 7: " << authManager.countUnexpiredTokens(7) << endl; // Kết quả là 1
    
    return 0;
}