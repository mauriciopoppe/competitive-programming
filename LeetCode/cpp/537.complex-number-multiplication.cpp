class Complex {    
public:
    int re;
    int im;
    Complex(int _re, int _im): 
        re(_re), 
        im(_im) 
        {}
    
    Complex(string s) {
        re = im = 0;
        int i = 0;
        re = parseNextNumber(s, i);
        i++;
        im = parseNextNumber(s, i);
    }
    
    int parseNextNumber(string s, int &i) {
        int mult = 1;
        int num = 0;
        if (!isdigit(s[i])) {
            mult = s[i++] == '-' ? -1 : 1;
        }
        while (isdigit(s[i])) {
            num = num * 10 + s[i++] - '0';
        }
        return mult * num;
    }
    
    string toString() {
        return to_string(re) + "+" + to_string(im) + "i";
    }
};

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        Complex ia(a);
        Complex ib(b);
        Complex ans(
            ia.re * ib.re - ia.im * ib.im,
            ia.im * ib.re + ia.re * ib.im
        );
        return ans.toString();
    }
};
