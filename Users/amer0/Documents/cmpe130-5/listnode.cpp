#include "listnode.h"

ListNode::ListNode()
{
    this->name = " ";
    this->phone_num = 0;
    this->room_num = 0;
    this->room_price = 0;
}

ListNode::ListNode(const ListNode &n)
{
    this->name = n.name;
    this->phone_num = n.phone_num;
    this->room_num = n.room_num;
    this->room_price = n.room_price;
}

ListNode &ListNode::operator =(const ListNode &n)
{
    this->name = n.name;
    this->phone_num = n.phone_num;
    this->room_num = n.room_num;
    this->room_price = n.room_price;
}

void ListNode::set_room(int roomNum)
{
    this->room_num = roomNum;
}

void ListNode::set_name(std::string n){
    this->name = n;
}

void ListNode::set_phone(long number){
    this->phone_num = number;
}

double ListNode::price_gen()
{
        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        std::default_random_engine e(seed);
        std::normal_distribution<double> distrN(350.0, 12.0);
        double price = distrN(e);

        return price;
}

void ListNode::name_gen()
{

}

long long int ListNode::phone_gen()
{
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    srand(seed);
    long long int phone = rand() % 462587542587487 + 4086373166;
    return phone;
}



void ListNode::set_price(double price){
    this->room_price = price;
}

