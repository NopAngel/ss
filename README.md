
# ss — Simple Snapshot Version Control

`ss` is a lightweight version control system written in C, designed to help you track changes, manage commits, and handle basic repository operations. It's a simplified alternative to Git, ideal for learning how version control works under the hood.

---

## 🚀 Features

- `init` — Initialize a new repository
- `add <file>` — Stage a file for commit
- `commit -m "<message>"` — Save a snapshot with a message
- `status` — Show current repository status
- `diff <file>` — View changes between working file and last commit
- `clean` — Clear the staging area
- `checkout <commit_id>` — Restore files from a previous commit
- `remote <url>` — Set a remote repository URL
- `head` — Show the latest commit ID
- `end` — Delete the repository

---

## 🛠️ Build Instructions

Make sure you have all source files in the `src/` folder and headers in `include/`.

### Compile manually:

```bash
gcc src/*.c -Iinclude -o ss
```

Or use the provided `Makefile`:

```bash
make
```

---

## 📦 Usage

```bash
./ss init
./ss add file.txt
./ss commit -m "Initial commit"
./ss status
./ss diff file.txt
./ss clean
./ss checkout 20250809153000
./ss remote https://example.com/repo.git
./ss head
./ss end
```

---

## 🧠 Why "ss"?

The name stands for **Simple Snapshot** — because this tool captures the essence of version control without the complexity.

---

## 📂 Project Structure

```
ss/
├── src/
│   ├── main.c
│   ├── add.c
│   ├── commit.c
│   ├── ...
├── include/
│   ├── add.h
│   ├── commit.h
│   ├── ...
├── README.md
├── Makefile
```

---

## 🤝 Contributing

Feel free to fork, improve, and submit pull requests. This project is meant to be a learning playground for systems programming and version control concepts.

---

## License

This project use Apache 2.0 (OPEN-SOURCE)
