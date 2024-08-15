#include <bits/stdc++.h>

const std::string NUMBERS = "0123456789";
const std::string Pi = "3.14";
// using Division_By_Zero_error = 505

class BigInt {
public:
    std::string number;
    BigInt(std::string Number) {
        number = Number;
    }

    std::string add(BigInt &other);

    std::string subtract(BigInt &other);

    std::string multiply(BigInt &other);

    std::string divide(BigInt &other);

    std::string Pow(std::string power);

    std::string bin_AND(BigInt &other);

    std::string bin_OR(BigInt &other);

    std::string bin_NOT();

    std::string bin_XOR(BigInt &other);

    std::string bin_left_shift(std::string shift);

    std::string bin_right_shift(std::string shift);

    std::string ABS();

    bool IS_PRIME();

    std::string GCD(BigInt &other);

    std::string LCM(BigInt &other);

    bool Greater_Than(BigInt &other);

    bool Greater_Than_Equal(BigInt &other);

    bool Less_Than(BigInt &other);

    bool Less_Than_Equal(BigInt &other);

    bool Equal(BigInt &other);

    std::string RAND(int length);

};


// this is for removing all trailing zero in the string(num)
void remove_trailing_zero(std::string &num) {
    reverse(num.begin(), num.end());
    while(num.back() == '0') {
        num.pop_back();
    }
    reverse(num.begin(), num.end());
    if(num.size() == 0) num += '0';
}

// return positive num
std::string Abs(std::string num) {
    if(num[0] == '-') {
        reverse(num.begin(), num.end());
        num.pop_back();
        reverse(num.begin(), num.end());
    }
    remove_trailing_zero(num);
    return num;
} 

// num = -1 * num
std::string negate(std::string num) {
    if(num[0] == '-') return Abs(num);
    return '-' + num;
}

// if 0 then even, else odd
int parity(std::string num) {
    num = Abs(num);
    return (num.back() - '0') % 2;
}


// to make two number of equal lengths
int make_equal(std::string &num1, std::string &num2) {
    int size_1 = num1.size(), size_2 = num2.size();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    for(int i = 0; i < (size_2 - size_1); i++) num1 += '0';
    for(int i = 0; i < (size_1 - size_2); i++) num2 += '0';

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    return (int)num1.size();
}

// multiplyting string by 10 for shift_by steps
std::string shift(std::string num1, int shift_by) {
    // adding 0 to shift the stringw
    for(int i = 0; i < shift_by; i++) num1 += '0';
    return num1;
}

// if num1 >= num1 ? 1 : 0
bool greater_than_equal(std::string num1, std::string num2) {
    int sign_1 = (num1[0] == '-' ? -1 : 1), sign_2 = (num2[0] == '-' ? -1 : 1);
    num1 = Abs(num1);
    num2 = Abs(num2);
    if(num1 == "0") sign_1 = 1;
    if(num2 == "0") sign_2 = 1;
    make_equal(num1, num2);
    if(sign_1 == -1 && sign_2 == -1) {
        return (num2 >= num1);
    }
    else if(sign_1 == -1) {
        return 0;
    }
    else if(sign_2 == -1) return 1;
    return (num1 >= num2);
}

// if num1 == num2 ? 1 : 0
bool equal(std::string num1, std::string num2) {
    int sign_1 = (num1[0] == '-' ? -1 : 1), sign_2 = (num2[0] == '-' ? -1 : 1);
    num1 = Abs(num1);
    num2 = Abs(num2);
    if(num1 == "0") sign_1 = 1;
    if(num2 == "0") sign_2 = 1;
    make_equal(num1, num2);
    if(sign_1 * sign_2 == 1) {
        return (num2 == num1);
    }
    return 0;
}

// if num1 > num2 ? 1 : 0
bool greater_than(std::string num1, std::string num2) {
    int sign_1 = (num1[0] == '-' ? -1 : 1), sign_2 = (num2[0] == '-' ? -1 : 1);
    num1 = Abs(num1);
    num2 = Abs(num2);
    if(num1 == "0") sign_1 = 1;
    if(num2 == "0") sign_2 = 1;
    make_equal(num1, num2);
    if(sign_1 == -1 && sign_2 == -1) {
        return (num2 > num1);
    }
    else if(sign_1 == -1) {
        return 0;
    }
    else if(sign_2 == -1) return 1;
    return (num1 > num2);
}

