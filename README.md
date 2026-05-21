# Crossword Word Search (C++)

Small C++ prototype that scans a fixed 10x10 character grid and tries to find words in eight directions (N, NE, E, SE, S, SW, W, NW).

## What's in this repo

- `index.cpp`: Core word search logic using a hardcoded grid and word list.
- `tests/test.cpp`: Placeholder test file that prints `Hello world`.

## How it works

- The grid is a fixed 10x10 `char` array.
- The word list is hardcoded: `STACK`, `ARRAY`, `LOOP`, `CLASS`, `POINTER`.
- The program scans all grid cells for a first-letter match, then checks in all 8 directions for a full word match.
- Matches are stored in `found_indices`, but nothing is printed yet.

## Build and run

Using g++ from the project folder:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic index.cpp -o crossword
./crossword
```

On Windows (PowerShell), if g++ is in PATH:

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -pedantic .\index.cpp -o .\crossword.exe
.\crossword.exe
```

## Notes

- The current program does not print results yet; it only stores matches internally.
- The test file is a placeholder and not wired to the main logic.

## Current Complexity of the Code (will be improved)

n: columns and rows in the grid.
m: number of words to search.

main(): O(n^2 \* m)
