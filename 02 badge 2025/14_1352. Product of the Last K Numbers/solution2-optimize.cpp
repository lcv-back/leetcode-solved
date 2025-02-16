#include<iostream>
#include<vector>
using namespace std;

class ProductOfNumbers {
private:
    // Stores cumulative product of the stream
    vector<int> prefixProduct;
    int size = 0;

public:
    ProductOfNumbers() {
        // Initialize the product list with 1 to handle multiplication logic
        prefixProduct.push_back(1);
        size = 0;
    }

    void add(int num) {
        if (num == 0) {
            // If num is 0, reset the cumulative products since multiplication
            // with 0 invalidates previous products
            prefixProduct = {1};
            size = 0;
        } else {
            // Append the cumulative product of the current number with the last
            // product
            prefixProduct.push_back(prefixProduct[size] * num);
            size++;
        }
    }

    int getProduct(int k) {
        // Check if the requested product length exceeds the size of the valid
        // product list
        if (k > size) return 0;

        // Compute the product of the last k elements using division
        return prefixProduct[size] / prefixProduct[size - k];
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
