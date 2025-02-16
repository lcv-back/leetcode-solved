#include<iostream>
#include<vector>
using namespace std;

class ProductOfNumbers {
private:
	vector<int> stream;

public:
    ProductOfNumbers() {
		this->stream = stream;        
    }
    
    void add(int num) {
        this->stream.push_back(num);
    }
    
    int getProduct(int k) {
    	vector<int> temp = stream;
        if(this->stream.size() < k){
        	return 0;
        }

        int cnt = 0;
        int product = 1;
        while(cnt < k){
        	cnt++;
        	product *= (stream[stream.size()-1]);
        	stream.pop_back();
        }

        stream = temp;

        return product;
    }
};

int main(){
	ProductOfNumbers product_of_numbers;
	product_of_numbers.add(3);
	product_of_numbers.add(0);
	product_of_numbers.add(2);
	product_of_numbers.add(5);
	product_of_numbers.add(4);
	cout << product_of_numbers.getProduct(2) << " ";
	cout << product_of_numbers.getProduct(3) << " ";
	cout << product_of_numbers.getProduct(4) << " ";
	product_of_numbers.add(8);
	cout << product_of_numbers.getProduct(2) << " ";
	return 0;
}