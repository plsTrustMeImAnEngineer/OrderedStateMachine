#include <OrderedStateMachine.h>

template<size_t maxNumStates>
bool OrderedStateMachine<maxNumStates>::addState(State state)
{
    if(++m_numStates > maxNumStates) 
        return false;        

    m_states[m_numStates] = state;
    return true;
}


template<size_t maxNumStates>
bool OrderedStateMachine<maxNumStates>::addState(ActionCallback_t action = []{}, TransitionPredicate_t transitionPredicate = []{ return false; })
{
    return addState(State(action, transitionPredicate));
}


template<size_t maxNumStates>
bool OrderedStateMachine<maxNumStates>::jumpToState(size_t index)
{
    if(index > maxNumStates)
        return false;
    
    m_activeStateIndex = index;
}


template<size_t maxNumStates>
void OrderedStateMachine<maxNumStates>::transitionNextState()
{
    if(++m_activeStateIndex >= maxNumStates)
        m_activeStateIndex = 0;
}


template<size_t maxNumStates>
void OrderedStateMachine<maxNumStates>::run()
{
    if(m_states[m_activeStateIndex].transitionPredicate())
    {
        transitionNextState();
    }
    m_states[m_activeStateIndex].action();
}

void Bla::blub()
{
    return;
}