#include <iostream>
#include <vector>




using namespace std;


class Value
{
public:
    Value()
    {
        string type = "value";
        string v = "empty";
    }
    virtual void Print(){};
    //virtual bool Compare(const int& cmp){};
    //virtual bool Compare(const string& cmp){};
    bool Compare(Value* cmp_val)
    {
        if (type == cmp_val->type)
        {
            if (V() == cmp_val->V())
            {
                cout << type << cmp_val->type <<endl;
                return true;
            }
        }
        else
        {
            return false;
        }
    }
    virtual int Type(){};
    string V()
    {
        return v;
    }
    //virtual string V(){};
    //virtual int V(){};
private:
    string v;
protected:
    string type;
};
class lINT : public Value
{
public:
    lINT(const int& input)
    {
        v = input;
        type = "int";
    }
    void Print()
    {
        cout << v <<" ";
    }

    int V()
    {
        return v;
    }
private:
    int v;
protected:
    string type;
};

class lSTR : public Value
{
public:
    lSTR(const string& input)
    {
        v = input;
        type = "string";
    }
    void Print()
    {
        cout << "\""<< v <<"\" ";
    }


    string V()
    {
        return v;
    }
private:
    string v;
protected:
    string type;
};

class PList
{
private:
    vector<Value*> val;
public:
    void Add(const int& input){val.push_back(new lINT(input));}
    void Add(const string& input){val.push_back(new lSTR(input));}
    void Print(){for (Value* el : val) el->Print(); cout << endl;}
    //void Has(const int& input_cmp){Value* pp = new lINT(input_cmp);for (Value* el : val) cout << el->Compare(pp); cout << endl;}
    //void Has(const string& input_cmp){for (Value* el : val) cout << el->Compare(new lSTR(input_cmp)); cout << endl;}
    void getLength(){cout << val.size()<<endl;}

};



int main()
{
    //cout << ("hello"=="hg")<<endl;
    lINT r(7);
    cout << r.Compare(new lINT(8)) <<endl;
    PList p;
    p.Add("hello");
    p.Add(5);
    p.Add(7);
    p.Print();
    p.Has(7);
    //p.Add("hello");
    return 0;
}
