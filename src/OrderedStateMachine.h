#ifndef OrderedStateMachine_h
#define OrderedStateMachine_h

#include <State.h>
#include <AH/STL/vector>

class OrderedStateMachine
{
public:
    void run();
    void setActiveState(State& activeState);
    

private:
    std::vector<State> m_states;
    size_t activeStateIndex = 0;
    
};

#endif