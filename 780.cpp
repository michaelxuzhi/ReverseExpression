#include<stack>  
#include<iostream>  
#include<string>  
using namespace std;  
  
struct OneExpr {  
    string expr;  
    char oper = ' ';  
};  
  
int operatorPriority(char c) {//��������ȼ��Ƚ�  
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
    string postfix;//������ʽ  
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
        else {//�����  
            OneExpr num2;  
            num2 = infixExpr.top();  
            infixExpr.pop();  
            OneExpr num1;  
            num1 = infixExpr.top();  
            infixExpr.pop();  
            OneExpr o;  
  
            if (num2.oper != ' '&&operatorCmp(c, num2.oper) > 0)//������ţ�����3*��2+5������2+5�������  
            {  
                num2.expr.insert(0, 1, '(');  
                num2.expr.push_back(')');  
            }  
            o.expr = num1.expr + c + num2.expr;//��������  
            o.oper = c;  
            infixExpr.push(o);  
        }  
    }  
    cout << infixExpr.top().expr;  
}