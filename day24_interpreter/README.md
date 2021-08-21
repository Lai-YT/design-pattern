# Interpreter Pattern

This pattern isn't involved by guru. \
So in this specific topic, all codes are refered to and modified from [twmht.github.io/blog/posts/design-pattern/interpreter.html](https://twmht.github.io/blog/posts/design-pattern/interpreter.html). \
Visit for all other details.

## Design

Use the mini language below to control a toy car.

Basic movements are

- go: go straight
- right: turn right
- left: turn left

Other syntaxes are

- All statements should be enclosed by program-end.
- The statements enclosed by repeat-end is repeated.

### BNF (Backus Normal Form)

```
<program> ::= program <command list> end
<command list> ::= <command>*
<command> ::= <repeat command> | <primitive command>
<repeat command> ::= repeat <number> <command list> end
<primitive command> ::= go | right | left
```

### Example

- program go right right go end
- program repeat 4 go right end end