// if num1 <= num2 ? 1 : 0
bool less_than_equal(std::string num1, std::string num2) {
    int sign_1 = (num1[0] == '-' ? -1 : 1), sign_2 = (num2[0] == '-' ? -1 : 1);
    num1 = Abs(num1);
    num2 = Abs(num2);
    if(num1 == "0") sign_1 = 1;
    if(num2 == "0") sign_2 = 1;
    make_equal(num1, num2);
    if(sign_1 == -1 && sign_2 == -1) {
        return (num2 <= num1);
    }
    else if(sign_1 == -1) {
        return 1;
    }
    else if(sign_2 == -1) return 0;
    return (num1 <= num2);
}

// if num1 < num2 ? 1 : 0 
bool less_than(std::string num1, std::string num2) {
    int sign_1 = (num1[0] == '-' ? -1 : 1), sign_2 = (num2[0] == '-' ? -1 : 1);
    num1 = Abs(num1);
    num2 = Abs(num2);
    if(num1 == "0") sign_1 = 1;
    if(num2 == "0") sign_2 = 1;
    make_equal(num1, num2);
    if(sign_1 == -1 && sign_2 == -1) {
        return (num2 < num1);
    }
    else if(sign_1 == -1) {
        return 1;
    }
    else if(sign_2 == -1) return 0;
    return (num1 < num2);
}

// if lie within range than convert to integer
long long to_Int(std::string num) {
    remove_trailing_zero(num);
    if(num.size() <= 18) {
        int sum = 0, carry = 1;
        for(int i = num.size() - 1; i >= 0; i--) {
            sum += (num[i] - '0') * carry;
            carry *= 10;
        }
        return sum;
    }
    throw std::runtime_error("integer overflow");
}

