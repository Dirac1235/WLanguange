## WLanguage — small Flex/Bison-based interpreter

A small interpreter/parser project implemented with Flex (lex) and Bison (yacc). It parses a simple expression language, constructs an AST, and interprets or prints results. The codebase contains the lexer, parser, AST utilities, and a small example input in `examples/`.

## Repository layout

- `src/` — implementation sources: `ast.c`, `error.c`, `interpret.c`, `main.c`, `printAst.c`, `lex.l`, `parser.y`, etc.
- `include/` — public headers such as `ast.h`, `error.h`.
- `examples/` — example input files (e.g. `calc.w`).
- `build/` — generated build artifacts (contains `parser.tab.c`, `lex.yy.c`, etc.).
- top-level files: `Makefile`, `lex.yy.c`, `parser.tab.c`, `parser.tab.h`, `interpret` (built binary)

## Requirements

- GNU Make
- A C compiler (gcc/clang)
- Bison (for parser generation) — optional if you use the pre-generated sources in the repo
- Flex (for lexer generation) — optional if you use the pre-generated sources in the repo

On macOS you can install missing tools with Homebrew, e.g.: `brew install bison flex`.

## Build

The repository already includes generated parser/lexer files and a `Makefile`. The easiest build is:

```bash
make
```

This should produce an executable named `interpret` in the project root (or in the `build/` directory depending on the `Makefile`). If your `Makefile` places the binary elsewhere, adjust paths below accordingly.

To clean build artifacts:

```bash
make clean
```

If you prefer to regenerate the parser and lexer yourself (developer workflow):

```bash
bison -d parser.y -o parser.tab.c
flex -o lex.yy.c lex.l
# then compile (or use `make` which usually does this)
```

## Run

Run the interpreter against an example file or via standard input.

From project root (assuming `interpret` is in PATH or current directory):

```bash
./interpret examples/calc.w
# or
cat examples/calc.w | ./interpret
```

If the binary lives in `build/`:

```bash
./build/interpret examples/calc.w
```

## Project internals (for contributors)

- Grammar: `parser.y` — Bison grammar and semantic actions that build AST nodes.
- Lexer: `lex.l` — Flex rules that produce tokens for the parser.
- AST: `include/ast.h`, `src/ast.c` — AST node definitions and constructors (e.g., `makeBinaryExpr`).
- Interpreter/evaluator: `src/interpret.c` — walks the AST and evaluates expressions.
- Error handling: `src/error.c`, `include/error.h`.

When modifying grammar or lexer files, regenerate `parser.tab.c`/`parser.tab.h` and `lex.yy.c` before building, or commit the generated files if you want to keep the repo buildable without requiring Bison/Flex on users' machines.

## Examples

See `examples/calc.w` for a small sample program. The language supports binary operators, parentheses, and basic expressions. Use `printAst.c` for debugging AST construction.

## Tests and CI

There are no automated tests in the repository yet. Recommended next steps:

- Add a small test harness that runs `interpret` against example inputs and validates output.
- Add a CI workflow (GitHub Actions) to build and run the tests on push and PR.

## License

This repository does not include a LICENSE file. If you want an open-source license, add a `LICENSE` (for example, MIT or Apache-2.0) and update this README.

## Contact / Contributing

Contributions are welcome. Open an issue or submit a pull request with a clear description of changes. Include tests for any new behavior where practical.

---

Notes:

- This README assumes `make` produces an `interpret` binary in the project root; if your `Makefile` uses different paths, adapt accordingly.
- If you want, I can also add a simple `LICENSE` file and a GitHub Actions CI workflow that builds the project and runs the example as a smoke test.
