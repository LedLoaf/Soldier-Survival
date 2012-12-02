#ifndef IEVENT_HANDLER_HPP_
#define IEVENT_HANDLER_HPP_

class IEventHandler {
public:
//    virtual ~IEventHandler();
    virtual void processEvent() = 0;
};

#endif

