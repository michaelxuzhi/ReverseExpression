#include<stack>  
#include<iostream>  
#include<string>  
using namespace std;  
  
struct OneExpr {  
    string expr;  
    char oper = ' ';  
};  
  
int operatorPriority(char c) {//运算符优先级比较  
    if (c == '^')  
        return 3;  
    else if (c == '*' || c == '/')  
        return 2;  
    else if (c == '+' || c == '-')  
        return  1;  
}  
  
int operatorCmp(char c1, char c2) {  
    int t1, t2;  
    t1 = operatorPriority(c1);  
    t2 = operatorPriority(c2);  
    return t1 - t2;  
}  
  
stack<OneExpr> infixExpr;  
  
int main() {  
    string postfix;//逆序表达式  
    getline(cin, postfix);  
    string num;  
    for (int i = 0; i < postfix.length(); i++)  
    {  
        char c = postfix[i];  
        if (isdigit(c))  
        {  
            num += c;  
        }  
        else if (c == ' ')  
        {  
            if (!num.empty()) {  
                OneExpr t;  
                t.expr = num;  
                infixExpr.push(t);  
                num.clear();  
            }  
  
        }  
        else {//运算符  
            OneExpr num2;  
            num2 = infixExpr.top();  
            infixExpr.pop();  
            OneExpr num1;  
            num1 = infixExpr.top();  
            infixExpr.pop();  
            OneExpr o;  
  
            if (num2.oper != ' '&&operatorCmp(c, num2.oper) > 0)//添加括号，例如3*（2+5），给2+5添加括号  
            {  
                num2.expr.insert(0, 1, '(');  
                num2.expr.push_back(')');  
            }  
            o.expr = num1.expr + c + num2.expr;//连接起来  
            o.oper = c;  
            infixExpr.push(o);  
        }  
    }  
    cout << infixExpr.top().expr;  
}