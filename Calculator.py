Intuition
modular code with the easiest method ;)
postfix conversion + evaluation
Alright let's do this!

the first thing i remembered is: all the computers find it hard to evaluate infix, so processors usually work with prefix or postfix notations
in postfix the operator comes after the operands a + b -> ab+

Now, the first thing I should do was separate the operators and operands !
( operators are '+-*/' and operands are the numbers ( may be negative! )

Then after I have the list of operands and operators in infix form

I will convert it to postfix form

and finally evaluate the postfix form ;)

Implementation
inorder()
we will split the numbers into operands and operators, doing this by checking if it is not in '+-*/' it is a digit else it can be a '-' of the number's value

postorder()
we will simply take the infix and return a postfix

for each token
-> if it is a operand i insert it in int() to the result
->else if it is a greater precedence operator ( here '*/' > '+-' or empty ) then add it to the stack
-> else just keep popping from the stack and adding to the result for the greater/equal precedence operators since they MUST take place before you! ;)

finally the last part of the operators is left in the stack, just pop and add to the result ( while len(ops) )

postorder_eval()
this may be the easiest function

for each token
-> if it is a operand push it to the stack
-> if it is a operator, pop the previous two operands from the stack ( a, b ) , evaluate them and push them back inside (c);)

Time Complexity
\mathcal{O}(n)O(n) since each function works in a single pass ! so total time = 3 * n

Space Complexity
\mathcal{O}(n)O(n) the size of s, infix, postfix is n but 3 * n is still O(n) so this is also only O(n) which is acceptable :D

# convert the input from string to operands and operators
# in a list operand = numbers having multiple digits and neg!
def inorder(s):
    infix = []
    operand = ""
    prev_operator = "+"
    for c in s:
        if c not in "+-*/":
            operand += c
        elif prev_operator in "+-*/" and c == "-":
            # negative number found!
            operand += c
        else:
            infix.append(operand)
            infix.append(c)
            operand = ""
        prev_operator = c
    infix.append(operand)
    return infix


# convert infix to postfix expression using a stack
def postorder(s):
    # ops stack is storing the operators
    ops = []
    res = []

    for c in s:
        if c not in "+-/*":
            res.append(int(c))
        elif c in "/*" and len(ops) and ops[-1] in "+-" or len(ops) == 0:
            ops.append(c)
        else:
            # while precedence of operator is greater than or equal
            while len(ops) and (ops[-1] in "*/" or c in "+-"):
                res.append(ops.pop())
            ops.append(c)

    while len(ops):
        res.append(ops.pop())

    return res


# postfix is easy to evaluate for CPU and easy to code for us!
def postorder_eval(postfix):
    res = []

    for c in postfix:
        if isinstance(c, str):
            b = int(res.pop())
            a = int(res.pop())
            if c == "+":
                c = a + b
            elif c == "-":
                c = a - b
            elif c == "*":
                c = a * b
            elif c == "/":
                c = a // b
            res.append(c)
        else:
            res.append(c)

    return res[-1]


class Solution:
    def solve(self, s):

        infix = inorder(s)
        print(infix)

        postfix = postorder(infix)
        print(postfix)

        return postorder_eval(postfix)
    
------------------------------------------------------------------------------------------------------------------------------------------------------------------

// https://www.lintcode.com/problem/849/description

class Solution {
public:
    /**
     * @param s: the expression string
     * @return: the answer
     */
    int getPrecedence(string op){
        if(op=="*" || op=="/")return 1;
        else if(op=="+" || op=="-")return 0;
        else return -1;
    }
    bool isOperator(char op){
        if(op=='+' || op=='-' || op=='/' || op=='*')return true;
        else return false;
    } 
    bool isOperator(string op){
        if(op=="+" || op=="-" || op=="/" || op=="*" )return true;
        else return false;
    }
    vector<string> getExpression(string& s){
        vector<string> exp;
        string num="";
        int n = s.length();

        for(int i=0;i<n;i++){
            if(s[i]==' ')continue;
            else if(isdigit(s[i])){
                num+=s[i];
            }
            else{
                if(num!=""){
                    exp.push_back(num);
                    num="";
                }
                string temp="";
                temp+=s[i];
                exp.push_back(temp);
            }
        }
        if(num!=""){
            exp.push_back(num);
            num="";
        }
        return exp;
    }
    
    vector<string> getPostfix(vector<string>& exp){
        vector<string> postfix;
        stack<string> ops;
        int n = exp.size();
        for(int i=0;i<exp.size();i++){
            if(exp[i]=="("){
                ops.push(exp[i]);
            }
            else if(exp[i]==")"){
                //if(!ops.empty() && ops.top()=="(")return {};
                while(!ops.empty() && ops.top()!="("){
                    postfix.push_back(ops.top());
                    ops.pop();
                }
                if(ops.empty())return {};
                ops.pop();
            }
            else if(isOperator(exp[i])){
                while(!ops.empty() && getPrecedence(ops.top())>=getPrecedence(exp[i])){
                    postfix.push_back(ops.top());
                    ops.pop();
                }
                ops.push(exp[i]);
            }
            else{
                postfix.push_back(exp[i]);
            }
        }
        while(!ops.empty()){
            postfix.push_back(ops.top());
            ops.pop();
        }
        return postfix;
    }

    long long evaluatePostfix(vector<string>& postfixExp){
        int ans = 0;
        stack<long long> nums;
        for(auto u:postfixExp){
            if(u=="(" || u==")")return -1;
            else if(isOperator(u)){
                if(nums.size()<2)return -1;
                long long num1= nums.top();
                nums.pop();
                long long num2 = nums.top();
                nums.pop();
                if(u=="+")nums.push(num1+num2);
                else if(u=="*")nums.push(num1*num2);
                else if(u=="/")nums.push(num2/num1);
                else if(u=="-")nums.push(num2-num1);
            }
            else{
                nums.push(stoll(u));
            }
        }

        if(nums.size()!=1)return -1;
        return nums.top();
    }
    int calculate(string &s) {
        vector<string> exp = getExpression(s);
        for(auto u:exp)cout<<u<<" ";
        cout<<endl;
        vector<string> postfixExp = getPostfix(exp);
        for(auto u:postfixExp)cout<<u<<" ";
        cout<<endl;
        if(postfixExp.size()==0)return -1;
        return evaluatePostfix(postfixExp);
    }
};
