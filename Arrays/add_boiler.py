import os
import glob

# Append to C++ files
for filepath in glob.glob("cpp/*.cpp"):
    with open(filepath, "r") as f:
        content = f.read()
    if "int main()" not in content:
        with open(filepath, "a") as f:
            f.write("\n\nint main() {\n    return 0;\n}\n")

# Append to Python files
for filepath in glob.glob("python/*.py"):
    with open(filepath, "r") as f:
        content = f.read()
    if "if __name__ == '__main__':" not in content and "if __name__ == \"__main__\":" not in content:
        with open(filepath, "a") as f:
            f.write("\n\nif __name__ == '__main__':\n    pass\n")

print("Boilerplate code added successfully.")
