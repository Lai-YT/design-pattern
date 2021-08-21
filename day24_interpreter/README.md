# Interperter Pattern

This pattern isn't involved by guru. \
So in this specific topic, all codes are refered to and modified from [https://twmht.github.io/blog/posts/design-pattern/interpreter.html](https://twmht.github.io/blog/posts/design-pattern/interpreter.html). \
Visit for all other details.

## Design

Use the mini-language to control a toy car. \
Basic movements are

- go: go straight
- right: turn right
- left: turn left
- repeat-end: repeat the enclosed statement

### BNF (Backus Normal Form)

```
<program> ::= program <command list>
<command list> ::= <command>* end
<command> ::= <repeat command> | <primitive command>
<repeat command> ::= repeat <number> <command list>
<primitive command> ::= go | right | left
```

### Example

- program go right right go end
- program repeat 4 go right end end
