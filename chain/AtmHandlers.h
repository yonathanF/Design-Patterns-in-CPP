/* Chain of responsbility 
 *
 * Another nice patterns to replace a long
 * chain if else statement with a more OPP approach
 */

class ATMHandler{
  public:
    void setNextHandler(ATMHandler* handler){ nextHandler = handler;};
    void setPreviousHandler(ATMHandler* handler) { previousHandler = handler;};
    virtual int deposit(int value)=0;

  protected:
    ATMHandler *previousHandler, *nextHandler;
};


class TwentyHandler : public ATMHandler{
  public:
    int deposit(int value);
};


class FiftyHandler : public ATMHandler{
 public:
    int deposit(int value);

};

class HundredHandler : public ATMHandler{
 public:
    int deposit(int value);

};

class DefaultHandler : public ATMHandler{
 public:
    int deposit(int value);

};
