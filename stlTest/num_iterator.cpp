#include<iostream>
#include<algorithm>

class num_iterator{

private:
    int i;
public:
    explicit num_iterator( int position=0): i(position){}

    int operator*() const { return i; }
    num_iterator& operator++(){
         ++i;  
            return *this; }//++it 
    bool operator!=(const num_iterator& other) const{ 
        return i!=other.i;
    }
    bool operator==(const num_iterator& other) const
    {
        return !(*this!=other);
    }
    
    
};

class num_range{
private:
    int a;
    int b;
public:
    num_range(int from, int to):a(from),b(to){}
    num_iterator begin() const { return num_iterator(a); }
    num_iterator end() const { return num_iterator(b); }

};

namespace std {
    template<>
    struct iterator_traits<num_iterator>{
        using iterator_category = std::forward_iterator_tag;
        using value_type = int;
        using difference_type = int;
    };
}

int main(int argc, char const *argv[])
{
    for(int i: num_range(100,110))
    {
        std::cout << i << ",";
    }
    std::cout << std::endl;
    num_range r(100, 120);
    auto &&[minV, maxV] = std::minmax_element(r.begin(), r.end());
    std::cout <<*minV << ",-"<<*maxV <<std::endl;
    auto r5(std::next(r.begin(), 5));
    std::cout <<*r5<<std::endl;
    return 0;
}
