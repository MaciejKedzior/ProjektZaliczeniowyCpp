#include <iostream>
#include <string>

class Currency{
    public:
        Currency(float _ask, float _bid, std::string _name, std::string _code): 
        ask{_ask}, bid{_bid}, name{_name}, code_name{_code} {}
        float GetAsk() { return ask; };
        float GetBid() { return bid; };
        std::string GetName() { return name; };
        std::string GetCodeName() { return code_name; };
        ~Currency(){ std::cout<<"Currency object destructed!\n"; };
    private:
        float ask;
        float bid;
        std::string name;
        std::string code_name;
    friend float Selling(const Currency&, float); 
    friend std::ostream & operator << (std::ostream &out, const Currency &c);

};


std::ostream & operator << (std::ostream &out, const Currency &cur){
    out<<"Ask: "<<cur.ask<<std::endl;
    out<<"Bid: "<<cur.bid<<std::endl;
    out<<"Name: "<<cur.name<<std::endl;
    out<<"Code name: "<<cur.code_name<<std::endl<<std::endl;
    return out;
}