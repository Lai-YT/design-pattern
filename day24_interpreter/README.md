# Interperter Pattern

This pattern isn't involved by guru. \
So in this specific topic, all codes are refered to and modified from [https://twmht.github.io/blog/posts/design-pattern/interpreter.html](https://twmht.github.io/blog/posts/design-pattern/interpreter.html). \
Visit for all other details.

## Design

Use the mini-language to control a toy car. \
Basic movements are

1. go: go straight
1. right: turn right
1. left: turn left
1. repeat: repeat the statement enclosed by repeat-end

e.g., \
program go right right go end \
program repeat 4 go right end end

### BNF (Backus Normal Form)

- <program> ::= program <command list>
- <command list> ::= <command>* end
- <command> ::= <repeat command> | <primitive command>
- <repeat command> ::= repeat <number> <command list>
- <primitive command> ::= go | right | left
