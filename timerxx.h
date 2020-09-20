#include<chrono>


class Timer
{
    //using namespace std::chrono;
    using high_resolution_clock = std::chrono::high_resolution_clock;
    


protected:
    std::chrono::time_point<high_resolution_clock> m_begin;
    

public:
    Timer() : m_begin(high_resolution_clock::now()){};

    void reset() { m_begin = high_resolution_clock::now(); }
    template<typename Duration=std::chrono::milliseconds>
    int64_t elapsed() const
    {
        return std::chrono::duration_cast<Duration>(high_resolution_clock::now() - m_begin).count();

    }

    int64_t elapsed_micro()
    {
        return elapsed<std::chrono::microseconds>();
    }

    int64_t elapsed_second()
    {
        return elapsed<std::chrono::seconds>();
    }
};
