# Helldivers Stratagem Trainer

A small terminal mini-game written in C that helps you memorize **Helldivers 2** stratagem input patterns. Enter the directions with `WASD`, just like in the game, and the program tells you which stratagem you've completed.

> This is a fan-made practice tool. It is not affiliated with or endorsed by Arrowhead Game Studios or Sony Interactive Entertainment. *Helldivers* is a trademark of its respective owners.

## How it works

1. Start the program in any terminal.
2. Press `h` to display the stratagem sheet: the list of stratagems with their key combinations.
3. Enter a pattern with `W`, `A`, `S`, `D` (up, left, down, right). Each key you press is shown as an arrow.
4. The program checks your input against every stratagem in the sheet as you type:
   - If your keys still match at least one pattern, you keep going.
   - If they don't match any pattern, it prints `Wrong entry` and resets, ready for a new attempt.
   - When you complete a pattern, it prints the stratagem's name to confirm it is ready.

Keys are read instantly, with no need to press Enter.

## Controls

| Key | Action |
|---|---|
| `W` | Up |
| `A` | Left |
| `S` | Down |
| `D` | Right |
| `H` | Show the stratagem sheet |
| `Q` | Quit |

## Instructions

### Build

```bash
make          # builds the executable
make clean    # removes object files
make fclean   # removes object files and the executable
make re       # rebuilds everything
```

### Run

Run it from the project's root folder, because `stratagem.txt` is loaded from the current directory:

```bash
./helldivers
```

### Requirements

- A C compiler (`cc`/`gcc`/`clang`) and `make`
- A POSIX terminal (Linux, macOS, or WSL on Windows)
- A terminal font that can display the arrow glyphs (🡅 🡇 🡄 🡆). If they show up as empty boxes, install a font with Unicode arrow support.

## The stratagem sheet

Stratagems are defined in `stratagem.txt`, one per line: the key pattern first, then a space, then the name.

```
wsdaw Reinforce
ssdw Resupply
```

*(These two lines are only an illustration of the format.)* To add or fix a stratagem, edit that file. No recompilation is needed.

## Project structure

```
.
├── Makefile
├── stratagem.txt            # stratagem patterns and names
├── includes/
│   └── helldivers.h
└── srcs/
    ├── stratagem_training.c # terminal setup, input loop, key handling
    └── key_parsing.c        # pattern matching and arrow display
```

## Known limitations

- The matching code tracks up to 60 stratagems at once.
- The sheet must use only `w`, `a`, `s`, `d` for patterns.
