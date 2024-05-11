#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Coupon {
    int rank;
    string product;
};

class CouponStack {
private:
    Coupon* list;
    int maxsize;
    int top;

public:
    CouponStack(int size = 10) {
        maxsize = size;
        list = new Coupon[maxsize];
        top = -1;
    }

    ~CouponStack() {
        delete[] list;
    }

    bool isFull() const {
        return top == maxsize - 1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    void push(const Coupon& coupon) {
        if (!isFull()) {
            list[++top] = coupon;
        } else {
            cout << "Stack is full." << endl;
        }
    }

    Coupon pop() {
        if (!isEmpty()) {
            return list[top--];
        } else {
            cout << "No coupon to remove." << endl;
            return Coupon{0, ""}; // Return an empty coupon if stack is empty
        }
    }
};

int main() {
    int stackSize;
    cin >> stackSize; // Read stack size
    cin.ignore(); // Ignore any newline after the size input

    CouponStack stack(stackSize);
    string line;

    while (getline(cin, line)) {
        if (line.empty()) {
            continue;
        }

        if (line[0] == '+') {
            stringstream ss(line.substr(1)); // Create a stream from the line minus the '+'
            int rank;
            string product;
            ss >> rank;
            getline(ss, product);
            if (!product.empty() && product[0] == ' ') {
                product = product.substr(1); // Remove leading space from product name
            }
            Coupon newCoupon = {rank, product};
            stack.push(newCoupon);
        } else if (line[0] == '-') {
            Coupon removedCoupon = stack.pop();
            if (removedCoupon.rank != 0) { // Check if a valid coupon was popped
                cout << removedCoupon.rank << "등 - " << removedCoupon.product << endl;
            }
        } else if (line == "q") {
            break; // Exit the loop if 'q' is entered
        }
    }

    return 0;
}