// converting string to number
std::string to_string(int num) {
    if(num == 0) return "0";
    std::string result;
    while(num > 0) {
        result += NUMBERS[num % 10];
        num /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}


// adding two positive numbers
std::string positive_Add(std::string num1, std::string num2) {
    int size_1 = num1.size(), size_2 = num2.size(), carry = 0;
    int pos_1 = size_1 - 1, pos_2 = size_2 - 1;
    std::string result = "";
    for(int i = 0; i < std::min(size_1, size_2); i++) {
        int sum = (num1[pos_1--] - '0') + (num2[pos_2--] - '0') + carry;
        result += NUMBERS[(sum % 10)];
        carry = sum / 10;
    }
    for(int i = pos_2; i >= 0; i--) {
        int sum = (num2[i] - '0') + carry;
        result += NUMBERS[sum % 10];
        carry = sum / 10;
    }
    for(int i = pos_1; i >= 0; i--) {
        int sum = (num1[i] - '0') + carry;
        result += NUMBERS[sum % 10];
        carry = sum / 10;
    }
    if(carry != 0) {
        result += NUMBERS[carry];
    }
    reverse(result.begin(), result.end());
    return result;
}


// subtracting two positive numbers
std::string positive_Subtract(std::string num1, std::string num2) {
    int size_1 = num1.size(), size_2 = num2.size(), carry = 0, sign = 1;
    std::string temp_1 = num1, temp_2 = num2;

    make_equal(temp_1, temp_2);

    if(temp_1 < temp_2) {
        swap(temp_1, temp_2);
        sign *= -1;
    }

    // now number is bigger than 

    std::string result = "";

    for(int i = temp_1.size() - 1; i >= 0; i--) {
        if((temp_1[i] - '0') >= (temp_2[i] - '0')) {
            result += NUMBERS[(temp_1[i] - temp_2[i])];
        }
        else {
            int cur_pos = i;
            for(int j = cur_pos - 1; j >= 0; j--) {
                if(temp_1[j] == '0') temp_1[j] = '9';
                else {
                    temp_1[j] = NUMBERS[((temp_1[j] - '0') - 1)];
                    break;
                }
            }
            result += NUMBERS[(temp_1[i] - '0') + 10 - (temp_2[i] - '0')];
        }
    }
    
    reverse(result.begin(), result.end());
    remove_trailing_zero(result);
    if(sign < 0) return '-' + result;
    return result;
}


// This is main Add function 
std::string Add(std::string num1, std::string num2) {
    int sign_1 = (num1[0] == '-' ? -1 : 1), sign_2 = (num2[0] == '-' ? -1 : 1);
    std::string temp_1, temp_2;
    for(int i = 0; i < (int)num1.size(); i++) {
        if(num1[i] != '-') temp_1 += num1[i];
    } 
    for(int i = 0; i < (int)num2.size(); i++) {
        if(num2[i] != '-') temp_2 += num2[i];
    }
    if(sign_1 == -1 && sign_2 == -1) return '-' + positive_Add(temp_1, temp_2);
    if(sign_1 == -1) return positive_Subtract(temp_2, temp_1);
    if(sign_2 == -1) return positive_Subtract(temp_1, temp_2);
    return positive_Add(temp_1, temp_2);
}

// This is main subtract function
std::string Subtract(std::string num1, std::string num2) {
    int sign_1 = (num1[0] == '-' ? -1 : 1), sign_2 = (num2[0] == '-' ? -1 : 1);
    std::string temp_1, temp_2;
    for(int i = 0; i < (int)num1.size(); i++) {
        if(num1[i] != '-') temp_1 += num1[i];
    } 
    for(int i = 0; i < (int)num2.size(); i++) {
        if(num2[i] != '-') temp_2 += num2[i];
    }
    // std::cout << num1 << " " << num2 << " " << temp_1 << " " << temp_2 << " \n";
    if(sign_1 == -1 && sign_2 == -1) return positive_Subtract(temp_2, temp_1);
    if(sign_1 == -1) return '-' + positive_Add(temp_1, temp_2);
    if(sign_2 == -1) return positive_Add(temp_1, temp_2);
    // std::cout << temp_1 << " " << temp_2 << "\n";
    return positive_Subtract(temp_1, temp_2);
}


// multiplyting two positive numbers
std::string positive_Multiply(std::string num1, std::string num2) {
    // std::cout << num1 << " " << num2 << "\n";
    int n = make_equal(num1, num2);
    if(n == 0) return "0";
    if(n == 1) {
        int product = (num1[0] - '0') * (num2[0] - '0');
        std::string res = "";
        if(product >= 10) {
            
            res += NUMBERS[product / 10];
            res += NUMBERS[product % 10];

        }
        else {
            res += NUMBERS[product];
        }
        // std::cout << res << " " << product << "\n";
        return res;
    }
    int mid = (n) / 2, s_mid = n - mid;
    // std::cout << mid << " " << s_mid << "\n";
    std::string X_l = num1.substr(0, mid), X_r = num1.substr(mid, s_mid);
    std::string Y_l = num2.substr(0, mid), Y_r = num2.substr(mid, s_mid);

    std::string P1 = positive_Multiply(X_l, Y_l);
    std::string P2 = positive_Multiply(X_r, Y_r);
    std::string P3 = Subtract(positive_Multiply(Add(X_l, X_r), Add(Y_l, Y_r)), Add(P1, P2));

    // std::cout << P1 << " " << P2 << " " << P3 << "\n";

    return Add(Add(shift(P1, 2 * s_mid), shift(P3, s_mid)), P2);

}

// This is main Multiply function
std::string Multiply(std::string num1, std::string num2) {
    int sign_1 = (num1[0] == '-' ? -1 : 1), sign_2 = (num2[0] == '-' ? -1 : 1);
    std::string temp_1, temp_2;
    num1 = Abs(num1);
    num2 = Abs(num2);
    remove_trailing_zero(num1);
    remove_trailing_zero(num2);
    for(int i = 0; i < (int)num1.size(); i++) 
        temp_1 += num1[i];
    for(int i = 0; i < (int)num2.size(); i++) 
        temp_2 += num2[i];
    if(num1 == "0") sign_1 = 1;
    if(num2 == "0") sign_2 = 1;
    std::string result = positive_Multiply(temp_1, temp_2);
    remove_trailing_zero(result);
    if(sign_1 * sign_2 == -1) {
        return '-' + result;
    }
    return result;
}


// dividing a num by 2
std::string DivideBy_two(std::string num1) {
    int cur_pos = 0, prev = 0, sign = (num1[0] == '-' ? -1 : 1);
    std::string result, temp;
    for(int i = 0; i < num1.size(); i++) {
        if(num1[i] != '-') temp += num1[i];
    }
    num1 = temp;
    int size_1 = num1.size();
    while(cur_pos < size_1) {
        int value = (num1[cur_pos] - '0') + prev * 10;
        if(value < 2) {
            result += '0';
            prev = value;
        }
        else {
            result += (NUMBERS[value / 2]);
            prev = value % 2;
        }
        cur_pos++;
    }
    if(sign == -1) {
        reverse(result.begin(), result.end());
        result += '-';
        reverse(result.begin(), result.end());
    }
    remove_trailing_zero(result);
    return result;
}


// dividing two positive numbers
std::string positive_Divide(std::string num1, std::string num2) {
    // res = num1 / num2
    if(num2 == "0") return "Division by zero error";
    make_equal(num1, num2);
    if(num2.size() > num1.size()) return 0;
    std::string lo = "1", hi = "1", Ans = "0";
    for(int i = 0; i < num1.size(); i++) hi += '0';
    while(greater_than_equal(hi, lo)) {
        std::string mid = DivideBy_two(Add(Add(lo, hi), "1"));
        std::string MUL = Multiply(mid, num2);
        bool Greater_than = greater_than(MUL, num1);
        // std::cout << lo << " " << hi << " " << mid << " " << MUL << " " << Greater_than_equal << "\n";
        if(Greater_than) {
            hi = Subtract(mid, "1");
        }
        else {
            Ans = mid;
            lo = Add(mid, "1");
        }
    }
    return Ans;
}

// This is main divide function
std::string Divide(std::string num1, std::string num2) {
    if(num2 == "0") throw std::runtime_error("division by 0");
    int sign_1 = (num1[0] == '-' ? -1 : 1), sign_2 = (num2[0] == '-' ? -1 : 1);
    std::string temp_1, temp_2;

    for(int i = 0; i < (int)num1.size(); i++) 
        if(num1[i] != '-') temp_1 += num1[i];
    for(int i = 0; i < (int)num2.size(); i++) 
        if(num2[i] != '-') temp_2 += num2[i];
    
    std::string quotient = positive_Divide(temp_1, temp_2);
    if(sign_1 == -1 && sign_2 == -1) return quotient;
    else if(sign_1 == -1 || sign_2 == -1) {
        if(quotient != "0") return '-' + quotient;
        return quotient;
    }
    return quotient;
}

// modulus
std::string Modulo(std::string num1, std::string num2) {
    if(num2 == "0") throw std::runtime_error("division by 0");
    make_equal(num1, num2);
    if(num2.size() > num1.size()) return 0;
    std::string lo = "1", hi = "1", Ans;
    for(int i = 0; i < num1.size(); i++) hi += '0';
    while(greater_than_equal(hi, lo)) {
        std::string mid = DivideBy_two(Add(Add(lo, hi), "1"));
        std::string MUL = Multiply(mid, num2);
        bool Greater_than = greater_than(MUL, num1);
        // std::cout << lo << " " << hi << " " << mid << " " << MUL << " " << Greater_than_equal << "\n";
        if(Greater_than) {
            hi = Subtract(mid, "1");
        }
        else {
            Ans = mid;
            lo = Add(mid, "1");
        }
    }
    return Subtract(num1, Multiply(num2, Ans));
}

// gcd
std::string Gcd(std::string num1, std::string num2) {
    remove_trailing_zero(num2);
    if(num2 == "0") return num1;
    return Gcd(num2, Modulo(num1, num2));
}

// lcm
std::string lcm(std::string num1, std::string num2) {
    return Divide(Gcd(num1, num2), Multiply(num1, num2));
}


// power function num ^ power
std::string pow(std::string num, std::string power) {
    if(power == "0") {
        return "1";
    }
    std::string result = pow(num, DivideBy_two(power));
    if(parity(power) == 0) return Multiply(result, result);
    else return Multiply(Multiply(result, result), num);
}

// std::string pow(std::string num, int power) {
//     return "1";
// }

// power function num ^ power % mod
std::string pow_mod(std::string num, std::string power, std::string mod) {
    if(power == "0") {
        return "1";
    }
    std::string result = pow_mod(num, DivideBy_two(power), mod);
    if(parity(power) == 0) return Modulo(Multiply(result, result), mod);
    else return Modulo(Multiply(Modulo(Multiply(result, result), mod), num), mod);
}

// sqrt
std::string sqrt(std::string num) {
    if(num[0] == '-') throw std::runtime_error("negative number error");
    std::string lo = "0", hi = num, square_root;
    while(greater_than_equal(hi, lo)) {
        std::string mid = DivideBy_two(Add(lo, hi));
        if(less_than_equal(Multiply(mid, mid), num)) {
            lo = Add(mid, "1");
            square_root = mid;
        }
        else {
            hi = Subtract(mid, "1");
        }
    }
    return square_root;
}

//cbrt
std::string cbrt(std::string num) {
    std::string lo = "0", hi = num, cube_root;
    while(greater_than_equal(hi, lo)) {
        std::string mid = DivideBy_two(Add(lo, hi));
        if(less_than_equal(Multiply(Multiply(mid, mid), mid), num)) {
            lo = Add(mid, "1");
            cube_root = mid;
        }
        else {
            hi = Subtract(mid, "1");
        }
    }
    return cube_root;
}

// generates a random BigInt
std::string Rand(int length) {
    // not greater than length
    std::srand(std::time(0)); // seeding the random function
    int random_length = rand() % length;
    std::string random_number = "0";
    for(int i = 0; i < random_length; i++) {
        random_number += NUMBERS[(rand() % 10)];
    }
    remove_trailing_zero(random_number);
    return random_number;
}


bool check_composite(std::string num, std::string A, std::string D, int s) {
    std::string val = pow_mod(A, D, num), comp = Subtract(num, "1");
    remove_trailing_zero(val);
    if(val == "1" || equal(val, num)) return false;

    for (int i = 1; i < s; i++) {
        val = Modulo(Multiply(val, val), num);
        if(equal(val, comp)) return false;
    }

    return true;
}


// check if number is prime or not
bool is_prime(std::string num1) {
    int iter = 10;
    remove_trailing_zero(num1);
    if(less_than(num1, "4")) {
        return (num1 == "2" || num1 == "3");
    } 

    int s = 0;
    std::string D = Subtract(num1, "1");

    while(parity(D) == 0) {
        D = Divide(D, "2");
        s++;
    }

    std::string SUB = Subtract(num1, "3");

    int length = num1.size();

    for(int i = 0; i < iter; i++) {
        std::string A = Add("2", Modulo(Rand(length), (SUB)));
        if(check_composite(num1, A, D, s)) return false;

    }
    return true;
}

// return vector of prime numbers
std::vector<std::string> prime_factors(std::string num1) {
    return {"1"};
}





// Bitwise operations

// converting number to bin i.e base 2
std::string to_bin(std::string num) {
    std::string bin_num;
    while(num != "0") {
        remove_trailing_zero(num); // due to this there is high complexity 
        // one thinng that I can do is always computer from backwards
        if(parity(num) == 1) bin_num += '1';
        else bin_num += '0';
        num = DivideBy_two(num);
    }
    reverse(bin_num.begin(), bin_num.end());
    return bin_num;
}

// shifting number by shift bits to the left
std::string left_shift(std::string num, std::string shift) {
    std::string POW = pow("2", shift);
    return Multiply(POW, num);
}

// shifting number by shift bits to the left
std::string left_shift(std::string num, int shift) {
    // std::cout << to_string(shift) << " " << shift << "\n";
    std::string POW = pow("2", to_string(shift));
    return Multiply(POW, num);
}

// shifting number by shift bits to the right
std::string right_shift(std::string num, std::string shift) {
    std::string POW = pow("2", shift);
    return Divide(num, POW);
}

// shifting number by shift bits to the right
std::string right_shift(std::string num, int shift) {
    std::string POW = pow("2", to_string(shift));
    return Divide(num, POW);
}

// bitwise OR of num1 and num2
std::string OR(std::string num1, std::string num2) {
    std::string bin_num1 = to_bin(num1);
    std::string bin_num2 = to_bin(num2);
    std::string result = "0";
    
    int len = make_equal(bin_num1, bin_num2);
    // std::cout << bin_num1 << " " << bin_num2 << "\n";
    for(int i = len - 1; i >= 0; i--) {
        if(bin_num1[i] == '1' || bin_num2[i] == '1') {
            // std::cout << left_shift("1", len - i - 1) << " " << len - i - 1<< "\n";
            result = Add(result, left_shift("1", i));
        }
    }
    return result;
}

// bitwise AND num1 and num2
std::string AND(std::string num1, std::string num2) {
    std::string bin_num1 = to_bin(num1);
    std::string bin_num2 = to_bin(num2);
    std::string result = "0";
    int len = make_equal(bin_num1, bin_num2);
    for(int i = len; i >= 0; i--) {
        if(bin_num1[i] == '1' && bin_num2[i] == '1') {
            result = Add(result, left_shift("1", i));
        }
    }
    return result;
}

// bitwise XOR num1 and num2
std::string XOR(std::string num1, std::string num2) {
    std::string bin_num1 = to_bin(num1);
    std::string bin_num2 = to_bin(num2);
    std::string result = "0";
    int len = make_equal(bin_num1, bin_num2);
    for(int i = len; i >= 0; i--) {
        if(bin_num1[i] == '1' && bin_num2[i] == '0') {
            result = Add(result, left_shift("1", i));
        }
        else if(bin_num1[i] == '0' && bin_num2[i] == '0') {
            result = Add(result, left_shift("1", i));
        }
    }
    return result;
}

// bitwise NOT
std::string NOT(std::string num1) {
    std::string bin_num = to_bin(num1), result = "0";
    for(int i = (int)bin_num.size() - 1; i >= 0; i--) {
        if(bin_num[i] == '0')
            result = Add(result, left_shift("1", i));
    }
    return result;
}

std::string change_base(std::string num, std::string base) {
    return "1";
}

std::string change_base(std::string num, int base) {
    return "1";
}


// O(N) - length of string
std::string BigInt::add(BigInt &other) {
    return Add(number, other.number);
}

// O(N) length of string
std::string BigInt::subtract(BigInt &other) {
    return Subtract(number, other.number);
}

// O(N ^ 1.6) - use karatsuba algo
std::string BigInt::multiply(BigInt &other) {
    return Multiply(number, other.number);
}

// (N * log(N)) - use binary search
std::string BigInt::divide(BigInt &other) {
    return Divide(number, other.number);
}

std::string BigInt::Pow(std::string power) {
    return pow(number, power);
}

std::string BigInt::bin_AND(BigInt &other) {
    return AND(number, other.number);
}

std::string BigInt::bin_OR(BigInt &other) {
    return OR(number, other.number);
}

std::string BigInt::bin_NOT() {
    return NOT(number);
}

std::string BigInt::bin_XOR(BigInt &other) {
    return XOR(number, other.number);
}

std::string BigInt::bin_left_shift(std::string shift) {
    return left_shift(number, shift);
}

std::string BigInt::bin_right_shift(std::string shift) {
    return right_shift(number, shift);
}


std::string BigInt::ABS() {
    return Abs(number);
}

bool BigInt::IS_PRIME() {
    return is_prime(number);
}

std::string BigInt::GCD(BigInt &other) {
    return Gcd(number, other.number);
}

std::string BigInt::LCM(BigInt &other) {
    return lcm(number, other.number);
}

bool BigInt::Greater_Than(BigInt &other) {
    return greater_than(number, other.number);
}

bool BigInt::Greater_Than_Equal(BigInt &other) {
    return greater_than_equal(number, other.number);
}

bool BigInt::Less_Than(BigInt &other) {
    return less_than(number, other.number);
}

bool BigInt::Less_Than_Equal(BigInt &other) {
    return less_than_equal(number, other.number);
}

bool BigInt::Equal(BigInt &other) {
    return equal(number, other.number);
}

std::string BigInt::RAND(int length) {
    return Rand(length);
}
