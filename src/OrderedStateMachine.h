#ifndef OrderedStateMachine_h
#define OrderedStateMachine_h

#include <State.h>
#include <stddef.h>

template<size_t maxNumStates>
class OrderedStateMachine
{
public:
    bool addState(State state)
    {
        if(m_numStates++ > maxNumStates) 
            return false;        

        m_states[m_numStates] = state;
            return true;
    }


    bool addState(ActionCallback_t action = []{}, TransitionPredicate_t transitionPredicate = []{ return false; })
    {
        return addState(State(action, transitionPredicate));
    }


    bool jumpToState(size_t index)
    {
        if(index > maxNumStates)
            return false;
    
        m_activeStateIndex = index;
    }


    void transitionNextState()
    {
        if(++m_activeStateIndex >= maxNumStates)
            m_activeStateIndex = 0;
    }


    void run()
    {
        if(m_states[m_activeStateIndex].transitionPredicate())
        {
            transitionNextState();
        }
        m_states[m_activeStateIndex].action();
    }

private:
    size_t m_activeStateIndex = 0;
    size_t m_numStates = 0;
    State m_states[maxNumStates];
};

#endif