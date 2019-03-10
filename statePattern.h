class FiniteState;

class State{

  public:
    State(FiniteState *fa):FA(fa){};
    virtual void addNewCharacter(char newChar) = 0;
    virtual bool isValid() = 0;
  protected:
    FiniteState *FA;

};

class State0 : public State{

  public: 
    State0(FiniteState *fa):State(fa){};
    void addNewCharacter(char newChar);
    bool isValid();
};

class State1 : public State{

  public: 
    State1(FiniteState *fa):State(fa){};
    void addNewCharacter(char newChar);
    bool isValid();
};

class State2 : public State{

  public: 
    State2(FiniteState *fa):State(fa){};
    void addNewCharacter(char newChar);
    bool isValid();
};

class State3 : public State{

  public: 
    State3(FiniteState *fa):State(fa){};
    void addNewCharacter(char newChar);
    bool isValid();
};

class RejectState: public State{

  public: 
    RejectState(FiniteState *fa):State(fa){};
    void addNewCharacter(char newChar);
    bool isValid();
};



class FiniteState{
  public:
    FiniteState();
    ~FiniteState();
    void goToState(State *nextState) { currentState = nextState;};
    void addNewCharacter(char newChar) {currentState->addNewCharacter(newChar);};
    bool isValid() {return currentState->isValid();};

    State* getState0(){return state0;}; 
    State* getState1(){return state1;};
    State* getState2(){return state2;};
    State* getState3(){return state3;};
    State* getRejectState(){return rejectState;};

  private:
    State *state0, *state1, *state2, *state3, *rejectState, *currentState;
};


