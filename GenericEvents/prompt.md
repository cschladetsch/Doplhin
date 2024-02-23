# C++20 - Generic Event System

In many applications, the ability to dynamically register, manage, and invoke event handlers based on different triggers is crucial. 

C++ does not have a built-in system to support this, like in other languages (e.g., C#'s `event` keyword).

## Problem Statement

Generate code for a generic, type-safe event system using modern C++20 features and libraries, where events are instances that can have handlers (also called 'delegates') attached and be directly invoked with arguments.

The code generated implements a generic event handling system that allows events to be created with specific argument types of variable length.

The system created should use modern C++ features such as variadic template classes and methods, lambda expressions, and `std::function`, to achieve flexibility and ease of use.

## Requirements

1. **Event Instance Creation**: Allow for the creation of event instances that specify the types of arguments they accept using a variadic template mechanism.
1. **Handler Registration**: Allow the attachment of handlers (also called 'delegates') to an event instance using an `operator+=(...)` overload for the Event template class. 
 * Handlers should be functions or other callable objects that match the event's argument signature.
1. **Multicast**: Allow for multiple delegates to be added to an event. 
1. **Invocation**: Support invoking all attached delegates to be called when the event is treated as a function. Overload `operator()` for this.
1. **Type Safety**: Ensure that only handlers matching the event's signature can be attached and that the event can only be invoked with arguments that match the signature of the event's argument list.
1. **Comments**: Add comments to the code, focusing on "why" and not "how" or "what".
1. **C++20**: Use only standard C++20 features and libraries. Do not use external libraries.
1. **Error Handling**: Use exceptions to deal with errors. When errors are caught, add local contextual extra information then rethrow the exception.

## Starter Framework

Here's a starting framework to guide the implementation:

```cpp
template <typename... Args>
class Event {
public:
    // operator to add a new handler (delegate)
    Event& operator+=(std::function<void(Args...)> handler);

    // Invoke all attached handlers
    void operator()(Args... args);
};
```

## Sample Usage

```cpp
// Include necessary headers

int main() {
    auto myEvent = Event<int, bool>();
    myEvent += [](int n, bool b) {
        std::cout << n*2 << std::boolalpha << " " << !b << std::endl;
    };
    myEvent(42, false); // outputs: 84 true
    myEvent(6, true);   // outputs: 12 false
    return 0;
}
```

## Notes

* Give discussions about:
 * The difficulties of removing delegates that are given as a lambda. Discus ways around this.
 * Changes required to make the event system thread-safe.
 * Exception safety, especially in scenarios where a handler may throw an exception. You might want to catch the exception within the invocation operator to ensure all other handlers are called ot design a strategy to let the caller handle exceptions and either halt or continue.


