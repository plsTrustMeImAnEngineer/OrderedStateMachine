#ifndef State_h
#define State_h

using ActionCallback_t = void(*)();
using TransitionPredicate_t = bool(*)();

struct State
{
    State(ActionCallback_t action = []{}, TransitionPredicate_t transitionPredicate = []{ return false; }) :
        action(action),
        transitionPredicate(transitionPredicate)
    {}

    ActionCallback_t action;
    TransitionPredicate_t transitionPredicate;
};

#endif