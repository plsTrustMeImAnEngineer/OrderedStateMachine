#ifndef OrderedStateMachine_h
#define OrderedStateMachine_h

#include <State.h>
#include <stddef.h>

template<size_t maxNumStates>
class OrderedStateMachine
{
public:
    bool addState(State state);
    bool addState(ActionCallback_t action = []{}, TransitionPredicate_t transitionPredicate = []{ return false; });
    bool jumpToState(size_t index);
    void transitionNextState();
    void run();

private:
    size_t m_activeStateIndex = 0;
    size_t m_numStates = 0;
    State m_states[maxNumStates];
};

class Bla
{
public:
    void blub();
};

#endif