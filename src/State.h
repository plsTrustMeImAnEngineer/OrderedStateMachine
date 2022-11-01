#ifndef State_h
#define State_h

using ActionCallback_t = void(*)();
using TransitionPredicate_t = bool(*)();

class State
{
public:
    void operator()();
    
private:
    ActionCallback_t m_action = nullptr;
    TransitionPredicate_t m_transitionPredicate = nullptr;
};

#endif