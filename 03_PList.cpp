#include <iostream>
#include <vector>




using namespace std;


class Value
{
public:
    virtual void Print(){};
    virtual Value* Has(const int& cmp){};
    virtual Value* Has(const string& cmp){};
    virtual Value* Has(const double& cmp){};
private:
    string v;
};
class lINT : public Value
{
public:
    lINT(const int& input)
    {
        v = input;
    }
    void Print() override
    {
        cout << v <<" ";
    }
    lINT* Has(const int& cmp) override
    {
        if (cmp==v)
        {
            return this;
        }
        else
        {
            return NULL;
        }
    }
    ~lINT()
    {
        cout << v << " dropped" << endl;
    }
private:
    int v;
};

class lDOUB : public Value
{
public:
    lDOUB(const double& input)
    {
        v = input;
    }
    void Print() override
    {
        cout << v <<" ";
    }
    lDOUB* Has(const double& cmp) override
    {
        if (cmp==v)
        {
            return this;
        }
        else
        {
            return NULL;
        }
    }
    ~lDOUB()
    {
        cout << v << " dropped" << endl;
    }
private:
    double v;
};

class lSTR : public Value
{
public:
    lSTR(const string& input)
    {
        v = input;
    }
    void Print() override
    {
        cout << "\""<< v <<"\" ";
    }
    lSTR* Has(const string& cmp) override
    {
        if (cmp==v)
        {
            return this;
        }
        else
        {
            return NULL;
        }
    }
    ~lSTR()
    {
        cout << v << " dropped" << endl;
    }
private:
    string v;
};

class PList
{
private:
    vector<lINT*> val_int;
    vector<lSTR*> val_str;
    vector<lDOUB*> val_doub;
    vector<Value*> val;
public:
    //INT
    void add(const int& input){lINT* a = new lINT(input); val_int.push_back(a); val.push_back(a);}
    void has(const int& cmp){bool has = 0; for (Value* el : val_int) if (el->Has(cmp) != NULL) has += 1; cout << "has(" << cmp << ")= "<< has <<endl;}
    void drop(const int& cmp){int i = 0, j = 0;for (i = 0; i < val_int.size(); i++){lINT* p = val_int[i]->Has(cmp);if (p != NULL){for (j = 0; j < val.size(); j++){if (val[j] == p){delete p;val_int.erase(val_int.begin()+i);val.erase(val.begin()+j);}}}}}
    //STRING
    void add(const string& input){lSTR* a = new lSTR(input); val_str.push_back(a); val.push_back(a);}
    void has(const string& cmp){bool has = 0; for (Value* el : val_str) if (el->Has(cmp) != NULL)  has += 1; cout << "has(" << cmp << ")= "<< has <<endl;}
    void drop(const string& cmp){int i = 0, j = 0;for (i = 0; i < val_str.size(); i++){lSTR* p = val_str[i]->Has(cmp);if (p != NULL){for (j = 0; j < val.size(); j++){if (val[j] == p){delete p;val_str.erase(val_str.begin()+i);val.erase(val.begin()+j);}}}}}
    //DOUB
    void add(const double& input){lDOUB* a = new lDOUB(input); val_doub.push_back(a); val.push_back(a);}
    void has(const double& cmp){bool has = 0; for (Value* el : val_doub) if (el->Has(cmp) != NULL)  has += 1; cout << "has(" << cmp << ")= "<< has <<endl;}
    void drop(const double& cmp){int i = 0, j = 0;for (i = 0; i < val_doub.size(); i++){lDOUB* p = val_doub[i]->Has(cmp);if (p != NULL){for (j = 0; j < val.size(); j++){if (val[j] == p){delete p;val_doub.erase(val_doub.begin()+i);val.erase(val.begin()+j);}}}}}

    //ALL
    void print(){for (Value* el : val) el->Print(); cout << endl;}

};



int main()
{
    PList p;
    p.add("hello");
    p.add(5.87);
    p.add(5);
    p.add(7);
    p.print();
    p.has(5.87);
    p.has(8);
    p.has("hel");
    p.has("hello");
    p.drop(7);
    p.print();

    //p.Add("hello");
    return 0;
}
